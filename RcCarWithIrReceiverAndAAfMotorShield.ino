#include <IRremote.h>
#include <AFMotor.h>

const int recvPin = 2;

// Define motor objects
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

IRrecv irrecv(recvPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  
  // Initialize the IR receiver
  irrecv.enableIRIn();
  
  // Set initial motor speed for forward/backward
  motor3.setSpeed(255);
  motor4.setSpeed(255);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Received code: ");
    Serial.println(results.value, HEX);

    switch (results.value) {
      case 0xFFE21D:
      case 0xEE886D7F: // Example code for forward
        moveForward();
        break;
      case 0xFFA25D:
      case 0xE318261B: // Example code for backward
        moveBackward();
        break;
      case 0xFF22DD:
      case 0x52A3D41F: // Example code for left
        turnLeft();
        break;
      case 0xFF629D:
      case 0x511DBB: // Example code for right
        turnRight();
        break;
      case 0xFFFFFFFF: // Repeat code, ignore
        break;
      case 0xFF02FD:
        stopCar();
        break;
      default:
        stopCar();
        break;
    }
    irrecv.resume(); // Ready to receive the next code
  }
}

void moveForward() {
  motor3.setSpeed(255);  // Set speed to 255 for moving forward
  motor4.setSpeed(255);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  Serial.println("Moving forward");
}

void moveBackward() {
  motor3.setSpeed(255);  // Set speed to 255 for moving backward
  motor4.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  Serial.println("Moving backward");
}

void turnRight() {
  motor3.setSpeed(150);  // Reduce speed to 150 for turning left
  motor4.setSpeed(150);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  Serial.println("Turning left");
}

void turnLeft() {
  motor3.setSpeed(150);  // Reduce speed to 150 for turning right
  motor4.setSpeed(150);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  Serial.println("Turning right");
}

void stopCar() {
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  Serial.println("Stopping");
}
