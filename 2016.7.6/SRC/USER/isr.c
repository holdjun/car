#include "isr.h"
#include "dma.h"
#include "led.h"
#include "oled.h"
#include "ftm.h"

extern uint8_t DMA_Value0 = 0,DMA_Value1 = 0 ,speed_num = 0, FTMDuty = 0;

void PIT0_IRQHandler(void)
{
	DMA_Value0 = DMACNT_GetValue(DMA_CH0);
	DMA_Value1 = DMACNT_GetValue(DMA_CH1);
	UART_printf("DMACNT_CH0_Value:%d ",DMA_Value0);
	UART_printf("DMACNT_CH1_Value:%d\r\n",DMA_Value1);
	PIT_ClearITPendingBit(PIT0,PIT_IT_TIF);
	speed_num = FTMDuty/100;
	OLED_Write_String(2,2,"speed");
	OLED_Write_Num3(4,4,speed_num);
	FTM_PWM_ChangeDuty(FTM1_CH1_PB1,FTMDuty); //FTMDUTY±ä»¯
}
