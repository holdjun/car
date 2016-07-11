#include "isr.h"
extern  uint8_t ch,i,j;
void PIT0_IRQHandler(void)
{ 
}

void UART0_RX_TX_IRQHandler(void)
{
	//UART_SendDataIntProcess(UART0);
	if(i==0&&UART_ReceiveData(UART0,&ch)==1){
	switch(ch)
	{
		case 0x01:UART_Send_String(UART0,"A.USA");UART_SendData(UART0,13);UART_Send_String(UART0,"B.banama");UART_SendData(UART0,13);UART_Send_String(UART0,"C.hanguo");UART_SendData(UART0,13);i=1;break;
		case 0x02:UART_Send_String(UART0,"error");UART_SendData(UART0,13);break;
		case 0x03:UART_Send_String(UART0,"error");UART_SendData(UART0,13);break;
		default:UART_Send_String(UART0,"error");UART_SendData(UART0,13);break;
	}
}
	if(i==1&&UART_ReceiveData(UART0,&ch)==1){
	switch(ch)
	{
		case 0x02:UART_Send_String(UART0,"A.jianada");UART_SendData(UART0,13);UART_Send_String(UART0,"B.yiselie");UART_SendData(UART0,13);UART_Send_String(UART0,"C.gelujiya");UART_SendData(UART0,13);i=2;break;
		case 0x01:UART_Send_String(UART0,"error");UART_SendData(UART0,13);break;
		case 0x03:UART_Send_String(UART0,"error");UART_SendData(UART0,13);break;
		default:UART_Send_String(UART0,"error");UART_SendData(UART0,13);break;
	}
}
	if(i==2&&UART_ReceiveData(UART0,&ch)==1){
	switch(ch)
	{
		case 0x03:UART_Send_String(UART0,"Gongxi!!");break;
		case 0x02:UART_Send_String(UART0,"error");UART_SendData(UART0,13);break;
		case 0x01:UART_Send_String(UART0,"error");UART_SendData(UART0,13);break;
		default:UART_Send_String(UART0,"error");UART_SendData(UART0,13);break;
	}
}
}


