#include "isr.h"

#include "led.h"


void UART4_RX_TX_IRQHandler(void)
{
	uint8_t ch;
	//中断发送处理过程
	UART_SendDataIntProcess(UART4);
	//如果成功接收到了数据
	if(UART_ReceiveData(UART4,&ch))
	{
		//把接收到的信息发送回去
		UART_SendData(UART4,ch);
	}
}

void PIT0_IRQHandler(void)
{
	UART_printf("PIT0 Int\r\n");
	LED2 = !LED2;
	PIT_ClearITPendingBit(PIT0,PIT_IT_TIF);
}

void PORTB_IRQHandler(void)
{
	
	LED4 = !LED4;
	GPIO_ClearITPendingBit(PTB,GPIO_Pin_9);
}

uint16_t TSIStatues = TRUE;    //记录上次的状态
void TSI0_IRQHandler(void)
{
	uint16_t Status = 0;
	Status = TSI_GetChannelOutOfRangleFlag(TSI0,TSI0_CH5);
	if((Status == TRUE) && (TSIStatues == FALSE))
	{
		LED3 = !LED3;
		UART_printf("TSI EnterInt \r\n");
	}
		TSIStatues = Status; //记录上次状态
	TSI_ClearAllITPendingFlag(TSI0);
	
}


void LPTimer_IRQHandler(void)
{
	UART_printf("!!\r\n");
	LPTM_ClearITPendingBit(LPTMR0,LPTM_IT_TCF);
}
