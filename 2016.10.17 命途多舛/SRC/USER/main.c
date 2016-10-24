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

extern Data_Type *Sent_Data;

uint16_t FTMDuty = 4880; 
uint16_t FTMDuty_1 = 1900;
uint16_t FTMDuty_2 = 1850;
uint16_t FTMDuty_3 = 200;
uint16_t FTMDuty_4 = 150;

uint16_t CenterLast[5];
uint16_t Center = 64;
uint16_t saoxian = 64;
uint16_t Right;
uint16_t Left;
uint16_t Right_last;
uint16_t Left_last;
uint16_t Budao;
uint16_t Left_p1 = 27;
uint16_t Right_p1 = 27;
uint16_t Left_p2 = 27;
uint16_t Right_p2 = 27;

uint16_t hang = 1;
uint16_t leixin = 0;
uint16_t leixin_last[5];

uint8_t flag_black = 0;
uint8_t flag_miss = 0;

uint16_t black_Value = 79;
uint16_t white_Value = 130;
uint16_t Valuemax_flag = 0;
uint16_t setValue = 135;

uint8_t Cross_flag = 0;
uint8_t Cross_flag_wan = 0;
uint8_t Cross_flag_time = 0;

uint16_t jiasuflag = 0;
uint16_t jiansuflag = 0;
uint16_t jiansu_Num = 2;
uint16_t jiasu_Num = 4;

uint16_t zhidaoflag = 0;
uint16_t zhidaoflag_save = 0;
uint16_t zhidao_Num = 250;
uint16_t a1 = 20;

uint8_t P1[128];
uint8_t oled_data[8][128];
uint8_t Send_Data[200];
int16_t sendData[200];

uint32_t SD_X;
uint32_t SD_D;
uint8_t Flag = 0;
uint8_t SD_Flag  = 1;
uint8_t TIME1flag_20ms = 0;

int main(void)
{
	uint16_t a2 = 0;
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
				ImageCapture(P1);
//				Sd_X();
//				Sd_D();
//				UART_Send_Con();
				oled_collect();
				oled_show();
			}
			CCD_HeiXian();
			OLED_ZhongXian();
			OLED_Write_Num3(4,0,Center);
			OLED_Write_Num3(0,0,Left);
			OLED_Write_Num3(9,0,Right);
			OLED_Write_Num3(0,2,AverageValue);

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
					FTM_PWM_ChangeDuty(FTM1_CH1_PB1,0);
				}
			}
			if(Key_up == 0) //SD 发车
			{
				DelayMs(100);
				if(Key_up == 0)
				{
					SD_Flag = !SD_Flag;
					if(SD_Flag) OLED_Write_String(2,2,"SD running");
					else 				OLED_Write_String(2,2,"SD stopping");
				}
			}
			if(Key_right == 0) //上位机
			{
				DelayMs(100);
				if(Key_right == 0)
				{
					while(1)
					{
						OLED_Clear();
						Sd_D();
						UART_Send_Con();
					}
				}
			}
		}
		
	//发车
		while(Flag == 2)
		{
			if (a2 <= 3)
			{
				FTM_PWM_ChangeDuty(FTM1_CH0_PB0,6000);
				a2 ++;
			}
			if(TIME1flag_20ms == 1)
			{
				TIME1flag_20ms = 0;
				ImageCapture(P1);
				Sd_X();
			}
			CCD_HeiXian();
			if(leixin == 0)
			{
				if (jiasuflag <= jiasu_Num) FTM_PWM_ChangeDuty(FTM1_CH0_PB0,6000);
				else 								 				FTM_PWM_ChangeDuty(FTM1_CH0_PB0,FTMDuty_1);
			}
			if(leixin == 1 && Cross_flag == 0) 
			{
//				if (zhidaoflag_save < zhidao_Num && jiansuflag <= jiansu_Num)
//				{
//					FTM_PWM_ChangeDuty(FTM1_CH0_PB0,0);
//					FTM_PWM_ChangeDuty(FTM1_CH1_PB1,FTMDuty_3);
//				}
				if(jiansuflag <= 8)
				{
					FTM_PWM_ChangeDuty(FTM1_CH0_PB0,0);
					FTM_PWM_ChangeDuty(FTM1_CH1_PB1,FTMDuty_4);
				}
				else FTM_PWM_ChangeDuty(FTM1_CH0_PB0,FTMDuty_2);
			}
			if(Cross_flag == 1) FTM_PWM_ChangeDuty(FTM1_CH0_PB0,FTMDuty_2);
			
			if(Key_down == 0) //菜单
			{
				DelayMs(100);
				if(Key_down == 0)
				{
					OLED_Clear();
					Flag = 0;
					PIT_Stop(PIT1);
					FTM_PWM_ChangeDuty(FTM1_CH0_PB0,0);
					FTM_PWM_ChangeDuty(FTM1_CH1_PB1,0);
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

