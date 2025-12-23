#include "iic.h"
sbit I2C_SDA = P1^0;
sbit I2C_SCL = P1^1;

void Delay1us(unsigned int ms){//@40.000MHz
	while(ms--){
		unsigned char data i;
		_nop_();
		i = 11;
		while (--i);
	
	}
}

//初始化I2C
void I2C_Init(void){
	P1M0 = 0;//配置P1端口为准双向口
	P1M1 = 0;
}

//iic启动 在SCL为1期间SDA产生下降沿
void I2C_Start(void){
	I2C_SDA = 1;//确保SDA为1(否则无法产生下降沿)
	
	I2C_SCL = 1;
	Delay1us(1);
	I2C_SDA = 0;//SDA有一个下降沿
	
	Delay1us(1);
	I2C_SCL = 0;//防止误操作SDA
}

//iic停止 在SCL为1期间SDA产生上升沿
void I2C_Stop(void){
	I2C_SDA = 0;
	Delay1us(5);
	
	I2C_SCL = 1;
	Delay1us(1);
	I2C_SDA = 1;
	
}

//I2C发送一个字节
void I2C_SendByte(unsigned char Send_Byte) {
    unsigned char i;
    for (i = 0; i < 8; i++) {
        I2C_SDA = (Send_Byte & (0x80 >> i)) ? 1 : 0; // 显式转为 0/1
        Delay1us(1);
        I2C_SCL = 1;
        Delay1us(1);         
        I2C_SCL = 0;          
    }
}

//I2C接收一个字节
unsigned char I2C_RecvByte(void) {
    unsigned char i;
    unsigned char Byte = 0;
    I2C_SDA = 1; // 释放总线
    for (i = 0; i < 8; i++) {
        I2C_SCL = 1;
		Delay1us(1);
        if (I2C_SDA) {
            Byte |= (0x80 >> i);
        }
        I2C_SCL = 0; // 必须在每次循环末尾拉低
        Delay1us(1);
    }
    return Byte;
}

//I2C发送应答
void I2C_Send_Ack(unsigned char SDA_Ack){
	I2C_SDA = SDA_Ack;
	Delay1us(1);
	I2C_SCL = 1;
	Delay1us(1);
	I2C_SCL = 0;
}

//I2C接受应答
unsigned char I2C_Recv_Ack(void){
	unsigned char Ack;
	I2C_SDA = 1;
	Delay1us(1);
	I2C_SCL = 1;
	Delay1us(1);
	Ack = I2C_SDA;
	I2C_SCL = 0;
	return Ack;
}

