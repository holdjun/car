#include "isr.h"
#include "oled.h"
extern unsigned char j;
void PIT0_IRQHandler(void)
{ 
	PIT_ClearITPendingBit(PIT0,PIT_IT_TIF);
	//OLED_Clear();
}

void UART4_RX_TX_IRQHandler(void)
{
	uint8_t ch;
	if(UART_ReceiveData(UART4,&ch))
	{
		UART_SendData(UART4,ch+1);
	}
}


