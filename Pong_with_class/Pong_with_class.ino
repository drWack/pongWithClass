#include "myLib.h"


int pixels[8][8]; //the current 2 dimensional array that we know. 

// cursor position:
int x1 = 5;
int x2 = 5;

Matrix mymat; //in Matrix.cpp, sets up the LED matrix to actually work. 
void setup()
{
  
}


void loop() {
  readSensors();//tells the Matrix Class what to draw
  mymat.refreshScreen(); //draws it
}

void readSensors() {
  mymat.clearArray();
  // read the sensors for X and Y values:
  x1 = 7 - map(analogRead(A0), 0, 1023, 0, 5) -1;
  x2 = 7- map(analogRead(A1), 0, 1023, 0, 5)-1;

//tells the matrix what to do for the left paddle
  setLight(x1+1,0,LOW);
  setLight(x1-1,0,LOW);
  setLight(x1+0,0,LOW);

//tells the matrix what to do for the right paddle
  setLight(x2-1,7,LOW);
  setLight(x2+1,7,LOW);
  setLight(x1+0,7,LOW);
  
}
