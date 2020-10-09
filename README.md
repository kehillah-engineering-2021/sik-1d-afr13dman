# RGB Night Light

### Running the Program
The program is compatible with an Arduino Uno board which was set up using a SparkFun Inventor's Kit. Following the instructions, the basic board set up should look like this: 

![Arduino Board](images-and-gifs/board-template.jpg)

You will need:
![Items needed](images-and-gifs/1Dparts.png)

The longest pin of the RGB light is the common or ground.

Arduino and USB drivers will need to be installed for the code to work. Go to www.arduino.cc/downloads to download Arduino and www.sparkfun.com/ch340 to download drivers. Pnce Arduino is installed you will need to select the correct board, in this case: Arduino Uno, and the correct port. Next, connect your board to the computer using an USB cable.

To run the code click on the upload button on the top left corner (second to left) on the arduino interface.

![Upload Button](images-and-gifs/upload-button.png)

### The Code
The program is designed to turn on or off a night light (the RGB LED) based off of the darkness of a room.
```C
int photoresistor = A0;          //variable for storing the photoresistor value
int potentiometer = A1;          //this variable will hold a value based on the position of the knob
int threshold = 700;            //if the photoresistor reading is lower than this value the light will turn on
```
The pins of the RGB LED are connected as such:
```C
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;
```
In the main loop, the input photoresistor and potentiometer are read and based on what choices are made, the loop can run four different programs:
```C
void loop() {

  photoresistor = analogRead(A0);         //read the value of the photoresistor
  potentiometer = analogRead(A1);

[... part of the code has been removed for visual purposes in the README...]

  // user can choose which program they want to run and comment out the others
  multiple_colors();
  multi_color_blink();
  fadeLED();
  change_threshold();
  
[... part of the code has been removed for visual purposes in the README...]
}
```

### Challenges
1. Add more colors:

![More colors](images-and-gifs/more-colors.gif)

2. Multi-color blink:

![Multi color blink](images-and-gifs/multi-color-blink.gif)

3. Change the threshold:

![Change threshold](images-and-gifs/change-threshold.gif)

4. Fading the led:

![Fade LED](images-and-gifs/fade-LED.gif)
