/*
  ==============================================================================

    Envelope.cpp
    Created: 26 Nov 2020 8:17:37pm
    Author:  Vincent Huang

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(SynthesizerAudioProcessor& p) :
audioProcessor(p)
{


    setSize(300, 200);

    // attack slider
    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    attackSlider.setValue(0.1f);
    attackSlider.addListener(this);
    addAndMakeVisible(attackSlider);
    attackSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ATTACK", attackSlider);

    addAndMakeVisible(attackLabel);
    attackLabel.setText("Attack", juce::dontSendNotification);
    attackLabel.attachToComponent(&attackSlider, false);

    // decay slider
    decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decaySlider.setRange(0.1f, 2000.0f);
    decaySlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    decaySlider.setValue(0.1f);
    decaySlider.addListener(this);
    addAndMakeVisible(decaySlider);
    decaySliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "DECAY", decaySlider);

    addAndMakeVisible(decayLabel);
    decayLabel.setText("Decay", juce::dontSendNotification);
    decayLabel.attachToComponent(&decaySlider, false);

    // sustain slider
    sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustainSlider.setRange(0.1f, 0.8f);
    sustainSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    sustainSlider.setValue(0.1f);
    sustainSlider.addListener(this);
    addAndMakeVisible(sustainSlider);
    sustainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "SUSTAIN", sustainSlider);

    addAndMakeVisible(sustainLabel);
    sustainLabel.setText("Sustain", juce::dontSendNotification);
    sustainLabel.attachToComponent(&sustainSlider, false);

    // release Slider
    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseSlider.setRange(0.1f, 5000.0f);
    releaseSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    releaseSlider.setValue(0.1f);
    releaseSlider.addListener(this);
    addAndMakeVisible(&releaseSlider);
    releaseSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "RELEASE", releaseSlider);

    addAndMakeVisible(releaseLabel);
    releaseLabel.setText("Release", juce::dontSendNotification);
    releaseLabel.attachToComponent(&releaseSlider, false);
}

Envelope::~Envelope()
{
}

void Envelope::paint (juce::Graphics& g)
{
    g.fillAll(Colours::black);
}

void Envelope::resized()
{
    attackSlider.setBounds(10, 30, 45, 100);
    decaySlider.setBounds(50, 30, 45, 100);
    sustainSlider.setBounds(90, 30, 45, 100);
    releaseSlider.setBounds(130, 30, 45, 100);
}

void Envelope::sliderValueChanged (Slider* slider) {
}

