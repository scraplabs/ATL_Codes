#define redPin 11
#define greenPin 10
#define bluePin 9

void setup() {

  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  while (Serial.available() <= 0) {

    //do nothing and wait for input
  }

  if (Serial.available() > 0) {
    int redInt = Serial.parseInt();
    int greenInt = Serial.parseInt();
    int blueInt = Serial.parseInt();

    redInt = constrain(redInt, 0, 255);
    greenInt = constrain(greenInt, 0, 255);
    blueInt = constrain(blueInt, 0, 255);

    analogWrite(redPin, redInt);
    analogWrite(greenPin, greenInt);
    analogWrite(bluePin, blueInt);

    Serial.flush();
  }
}
