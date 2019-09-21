/*!
 \file   globals.cpp
 \brief  Global Constants Class Implementation
 \author J Cole-Baker (For Smartest)
 \date   Jan 2015
*/

#include "globals.h"

// Macro file information:
const globals::MacroFileInfo globals::MACRO_FILES[] =
{
    // [File Name],    [Line Count], [Version (byte array)], [Version (String)]
    { ":/UNKNOWN.hex",           0,   { 0x00, 0x00, 0x00, 0x00 }, "Unknown" },   // Placeholder for unrecognised macro version
    { ":/MACRO_VER_1_E_0_C.hex", 309, { 0x01, 0x45, 0x00, 0x43 }, "1E0C"    },
    { ":/MACRO_VER_1_E_1_C.hex", 317, { 0x01, 0x45, 0x01, 0x43 }, "1E1C"    }
};
const size_t globals::N_MACRO_FILES = sizeof(MACRO_FILES) / sizeof(MACRO_FILES[0]);


// Component I2C Addresses:
// Each board contains:
//   2 x GT1725 (or compatible) BERT cores
//   1 x LMX2594 clock synthesizer (connected via SC18IS602 I2C to SPI bridge)
//   1 x PCA9557 I/O expander
//
// When a slave is connected, components appear as if connected to the master,
// except with translated I2C addresses.
//
//#define I2C_ADDRESS_TEST
//#define I2C_ADDRESS_PIXIE
//                                                       Master      Slave (if present)
#ifdef I2C_ADDRESS_TEST
 // ---- TEST / Smartest Dual GT1724 Board with Fake Slave: --------------------------------
 const QList<uint8_t> globals::I2C_ADDRESSES_GT1724   = { 0x12, 0x14, 0x12, 0x14 };
 const QList<uint8_t> globals::I2C_ADDRESSES_LMX2594  = { 0x28,       0x28       };
 const QList<uint8_t> globals::I2C_ADDRESSES_PCA9557  = { 0x1C,       0x1C       };
 const QList<uint8_t> globals::I2C_ADDRESSES_M24M02   = { 0x50,       0x50       };
 const QList<uint8_t> globals::I2C_ADDRESSES_SI5340   = { 0x76,       0x76       };
#else
 #ifdef I2C_ADDRESS_PIXIE
  // ---- REAL / Smartest Single GT1724 PIXIE Board: ---------------------------------------
  const QList<uint8_t> globals::I2C_ADDRESSES_GT1724   = { 0x12 };
  const QList<uint8_t> globals::I2C_ADDRESSES_LMX2594  = { 0x28 };
  const QList<uint8_t> globals::I2C_ADDRESSES_PCA9557  = { 0x1C };
  const QList<uint8_t> globals::I2C_ADDRESSES_M24M02   = { 0x50 };
  const QList<uint8_t> globals::I2C_ADDRESSES_SI5340   = { 0x76 };
 #else
  // ---- REAL / Smartest Dual GT1724 Board: -----------------------------------------------
  const QList<uint8_t> globals::I2C_ADDRESSES_GT1724   = { 0x12, 0x14, 0x16, 0x10 };
  const QList<uint8_t> globals::I2C_ADDRESSES_LMX2594  = { 0x28,       0x2C       };
  const QList<uint8_t> globals::I2C_ADDRESSES_PCA9557  = { 0x1C,       0x18       };
  const QList<uint8_t> globals::I2C_ADDRESSES_M24M02   = { 0x50,       0x54       };
  const QList<uint8_t> globals::I2C_ADDRESSES_SI5340   = { 0x76,       0x72       };
 #endif
#endif

const double globals::BELOW_DETECTION_LIMIT = -999999.0;

const QString globals::BUILD_VERSION = QString( "3.2.10" );
const QString globals::BUILD_DATE = __DATE__ " " __TIME__;

const QString globals::FACTORY_KEY_HASH = QString("77feacb4228cb24a8cfd372f2a7d6d920052f48f38f5d6b84e99350a094aaba3");

const QStringList globals::BERT_MODELS = { "Select...", "PPG-3204-C", "SB-3204-C", "PPG3204D_PIXIE", "SB3202D_PIXIE" };


QString globals::appPath = QString("");

void globals::setAppPath(QString path)
{
    globals::appPath = QString(path);
}

QString globals::getAppPath()
{
    return globals::appPath;
}

