
// L298N connection PINs
// enA, in1, in2, in3, in4, enB
unsigned char rear_drive [] = {2, 3, 4, 5, 6, -1};
unsigned char front_drive [] = {8, 9, 10, 11, 12, -1};

void forward() {
    // enA write 100
    digitalWrite(rear_drive[0], 100);
    digitalWrite(front_drive[0], 100);

    digitalWrite(rear_drive[1], HIGH);
    digitalWrite(front_drive[1], HIGH);

    digitalWrite(rear_drive[2], LOW);
    digitalWrite(front_drive[2], LOW);

    digitalWrite(rear_drive[3], HIGH);
    digitalWrite(front_drive[3], HIGH);

    digitalWrite(rear_drive[4], LOW);
    digitalWrite(front_drive[4], LOW);
}

void setup() {
    Serial.begin(9600);
    // Setup pin mode to output for each control pins
    for (int i = 0; i < 5; i++) {
        pinMode(rear_drive[i], OUTPUT);
        pinMode(front_drive[i], OUTPUT);
    }
}

void loop() {
    char input = (char)Serial.read();


}
