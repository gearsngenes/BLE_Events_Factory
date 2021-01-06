#include "Arduino.h"
#include <string.h>

/** ******************************************************************
 * A basic example of how to use GearsNGenes Bluetooth tools to help *
 * provide wireless instructions from the Bluefruit app.             *
 *                                                                   *
 *                                                                   *
 * Website: https://gearsngenes.com/                                 *
 * GitHub:  https://github.com/gearsngenes                           *
 * YouTube: https://www.youtube.com/channel/UCMH8Gw6IxXYRETRTJV2K52w *
 *                                                                   *
 * The following #defines are to enable the programmer to select     *
 * which kinds of events to subscribe their code to. For instance, if*
 * you declare the "_Subscribe2Button", you are enabling your code to*
 * be able to detect buttons being pressed on the Adafruit Bluefruit *
 * app.                                                              *
 *                                                                   *
 * Similar #defines are provided for color events and accelerometer  *
 * events, each of which have sensors on the Bluefruit app. Aditional*
 * sensors can be used with the "_Subscribe2Other", such as the      *
 * gyroscope, magnometer, and so on.                                 *
 *                                                                   *
 * Once you write the #define variable, you MUST provide the         *
 * appropriate callback function for that kind of event. See the     *
 * "callBackServices" tab on this program.                           *
 *                                                                   *
 * This program checks that the appropriate #define variable has     *
 * been declared through #ifdef statements. If the #ifdef returns    *
 * true, then you MUST implement the function, otherwise it will     *
 * result in compilation errors.                                     *
 * *******************************************************************
 */

#define _Subscribe2Button
#define _Subscribe2Color
#define _Subscribe2Acc

#define _Subscribe2Other

/** ******************************************************************
 *  The EventFactory Library is something that can take a message and*
 *  turn it into an event object which can be executed. The content  *
 *  of the message determines what kind of event it will be. How the *
 *  event is executed determines on the implementation of the        *
 *  callback function you provide for it.                            *
 * *******************************************************************
 */
#include <EventFactory.h>
#include "EventFactory.cpp"


/*********************************************************************
 * This class allows us to actually retrieve information from the    *
 * Bluefruit app. It takes the wireless signal and converts it into  *
 * a standard-format message that is then proccessed by a factory    *
 * to produce an event that we can use later in the program          *
 * *******************************************************************
 */
#include <GnG_BLE_HWSPI.h>

GnG_BLE_HWSPI blueToothFeather;

void setup() {

  Serial.begin(115200);
  delay(2000);

  blueToothFeather.basicSetup("GnG BF1");

}


void readAndProcessEvents()
{
  uint8_t len = blueToothFeather.readPacket();
  if (len == 0) return;
  GnGBleFactory eventFactory;
  eventFactory.setMessage(blueToothFeather.packetbuffer, len);
  GnGBLEBaseEvent* bleEvent = eventFactory.transformMsg2Event();
  bleEvent-> processEvent();
  free( bleEvent);
}

void loop() {
  readAndProcessEvents();
  delay(5);
}
