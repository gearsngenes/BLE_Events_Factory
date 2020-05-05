#ifndef Factory_h
#define Factory_h
//#include "GnG_BLE_HWSPI.h"
#include "Arduino.h"

#include "Events.h"

class Factory
{
  public:
    static const int bufsize = 20;
    static float Factory:: parsefloat(uint8_t *buffer);
    uint8_t   messageChar[bufsize + 1];
    Factory::Factory();
    void Factory::setMessage(uint8_t buffer1[bufsize + 1], int len1);
    GnG_BF_Controller_BaseEvent* Factory::instanceTransformMsg2SpecificEvent();
    void Factory::printMessage(int len1);

};
#endif