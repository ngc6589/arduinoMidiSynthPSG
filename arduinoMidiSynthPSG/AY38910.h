/*
 * 2021/10/10 First Written
 * Masahiro Kusunoki(JP3SRS)
 */
#include "arduino.h"
#include <stdint.h>

class AY38910
{
  public:
    AY38910(void);
    void begin(void);
    void setAmplitude(uint8_t ch, uint8_t amplitude);
    void setTone(uint8_t ch, uint8_t outNote);
    void regWrite(uint8_t unit, uint8_t reg, uint8_t val);
  
  private:
    uint8_t unit[12]     = {0,0,0,1,1,1,2,2,2,3,3,3};
    uint8_t chFine[12]   = {0,2,4,0,2,4,0,2,4,0,2,4};
    uint8_t chrough[12]  = {1,3,5,1,3,5,1,3,5,1,3,5};
    uint8_t chAmp[12]    = {8,9,10,8,9,10,8,9,10,8,9,10};   
    uint8_t bdir[4] = {0,1,2,3};
    uint8_t bc1[4]  = {4,5,6,7}; 
};
