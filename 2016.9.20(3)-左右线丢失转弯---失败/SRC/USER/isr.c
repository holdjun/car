#include "isr.h"
#include "ftm.h"
#include "oled.h"
#include "ccd.h"
#include "define.h"

void PIT0_IRQHandler(void)
{ 
	PIT_ClearITPendingBit(PIT0,PIT_IT_TIF);
}

/*************************************************************************
*
*  函数名称：PIT1_IRQHandler
*  功能说明：PIT1定时中断服务函数
*  参数说明：无
*  函数返回：无
*  修改时间：
*  备    注：
*************************************************************************/
void PIT1_IRQHandler(void)
{
	static uint8_t TimerCnt_20ms=0;
	PIT_ClearITPendingBit(PIT1,PIT_IT_TIF);
	TimerCnt_20ms++;
	if(TimerCnt_20ms >= 20)
	{
		TimerCnt_20ms  = 0;
		TIME1flag_20ms = 1;
	}
}

void UART4_RX_TX_IRQHandler(void)
{
	uint8_t ch;
	if(UART_ReceiveData(UART4,&ch))
	{
		UART_SendData(UART4,ch+1);
	}
}




/**************************************??????*******************************************/
#define  CHIP_DEBUG         ON		//??????????????a???????????
#if(CHIP_DEBUG==ON)
__asm void wait()
{
  BX lr	//?????????
}
#endif

void HardFault_Handler(void)//?????????
{
	OLED_Clear();
	FTM_PWM_ChangeDuty(FTM0_CH3_PA6,0);
	FTM_PWM_ChangeDuty(FTM0_CH4_PA7,0);
//	FTM_PWM_ChangeDuty(FTM1_CH0_PA8,0);
//	FTM_PWM_ChangeDuty(FTM1_CH1_PA9,0);
	OLED_Write_String(0,0,(uint8_t *)"The memory");
	
	OLED_Write_String(0,2,(uint8_t *)"or Stacks");	
	
	OLED_Write_String(0,4,(uint8_t *)"overflows");
	
	#if(CHIP_DEBUG==ON)
	wait();
	#endif
	while(1);
}

void NMI_Handler(void)//??????
{
	OLED_Clear();
	FTM_PWM_ChangeDuty(FTM0_CH3_PA6,0);
	FTM_PWM_ChangeDuty(FTM0_CH4_PA7,0);
//	FTM_PWM_ChangeDuty(FTM1_CH0_PA8,0);
//	FTM_PWM_ChangeDuty(FTM1_CH1_PA9,0);

	OLED_Write_String(0,0,(uint8_t *)"The Chip");
	
	OLED_Write_String(0,2,(uint8_t *)"have big");	
	
	OLED_Write_String(0,4,(uint8_t *)"error");
	#if(CHIP_DEBUG==ON)	
	wait();
	#endif
	while(1);
}

void MemManage_Handler(void)//??????
{
	FTM_PWM_ChangeDuty(FTM0_CH3_PA6,0);
	FTM_PWM_ChangeDuty(FTM0_CH4_PA7,0);
//	FTM_PWM_ChangeDuty(FTM1_CH0_PA8,0);
//	FTM_PWM_ChangeDuty(FTM1_CH1_PA9,0);
	#if(CHIP_DEBUG==ON)	
	wait();
	#endif
}

void BusFault_Handler(void)//??????
{
	FTM_PWM_ChangeDuty(FTM0_CH3_PA6,0);
	FTM_PWM_ChangeDuty(FTM0_CH4_PA7,0);
//	FTM_PWM_ChangeDuty(FTM1_CH0_PA8,0);
//	FTM_PWM_ChangeDuty(FTM1_CH1_PA9,0);

	#if(CHIP_DEBUG==ON)	
	wait();
	#endif
}

void UsageFault_Handler(void)//??????
{
	FTM_PWM_ChangeDuty(FTM0_CH3_PA6,0);
	FTM_PWM_ChangeDuty(FTM0_CH4_PA7,0);
//	FTM_PWM_ChangeDuty(FTM1_CH0_PA8,0);
//	FTM_PWM_ChangeDuty(FTM1_CH1_PA9,0);


	#if(CHIP_DEBUG==ON)	
	wait();
	#endif
}

