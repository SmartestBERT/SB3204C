#ifndef TLC59108_H
#define TLC59108_H

#include <stdint.h>

#include "globals.h"
#include "BertComponent.h"
#include "I2CComms.h"

class TLC59108 : public BertComponent
{
     Q_OBJECT


public:

    const  uint8_t ledOut0 = 0x0C;    //PG1&PG2 LEDs register Address
    const  uint8_t ledOut1 = 0x0D;    //PG3&PG4 LEDs register Address
    bool ledOn[4];        // LEDs status value
    bool Green[4];        //


    uint8_t ledData0;  //Register value for PG1&2
    uint8_t ledData1;  //Register Value for PG3&4

    int edUpdateCounter[4];


    TLC59108(I2CComms *comms, const uint8_t i2cAddress, const int deviceID);

    static bool ping(I2CComms *comms, const uint8_t i2cAddress);
    void getOptions();
    int init();
    void ChangEDLedStatus();



#define TLC59108_CONNECT_SIGNALS(CLIENT, TLC59108) \
    connect(CLIENT,  SIGNAL(ChangPGLedStatus(int, bool)),    TLC59108, SLOT(ChangPGLedStatus(int, bool)));     \
    connect(CLIENT,  SIGNAL(edLedFlash(int,bool,bool)),      TLC59108, SLOT(edLedFlash(int,bool,bool)));       \
    connect(CLIENT,  SIGNAL(StartEDLed()),                   TLC59108, SLOT(StartEDLed()));                    \
    connect(CLIENT,  SIGNAL(StopEDLed()),                    TLC59108, SLOT(StopEDLed()));                     \
    connect(CLIENT,  SIGNAL(StartEyeScanLed(int)),           TLC59108, SLOT(StartEyeScanLed(int)));             \
    BERT_COMPONENT_CONNECT_SIGNALS(CLIENT, TLC59108) \

#define TLC59108_SLOTS \
    void ChangPGLedStatus(int,bool);    \
    void edLedFlash(int, bool,bool);    \
    void StartEDLed();                  \
    void StopEDLed();                   \
    void StartEyeScanLed(int);          \


    // Public Slots for TLC59108 commands:
public slots:
    TLC59108_SLOTS


private:

        I2CComms *comms;
        const uint8_t i2cAddress;
        const int deviceID;





};

#endif // TLC59108_H
