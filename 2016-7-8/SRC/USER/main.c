#include "sys.h"
#include "gpio.h"
#include "delay.h"
#include "led.h"
#include "wdog.h"
#include "pit.h"
#include "dma.h"
#include "ftm.h"
#include "lptm.h"
#include "adc.h"
#include "tsi.h"
#include "dac.h"
#include "spi.h"
#include "i2c.h"
#include "pdb.h"
#include "sd.h"
#include "flash.h"
#include "spilcd.h"
#include "stdio.h"			
#include "uart.h"
#include "oled.h"
#include "dmacnt.h"
#include "DataScope_DP.h"

uint32_t Pid_Set=3500;
int PID_FinalOut;
double Kd = 6;
double Ki = 3;
double Kp = 8;
double Td = 1;
uint32_t pid_out;
uint32_t *Pid_Out=&pid_out;
uint32_t PidError[3]={0};
double PidOut;

int key_detect1();
int key_detect2();
int key_detect3();
int key_detect4();
int key_detect5();
int key_detect6();


int main(void)
{
	unsigned char i;          
	unsigned char Send_Count; 
	uint32_t DMA_Value0 = 0;
	uint32_t DMA_Value1 = 0;
	PIT_InitTypeDef PIT_InitStruct1;
	GPIO_InitTypeDef GPIO_InitStruct1;
	FTM_InitTypeDef FTM_InitStruct1;
	DMACNT_InitTypeDef DMACNT_InitStruct1;
	SystemClockSetup(ClockSource_EX50M,CoreClock_100M);
	UART_DebugPortInit(UART0_RX_PA14_TX_PA15,115200);
	DisplayCPUInfo();
	DelayInit();
	OLED_Init();
	DMACNT_InitStruct1.DMACNT_Mode = DMACNT_MODE_FALLING;  //上升沿计数
	DMACNT_InitStruct1.DMA_Chl = DMA_CH0;                 //使用通道 0
	DMACNT_InitStruct1.GPIOx = PTC;                       //PTC5
	DMACNT_InitStruct1.GPIO_Pin = GPIO_Pin_5; 
	DMACNT_Init(&DMACNT_InitStruct1);

	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;
	GPIO_InitStruct1.GPIOx = PTB;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStruct1.GPIO_InitState = Bit_SET;
	GPIO_InitStruct1.GPIOx = PTB;
	GPIO_Init(&GPIO_InitStruct1);
	
	PIT_InitStruct1.PITx=PIT2;
	PIT_InitStruct1.PIT_Interval=100;
	PIT_Init(&PIT_InitStruct1);
	NVIC_EnableIRQ(PIT2_IRQn);
	PIT_ITConfig(PIT2,PIT_IT_TIF,ENABLE);
	
	PIT_InitStruct1.PITx=PIT0;
	PIT_InitStruct1.PIT_Interval=20000;
	PIT_Init(&PIT_InitStruct1);
	PIT_ITConfig(PIT0,PIT_IT_TIF,ENABLE);
	NVIC_EnableIRQ(PIT0_IRQn);
	FTM_InitStruct1.Frequency = 800;
	FTM_InitStruct1.FTM_Mode = FTM_Mode_EdgeAligned;
//	FTM_InitStruct1.InitalDuty = 10000;
	FTM_InitStruct1.FTMxMAP = FTM0_CH0_PC1;
	FTM_Init(&FTM_InitStruct1);
	UART_printf("DMACNT_CH0_Value:%d \n",*Pid_Out);


	while(1)
	{
//		if(key_detect1()){
//			Pid_Set += 500;
//		}
//		if(key_detect3()){
//			Pid_Set -= 500;
//		}
		GPIO_ResetBits(PTB,GPIO_Pin_0);
		PidError[2] = Pid_Set - *Pid_Out;
		PidOut =  Kp * (PidError[2] - PidError[1]);
		PidOut += Ki *  PidError[2] * Td;
		PidOut += Kd * (PidError[2] - 2 * PidError[1] + PidError[0]) / Td;
		PidError[0] = PidError[1];
		PidError[1] = PidError[2];
		PID_FinalOut =PidOut*2;
		
		
//		
//		if(key_detect5()){
//			Kd+=0.2;OLED_Clear();
//		}
//		else if(key_detect6()){
//			Kd-=0.2;OLED_Clear();
//		}
//		
//		OLED_Write_String(2,0,"Kp");
//		OLED_Write_String(2,2,"Ki");
//		OLED_Write_String(2,4,"Kd");
//		OLED_Write_Num3(6,0,Kp*10);
//		OLED_Write_Num3(6,2,Ki*10);
//		OLED_Write_Num3(6,4,Kd*10);
//		OLED_Write_Num4(9,6,*Pid_Out-1000);
//		
		
		if(PID_FinalOut>10000) PID_FinalOut=10000;
		else if(PID_FinalOut<0) PID_FinalOut=0;
		
		FTM_PWM_ChangeDuty(FTM0_CH0_PC1,PID_FinalOut);
		
	}
}



