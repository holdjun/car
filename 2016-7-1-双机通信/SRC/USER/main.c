#include "sys.h"
#include "gpio.h"
#include "delay.h"
#include "led.h"
#include "uart.h"
#include "wdog.h"
#include "pit.h"
#include "rtc.h"
#include "dma.h"
#include "ftm.h"
#include "lptm.h"
#include "adc.h"
#include "dac.h"
#include "tsi.h"
#include "spi.h"
#include "enet.h"
#include "i2c.h"
#include "pdb.h"
#include "can.h"
#include "sd.h"
#include "flash.h"
#include "spiflash.h"
#include "spilcd.h"
#include "stdio.h"
#include "mma845x.h"
#include "oled.h"
uint8_t ch,i,j;
int main(void)
{
		UART_InitTypeDef UART_InitStruct1; 
		UART_InitStruct1.UARTxMAP= UART0_RX_PA14_TX_PA15; 
		UART_InitStruct1.UART_BaudRate=115200;
		UART_Init(&UART_InitStruct1);
		UART_ITConfig(UART0,UART_IT_RDRF, ENABLE);
	  NVIC_EnableIRQ(UART0_RX_TX_IRQn);	
		OLED_Init();
	while(1){
		//UART_SendData(UART0,1);
		//OLED_Write_Char(2,2,ch);
		//UART_SendData(UART0,'x');
		//UART_Send_String(UART0,"abcdefg");
	}
}



void assert_failed(uint8_t* file, uint32_t line)
{
	UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}


