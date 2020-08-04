/*
  ==============================================================================

    MidiFunctions.h
    Created: 3 Aug 2020 9:43:40pm
    Author:  Nihar Gagneja

  ==============================================================================
*/

#pragma once

#ifndef MIDI_FUNCTIONS_H_INCLUDED
#define MIDI_FUNCTIONS_H_INCLUDED

#include <string>
using namespace std;

string getPitchClassFromMidiValue(int midiValue);
string midiToPitchName(int midiValue);
int getOctaveFromMidiValue(int midiValue);

#endif
