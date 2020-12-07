# Objective

The goal of my project was to build a basic version of a wavetable synthesizer that can be plugged into a DAW and work cross-platform. It can deal with incoming midi messages and produces different   wave forms. Moreover, inspired by ReaMote and Reaper, I decided to add in support for remote control as well provided with the IP address and port number of the host. A user can use any OpenSoundControl applications to change the behavior of the synthesizer, all operations can be performed from the host as well.

# Technical Stack

## JUCE

JUCE is a framework built in C++ for cross-platform audio development. It supports building on PC, Mac, Linux, Android and IOS for plug-in formats including AU, VST and AAX. JUCE constitutes the back bone of this project and I used it as a bare minimum to start. For this project specifically, I utilized the synthesizer module to hold the DSP algorithms and the OSCReceiver class to receive and parse the OSC messages

## Maximilian

Maximilian is a library for audio synthesis and signal processing built in C++. Unlike JUCE, it is a less opinionated framework, which gives the user more control over the application and its DSP modules are simpler to implement, especially considering I have limited experience with DSP. I decided that it is a good idea to import this library as a third-party tool to ease the learning curve on DSP algorithms.

# Binaries

The binaries for this project can be found here [https://github.com/VincentCloud/Synthesizer/releases/tag/v1.0](https://github.com/VincentCloud/Synthesizer/releases/tag/v1.0).

# Project Architecture and Implementations

The overall structure of this project is similar to a typical JUCE project, where different parts of the application are divided into hierarchical components. 

![https://github.com/VincentCloud/Synthesizer/blob/master/architecture.png](https://github.com/VincentCloud/Synthesizer/blob/master/architecture.png)

A rough architecture diagram on the structure of the synthesizer

As shown in the diagram, the two main components of this application are `SynthesizerAudioProcessor` and `SynthesizerAudioProcessorEditor`, which are responsible for the DSP algorithms and UI, respectively. `SynthSound.h` and `SynthVoice` are utilized to support the I/O feature.

## DSP Components

On the DSP aspect, `SynthVoice` class extends from JUCE's built-in `SynthesiserVoice` class, where the parent takes care of the sampling, input and output of the sound. In order to make this application work as a standalone app as well as a plugin usable in DAW, I decided to convert the midi message into wave frequency to produce an output. This is simpler than relying on a midi output device and it simplifies the "pitch bend" feature significantly. `SynthesiserVoice` follows an event-driven protocol, which means it keeps a message loop on a separate thread to detect different events from the input devices such as "note on", "note off", "pitch bend", etc. When a event is detected, a callback function will be triggered to perform certain operations. For example, in `pitchWheelMoved`, it detects the "pitch bend" midi message and changes the frequency of the sample accordingly. `renderNextBlock` gets called by the main DSP component to output the sample block. Since the DSP component works on an audio thread where the sampling happens at a very high rate, it is critical to leave out any standard input / output messages as they could slow down the system and cause delay.

## UI Components

On the UI side, I followed the conventional way of making a GUI application in JUCE having the `SynthesizerAudioProcessorEditor` as the main UI component. Its child components are Oscillator and Envelope. The Oscillator component is mainly responsible for showing up the options of wave forms in a combo box, which enables the user to select from sine wave, saw wave and square wave. This component takes up roughly 1/3 of the width of the main window. On the other hand, the Envelope component helps the user modify the behavior of the wave. In this project specifically, I built an adsr synthesizer, which has "attack", "decay", "sustain" and "release" as the parameters. And the user is able to change the parameters through the sliders. 

## Communications Between Components

Mapping the control in UI to the processor component is the most critical part in this project. And I have experimented different ways of doing this in JUCE. Recalling the listeners mentioned above, they monitor the change of a certain parameter from the processor, which could have been easily achieved if there was only one component. However, this was not the case in my project. We have multiple independent classes and we would need to pass 5 different parameters among different components. We could set up a reference for each but this approach would easily get messy when we have multiple threads and a single race condition could lead us into the undefined behavior area. Therefore, I adopted the class `AudioProcessorValueTreeState`, which packs the parameter and store them in one object (`apvts`). This object is stored within the `SynthesizerAudioProcessor`, which is a singleton class in this project. In this way, we can access the parameters from any class as long as we have access to the `SynthesizerAudioProcessor` class.

## Open Sound Control Feature

For the OSC feature of the Synthesizer, it was set up to listen to port 8000 on the host and it will receive OSC messages in the address /adsr and in the format of <value> <message_type>. For example, passing in "/adsr 2000 attack" will set the attack time of the synthesizer to 2000ms. In terms of the implementation, OSC messages are parsed in `SynthesizerAudioProcessor` class because we can have direct access to the `apvts`. When a parameter value is changed, it will notify the other components as long as they access the audioProcessor instance. Moreover, the corresponding callbacks functions bound to events will be triggered as well.

# Results and Demo

# Challenges and Reflection

Despite the learning curve of JUCE and C++, I managed to build a working version of this Synthesizer though very basic. The biggest challenge in this project would be the communications between the "frontend" and the "backend". The publisher-subscriber pattern was new to me and I had to read up on this topic to get a good idea of how it works. The documentation from JUCE was enough for reference but quite hard to understand. I needed to borrow ideas from a series of youtube videos to get myself started on this framework. Besides, due to the nature of C++, it requires the skills and proficiency to truly utilize this language to its best potential, but to me it was a steep learning curve especially coming from smaller libraries like RtMidi. 

One existing problem with this project is that I constantly get popup noise when switching notes or executing pitch bending command via my MIDI keyboard. I could not fix it in the end, but I did get some progress. When rendering the blocks, originally I always started from sample 0, which can cause a cutoff between two different notes because the sampling always starts from the first. JUCE hid the logic it deals with `renderNextBlock` and always starting from where the previous call left off reduced the noise between note switching. However, it did not fix the pop up noise with pitch bending.

# Full Report
https://www.notion.so/OSCSynthesizer-d4b22df37a86415cbce6b56186c418fc
