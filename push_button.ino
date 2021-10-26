/*
  Button

 Pushing a button will turn on LED1, then on the 2nd press light LED2 whilst
 turning off LED1. On the 3rd press it will light LED3 whilst turning off LED2.
 A 4th press will return the loop back to the start.
 pins 11, 12 & 13 are connected each to an LED. The pushbutton is attached to pin 2.
 A 4th LED is connected to pin 8 and will flash if a long press of the pushbutton
 is detected.


 The circuit:
 * LED1 attached from pin 12 to ground
 * LED2 attached from pin 11 to ground
 * LED3 attached from pin 10 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 * LED4 attached from pin 8 to +5V rail on breadboard to the Anode, Cathode to Ground.

 
 created 2021
 Kiran Perveen
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 9;      // the number of the pushbutton pin
const int ledPin1 =  12;      // the number of the LED 1 pin
const int ledPin2 =  11;      // the number of the LED 2 pin
const int ledPin3 =  10;      // the number of the LED 3 pin
//const int ledPin4 =  8;       // the number of the LED 4 pin Used for a long press indication

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
//  pinMode(ledPin4, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // went from off to on:
      buttonPushCounter++;
          } else {
      // if the current state is LOW then the button
      // went from on to off:
          }
    // Add a delay to debounce
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;


  // turns on the LED every one button push and
  // Lights each LED in turn one at a time turning
  // off the preceeding LED as well
  if (buttonPushCounter  == 1) {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin1, HIGH);
    
  }
  if (buttonPushCounter == 2) {
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
  }
  if (buttonPushCounter == 3) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
  }
  if (buttonPushCounter == 4) {
    buttonState = 0;
  }
    
}
