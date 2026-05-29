#include "SR04.h"

#define TRIG_PIN 12
#define ECHO_PIN 11
#define GREEN_LED 4
#define YELLOW_LED 3
#define RED_LED 2
#define BUZZER 8

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  long distance = sr04.Distance();
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  noTone(BUZZER);

  // ignore invalid readings
  if (distance <= 0 || distance > 200) {
    digitalWrite(GREEN_LED, HIGH);
    delay(100);
    return;
  }

  if (distance > 50) {
    digitalWrite(GREEN_LED, HIGH);
    
  } else if (distance > 20) {
    digitalWrite(YELLOW_LED, HIGH);
    tone(BUZZER, 1000, 100);
    delay(500);
    
  } else if (distance > 5) {
    digitalWrite(RED_LED, HIGH);
    tone(BUZZER, 1500, 100);
    delay(200);
    
  } else {
    digitalWrite(RED_LED, HIGH);
    tone(BUZZER, 2000);
  }
  
  delay(100);
}
