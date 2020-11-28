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

class SynthVoice : public juce::SynthesiserVoice{
public:

    bool canPlaySound ( juce::SynthesiserSound * sound) override {
        // return whether it can play a sound
        // use a dynamic cast
        return dynamic_cast<SynthSound *>(sound) != nullptr;
    }

    void getParam (float * attack, float *decay, float *sustain, float * release) {
        // set the attack value
        env1.setAttack(double(*attack));
        env1.setDecay(double(*decay));
        env1.setSustain(double(*sustain));
        env1.setRelease(double(*release));
    }

    void getOscType(float *selection) {
        theWave = *selection;
    }

    double setOscType() {
        if (theWave == 0) {
            return osc1.sinewave(frequency);
        }
        if (theWave == 1) {
            return osc1.saw(frequency);
        }
        if (theWave == 2) {
            return osc1.square(frequency);
        } else {
            return osc1.sinewave(frequency);
        }
    }

    void startNote ( int midiNoteNumber, float velocity, juce::SynthesiserSound * sound, int currentPitch ) override {
        // when a key is hit on the keyboard, what's gonna happen
        env1.trigger = 1; // whether the env is triggered
        note = midiNoteNumber;
        level = velocity;
        frequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    }

    void stopNote ( float velocity, bool allowTailOff ) override {
        // clear the note after we stop playing
        env1.trigger = 0;
        allowTailOff = true;

        if ( velocity == 0 ) {
            clearCurrentNote();
            note = 0;
        }
    }

    void pitchWheelMoved ( int newPitchWheelValue ) override {
//        cout << "frequency before " << frequency << std::endl;
        frequency = pow(2, (newPitchWheelValue - 8192.0)/8192.0) * juce::MidiMessage::getMidiNoteInHertz(note);
//        cout << "pitch wheel value " << newPitchWheelValue << std::endl;
//        cout << "power " << (newPitchWheelValue - 8192.0)/8192.0 << std::endl;
//        cout << "new frequency " << frequency << std::endl;
    }

    void controllerMoved (int controllerNumber, int newControllerValue ) override {

    }

    void renderNextBlock ( juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples ) override {

        for (int sample = startSample; sample < numSamples; sample++) {
            double theSound = env1.adsr(setOscType(), env1.trigger) * level;
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
    int theWave;
    int note;

    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;
};