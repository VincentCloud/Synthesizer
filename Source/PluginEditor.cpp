/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthesizerAudioProcessorEditor::SynthesizerAudioProcessorEditor (SynthesizerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);

    attackSlider.setValue(0.1f);
//    attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20, 10);
    attackSlider.addListener(this);
    addAndMakeVisible(&attackSlider);

    sliderTree = new AudioProcessorValueTreeState::SliderAttachment(audioProcessor.tree, "attack", attackSlider);
}

SynthesizerAudioProcessorEditor::~SynthesizerAudioProcessorEditor()
{
}

//==============================================================================
void SynthesizerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void SynthesizerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    attackSlider.setBounds(10, 10, 40, 100);
}

void SynthesizerAudioProcessorEditor::sliderValueChanged (Slider* slider) {
    if (slider == &attackSlider) {
        audioProcessor.attackTime = attackSlider.getValue();
    }
}