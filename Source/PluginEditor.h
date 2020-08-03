/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
using namespace juce;
class PaddedAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    PaddedAudioProcessorEditor (PaddedAudioProcessor&);
    ~PaddedAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void initPadGrid();

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PaddedAudioProcessor& audioProcessor;
    std::vector<TextButton*> grid;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PaddedAudioProcessorEditor)
};
