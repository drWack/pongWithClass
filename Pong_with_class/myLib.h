#include "Arduino.h"

class Matrix
{
  public:
  Matrix();
  void refreshScreen();
 // void readInput();
 void setPixelArr(int arr[8][8]);
 void clearArray();
 void setLight(int x, int y, bool status);
  private:
  int pixelList[8][8];
  
};