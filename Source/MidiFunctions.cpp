/*
  ==============================================================================

    MidiFunctions.cpp
    Created: 3 Aug 2020 9:43:40pm
    Author:  Nihar Gagneja

  ==============================================================================
*/

#include "MidiFunctions.h"
#include <string>

using namespace std;

string midiToPitchName(int midiValue) {
    return getPitchClassFromMidiValue(midiValue) + to_string(getOctaveFromMidiValue(midiValue));
}

int getOctaveFromMidiValue(int midiValue) {
    return (midiValue - 21) / 12 + 1; // purposely do integer division to remove decimal
}


string getPitchClassFromMidiValue(int midiValue) {
    switch (midiValue%12) {
        case 0:
            return "C";
            break;
        case 1:
            return "C#";
            break;
        case 2:
            return "D";
            break;
        case 3:
            return "D#";
            break;
        case 4:
            return "E";
            break;
        case 5:
            return "F";
            break;
        case 6:
            return "F#";
            break;
        case 7:
            return "G";
            break;
        case 8:
            return "G#";
            break;
        case 9:
            return "A";
            break;
        case 10:
            return "A#";
            break;
        case 11:
            return "B";
            break;
        default:
            return "ERR";
            break;
    }
}
