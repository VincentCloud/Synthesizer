/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "SynthVoice.h"

//==============================================================================
/**
*/
class SynthesizerAudioProcessor  : public juce::AudioProcessor,
        public OSCReceiver,
        public OSCReceiver::ListenerWithOSCAddress<OSCReceiver::MessageLoopCallback>
{
public:
    //==============================================================================
    SynthesizerAudioProcessor();
    ~SynthesizerAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    void oscMessageReceived(const OSCMessage& message) override;



    float attackTime; // set it to pass the attack values to other components
    float releaseTime;
    AudioProcessorValueTreeState apvts;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthesizerAudioProcessor)
    juce::AudioProcessorValueTreeState::ParameterLayout createParameters();

    juce::Synthesiser mySynth;
    SynthVoice *myVoice;

    double lastSampleRate;
};
