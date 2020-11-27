/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Oscillator.h"
#include "Envelope.h"

//==============================================================================
/**
*/
class SynthesizerAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SynthesizerAudioProcessorEditor (SynthesizerAudioProcessor&);
    ~SynthesizerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthesizerAudioProcessor& audioProcessor;
    Oscillator oscGUI;
    Envelope envGUI;

//    juce::Slider attackSlider;
//    juce::Slider releaseSlider;
//    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> attackSliderAttachment;
//    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> releaseSliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthesizerAudioProcessorEditor)
};
