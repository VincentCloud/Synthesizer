/*
  ==============================================================================

    Oscillator.h
    Created: 26 Nov 2020 2:39:55pm
    Author:  Vincent Huang

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Oscillator  : public juce::Component, private ComboBox::Listener
{
public:
    Oscillator(SynthesizerAudioProcessor&);
    ~Oscillator() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void comboBoxChanged(ComboBox*) override;

private:
    SynthesizerAudioProcessor& audioProcessor;

    ComboBox oscMenu;
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> comboBoxAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
