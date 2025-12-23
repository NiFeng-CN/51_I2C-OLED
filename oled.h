#include <AI8051U.H>
#include "iic.h"
#ifndef __OLED_H__
#define __OLED_H__

void OLED_SendCommand(unsigned char Command);
void OLED_SendData(unsigned char Data);
void OLED_Init(void);
void OLED_SetCursor(unsigned char X, unsigned char  Page);
void OLED_Clear(void);
#endif
