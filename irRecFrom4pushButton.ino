#include <IRremote.h>

// Pin definition
const int recvPin = 2;

IRrecv irrecv(recvPin);
decode_results results;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Enable the IR receiver
  irrecv.enableIRIn();
}

void loop() {
  // Check if an IR signal is received
  if (irrecv.decode(&results)) {
    // Print the received code to the Serial Monitor
    Serial.print("Received code: ");
    Serial.println(results.value, HEX);

    // Resume the receiver to listen for the next signal
    irrecv.resume();
  }
}
