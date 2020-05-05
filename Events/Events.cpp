#include "Events.h"
#include "Arduino.h"


GnG_BF_Controller_BaseEvent::GnG_BF_Controller_BaseEvent ()
{

}
GnG_BF_Controller_BaseEvent::GnG_BF_Controller_BaseEvent (int inputVal)
{
  decidingNumber = inputVal;
}
void GnG_BF_Controller_BaseEvent::printSelf()
{
  Serial.print("Base Class "); Serial.println (" instance.");
}

 void GnG_BF_Controller_BaseEvent::processEvent()
{
  // Error if this function is called.
  Serial.println ("**** Base Extern Function");
}

GnG_BF_Controller_ButtonEvent::GnG_BF_Controller_ButtonEvent(uint8_t p, boolean b) {
  buttonPressed = b;
  buttonNum = p;
}
void GnG_BF_Controller_ButtonEvent::printSelf() {
  Serial.print("Button #: ");
  Serial.print(buttonNum);
  if (buttonPressed) {
    Serial.println(" Pressed ");
  } else {
    Serial.println("  RELEASED");
  };
  //  Serial.println(buttonPressed);
}
void GnG_BF_Controller_ButtonEvent::processEvent()
{
  extButtonEventProcess(this);
}

GnG_BF_Controller_ColorEvent::GnG_BF_Controller_ColorEvent(int r, int g, int b) {
  red = r;
  green = g;
  blue = b;
}

void GnG_BF_Controller_ColorEvent::printSelf() {
  Serial.print("ColorEvent- R: ");
  Serial.print(red);
  Serial.print(" G:");
  Serial.print(green);
  Serial.print(" B:");
  Serial.println(blue);
}

void GnG_BF_Controller_ColorEvent::processEvent()
{
  extColorEventProcess(this);
}

GnG_BF_Controller_AccEvent::GnG_BF_Controller_AccEvent(float x, float y, float z)
{
  xcoord = x;
  ycoord = y;
  zcoord = z;
}

void GnG_BF_Controller_AccEvent::printSelf() {
    Serial.print("Accel\t");
    Serial.print(xcoord); Serial.print('\t');
    Serial.print(ycoord); Serial.print('\t');
    Serial.print(zcoord); Serial.println();
}
void GnG_BF_Controller_AccEvent::processEvent()
{
  extAccEventProcess(this);
}

GnG_BF_Controller_MagEvent::GnG_BF_Controller_MagEvent(float x, float y, float z)
{
  xv = x;
  yv = y;
  zv = z;
}


void GnG_BF_Controller_MagEvent::printSelf() {
    Serial.print("MAG EVENT\t");
    Serial.print(xv); Serial.print('\t');
    Serial.print(yv); Serial.print('\t');
    Serial.print(zv); Serial.println();
}

void GnG_BF_Controller_MagEvent::processEvent()
{
  extMagEventProcess(this);
}



GnG_BF_Controller_GyroEvent::GnG_BF_Controller_GyroEvent(float x, float y, float z)
{
  xg = x;
  yg = y;
  zg = z;
}



void GnG_BF_Controller_GyroEvent::printSelf() {
   Serial.print("Gyro\t");
    Serial.print(xg); Serial.print('\t');
    Serial.print(yg); Serial.print('\t');
    Serial.print(zg); Serial.println();
}

void GnG_BF_Controller_GyroEvent::processEvent()
{
  extGyroEventProcess(this);
}



GnG_BF_Controller_QuatEvent::GnG_BF_Controller_QuatEvent(float x, float y, float z, float w)
{

  xq = x;
  yq = y;
  zq = z;
  wq = w;
}

void GnG_BF_Controller_QuatEvent::printSelf() {
   Serial.print("Quat\t");
    Serial.print(xq); Serial.print('\t');
    Serial.print(yq); Serial.print('\t');
    Serial.print(zq); Serial.print('\t');
    Serial.print(wq); Serial.println();
}

void GnG_BF_Controller_QuatEvent::processEvent()
{
  extQuatEventProcess(this);
}