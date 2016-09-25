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
int a1 = 1,a2 = 5,a3 = 15,a4 = 25,a5 = 30;
uint16_t FTMDuty = 4400; 
uint16_t FTMDuty_1 = 1700;
uint16_t FTMDuty_2 = 1500;

uint8_t Right;//右线
uint8_t Left;//左线
uint8_t Center;//中线
uint8_t Budao;
uint8_t Saoxian = 64;
uint8_t hang = 1;
//uint8_t Leixin = 0;


unsigned char AverageValue;

uint8_t Pixel[128];
uint8_t oled_data[8][128];
uint8_t Send_Data[200];
int16_t sendData[200];	

uint32_t SD_X;
uint32_t SD_D;
uint8_t Flag = 0;
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
		while(Flag == 1)
		{
			if(TIME1flag_20ms==1)
			{
				TIME1flag_20ms=0;
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
			if(Key_1 == 0)
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
			if(Key_down == 0)
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
					Sd_X();
				}
				CCD_HeiXian();
				if(Center - 64 >= 10 || 63 - Center >= 10) FTM_PWM_ChangeDuty(FTM0_CH3_PA6,FTMDuty_2);
				if(Center - 64 <= 10 || 63 - Center >= 10) FTM_PWM_ChangeDuty(FTM0_CH3_PA6,FTMDuty_1);
				if(Key_down == 0)
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




