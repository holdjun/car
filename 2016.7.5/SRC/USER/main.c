#include "sys.h"
#include "gpio.h"
#include "delay.h"
#include "led.h"
#include "wdog.h"
#include "pit.h"
#include "dma.h"
#include "ftm.h"
#include "lptm.h"
#include "key.h"
#include "adc.h"
#include "tsi.h"
#include "dac.h"
#include "spi.h"
#include "i2c.h"
#include "pdb.h"
#include "sd.h"
#include "oled.h"
#include "flash.h"
#include "spilcd.h"
#include "stdio.h"
#include "nrf2401.h"
#include "uart.h"

#include "dmacnt.h"
int main(void)
{
	uint32_t FTMDuty = 0, DMA_Value0 = 0,DMA_Value1 = 0;
	int speed_num=0;
	FTM_InitTypeDef FTM_InitStruct1;
	GPIO_InitTypeDef GPIO_InitStruct1;
	DMACNT_InitTypeDef DMACNT_InitStruct1;
	//初始化系统时钟 使用外部50M晶振 PLL倍频到100M
	SystemClockSetup(ClockSource_EX50M,CoreClock_100M);
	//初始化默认的调试串口
	UART_DebugPortInit(UART0_RX_PA14_TX_PA15,115200);
	//打印MCU信息
	DisplayCPUInfo();
	DelayInit();
	OLED_Init();

	GPIO_InitStruct1.GPIOx = PTA;                             
	GPIO_InitStruct1.GPIO_InitState = Bit_SET;                
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;            
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_27;  	
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;  
	GPIO_Init(&GPIO_InitStruct1); 
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_28;  	      
	GPIO_Init(&GPIO_InitStruct1); 			
																									 //加减速度
																									 //初始化FTM
	FTM_InitStruct1.Frequency = 1000;                // 1KHZ
	FTM_InitStruct1.FTMxMAP = FTM1_CH1_PB1;          //FTM0_CH0 PC1引脚
	FTM_InitStruct1.FTM_Mode = FTM_Mode_EdgeAligned; //边沿对齐模式
	FTM_InitStruct1.InitalDuty = 10000;               
	FTM_Init(&FTM_InitStruct1);

//	FTM_InitStruct1.InitalDuty = 0;               
//	FTM_InitStruct1.FTMxMAP = FTM1_CH0_PB0;
//	FTM_Init(&FTM_InitStruct1);

	DMACNT_InitStruct1.DMACNT_Mode = DMACNT_MODE_RISING;  //上升沿计数
	DMACNT_InitStruct1.DMA_Chl = DMA_CH0;                 //使用通道 0
	DMACNT_InitStruct1.GPIOx = PTC;                       //PTC5
	DMACNT_InitStruct1.GPIO_Pin = GPIO_Pin_5;
	DMACNT_Init(&DMACNT_InitStruct1);

	while(1)
	{
		DMA_Value0 = DMACNT_GetValue(DMA_CH0);
		DMA_Value1 = DMACNT_GetValue(DMA_CH1);
		UART_printf("DMACNT_CH0_Value:%d ",DMA_Value0);
		UART_printf("DMACNT_CH1_Value:%d\r\n",DMA_Value1);
		if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_28)==0)
			{
				DelayMs(60);
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_28)==0)
					{
						FTMDuty += 500;
						FTMDuty %= 10000;
						while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_28));
					}
			}
			if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0)
			{
				DelayMs(60);
				if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0)
					{
						FTMDuty -= 500;
						FTMDuty %= 10000;
						while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_27));
					}
			}
			DelayMs(50);
			speed_num = FTMDuty/100;
			OLED_Write_String(2,2,"speed");
			OLED_Write_Num3(4,4,speed_num);
			FTM_PWM_ChangeDuty(FTM1_CH1_PB1,FTMDuty); //FTMDUTY变化
	}
}


void assert_failed(uint8_t* file, uint32_t line)
{
	//断言失败检测
	UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}

