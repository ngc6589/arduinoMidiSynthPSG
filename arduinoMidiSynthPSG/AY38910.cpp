/*
 * 2021/10/10 First Written
 * Masahiro Kusunoki(JP3SRS)
 */
#include "AY38910.h"
#include "AY38910ToneValue.h"

AY38910::AY38910(void) 
{
  PORTA = 0x00;
  DDRA = 0XFF;
  PORTC = 0x00;
  DDRC = 0xFF;
}

void AY38910::begin(void)
{
  regWrite(0,  0, 0x00);	// CH A fine
  regWrite(0,  1, 0x00);	// CH A rough
  regWrite(0,  2, 0x00);	// CH B fine
  regWrite(0,  3, 0x00);	// CH B rough
  regWrite(0,  4, 0x00);	// CH C fine
  regWrite(0,  5, 0x00);	// CH C rough
  regWrite(0,  6, 0x00);	// noise frequency
  regWrite(0,  7, 0xF8);	// MIXER
  regWrite(0,  8, 0x00);	// CH A Level
  regWrite(0,  9, 0x00);	// CH B Level
  regWrite(0, 10, 0x00);	// CH C Level
  regWrite(0, 11, 0x00);	// Frequency of envelope
  regWrite(0, 12, 0x00);	// Frequency of envelope
  regWrite(0, 13, 0x00);	// Shape of envelope
  regWrite(1,  0, 0x00);	// CH A fine
  regWrite(1,  1, 0x00);	// CH A rough
  regWrite(1,  2, 0x00);	// CH B fine
  regWrite(1,  3, 0x00);	// CH B rough
  regWrite(1,  4, 0x00);	// CH C fine
  regWrite(1,  5, 0x00);	// CH C rough
  regWrite(1,  6, 0x00);	// noise frequency
  regWrite(1,  7, 0xF8);	// MIXER
  regWrite(1,  8, 0x00);	// CH A Level
  regWrite(1,  9, 0x00);	// CH B Level
  regWrite(1, 10, 0x00);	// CH C Level
  regWrite(1, 11, 0x00);	// Frequency of envelope
  regWrite(1, 12, 0x00);	// Frequency of envelope
  regWrite(1, 13, 0x00);	// Shape of envelope
  regWrite(2,  0, 0x00);	// CH A fine
  regWrite(2,  1, 0x00);	// CH A rough
  regWrite(2,  2, 0x00);	// CH B fine
  regWrite(2,  3, 0x00);	// CH B rough
  regWrite(2,  4, 0x00);	// CH C fine
  regWrite(2,  5, 0x00);	// CH C rough
  regWrite(2,  6, 0x00);	// noise frequency
  regWrite(2,  7, 0xF8);	// MIXER
  regWrite(2,  8, 0x00);	// CH A Level
  regWrite(2,  9, 0x00);	// CH B Level
  regWrite(2, 10, 0x00);	// CH C Level
  regWrite(2, 11, 0x00);	// Frequency of envelope
  regWrite(2, 12, 0x00);	// Frequency of envelope
  regWrite(2, 13, 0x00);	// Shape of envelope
  regWrite(3,  0, 0x00);	// CH A fine
  regWrite(3,  1, 0x00);	// CH A rough
  regWrite(3,  2, 0x00);	// CH B fine
  regWrite(3,  3, 0x00);	// CH B rough
  regWrite(3,  4, 0x00);	// CH C fine
  regWrite(3,  5, 0x00);	// CH C rough
  regWrite(3,  6, 0x00);	// noise frequency
  regWrite(3,  7, 0xF8);	// MIXER
  regWrite(3,  8, 0x00);	// CH A Level
  regWrite(3,  9, 0x00);	// CH B Level
  regWrite(3, 10, 0x00);	// CH C Level
  regWrite(3, 11, 0x00);	// Frequency of envelope
  regWrite(3, 12, 0x00);	// Frequency of envelope
  regWrite(3, 13, 0x00);	// Shape of envelope

}

void AY38910::setAmplitude(uint8_t ch, uint8_t amplitude)
{
  uint8_t ampValue = amplitude / 8;
  regWrite(unit[ch], chAmp[ch], ampValue);
  ;
}

void AY38910::setTone(uint8_t ch, uint8_t outNote)
{
  uint16_t noteValue = pitchValue[outNote];
  uint8_t  noteVlaueL = (uint8_t)(noteValue & 0x00FF);
  uint8_t  noteValueH = (uint8_t)(noteValue>>8);
  noteValueH &= 0x0F;
  regWrite(unit[ch], chFine[ch], noteVlaueL);
  regWrite(unit[ch], chrough[ch], noteValueH);
}

void AY38910::regWrite(uint8_t unit, uint8_t reg, uint8_t val)
{

  PORTC |= (1 << bdir[unit]) | (1 << bc1[unit]);  // LATCH  ADDRESS
  PORTA = reg;
  asm("NOP");
  asm("NOP");
  PORTC &= ~(1 << bdir[unit]) & ~(1 << bc1[unit]);  // INACTIVE
  PORTA = val;
  PORTC |= (1 << bdir[unit]);  // WRITE TO PSG
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  PORTC = 0x00;
}