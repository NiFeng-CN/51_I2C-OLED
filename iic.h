#include <AI8051U.H>
#ifndef __IIC_H__
#define __IIC_H__

void Delay1us(unsigned int ms);
void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_SendByte(unsigned char Send_Byte);
unsigned char I2C_RecvByte(void);
void I2C_Send_Ack(unsigned char SDA_Ack);
unsigned char I2C_Recv_Ack(void);
#endif
