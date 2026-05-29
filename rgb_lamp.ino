#define RED 6
#define GREEN 5
#define BLUE 3
#define TILT_PIN 2

int currentColor = 0;
bool lastState = HIGH;

void setColor(int r, int g, int b) {
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(TILT_PIN, INPUT);
  digitalWrite(TILT_PIN, HIGH);
  setColor(255, 0, 0); // start red
}

void loop() {
  bool currentState = digitalRead(TILT_PIN);
  
  if (currentState != lastState) {
    delay(50); // debounce
    if (currentState == LOW) {
      currentColor = (currentColor + 1) % 6;
      switch(currentColor) {
        case 0: setColor(255, 0, 0);   break; // red
        case 1: setColor(0, 255, 0);   break; // green
        case 2: setColor(0, 0, 255);   break; // blue
        case 3: setColor(255, 255, 0); break; // yellow
        case 4: setColor(0, 255, 255); break; // cyan
        case 5: setColor(255, 0, 255); break; // purple
      }
    }
    lastState = currentState;
  }
}
