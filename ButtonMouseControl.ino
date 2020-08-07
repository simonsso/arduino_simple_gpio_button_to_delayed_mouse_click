/*
  Push down click based on:
  ButtonMouseControl

  For Leonardo and Due boards only.

  Hardware:
  - One pushbuttons attached to D12

  The mouse movement is always relative. This sketch reads four pushbuttons,
  and uses them to set the movement of the mouse.

  created 15 Mar 2012
  modified 27 Mar 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ButtonMouseControl
*/

#include "Mouse.h"

// set pin numbers for the swich - connect the swich to 
// GPIO12 - convineint distance from a ground pin 
const int mouseButton = 12;

int responseDelay = 10;    // response delay of the mouse, in ms

bool aim = true;           // only aim again after swich have been released

void setup() {
  // initialize the buttons' inputs:
  pinMode(mouseButton, INPUT);
  // initialize mouse control:
  Mouse.begin();
}

void loop() {
  // read the buttons:
  int clickState = digitalRead(mouseButton);

  // calculate the movement distance based on the button states:
  // if the mouse button is pressed:
  if ( clickState == LOW) {
      if (aim) {
        aim = false;
        delay(500); // wait half a second before clicking button
        Mouse.press(MOUSE_LEFT);
        delay(50);
        Mouse.release(MOUSE_LEFT);
       }
  }else{
    aim = true;
  }

  // a delay so the mouse doesn't move too fast:
  delay(responseDelay);
}
