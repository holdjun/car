#include "chuinit.h"
#include "gpio.h"
#include "adc.h"
#include "ftm.h"
#include "pit.h"

/***************************菜单按键初始化******************************/
void chuinit_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct1;
	ADC_InitTypeDef ADC_InitStruct1;
	FTM_InitTypeDef FTM_InitStruct1;
	PIT_InitTypeDef PIT_InitStruct1;
	
	GPIO_InitStruct1.GPIO_Pin = Key_left_PIN;                 // KEY LEFT
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct1.GPIOx = Key_left_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = Key_right_PIN;                 //KEY RIGHT
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct1.GPIOx = Key_right_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = Key_up_PIN;                 //KEY UP
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct1.GPIOx = Key_up_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = Key_down_PIN;                 //KEY DOWN
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct1.GPIOx = Key_down_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = Key_1_PIN;                 //KEY K1
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct1.GPIOx = Key_1_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = Key_2_PIN;                 //KEY K2
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct1.GPIOx = Key_2_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	
	ADC_InitStruct1.ADCxMap = ADC1_SE10_PB4;
	ADC_InitStruct1.ADC_Precision=ADC_PRECISION_8BIT;
	ADC_InitStruct1.ADC_TriggerSelect=ADC_TRIGGER_SW;
	ADC_Init(&ADC_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = CCD_CLK_PIN;                    //  ccd clk0
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;
	GPIO_InitStruct1.GPIOx = CCD_CLK_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = CCD_SI_PIN;                    //    ccd si0
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;
	GPIO_InitStruct1.GPIOx = CCD_SI_PORT;
	GPIO_Init(&GPIO_InitStruct1);  
	
	FTM_InitStruct1.Frequency = 300; 								 //舵机
	FTM_InitStruct1.FTMxMAP=FTM0_CH4_PA7;
	FTM_InitStruct1.FTM_Mode=FTM_Mode_EdgeAligned;
	FTM_InitStruct1.InitalDuty = 4700; 
	FTM_Init(&FTM_InitStruct1);
	
	FTM_InitStruct1.Frequency = 10000; 								 //电机前
	FTM_InitStruct1.FTMxMAP=FTM1_CH0_PB0;
	FTM_InitStruct1.FTM_Mode=FTM_Mode_EdgeAligned;
	FTM_InitStruct1.InitalDuty = 0; 
	FTM_Init(&FTM_InitStruct1);
	
	FTM_InitStruct1.Frequency = 10000; 								 //电机后
	FTM_InitStruct1.FTMxMAP=FTM1_CH1_PB1;
	FTM_InitStruct1.FTM_Mode=FTM_Mode_EdgeAligned;
	FTM_InitStruct1.InitalDuty = 0; 
	FTM_Init(&FTM_InitStruct1);
	
	PIT_InitStruct1.PITx=PIT1;
	PIT_InitStruct1.PIT_Interval = 1;
	PIT_Init(&PIT_InitStruct1);
	PIT_ITConfig(PIT1,PIT_IT_TIF,ENABLE);
	NVIC_EnableIRQ(PIT1_IRQn);
	PIT_Stop(PIT1);
}
