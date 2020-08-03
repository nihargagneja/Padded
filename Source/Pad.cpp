/*
  ==============================================================================

    Pad.cpp
    Created: 3 Aug 2020 4:31:23pm
    Author:  Nihar Gagneja

  ==============================================================================
*/

#include "Pad.h"
using namespace juce;

Pad::Pad(TextButton* psb, ImageButton* lsb) {
    playSampleButton = psb;
    loadSampleButton = lsb;
}

TextButton* Pad::getPlaySampleButton() {
    return this->playSampleButton;
}

ImageButton* Pad::getLoadSampleButton() {
    return this->loadSampleButton;
}

Label* Pad::getMidiTriggerText() {
    return this->midiTriggerText;
}

void Pad::draw(int x, int y, int height, int width) {
    playSampleButton->setBounds(x, y, height, width);
    loadSampleButton->setBounds(x, y + 300, 40, width - 10);
    
    midiTriggerText->attachToComponent(playSampleButton, true);
    midiTriggerText->setText("C3", dontSendNotification);
    midiTriggerText->setColour(Label::textColourId, Colours::grey);
    midiTriggerText->setBounds(x + 15, y + 15, 40, 10);
}


