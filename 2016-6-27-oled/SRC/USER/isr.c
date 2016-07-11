#include "isr.h"


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


