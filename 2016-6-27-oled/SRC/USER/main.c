#include "sys.h"
#include "gpio.h"
#include "delay.h"
#include "led.h"
#include "uart.h"
#include "wdog.h"
#include "pit.h"
#include "rtc.h"
#include "dma.h"
#include "ftm.h"
#include "lptm.h"
#include "adc.h"
#include "dac.h"
#include "tsi.h"
#include "spi.h"
#include "enet.h"
#include "i2c.h"
#include "oled.h"
#include "pdb.h"			
#include "can.h"
#include "sd.h"
#include "flash.h"
#include "spiflash.h"
#include "spilcd.h"
#include "stdio.h"
#include "mma845x.h"

int main(void)
{
	int a=2,b=0,c=0;//a、b指针上下移动的位置 c页数 菜单滚动
	GPIO_InitTypeDef GPIO_InitStruct1;
	//初始化GPIO
	SystemClockSetup(ClockSource_EX50M,CoreClock_100M);
	//初始化系统时钟 使用外部50M晶振 PLL倍频到100M
	DelayInit();
	OLED_Init();

	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_25;
  GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
  GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
  GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStruct1.GPIOx = PTA;
  GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_26;
  GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(&GPIO_InitStruct1);
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_27;
  GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(&GPIO_InitStruct1);
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;	
  GPIO_Init(&GPIO_InitStruct1);	
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;	
  GPIO_Init(&GPIO_InitStruct1);	
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;	
  GPIO_Init(&GPIO_InitStruct1);	
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;	
  GPIO_Init(&GPIO_InitStruct1);	
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;	
  GPIO_Init(&GPIO_InitStruct1);	
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;	
  GPIO_Init(&GPIO_InitStruct1);	
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;	
  GPIO_Init(&GPIO_InitStruct1);	
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_16;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;	
  GPIO_Init(&GPIO_InitStruct1);	
	
	OLED_Write_Char(1, a, 43);
	OLED_Write_Char(0, 0, 164);
	OLED_Write_Char(1, 0, 165);
	OLED_Write_Char(2, 0, 166);
	OLED_Write_Char(3, 0, 167);
	
	while(1)
	{
			
		if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_25)==0)
			{
				DelayMs(60);
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_25)==0)
					{
						OLED_Write_Char(1, a, 36);
						a += 2;
						if(a==8)
						{
							if(c==2) a=6;
							else {
								a = 2;
								c = c+1;
							}
						}
						OLED_Write_Char(1, a, 43);
					}
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_25));
			}
			
			if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_26)==0)
			{
				DelayMs(60);
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_26)==0)
					{
						OLED_Write_Char(1, a, 36);
						a -= 2;
						if(a==0)
						{
							if(c==0) a=2;
							else {
								a = 6;
								c = c-1;
							}
						} 
						OLED_Write_Char(1, a, 43);
					}
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_26));
			}
			
			if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0)
			{
				DelayMs(60);
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0)
					{
						b = !b;
					}
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_27));
			}
			
			if(c==0)
			{
				OLED_Write_Char(3, 2, 128);
				OLED_Write_Char(4, 2, 129);
				OLED_Write_Char(5, 2, 130);
				OLED_Write_Char(6, 2, 131);
				OLED_Write_Char(3, 4, 132);
				OLED_Write_Char(4, 4, 133);
				OLED_Write_Char(5, 4, 134);
				OLED_Write_Char(6, 4, 135);
				OLED_Write_Char(3, 6, 140);
				OLED_Write_Char(4, 6, 141);
				OLED_Write_Char(5, 6, 142);
				OLED_Write_Char(6, 6, 143);
				OLED_Write_Char(7, 6, 144);
				OLED_Write_Char(8, 6, 145);
			}
			
			if(c==1)
			{
				OLED_Write_Char(3, 2, 146);
				OLED_Write_Char(4, 2, 147);
				OLED_Write_Char(5, 2, 148);
				OLED_Write_Char(6, 2, 149);
				OLED_Write_Char(3, 4, 63);
				OLED_Write_Char(4, 4, 48);
				OLED_Write_Char(5, 4, 62);
				OLED_Write_Char(6, 4, 63);
				OLED_Write_Char(3, 6, 152);
				OLED_Write_Char(4, 6, 153);
				OLED_Write_Char(5, 6, 154);
				OLED_Write_Char(6, 6, 155);
				OLED_Write_Char(7, 6, 156);
				OLED_Write_Char(8, 6, 157);
			}
			
			if(c==2)
			{
				OLED_Write_Char(3, 2, 146);
				OLED_Write_Char(4, 2, 147);
				OLED_Write_Char(5, 2, 148);
				OLED_Write_Char(6, 2, 149);
				OLED_Write_Char(3, 4, 51);
				OLED_Write_Char(4, 4, 48);
				OLED_Write_Char(5, 4, 51);
				OLED_Write_Char(6, 4, 48);
				OLED_Write_Char(3, 6, 158);
				OLED_Write_Char(4, 6, 159);
				OLED_Write_Char(5, 6, 160);
				OLED_Write_Char(6, 6, 161);
				OLED_Write_Char(7, 6, 162);
				OLED_Write_Char(8, 6, 163);
			}
			
			while(a==2 && b==1 && c==0)
			{
			GPIO_ToggleBit(PTA,GPIO_Pin_5);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_5);
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0)
			{	DelayMs(60);	
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0) b = !b;
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_27));}
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_6);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_6);
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0)
			{	DelayMs(60);	
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0) b = !b;
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_27));}
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_7);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_7);
			DelayMs(50);
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0)
			{	DelayMs(60);	
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0) b = !b;
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_27));}
			GPIO_ToggleBit(PTA,GPIO_Pin_8);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_8);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_9);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_9);
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0)
			{	DelayMs(60);	
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0) b = !b;
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_27));}
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_14);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_14);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_15);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_15);
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0)
			{	DelayMs(60);	
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0) b = !b;
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_27));}
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_16);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_16);
			DelayMs(50);
			}
			if(a==4 && b==1 && c==0)
			{
			GPIO_ToggleBit(PTA,GPIO_Pin_16);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_16);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_15);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_15);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_14);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_14);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_9);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_9);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_8);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_8);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_7);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_7);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_6);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_6);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_5);
			DelayMs(50);
			GPIO_ToggleBit(PTA,GPIO_Pin_5);
			DelayMs(50);
			}
			while(a==6 && b==1 && c==0)
			{
				//
				OLED_Write_Picture();
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0)
				{DelayMs(60);
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0) {
					b = !b;
					OLED_Clear();
					OLED_Write_Char(1, a, 43);
					OLED_Write_Char(0, 0, 164);
					OLED_Write_Char(1, 0, 165);
					OLED_Write_Char(2, 0, 166);
					OLED_Write_Char(3, 0, 167);
				}
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_27));}
			}
		}
	}
	


void assert_failed(uint8_t* file, uint32_t line)
{
	UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}

