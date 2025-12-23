#include "oled.h"

//向oled写入数据
void OLED_SendCommand(unsigned char Command){
	I2C_Start();
	I2C_SendByte(0x78);
	I2C_Recv_Ack();
	I2C_SendByte(0x00);//Control Byte
	I2C_Recv_Ack();
	I2C_SendByte(Command);//Data Byte
	I2C_Recv_Ack();
	I2C_Stop();
}

//向oled写入数据
void OLED_SendData(unsigned char Data){
	I2C_Start();
	I2C_SendByte(0x78);
	I2C_Recv_Ack();
	I2C_SendByte(0x40);//Control Byte
	I2C_Recv_Ack();
	I2C_SendByte(Data);//Data Byte
	I2C_Recv_Ack();
	I2C_Stop();
}

//初始化OLED显示
void OLED_Init(void){
	OLED_SendCommand(0xAE);   //display off
	OLED_SendCommand(0x20);	//Set Memory Addressing Mode	
	OLED_SendCommand(0x10);	//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	OLED_SendCommand(0xb0);	//Set Page Start Address for Page Addressing Mode,0-7
	OLED_SendCommand(0xc8);	//Set COM Output Scan Direction
	OLED_SendCommand(0x00);//---set low column address
	OLED_SendCommand(0x10);//---set high column address
	OLED_SendCommand(0x40);//--set start line address
	OLED_SendCommand(0x81);//--set contrast control register
	OLED_SendCommand(0xdf);
	OLED_SendCommand(0xa1);//--set segment re-map 0 to 127
	OLED_SendCommand(0xa6);//--set normal display
	OLED_SendCommand(0xa8);//--set multiplex ratio(1 to 64)
	OLED_SendCommand(0x3F);//
	OLED_SendCommand(0xa4);//0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	OLED_SendCommand(0xd3);//-set display offset
	OLED_SendCommand(0x00);//-not offset
	OLED_SendCommand(0xd5);//--set display clock divide ratio/oscillator frequency
	OLED_SendCommand(0xf0);//--set divide ratio
	OLED_SendCommand(0xd9);//--set pre-charge period
	OLED_SendCommand(0x22); //
	OLED_SendCommand(0xda);//--set com pins hardware configuration
	OLED_SendCommand(0x12);
	OLED_SendCommand(0xdb);//--set vcomh
	OLED_SendCommand(0x20);//0x20,0.77xVcc
	OLED_SendCommand(0x8d);//--set DC-DC enable
	OLED_SendCommand(0x14);//
	OLED_SendCommand(0xaf);//--turn on oled panel 
}

//设置显示位置
void OLED_SetCursor(unsigned char X, unsigned char  Page)
{
	OLED_SendCommand(0xB0 | Page);					//设置页位置
	OLED_SendCommand(0x10 | ((X & 0xF0) >> 4));	//设置X位置高4位
	OLED_SendCommand(0x00 | (X & 0x0F));			//设置X位置低4位
}

//oled清屏
void OLED_Clear(void){
	unsigned char j,i;
	for(j = 0; j < 8 ; j++){
		OLED_SetCursor(0,j);
		for(i = 0;i < 128;i++){
			OLED_SendData(0x00);
		}
		
	}
}

