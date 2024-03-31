
// L298N connection PINs
// enA, in1, in2, in3, in4, enB
unsigned char front_drive [] = {2, 3, 4, 5, 6, -1};
unsigned char rear_drive [] = {8, 9, 10, 11, 12, -1};

void turn_right() {
    digitalWrite(rear_drive[0], 255);
    digitalWrite(front_drive[0], 255);

    digitalWrite(rear_drive[1], HIGH);
    digitalWrite(front_drive[1], LOW);

    digitalWrite(rear_drive[2], LOW);
    digitalWrite(front_drive[2], HIGH);

    digitalWrite(rear_drive[3], HIGH);
    digitalWrite(front_drive[3], LOW);

    digitalWrite(rear_drive[4], LOW);
    digitalWrite(front_drive[4], HIGH);
}
void turn_left() {
    digitalWrite(rear_drive[0], 255);
    digitalWrite(front_drive[0], 255);

    digitalWrite(rear_drive[1], LOW);
    digitalWrite(front_drive[1], HIGH);

    digitalWrite(rear_drive[2], HIGH);
    digitalWrite(front_drive[2], LOW);

    digitalWrite(rear_drive[3], LOW);
    digitalWrite(front_drive[3], HIGH);

    digitalWrite(rear_drive[4], HIGH);
    digitalWrite(front_drive[4], LOW);
}

void backward() {
    // enA write 100
    digitalWrite(rear_drive[0], 255);
    digitalWrite(front_drive[0], 255);

    digitalWrite(rear_drive[1], HIGH);
    digitalWrite(front_drive[1], HIGH);

    digitalWrite(rear_drive[2], LOW);
    digitalWrite(front_drive[2], LOW);

    digitalWrite(rear_drive[3], LOW);
    digitalWrite(front_drive[3], LOW);

    digitalWrite(rear_drive[4], HIGH);
    digitalWrite(front_drive[4], HIGH);
}

void forward() {
    // enA write 100
    digitalWrite(rear_drive[0], 255);
    digitalWrite(front_drive[0], 255);

    digitalWrite(rear_drive[1], LOW);
    digitalWrite(front_drive[1], LOW);

    digitalWrite(rear_drive[2], HIGH);
    digitalWrite(front_drive[2], HIGH);

    digitalWrite(rear_drive[3], HIGH);
    digitalWrite(front_drive[3], HIGH);

    digitalWrite(rear_drive[4], LOW);
    digitalWrite(front_drive[4], LOW);

}

void stop() {
  for (int i = 1; i < 5; i++) {
    digitalWrite(rear_drive[i], LOW);
    digitalWrite(front_drive[i], LOW);
  }
}

void setup() {
    Serial.begin(9600);
    // Setup pin mode to output for each control pins
    for (int i = 0; i < 5; i++) {
        pinMode(rear_drive[i], OUTPUT);
        pinMode(front_drive[i], OUTPUT);

        if (i > 0) {
          digitalWrite(rear_drive[i], LOW);
          digitalWrite(front_drive[i], LOW);
        }
    }
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();

    switch(input) {
      case 'w':
        forward();
        break;
      case 's':
        backward();
        break;
      case 'a':
        turn_left();
        break;
      case 'd':
        turn_right();
        break;
    }

    delay(500);
    stop();
  }
}
