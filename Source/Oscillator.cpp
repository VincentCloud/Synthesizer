/*
  ==============================================================================

    Oscillator.cpp
    Created: 26 Nov 2020 2:39:55pm
    Author:  Vincent Huang

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Oscillator.h"
#include "PluginProcessor.h"


//==============================================================================
Oscillator::Oscillator(SynthesizerAudioProcessor& p) :
audioProcessor(p)
{
    setSize(200, 200);

    oscMenu.addItem("Sine", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Square", 3);
    oscMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscMenu);
    oscMenu.addListener(this);

    comboBoxAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.apvts, "WAVETYPE", oscMenu);

}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (juce::Graphics& g)
{

}

void Oscillator::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40, 40); // give some margin

    oscMenu.setBounds(area.removeFromTop(20));

}

void Oscillator::comboBoxChanged(ComboBox * box) {

}
