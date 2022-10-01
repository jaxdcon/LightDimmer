#include <Arduino.h>

int iButton;
int iBrightness;

int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int controlState = 0;

void setup() {
  Serial.begin(115200);

  pinMode(D4, OUTPUT);
  pinMode(D5, INPUT_PULLUP); 

  // set default PWM range 
  analogWriteRange(1023); 
}

void loop() {
  buttonState = digitalRead(D5);
  
  //Maintain Switch State
  if (lastButtonState == 1 && buttonState == 0) 
  {
    if(controlState == 0)
    {
      controlState = 1;
    }
    else 
    {
      controlState = 0; 
    }
  }

  //LED ON/OFF
  int iVal;
  if (controlState  == 1) 
  {
    //Read from the variable resitor to led
    iVal = analogRead(A0);
    analogWrite(D4, iVal); 
  } else {
    //Turn LED OFF
    analogWrite(D4, 1023);
  }

  lastButtonState = buttonState;
  delay(100); 
}