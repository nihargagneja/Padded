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
    //initGrid();
    initPadGrid();
    setSize (1000, 600); // required
}

PaddedAudioProcessorEditor::~PaddedAudioProcessorEditor()
{
}

//==============================================================================
void PaddedAudioProcessorEditor::initGrid() {
    for(int i = 0; i < numPads; ++i) {
        grid.push_back(new TextButton("Sample " + String(i+1)));
        addAndMakeVisible(grid[i]);
    }
}

void PaddedAudioProcessorEditor::initPadGrid() {
    for(int i = 0; i < numPads; ++i) {
        TextButton* playSampleButton = new TextButton("Sample" + String(i + 1));
        ImageButton* loadSampleButton = new ImageButton();
        padGrid.push_back(new Pad(playSampleButton, loadSampleButton));
        
        addAndMakeVisible(padGrid[i]->getLoadSampleButton());
        addAndMakeVisible(padGrid[i]->getPlaySampleButton());
        //addAndMakeVisible(padGrid[i]->getMidiTriggerText()); do i need this?
    }
}

void PaddedAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void PaddedAudioProcessorEditor::resized()
{
    for (int i = 0; i < padGrid.size(); ++i) {
        int x = i * 200;
        int y = 25;
        padGrid[i]->draw(x, y, 200, 550);
    }
}
