/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthesizerAudioProcessorEditor::SynthesizerAudioProcessorEditor (SynthesizerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), oscGUI(p), envGUI(p)
{
    setSize (400, 200);

    addAndMakeVisible(&oscGUI);
    addAndMakeVisible(&envGUI);
}

SynthesizerAudioProcessorEditor::~SynthesizerAudioProcessorEditor()
{
}

//==============================================================================
void SynthesizerAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void SynthesizerAudioProcessorEditor::resized()
{
    Rectangle<int> area = getLocalBounds();

    const int oscComponentWidth = 150;
    const int oscComponentHeight = 200;

    const int envComponentWidth = 250;
    const int envComponentHeight = 200;

    oscGUI.setBounds(area.removeFromLeft(oscComponentWidth).removeFromTop(oscComponentHeight));
    envGUI.setBounds(area.removeFromLeft(envComponentWidth).removeFromTop(envComponentHeight));
}
