#include "pitches.h"

int melody[] = {
  NOTE_E5, NOTE_D5, NOTE_FS4, NOTE_GS4,
  NOTE_CS5, NOTE_B4, NOTE_D4, NOTE_E4,
  NOTE_B4, NOTE_A4, NOTE_CS4, NOTE_E4,
  NOTE_A4
};

int durations[] = {
  125, 125, 250, 250,
  125, 125, 250, 250,
  125, 125, 250, 250,
  1000
};

void setup() {}

void loop() {
  for (int i = 0; i < 13; i++) {
    tone(8, melody[i], durations[i]);
    delay(durations[i] * 1.3);
    noTone(8);
  }
  delay(2000);
}