/*  按键检测部分   */
int key_detect6()
{
		GPIO_InitTypeDef GPIO_InitStruct1;
		GPIO_InitStruct1.GPIO_Pin=GPIO_Pin_24;
		GPIO_InitStruct1.GPIO_InitState=Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode=GPIO_IT_DISABLE;
		GPIO_InitStruct1.GPIO_Mode=GPIO_Mode_IPU;
		GPIO_InitStruct1.GPIOx=PTA;
		GPIO_Init(&GPIO_InitStruct1);
		if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_24)==0){
				DelayMs(20);
			if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_24)==0){
				
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_24));
				return 1;
			}
		}
		else return 0;
}

int key_detect5()
{
		GPIO_InitTypeDef GPIO_InitStruct1;
		GPIO_InitStruct1.GPIO_Pin=GPIO_Pin_25;
		GPIO_InitStruct1.GPIO_InitState=Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode=GPIO_IT_DISABLE;
		GPIO_InitStruct1.GPIO_Mode=GPIO_Mode_IPU;
		GPIO_InitStruct1.GPIOx=PTA;
		GPIO_Init(&GPIO_InitStruct1);
		if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_25)==0){
				DelayMs(20);
			if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_25)==0){
				
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_25));
				return 1;
			}
		}
		else return 0;
}

int key_detect4()
{
		GPIO_InitTypeDef GPIO_InitStruct1;
		GPIO_InitStruct1.GPIO_Pin=GPIO_Pin_26;
		GPIO_InitStruct1.GPIO_InitState=Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode=GPIO_IT_DISABLE;
		GPIO_InitStruct1.GPIO_Mode=GPIO_Mode_IPU;
		GPIO_InitStruct1.GPIOx=PTA;
		GPIO_Init(&GPIO_InitStruct1);
		if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_26)==0){
				DelayMs(20);
			if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_26)==0){
				
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_26));
				return 1;
			}
		}
		else return 0;
}

int key_detect3()
{
		GPIO_InitTypeDef GPIO_InitStruct1;
		GPIO_InitStruct1.GPIO_Pin=GPIO_Pin_27;
		GPIO_InitStruct1.GPIO_InitState=Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode=GPIO_IT_DISABLE;
		GPIO_InitStruct1.GPIO_Mode=GPIO_Mode_IPU;
		GPIO_InitStruct1.GPIOx=PTA;
		GPIO_Init(&GPIO_InitStruct1);
		if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0){
				DelayMs(20);
			if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_27)==0){
				
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_27));
				return 1;
			}
		}
		else return 0;
}

int key_detect2()
{
		GPIO_InitTypeDef GPIO_InitStruct1;
		GPIO_InitStruct1.GPIO_Pin=GPIO_Pin_28;
		GPIO_InitStruct1.GPIO_InitState=Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode=GPIO_IT_DISABLE;
		GPIO_InitStruct1.GPIO_Mode=GPIO_Mode_IPU;
		GPIO_InitStruct1.GPIOx=PTA;
		GPIO_Init(&GPIO_InitStruct1);
		if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_28)==0){
				DelayMs(20);
			if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_28)==0){
				
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_28));
				return 1;
			}
		}
		else return 0;
}

int key_detect1()
{
		GPIO_InitTypeDef GPIO_InitStruct1;
		GPIO_InitStruct1.GPIO_Pin=GPIO_Pin_29;
		GPIO_InitStruct1.GPIO_InitState=Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode=GPIO_IT_DISABLE;
		GPIO_InitStruct1.GPIO_Mode=GPIO_Mode_IPU;
		GPIO_InitStruct1.GPIOx=PTA;
		GPIO_Init(&GPIO_InitStruct1);
		if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_29)==0){
				DelayMs(20);
			if(GPIO_ReadInputDataBit(PTA,GPIO_Pin_29)==0){
				
				while(!GPIO_ReadInputDataBit(PTA,GPIO_Pin_29));
				return 1;
			}
		}
		else return 0;
}


void assert_failed(uint8_t* file, uint32_t line)
{
	//断言失败检测
	UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}
