


// https://github.com/bhagman/SoftPWM
#include "SoftPWM.h"

// set pin for color lights:
const int colorPin =  2;      // the number of the LED pin
// Variables will change:
int ledState = LOW;             // ledState used to set the LED


byte edgeLedPins[] = {3,5,6,9,10,11};
//byte resortedLedPins[] = {3,5,6,9,10,11};


/*
void setup()
{
  // Initialize
  SoftPWMBegin();

  for (int i ; i < 6 ; i++){
    // Create and set pin 13 to 0 (off)
    SoftPWMSet(edgeLedPins[i], 1);
  

    // Set fade time for pin 13 to 100 ms fade-up time, and 500 ms fade-down time
    SoftPWMSetFadeTime(edgeLedPins[i], 100, 500);
  }
}

void blinkAll(){
  for (int i ; i < 6 ; i++){
    // Turn on - set to 100%
    SoftPWMSetPercent(edgeLedPins[i], 100);
  }
  delay(1000);
  
  for (int i ; i < 6 ; i++){
    // Turn on - set to 100%
    SoftPWMSetPercent(edgeLedPins[i], 0);
  }
  delay(500);
}
*/


/*
void circleAnimation(int loop){

  for (int i , int j = loop; i<6 ; i++, j++){
    if (j %6 == 0){
      j = 0;
    }
    resortedLedPin[i] = edgeLedPins[j]; 
  }
    
  
  for (int i ; i < 6 ; i++){
    // Turn on - set to 100%
    SoftPWMSetPercent(13, 100);

    // Create and set pin 13 to 0 (off)
    SoftPWMSet(edgeLedPins[i], 0);
  

    // Set fade time for pin 13 to 100 ms fade-up time, and 500 ms fade-down time
    SoftPWMSetFadeTime(edgeLedPins[i], 100, 500);
  }
  
  }
*/

/*
void loop() {
  // put your main code here, to run repeatedly:
  blinkAll();
  delay(10);
  

}
*/

int toggleColorLight(int pin, int state){

      // if the LED is off turn it on and vice-versa:
      if (state == LOW)
        state = HIGH;
      else
        state = LOW;

      // set the LED with the ledState of the variable:
      digitalWrite(pin, state);
      
      return state;

}

void setup()
{
  // Initialize
  SoftPWMBegin();

  for (int i=0 ; i<6 ; i ++){
  // Create and set pin 13 to 0 (off)
  int led = edgeLedPins[i];
  SoftPWMSet(led, 0);

  // Set fade time for pin 13 to 100 ms fade-up time, and 500 ms fade-down time
  SoftPWMSetFadeTime(led, 100, 300);
  
  pinMode(colorPin, OUTPUT);  
  }
}

void loop()
{
  int j = 0, maxj = 5;
  while (j < maxj){
  for (int i=0 ; i<6 ; i ++){ 
  // Create and set pin 13 to 0 (off)
  int led = edgeLedPins[i];
  // Turn on - set to 100%
  SoftPWMSetPercent(led, 100);

  // if the LED is off turn it on and vice-versa:
  ledState = toggleColorLight(colorPin, ledState);
      
  // Wait for LED to turn on - you could do other tasks here
  delay(100);

  // Turn off - set to 0%
  SoftPWMSetPercent(led, 0);

  // Wait for LED to turn off
  
  }
  
  delay(10);
  // set the LED with the ledState of the variable:
      
  j++;
  if (j == maxj){
      delay(500);
      digitalWrite(colorPin, LOW);
      j = 0;
      for (int i=0 ; i<6 ; i ++){
      // Create and set pin 13 to 0 (off)
      int led = edgeLedPins[i];
      // Turn on - set to 100%
      SoftPWMSetPercent(led, 100);
    
      // Wait for LED to turn on - you could do other tasks here
      delay(10);
      
      }
      
      delay(1000);
      digitalWrite(colorPin, HIGH);  
      for (int i=0 ; i<6 ; i ++){
        // Create and set pin 13 to 0 (off)
        int led = edgeLedPins[i];
        
        // Turn off - set to 0%
        SoftPWMSetPercent(led, 0);
        
        }
        // set the LED with the ledState of the variable:
        digitalWrite(colorPin, HIGH);
    
        delay (500);
      }
      
  }
}
