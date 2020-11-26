/*
  ==============================================================================

    SynthSound.h
    Created: 10 Nov 2020 11:24:58am
    Author:  Vincent Huang

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public juce::SynthesiserSound{
public:
    bool appliesToNote (int /*midiNoteNumber*/) {
        return true;
    }

    bool appliesToChannel (int /*midiChannel*/) {
        return true;
    }
};
