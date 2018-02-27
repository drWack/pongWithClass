#include "myLib.h"
#include "Arduino.h"

// 2-dimensional array of row pin numbers:
const int row[8] = {
  2, 7, 19, 5, 13, 18, 12, 16
};

// 2-dimensional array of column pin numbers:
const int col[8] = {
  6, 11, 10, 3, 17, 4, 8, 9
};

// 2-dimensional array of pixels:
int pixelList[8][8];
Matrix::Matrix()
{
  
  // initialize the I/O pins as outputs iterate over the pins:
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    // take the col pins (i.e. the cathodes) high to ensure that the LEDS are off:
    digitalWrite(col[thisPin], HIGH);
  }

  // initialize the pixel matrix:
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pixelList[x][y] = HIGH;
    }
  }

}

void Matrix::refreshScreen()
{
  
  // iterate over the rows (anodes):
  for (int thisRow = 0; thisRow < 8; thisRow++) 
  {
    // take the row pin (anode) high:
    digitalWrite(row[thisRow], HIGH);
    // iterate over the cols (cathodes):
    for (int thisCol = 0; thisCol < 8; thisCol++) 
    {
      // get the state of the current pixel;
      int thisPixel = pixelList[thisRow][thisCol];
      // when the row is HIGH and the col is LOW,
      // the LED where they meet turns on:
      digitalWrite(col[thisCol], thisPixel);
      // turn the pixel off:
      if (thisPixel == LOW) 
      {
        digitalWrite(col[thisCol], HIGH);
      }
    }
    // take the row pin low to turn off the whole row:
    digitalWrite(row[thisRow], LOW);
  }
}
 void Matrix::setPixelArr(int arr[8][8])
 {
   pixelList[8][8] = arr[8][8];
   
 }
void Matrix::clearArray()
{
  for(int i =0; i<8; i++)
  {
    for(int j=0;j<8;j++)
    {
      pixelList[i][j]= HIGH;
    }
  }
}
void Matrix::setLight(int x, int y, bool status)
{
  pixelList[x][y] = status;
  
}