#include <IRremote.h>

// Pin definitions
const int button1 = 2; // Push button connected to D2
const int button2 = 4; // Push button connected to D3
const int button3 = 5; // Push button connected to D4
const int button4 = 6; // Push button connected to D5
const int irLedPin = 3; // IR LED connected to D7

IRsend irsend;

void setup() {
  // Initialize button pins as inputs
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  // Initialize IR LED pin
  pinMode(irLedPin, OUTPUT);

  // Send stop signal on reset
  irsend.sendNEC(0xFF02FD, 32); // Example stop signal
  delay(300); // Give time for the signal to be sent
}

void loop() {
  if (digitalRead(button1) == LOW) {
    irsend.sendNEC(0xFFA25D, 32); // Example signal for button 1
    delay(300); // Debounce delay
  }

  if (digitalRead(button2) == LOW) {
    irsend.sendNEC(0xFF629D, 32); // Example signal for button 2
    delay(300); // Debounce delay
  }

  if (digitalRead(button3) == LOW) {
    irsend.sendNEC(0xFFE21D, 32); // Example signal for button 3
    delay(300); // Debounce delay
  }

  if (digitalRead(button4) == LOW) {
    irsend.sendNEC(0xFF22DD, 32); // Example signal for button 4
    delay(300); // Debounce delay
  }
}
