#include "sys.h"
#include "gpio.h"
#include "delay.h"
#include "led.h"
#include "wdog.h"
#include "pit.h"
#include "dma.h"
#include "ftm.h"
#include "lptm.h"
#include "key.h"
#include "adc.h"
#include "tsi.h"
#include "dac.h"
#include "spi.h"
#include "i2c.h"
#include "pdb.h"
#include "sd.h"
#include "flash.h"
#include "spilcd.h"
#include "stdio.h"
#include "nrf2401.h"
#include "uart.h"
#include "mma845x.h"


uint8_t NRF2401TXBuffer[TX_PLOAD_WIDTH] = "NRF2401 TestData:KEY ";
uint8_t NRF2401RXBuffer[RX_PLOAD_WIDTH];
uint8_t ScanTimeFlag = FALSE;  //10MS扫描周期标志
int main(void)
{
	uint8_t key_res = 0;
	PIT_InitTypeDef PIT_InitStruct1;
	//初始化系统时钟 使用外部50M晶振 PLL倍频到100M
	SystemClockSetup(ClockSource_EX50M,CoreClock_100M);
	//初始化默认的调试串口
	UART_DebugPortInit(UART2_RX_D2_TX_D3,115200);
	//打印MCU信息
	DisplayCPUInfo();
	//初始化延时模块
	DelayInit();
	//初始化LED
	LED_Init();
  //初始化SPILCD
	SPILCD_Init();
	//OLED初始化
	OLED_Clear();
	OLED_Init();
	//初始化按键
	KEY_Init();
	//设置一个10MS定时器用于扫描按键
	PIT_InitStruct1.PITx = PIT0;
	PIT_InitStruct1.PIT_Interval = 10;
	PIT_Init(&PIT_InitStruct1);
	PIT_ITConfig(PIT0,PIT_IT_TIF,ENABLE);
	NVIC_EnableIRQ(PIT0_IRQn);
	//初始化NRF24L01
	if(NRF2401_Init() == NRF_OK)
	{
		LED2 = 1;
		UART_printf("NREF2401 初始化成功\r\n");
		OLED_Write_Char(4,4,1);
	}
	else
	{
		UART_printf("NREF2401 初始化失败\r\n");
	}
//	//先设置为接收模式
//	NRF2401_SetRXMode(); 
	while(1)
	{
//		if(ScanTimeFlag == TRUE)
//		{
//			key_res =KEY_Scan();
//			ScanTimeFlag = FALSE;
//		}
//		switch(key_res) //保证Key_Scan以大约100HZ的频率被调用
//		{
//			case KEY_NO_KEY: //无键
//				break;
//			case KEY_SINGLE: //单击
				NRF2401_SetTXMode();
				NRF2401TXBuffer[20] = '1';
				if(NRF2401_SendData(NRF2401TXBuffer) == TX_OK)
				{
					UART_printf("成功发送\r\n");
					OLED_Write_Char(6,6,3);
				}
				else
				{
					UART_printf("发送失败\r\n");
				}
				DelayMs(300);
				
//				NRF2401_SetRXMode();
//				key_res = KEY_NO_KEY;
//				break;
//			case KEY_DOUBLE: //双击
//				NRF2401_SetTXMode();
//				NRF2401TXBuffer[20] = '2';
//				if(NRF2401_SendData(NRF2401TXBuffer) == TX_OK)
//				{
//					UART_printf("发送成功\r\n");
//				}
//				else
//				{
//					UART_printf("发送失败\r\n");
//				}
//				NRF2401_SetRXMode(); 
//				key_res = KEY_NO_KEY;
//				break;
//			case KEY_LONG:  //长按
//				NRF2401_SetTXMode();
//				NRF2401TXBuffer[20] = '3';
//				if(NRF2401_SendData(NRF2401TXBuffer) == TX_OK)
//				{
//					UART_printf("发送成功\r\n");
//				}
//				else
//				{
//					UART_printf("发送失败\r\n");
//				}
//				NRF2401_SetRXMode(); 
//				key_res = KEY_NO_KEY;
//				break;
//			default:break;
//		}	
//		//接收
//		if(NRF2401_RecData(NRF2401RXBuffer) == NRF_OK) //接收到了数据
//		{
//			UART_printf("接收到数据数据:%s\r\n",NRF2401RXBuffer);
//		}
	}
}


void assert_failed(uint8_t* file, uint32_t line)
{
	//断言失败检测
	UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}

