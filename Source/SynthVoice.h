/*
  ==============================================================================

    SynthVoice.h
    Created: 10 Nov 2020 11:25:19am
    Author:  Vincent Huang

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"

class SynthVoice : public juce::SynthesiserVoice {
public:
    bool canPlaySound ( juce::SynthesiserSound * sound) override {
        // return whether it can play a sound
        // use a dynamic cast
        return dynamic_cast<SynthSound *>(sound) != nullptr;
    }

    void getParam (float * attack, float * release) {
        // set the attack value
        env1.setAttack(double(*attack));
        env1.setRelease(double(*release));
    }

    void startNote ( int midiNoteNumber, float velocity, juce::SynthesiserSound * sound, int currentPitch ) override {
        // when a key is hit on the keyboard, what's gonna happen
        env1.trigger = 1; // whether the env is triggered
        level = velocity;
        frequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        std::cout << midiNoteNumber << std::endl;
    }

    void stopNote ( float velocity, bool allowTailOff ) override {
        // clear the note after we stop playing
        env1.trigger = 0;
        allowTailOff = true;

        if ( velocity == 0 )
            clearCurrentNote();
    }

    void pitchWheelMoved ( int newPitchWheelValue ) override {

    }

    void controllerMoved (int controllerNumber, int newControllerValue ) override {

    }

    void renderNextBlock ( juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples ) override {
        env1.setDecay(500);
        env1.setSustain(0.8);

        for (int sample = 0; sample < numSamples; sample++) {
            double theWave = osc1.saw(frequency);
            double theSound = env1.adsr(theWave, env1.trigger) * level;
            double filterdSound = filter1.lores(theSound, 200, 0.1);
//            cout << "theWave "<<theWave << std::endl;
            for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++) {

                outputBuffer.addSample(channel, sample, filterdSound);
            }

            startSample++;
        }


    }

private:
    double level;
    double frequency;

    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;
};