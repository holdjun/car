#include "isr.h"
#include "dma.h"
#include "led.h"
#include "oled.h"

extern uint32_t pid_out,Pid_Set;
extern uint32_t *Pid_Out;
uint32_t DMA_Value0;
void printd( unsigned char ch )
{
		UART_SendData(UART0,ch);
}
void sci_dis(signed int ch0, signed int ch1, signed int ch2)
{
printd ((ch0+4000)/90+' ');
printd ((ch0+4000)%90+' ');
printd ((ch1+4000)/90+' ');
printd ((ch1+4000) %90+' ');
printd ((ch2+4000)/90+' ');
printd ((ch2+4000) %90+' ');
}
//void UART4_RX_TX_IRQHandler(void)
//{
//	uint8_t ch;
//	UART_SendDataIntProcess(UART4);
//	sci_dis(100,200,0);
//	if(UART_ReceiveData(UART4,&ch)) UART_SendData(UART4,ch);
//}

void PIT2_IRQHandler(void)
{
	PIT_ClearITPendingBit(PIT2,PIT_IT_TIF);
	*Pid_Out= DMACNT_GetValue(DMA_CH0)*6;
	sci_dis(*Pid_Out,2500,2400);
	//UART_printf("DMACNT_CH0_Value:%d \n",*Pid_Out);
}

void PIT0_IRQHandler(void)
{
	PIT_ClearITPendingBit(PIT0,PIT_IT_TIF);
	Pid_Set+=1000;
}


void LPTimer_IRQHandler(void)
{
	UART_printf("!!\r\n");
	LPTM_ClearITPendingBit(LPTMR0,LPTM_IT_TCF);
}
