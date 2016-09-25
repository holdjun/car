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

uint16_t a1 = 1,a2 = 8,a3 = 25,a4 = 35,a5 = 40,a6 = 20,a7 = 10, a8 = 20,a9 = 50;
uint16_t FTMDuty = 4850; 
uint16_t FTMDuty_1 = 2000;
uint16_t FTMDuty_2 = 1300;

uint16_t LeftLast[5];
uint16_t Left;
uint16_t CenterLast[5];
uint16_t Center = 64;
uint16_t RightLast[5];
uint16_t Right;
//uint8_t Width;//赛道宽度
uint16_t Budao;
uint16_t hang = 1;
uint16_t leixin = 0;
uint16_t shaoxian = 64;


uint8_t Pixel[128];
uint8_t oled_data[8][128];
uint8_t Send_Data[200];
int16_t sendData[200];	

uint32_t SD_X;
uint32_t SD_D;
uint8_t Flag = 0;
uint8_t SD_Flag  = 0;
uint8_t TIME1flag_20ms = 0;
uint16_t jiansuflag = 0;


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
		//ccd测试
		while(Flag == 1)
		{
			if(TIME1flag_20ms == 1)
			{
				TIME1flag_20ms = 0;
				ImageCapture(Pixel);
//				Sd_X();
//				Sd_D();
//				UART_Send_Con();
				erzhi();
				LB();
				oled_collect();
				oled_show();
			}
			CCD_HeiXian();
			OLED_ZhongXian();
			OLED_Write_Num3(4,0,Center);
			OLED_Write_Num3(0,0,Left);
			OLED_Write_Num3(9,0,Right);
			if(Key_1 == 0) //发车
			{
				DelayMs(100);
				if(Key_1 == 0)
				{
					OLED_Clear();
					Flag = 2;
					SD_X = 0;
					PIT_Start(PIT1);
				}
			}
			if(Key_down == 0) //菜单
			{
				DelayMs(100);
				if(Key_down == 0)
				{
					OLED_Clear();
					Flag = 0;
					PIT_Stop(PIT1);
					FTM_PWM_ChangeDuty(FTM1_CH0_PB0,0);
				}
			}
		}
		
	//发车
		while(Flag == 2)
		{
			if(TIME1flag_20ms==1)
			{
				TIME1flag_20ms=0;
				ImageCapture(Pixel);
				erzhi();
				LB();
//				Sd_X();
			}
			CCD_HeiXian();
			if(Center - 64 <= 7 || 63 - Center <= 7) FTM_PWM_ChangeDuty(FTM1_CH0_PB0,FTMDuty_1);
//			if(Center - 64 >= 7 || 63 - Center >= 7) 
//			{
//				if(jiansuflag <= 4) 									FTM_PWM_ChangeDuty(FTM1_CH0_PB0,0);
//				if(jiansuflag > 4 && jiansuflag < a6) FTM_PWM_ChangeDuty(FTM1_CH0_PB0,FTMDuty_2);
//				if(jiansuflag >= a6) jiansuflag = 0;
//			}
			if(Key_down == 0)//菜单
			{
				DelayMs(100);
				if(Key_down == 0)
				{
					OLED_Clear();
					Flag = 0;
					PIT_Stop(PIT1);
					FTM_PWM_ChangeDuty(FTM1_CH0_PB0,0);
				}
			}
		}
//			while(SD_Flag)
//			{
//				Sd_D();
//				UART_Send_Con();
//			}
	}
}


void assert_failed(uint8_t* file, uint32_t line)
{
	UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}

