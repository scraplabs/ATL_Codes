#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(10, 11); // Tx pin of the bluetooth module must be connected to Rx pin on arduino
// Rx pin of the bluetooth module must be connected to Tx pin on arduino
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;

String inputString;
String buttonId;
int buttonState = 0;
int pinNum = 0;



void setup() {
  //set the digital pins
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  //start communication with bluetooth module
  bluetoothSerial.begin(9600);

  //set all pins to off as default to start with
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}


void loop() {

  while (bluetoothSerial.available() <= 0) {
    //do nothing and wait
  }

  if ( bluetoothSerial.available()) {

    inputString = bluetoothSerial.readString();;        //make a string of the characters coming in serial

  }
  
  if (inputString.endsWith("/#")) { //if it ends with "/#" it is the end of the command
    inputString = inputString.substring(0, inputString.length() - 2); //get rid of the "/#" at the end

    for (int i = 0; i < inputString.length(); i++) { //split to get id and state
      if (inputString.charAt(i) == ',') {
        buttonId = inputString.substring(0, i); //get the id of the button
        buttonState = inputString.substring(i + 1).toInt(); //get the state of the button ,if its 0 switch it off and if its 1 turn it on

      }
    }

    inputString = "";  //reset the input data for the next time

  }
  pinNum =  buttonId.substring(1).toInt();  //get pin number and then convert the string toan int
  digitalWrite( pinNum, buttonState);
}





