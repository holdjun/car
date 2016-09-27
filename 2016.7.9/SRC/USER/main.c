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

int main(void)
{
	int Left_Speed,Right_Speed,Speed;
	GPIO_InitTypeDef GPIO_InitStruct1;
	PIT_InitTypeDef PIT_InitStruct1;
	FTM_InitTypeDef FTM_InitStruct1;
	FTM_InitTypeDef FTM_InitStruct2;
	SystemClockSetup(ClockSource_IRC,CoreClock_96M);

	DelayInit();
//	UART_DebugPortInit(UART0_RX_PA14_TX_PA15,115200);  //A 14 15 串口
//	UART_ITConfig(UART4,UART_IT_RDRF,ENABLE);
//	NVIC_EnableIRQ(UART4_RX_TX_IRQn);
//	DisplayCPUInfo();

	GPIO_InitStruct1.GPIOx = PTA; 										//A 5 6 7 8 9 16 传感器
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE; 	//A	17 24 25 26 按钮
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init(&GPIO_InitStruct1);
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_6;                        
	GPIO_Init(&GPIO_InitStruct1);
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_7;                            
	GPIO_Init(&GPIO_InitStruct1);
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_8;                            
	GPIO_Init(&GPIO_InitStruct1);
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_9;                            
	GPIO_Init(&GPIO_InitStruct1);
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_16;                            
	GPIO_Init(&GPIO_InitStruct1);
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_17;                            
	GPIO_Init(&GPIO_InitStruct1);
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_24;                            
	GPIO_Init(&GPIO_InitStruct1);
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_25;                            
	GPIO_Init(&GPIO_InitStruct1);
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_26;                            
	GPIO_Init(&GPIO_InitStruct1);
	
	PIT_InitStruct1.PIT_Interval = 500;
	PIT_InitStruct1.PITx = PIT0;
	PIT_Init(&PIT_InitStruct1);
	PIT_ITConfig(PIT0,PIT_IT_TIF, ENABLE);
	NVIC_EnableIRQ(PIT0_IRQn);
	 
	FTM_InitStruct1.Frequency = 1000;
	FTM_InitStruct1.FTMxMAP = FTM1_CH1_PB1;          //B 1 左电机
	FTM_InitStruct1.FTM_Mode = FTM_Mode_EdgeAligned;
	FTM_InitStruct1.InitalDuty = 4000;
	FTM_Init(&FTM_InitStruct1);
	
	FTM_InitStruct1.Frequency = 1000;
	FTM_InitStruct1.FTMxMAP = FTM1_CH0_PB0;          //B 0 右电机
	FTM_InitStruct1.FTM_Mode = FTM_Mode_EdgeAligned;
	FTM_InitStruct1.InitalDuty = 4000;
	FTM_Init(&FTM_InitStruct2);
	
	DelayMs(1000);
	
	while(1)
	{
		if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_17)==0)
		{
			DelayMs(20);
			if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_17)==0)
			{
				
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_17));
			}
		}
		if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_24)==0)
		{
			DelayMs(20);
			if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_24)==0)
			{
				
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_24));
			}
		}
		
		
		
	}
}


void assert_failed(uint8_t* file, uint32_t line)
{
	UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}

