/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SynthesizerAudioProcessor::SynthesizerAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), apvts(*this, nullptr, "Parameters", createParameters())
#endif
{
    /*
     * create 5 voices
     */
    mySynth.clearVoices();

    for ( int i = 0; i < 5; i++) {
        mySynth.addVoice( new SynthVoice() );
    }

    mySynth.clearSounds();
    mySynth.addSound((new SynthSound()));
}

SynthesizerAudioProcessor::~SynthesizerAudioProcessor()
{
}

//==============================================================================
const juce::String SynthesizerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SynthesizerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SynthesizerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SynthesizerAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SynthesizerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SynthesizerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SynthesizerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SynthesizerAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SynthesizerAudioProcessor::getProgramName (int index)
{
    return {};
}

void SynthesizerAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SynthesizerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    juce::ignoreUnused(samplesPerBlock); // ignore unused samples from the last key press
    lastSampleRate = sampleRate;
    mySynth.setCurrentPlaybackSampleRate(lastSampleRate);

}

void SynthesizerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SynthesizerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SynthesizerAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    for (int i = 0; i < mySynth.getNumVoices(); i++) {
        myVoice = dynamic_cast<SynthVoice *>(mySynth.getVoice((i)));
        if (myVoice) {
            myVoice->getParam((float*)(apvts.getRawParameterValue("ATTACK")),
                              (float*)(apvts.getRawParameterValue("DECAY")),
                              (float*)(apvts.getRawParameterValue("SUSTAIN")),
                              (float*)(apvts.getRawParameterValue("RELEASE")));

            myVoice->getOscType((float *)apvts.getRawParameterValue("WAVETYPE"));
        }
    }


    buffer.clear();

    mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());

}

//==============================================================================
bool SynthesizerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* SynthesizerAudioProcessor::createEditor()
{
    return new SynthesizerAudioProcessorEditor (*this);
}

//==============================================================================
void SynthesizerAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SynthesizerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SynthesizerAudioProcessor();
}

juce::AudioProcessorValueTreeState::ParameterLayout SynthesizerAudioProcessor::createParameters(){
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
    params.push_back(std::make_unique<juce::AudioParameterFloat>("ATTACK", "Attack", 0.1f, 5000.0f, 0.1f));
    params.push_back(std::make_unique<juce::AudioParameterFloat>("DECAY", "Decay", 0.1f, 2000.0f, 0.1f));
    params.push_back(std::make_unique<juce::AudioParameterFloat>("SUSTAIN", "Sustain", 0.1f, 0.8f, 0.1f));
    params.push_back(std::make_unique<juce::AudioParameterFloat>("RELEASE", "Release", 0.1f, 5000.0f, 0.1f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>("WAVETYPE", "WaveType", 0, 2, 0)); // the combox selection is 1-index, but the param is 0-index
    return { params.begin(), params.end() };
}
