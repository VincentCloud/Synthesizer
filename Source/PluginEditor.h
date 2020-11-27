/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Oscillator.h"

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
    Oscillator oscGUI;

//    juce::Slider attackSlider;
//    juce::Slider releaseSlider;
//    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> attackSliderAttachment;
//    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> releaseSliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthesizerAudioProcessorEditor)
};
