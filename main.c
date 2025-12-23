#include <AI8051U.H>
#include "iic.h"
#include "oled.h"
void main(void){
	unsigned char ack,i;
	P2M0 = 0;//配置P2端口为准双向口
	P2M1 = 0;//我这里仅仅作为点灯debug用
	
	/*测试是否应答 debug
	I2C_Start();
	I2C_SendByte(0x78);
	ack = I2C_Recv_Ack();
	I2C_Stop();
	*/
	
	//初始化I2C
	I2C_Init();
	OLED_Init();
	OLED_Clear();
	OLED_SetCursor(0,0);
	for(i = 0;i < 128;i++){
		OLED_SendData(0xff);
	}
	while(1){
		/* 这些代码仅仅用来debug，没有也无伤大雅
		P2 = 0xfe;
		if (ack == 0){
			P2 = 0x00;
		}
		*/
		
	}
}