#include <MIDI.h>
#include "noteList.h"
#include "pitches.h"
#include "AY38910.h"

//MIDI_CREATE_DEFAULT_INSTANCE();
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
AY38910 PSG;

#ifdef ARDUINO_SAM_DUE // Due has no tone function (yet), overriden to prevent build errors.
#define tone(...)
#define noTone(...)
#endif

// This example shows how to make a simple synth out of an Arduino, using the
// tone() function. It also outputs a gate signal for controlling external
// analog synth components (like envelopes).

static const unsigned sGatePin     = 13;
static const unsigned sAudioOutPin = 10;
static const unsigned sMaxNumNotes = 16;
MidiNoteList<sMaxNumNotes> midiNotes;
char buf[80];

// -----------------------------------------------------------------------------

inline void handleGateChanged(bool inGateActive)
{
    digitalWrite(sGatePin, inGateActive ? HIGH : LOW);
}

inline void pulseGate()
{
    handleGateChanged(false);
    delay(1);
    handleGateChanged(true);
}

// -----------------------------------------------------------------------------

void handleNotesChanged(bool isFirstNote = false)
{
    if (midiNotes.empty())
    {
        handleGateChanged(false);
        noTone(sAudioOutPin); // Remove to keep oscillator running during envelope release.
    }
    else
    {
        // Possible playing modes:
        // Mono Low:  use midiNotes.getLow
        // Mono High: use midiNotes.getHigh
        // Mono Last: use midiNotes.getLast

        byte currentNote = 0;
        if (midiNotes.getLast(currentNote))
        {
            tone(sAudioOutPin, sNotePitches[currentNote]);

            if (isFirstNote)
            {
                handleGateChanged(true);
            }
            else
            {
                pulseGate(); // Retrigger envelopes. Remove for legato effect.
            }
        }
    }
}

// -----------------------------------------------------------------------------

void handleNoteOn(byte inChannel, byte inNote, byte inVelocity)
{
    const bool firstNote = midiNotes.empty();
    midiNotes.add(MidiNote(inNote, inVelocity), inChannel);
    //handleNotesChanged(firstNote);
    byte aNote;
    byte aIdx;
    midiNotes.getIdx(aIdx, inNote, inChannel);
    //sprintf(buf,"ON  SZ %3d IX %3d CH %3d NT %3d  VL %3d", midiNotes.size(), aIdx, inChannel, inNote, inVelocity);
    //Serial2.println(buf);
    if((inNote > 20) && (inNote < 108))
    {
      PSG.setTone(aIdx, inNote);
      PSG.setAmplitude(aIdx, inVelocity);
    }
}

void handleNoteOff(byte inChannel, byte inNote, byte inVelocity)
{

    byte aNote;
    byte aIdx;
    if(midiNotes.getIdx(aIdx, inNote, inChannel)) 
    {
      midiNotes.remove(inNote, inChannel);
    } 
    else
    {
      midiNotes.getIdx(aIdx, inNote);
      midiNotes.remove(inNote);
    }
    
    //sprintf(buf,"OFF SZ %3d IX %3d CH %3d NT %3d  VL %3d", midiNotes.size(), aIdx, inChannel, inNote, inVelocity);
    //Serial2.println(buf);
    //handleNotesChanged();
    PSG.setAmplitude(aIdx, 0);
}

// -----------------------------------------------------------------------------

void setup()
{
    pinMode(sGatePin,     OUTPUT);
    pinMode(sAudioOutPin, OUTPUT);
    MIDI.setHandleNoteOn(handleNoteOn);
    MIDI.setHandleNoteOff(handleNoteOff);
    MIDI.begin(MIDI_CHANNEL_OMNI);
    PSG.begin();
    Serial2.begin(115200);
    Serial2.println("--- START ---");
}

void loop()
{
    MIDI.read();
}
