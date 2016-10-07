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

uint16_t a1 = 27,a2 = 27,a3 = 13,a4 = 35,a5 = 40,a6 = 20,a7 = 10, a8 = 20,a9 = 50;
uint16_t FTMDuty = 4896; 
uint16_t FTMDuty_1 = 1800;
uint16_t FTMDuty_2 = 1300;

uint16_t LeftLast;
uint16_t Left;
uint16_t CenterLast[5];
uint16_t Center = 64;
uint16_t RightLast;
uint16_t Right;
//uint8_t Width;//赛道宽度
uint16_t Budao;
uint16_t hang = 1;
uint16_t leixin = 0;
uint16_t saoxian = 64;
uint8_t flag_black = 0;
uint8_t flag_miss = 0;
uint8_t flag_miss_record;
uint8_t Cross_flag = 0;
uint8_t Cross_flag_wan = 0;
uint8_t Cross_flag_time = 0;

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
uint16_t jiasuflag = 0;


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
			if(Key_right == 0) //上位机
			{
				DelayMs(100);
				if(Key_right == 0)
				{
					OLED_Clear();
					Sd_D();
					UART_Send_Con();
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
//			if (leixin == 0) 
//			{
//				if(jiasuflag <= 1) FTM_PWM_ChangeDuty(FTM1_CH0_PB0,4000);
				FTM_PWM_ChangeDuty(FTM1_CH0_PB0,FTMDuty_1);
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
	}
}


void assert_failed(uint8_t* file, uint32_t line)
{
	UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}

