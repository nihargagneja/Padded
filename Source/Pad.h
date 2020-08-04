/*
  ==============================================================================

    Pad.h
    Created: 3 Aug 2020 4:31:23pm
    Author:  Nihar Gagneja

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

using namespace juce;

class Pad {
private:
    TextButton* playSampleButton;
    ImageButton* loadSampleButton;
    
    File sample;
    int midiTrigger;
    Label* midiTriggerText = new Label {"C4"};

public:
    // constructors
    Pad(TextButton* tb, ImageButton* ib, int midiTrigger);
    
    // set and get
    TextButton* getPlaySampleButton();
    ImageButton* getLoadSampleButton();
    Label* getMidiTriggerText();
    
    void draw(int x, int y, int height, int width);
};

