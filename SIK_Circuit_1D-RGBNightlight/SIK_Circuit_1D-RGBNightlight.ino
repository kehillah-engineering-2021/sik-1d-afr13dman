/*
  SparkFun Inventor’s Kit
  Circuit 1D-RGB Nightlight

  Turns an RGB LED on or off based on the light level read by a photoresistor.
  Change colors by turning the potentiometer.

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

int photoresistor = A0;          //variable for storing the photoresistor value
int potentiometer = A1;          //this variable will hold a value based on the position of the knob
int threshold = 700;            //if the photoresistor reading is lower than this value the light will turn on

//LEDs are connected to these pins
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

void setup() {
  Serial.begin(9600);           //start a serial connection with the computer

  //set the LED pins to output
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}

void loop() {

  photoresistor = analogRead(A0);         //read the value of the photoresistor
  potentiometer = analogRead(A1);

  Serial.print("Photoresistor value:");
  Serial.print(photoresistor);          //print the photoresistor value to the serial monitor
  Serial.print("  Potentiometer value:");
  Serial.println(potentiometer);          //print the potentiometer value to the serial monitor

  // user can choose which program they want to run and comment out the others
//  multiple_colors();
//  multi_color_blink();
//  fadeLED();
  change_threshold();
  
  delay(100); //short delay so that the printout is easier to read
}
void fadeLED () {
  if (photoresistor < threshold) {
    // if dark, light will fade from red to blue to red
    for (int i = 0; i <= 100; i = i + 5) {
      analogWrite(RedPin, 100-i);
      analogWrite(GreenPin, 0);
      analogWrite(BluePin, 0+i);
      delay(200);
    }
    for (int i = 0; i <= 100; i = i + 5) {
      analogWrite(RedPin, 0-i);
      analogWrite(GreenPin, 0);
      analogWrite(BluePin, 100-i);
      delay(200);
    }
  }
  else { //if it isn't dark turn the LED off, but will turn off after a run through of the fade
    turnOff(); //call the turn off function
  }
}
void change_threshold () {
  // light is read through the potentiometer not the photoresistor
  // the new threshold is based off of the value of the potentiometer (where it is pointing)
  // potentiometer can cover values 0-1023 and is divided up into four parts
  // the brighter the room, the redder the light
  // the darker the room, the bluer the light
  if (potentiometer > 0 && potentiometer <= 255.75) {
    // lowest quadrant of light, bottom left corner of the potentiometer
    red();
  }
  if (potentiometer > 255.75 && potentiometer <= 511.50) {
    // mid-low quadrant of light, bottom right corner of the potentiometer
    darkmagenta();
  }
  if (potentiometer > 511.50 && potentiometer <= 767.25) {
    // mid-high quadrant of light, top right corner of the potentiometer
    cyan();
  }
  if (potentiometer > 767.25 && potentiometer <= 1023) {
    // highest quadrant of light, top left corner of the potentiometer
    blue();
  }
}
void multi_color_blink () {
  if (photoresistor < threshold) {
    // if dark, light will blink the rainbow
    red();
    delay(300);
    orange();
    delay(300);
    yellow();
    delay(300);
    green();
    delay(300);
    blue();
    delay(300);
    darkmagenta();
    delay(300);
  }
  else { //if it isn't dark turn the LED off, but will turn off after a run through of the colors
    turnOff(); //call the turn off function
  }
}
void multiple_colors () {
  if (photoresistor < threshold) { //if it's dark (the photoresistor value is below the threshold) turn the LED on
    //These nested if statements check for a variety of ranges and
    //call different functions based on the current potentiometer value.
    //Those functions are found at the bottom of the sketch.
    if (potentiometer > 0 && potentiometer <= 100)
      red();
    if (potentiometer > 100 && potentiometer <= 200)
      orange();
    if (potentiometer > 200 && potentiometer <= 300)
      yellow();
    if (potentiometer > 300 && potentiometer <= 400)
      yellowgreen();
    if (potentiometer > 400 && potentiometer <= 500)
      green();
    if (potentiometer > 500 && potentiometer <= 600)
      greenblue();
    if (potentiometer > 600 && potentiometer <= 700)
      cyan();
    if (potentiometer > 700 && potentiometer <= 800)
      blue();
    if (potentiometer > 800 && potentiometer <= 900)
      magenta();
    if (potentiometer > 900)
      darkmagenta();
  }
  else { //if it isn't dark turn the LED off
    turnOff(); //call the turn off function
  }
}
void red () {
  //set the LED pins to values that make red
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
void orange () {
  //set the LED pins to values that make orange
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 50);
  analogWrite(BluePin, 0);
}
void yellow () {
  //set the LED pins to values that make yellow
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
}
void yellowgreen () {
  //set the LED pins to values that make green
  analogWrite(RedPin, 50);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
}
void green () {
  //set the LED pins to values that make green
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
}
void greenblue () {
  //set the LED pins to values that make green
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 50);
}
void cyan () {
  //set the LED pins to values that make cyan
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 100);
}
void blue () {
  //set the LED pins to values that make blue
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 100);
}
void magenta () {
  //set the LED pins to values that make magenta
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 100);
}
void darkmagenta () {
  //set the LED pins to values that make new_color
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 50);
}
void turnOff () {

  //set all three LED pins to 0 or OFF
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
