/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

using namespace juce;
//==============================================================================
PaddedAudioProcessorEditor::PaddedAudioProcessorEditor (PaddedAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    initPadGrid();
    setSize (1000, 600); // required
}

PaddedAudioProcessorEditor::~PaddedAudioProcessorEditor()
{
}

//==============================================================================
void PaddedAudioProcessorEditor::initPadGrid() {
    int numPads = 5;
    for(int i = 0; i < numPads; ++i) {
        grid.push_back(new TextButton("Sample " + String(i+1)));
        addAndMakeVisible(grid[i]);
    }
}

void PaddedAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void PaddedAudioProcessorEditor::resized()
{
    for (int i = 0; i < grid.size(); ++i) {
        int x = i * 200;
        int y = 25;
        grid[i]->setBounds(x, y, 200, 550);
    }
}
