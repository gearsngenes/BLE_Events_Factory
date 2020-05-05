#include "Arduino.h"
#include <Events.h>
#include "Factory.h"
//#include "GnG_BLE_HWSPI.h"

Factory::Factory()
{

}
float Factory::parsefloat(uint8_t *buffer)
{
  float f;
  memcpy(&f, buffer, 4);
  return f;
}

GnG_BF_Controller_BaseEvent* Factory::instanceTransformMsg2SpecificEvent()
{
  char firstChar = messageChar[1];

  if (firstChar == 'B') {
    uint8_t buttnum = messageChar[2] - '0';
    boolean pressed = messageChar[3] - '0';
   GnG_BF_Controller_ButtonEvent* bevent = new GnG_BF_Controller_ButtonEvent(buttnum, pressed);
    return bevent;
  }
  if (firstChar == 'C') {
    int r = messageChar[2];
    int g = messageChar[3];
    int b = messageChar[4];
    GnG_BF_Controller_ColorEvent* cevent = new GnG_BF_Controller_ColorEvent(r, g, b);
    return cevent;
  }

  if (firstChar == 'A')
  {
    float x = Factory:: parsefloat(messageChar + 2);
    float  y = Factory:: parsefloat(messageChar + 6);
    float z = Factory:: parsefloat(messageChar + 10);
    GnG_BF_Controller_AccEvent* accevent = new GnG_BF_Controller_AccEvent(x, y, z);
    return accevent;
  }

  if (firstChar == 'M') {
    float x = Factory:: parsefloat(messageChar + 2);
    float  y = Factory:: parsefloat(messageChar + 6);
    float z = Factory:: parsefloat(messageChar + 10);
    GnG_BF_Controller_MagEvent* magevent = new GnG_BF_Controller_MagEvent(x, y, z);
    return magevent;
  }

  if (firstChar == 'G') {

    float x = Factory:: parsefloat(messageChar + 2);
    float  y = Factory:: parsefloat(messageChar + 6);
    float z = Factory:: parsefloat(messageChar + 10);
    GnG_BF_Controller_GyroEvent* gyroevent = new GnG_BF_Controller_GyroEvent(x, y, z);
    return gyroevent;
  }
    if (firstChar == 'Q') 
    {
    float x = Factory:: parsefloat(messageChar + 2);
    float  y = Factory:: parsefloat(messageChar + 6);
    float z = Factory:: parsefloat(messageChar + 10);
    float w = Factory:: parsefloat(messageChar + 14);   
    GnG_BF_Controller_QuatEvent* quatevent = new GnG_BF_Controller_QuatEvent(x, y, z, w);

    return quatevent;
    }
}

void Factory::setMessage(uint8_t buffer1[bufsize + 1], int len1)
{
  {
    for (int i = 0; i <= len1; i++)
    {
      messageChar[i] = buffer1[i];
    }
  }

}
void Factory::printMessage(int len1)
{
  Serial.println ("Buffer Value from static Member:");
  for (int i = 0; i <= len1; i++)
  {
    char c = messageChar[i];
    Serial.print(c);
  }
  Serial.println();
  Serial.println("Buffer Value from static member...done"); Serial.println();
}