/*
  ==============================================================================

    Envelope.h
    Created: 26 Nov 2020 8:17:37pm
    Author:  Vincent Huang

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Envelope  : public juce::Component,
                  public Slider::Listener
{
public:
    Envelope(SynthesizerAudioProcessor &);
    ~Envelope() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged (Slider* slider) override;

private:
    juce::Slider attackSlider;
    juce::Label attackLabel;
    juce::Slider decaySlider;
    juce::Label decayLabel;
    juce::Slider sustainSlider;
    juce::Label sustainLabel;
    juce::Slider releaseSlider;
    juce::Label releaseLabel;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> attackSliderAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> decaySliderAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sustainSliderAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> releaseSliderAttachment;

    SynthesizerAudioProcessor& audioProcessor;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
