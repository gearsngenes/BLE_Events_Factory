#include "Arduino.h"

#ifndef GnG_BF_Controller_Events_h
#define GnG_BF_Controller_Events_h

class GnG_BF_Controller_BaseEvent
{
  protected:
    int decidingNumber; // not used

  public:
    GnG_BF_Controller_BaseEvent::GnG_BF_Controller_BaseEvent (int inputVal); // not used
    GnG_BF_Controller_BaseEvent::GnG_BF_Controller_BaseEvent ();
    virtual void GnG_BF_Controller_BaseEvent::printSelf();
   virtual void GnG_BF_Controller_BaseEvent::processEvent();
    
};

class GnG_BF_Controller_ButtonEvent: public GnG_BF_Controller_BaseEvent{
  private:
    boolean buttonPressed;
    uint8_t buttonNum;
  public:
    GnG_BF_Controller_ButtonEvent::GnG_BF_Controller_ButtonEvent(uint8_t p, boolean b);
    virtual void GnG_BF_Controller_ButtonEvent::printSelf();
    virtual void GnG_BF_Controller_ButtonEvent::processEvent();
};
extern void extButtonEventProcess(GnG_BF_Controller_ButtonEvent* buttonEventptr);

class GnG_BF_Controller_ColorEvent: public GnG_BF_Controller_BaseEvent{
  private:
    int red;
    int blue;
    int green;
  public:
    GnG_BF_Controller_ColorEvent::GnG_BF_Controller_ColorEvent(int r, int g, int b);
    virtual void GnG_BF_Controller_ColorEvent::printSelf();
    virtual void GnG_BF_Controller_ColorEvent::processEvent();
};
extern void extColorEventProcess(GnG_BF_Controller_ColorEvent* colorEventptr);

class GnG_BF_Controller_AccEvent: public GnG_BF_Controller_BaseEvent{
  private:
       float xcoord, ycoord, zcoord;
  public:
    GnG_BF_Controller_AccEvent::GnG_BF_Controller_AccEvent(float x, float y, float z);
    virtual void GnG_BF_Controller_AccEvent::printSelf();
    virtual void GnG_BF_Controller_AccEvent::processEvent();    
};
extern void extAccEventProcess(GnG_BF_Controller_AccEvent* accEventptr);

class GnG_BF_Controller_MagEvent: public GnG_BF_Controller_BaseEvent{
  private:
       float xv, yv, zv;
  public:
    GnG_BF_Controller_MagEvent ::GnG_BF_Controller_MagEvent(float x, float y, float z);
    virtual void GnG_BF_Controller_MagEvent::printSelf();
    virtual void GnG_BF_Controller_MagEvent::processEvent();        
};
extern void extMagEventProcess(GnG_BF_Controller_MagEvent* magEventptr);

class GnG_BF_Controller_GyroEvent: public GnG_BF_Controller_BaseEvent{
  private:
       float xg, yg, zg;
  public:
    GnG_BF_Controller_GyroEvent::GnG_BF_Controller_GyroEvent(float x, float y, float z);
    virtual void GnG_BF_Controller_GyroEvent::printSelf();
    virtual void GnG_BF_Controller_GyroEvent::processEvent();            
};
extern void extGyroEventProcess(GnG_BF_Controller_GyroEvent* magEventptr);


class GnG_BF_Controller_QuatEvent: public GnG_BF_Controller_BaseEvent{
  private:
       float xq, yq, zq, wq;
  public:
    GnG_BF_Controller_QuatEvent::GnG_BF_Controller_QuatEvent(float x, float y, float z, float w);
    virtual void GnG_BF_Controller_QuatEvent::printSelf();
    virtual void GnG_BF_Controller_QuatEvent::processEvent();         
};
extern void extQuatEventProcess(GnG_BF_Controller_QuatEvent* magEventptr);

#endif