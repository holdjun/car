#include "isr.h"
#include "oled.h"
extern unsigned char j,m,ms,s;
void PIT0_IRQHandler(void)
{ 
	PIT_ClearITPendingBit(PIT0,PIT_IT_TIF);
	++ms;
	if(ms==100){
		s++;
		ms=0;
	}
	if(s==60){
		m++;
		s=0;
	}
	if(m==60){
		m=0;
	}
}

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
