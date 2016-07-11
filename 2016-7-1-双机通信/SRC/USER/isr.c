#include "isr.h"
#include "oled.h"
extern  uint8_t ch,i,j;
void PIT0_IRQHandler(void)
{ 
}

void UART0_RX_TX_IRQHandler(void)
{
	//如果成功接收到了数据
	if(UART_ReceiveData(UART0,&ch))
	{
		if(ch==0){
		OLED_Write_Char(0,0,ch);
		}
		if(ch==1){
		OLED_Write_Char(0,2,ch);
		}
		if(ch==2){
		OLED_Write_Char(0,4,ch);
		}
		if(ch==3){
		OLED_Write_Char(0,6,ch);
		}
		if(ch==4){
		OLED_Write_Char(2,0,ch);
		}
	}
	
	if(!UART_ReceiveData(UART0,&ch))
	{
		OLED_Write_Char(2,2,ch);
	}
}