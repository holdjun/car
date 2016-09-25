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
#include "pdb.h"
#include "can.h"
#include "sd.h"
#include "flash.h"
#include "spiflash.h"
#include "spilcd.h"
#include "stdio.h"
#include "mma845x.h"
#include "oled.h"
#include "ccd.h"
#include "data_sent.h"
#include "define.h"
#include "chuinit.h"
#include "menu.h"

int i = 0;
int a1 = 10,a2 = 25,a3 = 30;
uint16_t FTMDuty = 4400; 
uint16_t FTMDuty_1 = 1700;
uint16_t FTMDuty_2 = 1500;

uint8_t CenterLast[5];
uint8_t Center = 63;
uint8_t LeftLast[5];
uint8_t Left;
uint8_t RightLast[5];
uint8_t Right;
uint8_t Width;


unsigned char AverageValue;

uint8_t Pixel[128];
uint8_t oled_data[8][128];
uint8_t Send_Data[200];
int16_t sendData[200];	

uint32_t SD_X;
uint32_t SD_D;
uint8_t CCD_Flag = 0;
uint8_t Run_Flag = 0;
uint8_t SD_Flag  = 0;
uint8_t TIME1flag_20ms = 0;


int main(void)
{

	SystemClockSetup(ClockSource_EX50M,CoreClock_100M);
	DelayInit();
	OLED_Init();
	Sd_Init();
	chuinit_Init();
	DataInit();
	Data_Uart_Init();
	
	while(1)
	{
		Menu_Init();
		//打开ccd测试
		while(CCD_Flag)
		{
			if(TIME1flag_20ms==1)
			{
				TIME1flag_20ms=0;
				ImageCapture(Pixel);
				Sd_X();
				Sd_D();
				UART_Send_Con();
				erzhi();
				LB();
				oled_collect();
				oled_show();
			}
			CCD_HeiXian();
			OLED_ZhongXian();	
//			OLED_Write_Num4(0,7,FTMDuty);
//			if(Center - 64 >= 10 || 63 - Center >= 10) FTM_PWM_ChangeDuty(FTM1_CH0_PB0,FTMDuty_2);
//			if(Center - 64 <= 10 || 63 - Center >= 10) FTM_PWM_ChangeDuty(FTM1_CH0_PB0,FTMDuty_1);
			Menu_Quit2();
		}
		
		//发车
			while(Run_Flag)
			{
				if(TIME1flag_20ms==1)
				{
					TIME1flag_20ms=0;
					ImageCapture(Pixel);
					erzhi();
					LB();
					Sd_X();
				}
				CCD_HeiXian();
				if(Center - 64 >= 10 || 63 - Center >= 10) FTM_PWM_ChangeDuty(FTM1_CH0_PB0,FTMDuty_2);
				if(Center - 64 <= 10 || 63 - Center >= 10) FTM_PWM_ChangeDuty(FTM1_CH0_PB0,FTMDuty_1);
				Menu_Quit1();
			}
			while(SD_Flag)
			{
				Sd_D();
				UART_Send_Con();
			}
	}
}


void assert_failed(uint8_t* file, uint32_t line)
{
	UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}




