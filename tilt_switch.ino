#include "pitches.h"

const int ledPin = 13;
const int buzzerPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
}

void loop() {
  int digitalVal = digitalRead(2);
  if (HIGH == digitalVal) {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  } else {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, NOTE_A5, 100);
    delay(150);
    noTone(buzzerPin);
  }
}
