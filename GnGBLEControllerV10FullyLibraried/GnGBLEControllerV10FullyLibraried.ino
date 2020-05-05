
#include "Arduino.h"
#include <string.h>

#include <Events.h>
#include <Factory.h>
#include <GnG_BLE_HWSPI.h>


GnG_BLE_HWSPI gngble;

void setup() {

  Serial.begin(115200);
  delay(2000);
  // gngble.basicSetup();
  gngble.basicSetup("GnG BF1");

}


void testFunction1()
{

  uint8_t len = gngble.readPacket();
  if (len == 0) return;

  Factory f;
  f.setMessage(gngble.packetbuffer, len);
  GnG_BF_Controller_BaseEvent* b10 = f.instanceTransformMsg2SpecificEvent();
 // b10->printSelf();
 b10-> processEvent();
  free( b10);
}

void loop() {
  testFunction1();
  delay(5);
}
