/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SynthesizerAudioProcessorEditor  : public juce::AudioProcessorEditor, public Slider::Listener
{
public:
    SynthesizerAudioProcessorEditor (SynthesizerAudioProcessor&);
    ~SynthesizerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged (Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthesizerAudioProcessor& audioProcessor;
    Slider attackSlider;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> sliderTree;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthesizerAudioProcessorEditor)
};
