#include "isr.h"
#include "ftm.h"
#include "oled.h"

void PIT0_IRQHandler(void)
{ 
	//Clear IT pending bit
	UART_printf("Pit0 Isr!\r\n");
	PIT_ClearITPendingBit(PIT0,PIT_IT_TIF);
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
#define  CHIP_DEBUG         ON	 //??????????????a???????????
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

#if(CHIP_DEBUG==ON)	
wait();
#endif
}

void BusFault_Handler(void)//??????
{
FTM_PWM_ChangeDuty(FTM0_CH3_PA6,0);
FTM_PWM_ChangeDuty(FTM0_CH4_PA7,0);

#if(CHIP_DEBUG==ON)	
wait();
#endif
}

void UsageFault_Handler(void)//??????
{
FTM_PWM_ChangeDuty(FTM0_CH3_PA6,0);
FTM_PWM_ChangeDuty(FTM0_CH4_PA7,0);


#if(CHIP_DEBUG==ON)	
wait();
#endif
}