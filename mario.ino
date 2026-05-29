#include "pitches.h"

int melody[] = {
  NOTE_E5, NOTE_E5, 0, NOTE_E5, 0, NOTE_C5, NOTE_E5, 0,
  NOTE_G5, 0, 0, 0, NOTE_G4, 0, 0, 0,
  NOTE_C5, 0, 0, NOTE_G4, 0, 0, NOTE_E4, 0,
  0, NOTE_A4, 0, NOTE_B4, 0, NOTE_AS4, NOTE_A4, 0,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, 0, NOTE_F5, NOTE_G5,
  0, NOTE_E5, 0, NOTE_C5, NOTE_D5, NOTE_B4, 0, 0
};

int durations[] = {
  125, 125, 125, 125, 125, 125, 125, 125,
  125, 125, 125, 125, 125, 125, 125, 125,
  125, 125, 125, 125, 125, 125, 125, 125,
  125, 125, 125, 125, 125, 125, 125, 125,
  83, 83, 83, 125, 125, 125, 125,
  125, 125, 125, 125, 125, 125, 125, 125
};

void setup() {}

void loop() {
  for (int i = 0; i < 48; i++) {
    if (melody[i] == 0) {
      noTone(8);
    } else {
      tone(8, melody[i], durations[i]);
    }
    delay(durations[i] * 1.3);
    noTone(8);
  }
  delay(4000);
}
