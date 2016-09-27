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
#include "oled.h"
#include "flash.h"
#include "spilcd.h"
#include "stdio.h"
#include "nrf2401.h"
#include "uart.h"
#include "mma845x.h"

const unsigned char qipan3[518] = { 
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};

uint8_t NRF2401TXBuffer[TX_PLOAD_WIDTH] = "NRF2401 TestData:KEY ";
uint8_t NRF2401RXBuffer[RX_PLOAD_WIDTH];
uint8_t ScanTimeFlag = FALSE;  //10MS扫描周期标志
unsigned char DATA[]="SUCCEED";
int main(void)
{
	int amd[3][3]={0},x=0,y=0,sum=0,flag=0;
	//初始化系统时钟 使用外部50M晶振 PLL倍频到100M
	SystemClockSetup(ClockSource_EX50M,CoreClock_100M);
	//初始化默认的调试串口
	UART_DebugPortInit(UART2_RX_D2_TX_D3,115200);
	//打印MCU信息RX_B10_TX_B11
	DisplayCPUInfo();
	//初始化延时模块
	OLED_Init();
	DelayInit();
	SPILCD_Init();
	//NVIC_EnableIRQ(PIT0_IRQn);
	//初始化NRF24L01
	if(NRF2401_Init() == NRF_OK) UART_printf("NREF2401 初始化成功\r\n");
	else                         UART_printf("NREF2401 初始化失败\r\n");

	NRF2401_SetRXMode(); 

	while(1)
	{
		OLED_Write_Picture(64,64,qipan3);
		OLED_Write_Char(x,y,43);	
		//显示棋盘,按键；
		if(NRF2401_RecData(NRF2401RXBuffer) == NRF_OK) 
			{
				UART_printf("接收到数据数据:%s\r\n",NRF2401RXBuffer);
				if(NRF2401RXBuffer[0]	==	'w')										// w,a,s,d，按键的移动;
					{
						if(amd[x/3][y/3] == 0) OLED_Write_Char(x,y,36);
						if(amd[x/3][y/3] == 1) OLED_Write_Char(x,y,'X');
						if(amd[x/3][y/3] == 2) OLED_Write_Char(x,y,'O');
						y += 3;
						if(y==9) y=0;
						OLED_Write_Char(x,y,43);
					}
				if(NRF2401RXBuffer[0]	== 	'a')
					{
						if(amd[x/3][y/3] == 0) OLED_Write_Char(x,y,36);
						if(amd[x/3][y/3] == 1) OLED_Write_Char(x,y,'X');
						if(amd[x/3][y/3] == 2) OLED_Write_Char(x,y,'O');
						x -= 3;
						if(x==-3) x=6;
						OLED_Write_Char(x,y,43);
					}
				if(NRF2401RXBuffer[0]	==	's')
					{
						if(amd[x/3][y/3] == 0) OLED_Write_Char(x,y,36);
						if(amd[x/3][y/3] == 1) OLED_Write_Char(x,y,'X');
						if(amd[x/3][y/3] == 2) OLED_Write_Char(x,y,'O');
						y -= 3;
						if(y==-3) y=6;
						OLED_Write_Char(x,y,43);
					}
				if(NRF2401RXBuffer[0]	==	'd')
					{
						if(amd[x/3][y/3] == 0) OLED_Write_Char(x,y,36);
						if(amd[x/3][y/3] == 1) OLED_Write_Char(x,y,'X');
						if(amd[x/3][y/3] == 2) OLED_Write_Char(x,y,'O');
						x += 3;
						if(x==9) x=0;
						OLED_Write_Char(x,y,43);
					}
				if(NRF2401RXBuffer[0]	==	'j')									//j,k确定 取消；
						{
							flag = !flag;
							sum++;
							if(flag) amd[x/3][y/3] = 1;
							else     amd[x/3][y/3] = 2;
						}
				if(NRF2401RXBuffer[0]	==	'k')
						{
							sum=0; x=0; y=0;
							OLED_Clear();
							OLED_Write_Picture(64,64,qipan3);
							OLED_Write_Char(x,y,43);
  						memset(amd,0, 3*3*sizeof(int) );
						}
			}
			
			else UART_printf("失败\r\n");
			
			if(amd[2][0]==1 && amd[2][0]==amd[1][1] && amd[1][1]==amd[0][2] ) {   				 //规则
				OLED_Clear();
				OLED_Write_String(5,2,"X,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[0][0]==1 && amd[0][0]==amd[0][1] && amd[0][1]==amd[0][2] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"X,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[1][0]==1 && amd[1][0]==amd[1][1] && amd[1][1]==amd[1][2] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"X,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[2][0]==1 && amd[2][0]==amd[2][1] && amd[2][1]==amd[2][2] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"X,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[0][0]==1 && amd[0][0]==amd[1][0] && amd[1][0]==amd[2][0] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"X,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[0][1]==1 && amd[0][1]==amd[1][1] && amd[1][1]==amd[2][1] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"X,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[0][2]==1 && amd[0][2]==amd[1][2] && amd[1][2]==amd[2][2] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"X,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[0][0]==1 && amd[0][0]==amd[1][1] && amd[1][1]==amd[2][2] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"X,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[2][0]==2 && amd[2][0]==amd[1][1] && amd[1][1]==amd[0][2] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"O,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[0][0]==2 && amd[0][0]==amd[0][1] && amd[0][1]==amd[0][2] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"O,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[1][0]==2 && amd[1][0]==amd[1][1] && amd[1][1]==amd[1][2] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"O,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[2][0]==2 && amd[2][0]==amd[2][1] && amd[2][1]==amd[2][2] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"O,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[0][0]==2 && amd[0][0]==amd[1][0] && amd[1][0]==amd[2][0] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"O,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[0][1]==2 && amd[0][1]==amd[1][1] && amd[1][1]==amd[2][1] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"O,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[0][2]==2 && amd[0][2]==amd[1][2] && amd[1][2]==amd[2][2] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"O,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(amd[0][0]==2 && amd[0][0]==amd[1][1] && amd[1][1]==amd[2][2] ) { 
				OLED_Clear();
				OLED_Write_String(5,2,"O,win");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
				}
			else if(sum==9){
				OLED_Clear();
				OLED_Write_String(5,2,"pingju");
				while(NRF2401_RecData(NRF2401RXBuffer) != NRF_OK);
			}
		}
	}



void assert_failed(uint8_t* file, uint32_t line)
{
	//断言失败检测
	UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}

