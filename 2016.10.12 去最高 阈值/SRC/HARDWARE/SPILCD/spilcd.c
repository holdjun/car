//*******************************************************************************	 
//硬件    :超核电子Kinetis核心板 V2.2
//处理器  :K10DN512VLL10  K60X256VLL10
//作者    :YANDLD @ UPC
//E-MAIL  :yandld@126.com
//修改日期:2012/6/10
//版本：V2.2
//淘宝：http://upcmcu.taobao.com
//论坛: http://www.tinychip.net
//Copyright(C) YANDLD 2012-2022
//All rights reserved
//********************************************************************************
#include "spilcd.h"
#include "delay.h"
#include "font.h"
#if (SPILCD_HARDWARE_SUPPORT ==1)
#include "spi.h"
#endif

//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//SPILCD DRIVER  LV0层    ----   LV0 实现初始化 以下函数
// 写一字节数据
// 写一字节命令
// 开始写GRAM命令
// 写GRAM数据
// 硬件初始化
// 开显示
// 关显示
// 定义前景色，背景色
//设置Windows
//反色显示

//前景色 背景色
uint16_t POINT_COLOR = WHITE,BACK_COLOR = BLACK;  
//函数名：SPILCD_WR_REG
//参  数：无
//        实现写入一字节命令
void SPILCD_WR_REG(uint8_t com)
{
#if (SPILCD_HARDWARE_SUPPORT==0 ) //软访模式
	SPILCD_RS=0;
	SPILCD_CS=0; 

	SPILCD_SDA=((com>>7)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((com>>6)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((com>>5)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((com>>4)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((com>>3)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((com>>2)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((com>>1)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((com>>0)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_CS=1; 	
#elif (SPILCD_HARDWARE_SUPPORT == 1) //硬件SPI支持
	SPILCD_RS=0;
	SPI_ReadWriteByte(SPI0_PCS0_PA14,com,SPI_PCS_Inactive);
#endif
}
//函数名：LCD_WR_REG
//参  数：无
//        实现写入一字节数据
void SPILCD_WR_DATA(uint8_t dat)
{
#if (SPILCD_HARDWARE_SUPPORT==0 ) //软访模式
	SPILCD_RS=1;
	SPILCD_CS=0; 

	SPILCD_SDA=((dat>>7)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((dat>>6)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((dat>>5)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((dat>>4)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((dat>>3)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((dat>>2)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((dat>>1)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_SDA=((dat>>0)&1);SPILCD_SCL=0;SPILCD_SCL=1;
	SPILCD_CS=1; 	
#elif (SPILCD_HARDWARE_SUPPORT == 1) //硬件SPI支持
	SPILCD_RS=1;
	SPI_ReadWriteByte(SPI0_PCS0_PA14,dat,SPI_PCS_Inactive);
#endif
}
//函数名：LCD_WR_REG
//参  数：无
//        准备开始写入GRAM
__inline void SPILCD_WriteRAM_Prepare(void)
{
	SPILCD_WR_REG(0x2c);   //写RAM
}	 

//函数名：LCD_WR_REG
//参  数：无
//        写GRAM数据
void SPILCD_WriteRAM(uint16_t RGB_Code)
{							    
    SPILCD_WR_DATA(RGB_Code>>8);
    SPILCD_WR_DATA(RGB_Code); 
}
//函数名：LCD_DisplayOn
//参  数：无
//        开启显示
void LCD_DisplayOn(void)
{					   
    SPILCD_WR_REG(0x29);   //
}	 
//函数名：LCD_DisplayOff
//参  数：无
//        关闭显示
void LCD_DisplayOff(void)
{	   
    SPILCD_WR_REG(0x28);   //
}   
//函数名：LCD_SetWindow
//参  数：Xpos:横坐标
//				Ypos:纵坐标
__inline void SPILCD_SetWindow(uint16_t xstat,uint16_t xend,uint16_t ystat,uint16_t yend)
{
	SPILCD_WR_REG(0x2A);
   SPILCD_WR_DATA(xstat>>8);
   SPILCD_WR_DATA(xstat);
   SPILCD_WR_DATA(xend>>8);
   SPILCD_WR_DATA(xend);
  
   SPILCD_WR_REG(0x2B);
   SPILCD_WR_DATA(ystat>>8);
   SPILCD_WR_DATA(ystat);
   SPILCD_WR_DATA(yend>>8);
	SPILCD_WR_DATA(yend);
}
//开启反色显示
void LCD_InvDisplayOn()
{
  SPILCD_WR_REG(0x21);  
}
//关闭反色显示
void LCD_InvDisplayOff()
{
  SPILCD_WR_REG(0x20); 
}   

//函数名：SPILCD_Init
//参  数：无
//        LCD 硬件初始化
void SPILCD_Init()
{
	SPI_InitTypeDef SPI_InitStruct1;

	/*
	#if (SPILCD_HARDWARE_SUPPORT==0 )    //软访模式
		GPIO_Init(SPILCD_CS_PORT,SPILCD_CS_PIN,GPIO_Mode_Out_PP,Bit_SET,GPIO_IRQC_DISABLE);
		GPIO_Init(SPILCD_RST_PORT,SPILCD_RST_PIN,GPIO_Mode_Out_PP,Bit_SET,GPIO_IRQC_DISABLE);
		GPIO_Init(SPILCD_SDA_PORT,SPILCD_SDA_PIN,GPIO_Mode_Out_PP,Bit_SET,GPIO_IRQC_DISABLE);
		GPIO_Init(SPILCD_SCL_PORT,SPILCD_SCL_PIN,GPIO_Mode_Out_PP,Bit_SET,GPIO_IRQC_DISABLE);
		GPIO_Init(SPILCD_RS_PORT,SPILCD_RS_PIN,GPIO_Mode_Out_PP,Bit_SET,GPIO_IRQC_DISABLE);
	#elif (SPILCD_HARDWARE_SUPPORT==1)   //硬件SPI模式
		GPIO_Init(SPILCD_RST_PORT,SPILCD_RST_PIN,GPIO_Mode_Out_PP,Bit_SET,GPIO_IRQC_DISABLE);
		GPIO_Init(SPILCD_RS_PORT,SPILCD_RS_PIN,GPIO_Mode_Out_PP,Bit_SET,GPIO_IRQC_DISABLE);
	
		SPI_InitStruct1.SPIxDataMap = SPI0_SCK_PA15_SOUT_PA16_SIN_PA17;
		SPI_InitStruct1.SPIxPCSMap = SPI0_PCS0_PA14;
		SPI_InitStruct1.SPI_DataSize = 8;
		SPI_InitStruct1.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
		SPI_InitStruct1.SPI_Mode = SPI_Mode_Master;
		SPI_InitStruct1.SPI_CPHA = SPI_CPHA_1Edge;
		SPI_InitStruct1.SPI_CPOL = SPI_CPOL_Low;
		SPI_InitStruct1.SPI_FirstBit = SPI_FirstBit_MSB;
		SPI_Init(&SPI_InitStruct1);
	
	#endif
		*/
	SPILCD_RST=1;
	DelayMs (1); //Delay 1ms
	SPILCD_RST=0;
	DelayMs (1); //Delay 1ms
	SPILCD_RST=1;
	DelayMs (120); //Delay 120ms
	SPILCD_WR_REG(0x11);//Sleep out
	DelayMs(120);
	//ST7735R Frame Rate
	SPILCD_WR_REG(0xB1);
	SPILCD_WR_DATA(0x01);
	SPILCD_WR_DATA(0x2C);
	SPILCD_WR_DATA(0x2D);
	SPILCD_WR_REG(0xB2);
	SPILCD_WR_DATA(0x01);
	SPILCD_WR_DATA(0x2C);
	SPILCD_WR_DATA(0x2D);
	SPILCD_WR_REG(0xB3);
	SPILCD_WR_DATA(0x01);
	SPILCD_WR_DATA(0x2C);
	SPILCD_WR_DATA(0x2D);
	SPILCD_WR_DATA(0x01);
	SPILCD_WR_DATA(0x2C);
	SPILCD_WR_DATA(0x2D);
	//------------------------------------End ST7735R Frame Rate-----------------------------------------//
	SPILCD_WR_REG(0xB4);//Column inversion
	SPILCD_WR_DATA(0x07);
	//------------------------------------ST7735R Power Sequence-----------------------------------------//
	SPILCD_WR_REG(0xC0);
	SPILCD_WR_DATA(0xA2);
	SPILCD_WR_DATA(0x02);
	SPILCD_WR_DATA(0x84);
	SPILCD_WR_REG(0xC1);
	SPILCD_WR_DATA(0xC5);
	SPILCD_WR_REG(0xC2);
	SPILCD_WR_DATA(0x0A);
	SPILCD_WR_DATA(0x00);
	SPILCD_WR_REG(0xC3);
	SPILCD_WR_DATA(0x8A);
	SPILCD_WR_DATA(0x2A);
	SPILCD_WR_REG(0xC4);
	SPILCD_WR_DATA(0x8A);
	SPILCD_WR_DATA(0xEE);
	//---------------------------------End ST7735R Power Sequence-------------------------------------//
	SPILCD_WR_REG(0xC5);//VCOM
	SPILCD_WR_DATA(0x0E);
	SPILCD_WR_REG(0x36);//MX, MY, RGB mode
	SPILCD_WR_DATA(0xC8);
	//------------------------------------ST7735R Gamma Sequence-----------------------------------------//
	SPILCD_WR_REG(0xe0);
	SPILCD_WR_DATA(0x02);
	SPILCD_WR_DATA(0x1c);
	SPILCD_WR_DATA(0x07);
	SPILCD_WR_DATA(0x12);
	SPILCD_WR_DATA(0x37);
	SPILCD_WR_DATA(0x32);
	SPILCD_WR_DATA(0x29);
	SPILCD_WR_DATA(0x2d);
	SPILCD_WR_DATA(0x29);
	SPILCD_WR_DATA(0x25);
	SPILCD_WR_DATA(0x2b);
	SPILCD_WR_DATA(0x39);
	SPILCD_WR_DATA(0x00);
	SPILCD_WR_DATA(0x01);
	SPILCD_WR_DATA(0x03);
	SPILCD_WR_DATA(0x10);
	SPILCD_WR_REG(0xe1);
	SPILCD_WR_DATA(0x03);
	SPILCD_WR_DATA(0x1d);
	SPILCD_WR_DATA(0x07);
	SPILCD_WR_DATA(0x06);
	SPILCD_WR_DATA(0x2e);
	SPILCD_WR_DATA(0x2c);
	SPILCD_WR_DATA(0x29);
	SPILCD_WR_DATA(0x2d);
	SPILCD_WR_DATA(0x2e);
	SPILCD_WR_DATA(0x2e);
	SPILCD_WR_DATA(0x37);
	SPILCD_WR_DATA(0x3f);
	SPILCD_WR_DATA(0x00);
	SPILCD_WR_DATA(0x00);
	SPILCD_WR_DATA(0x02);
	SPILCD_WR_DATA(0x10);
	SPILCD_WR_REG(0x2A);
	SPILCD_WR_DATA(0x00);
	SPILCD_WR_DATA(0x02);
	SPILCD_WR_DATA(0x00);
	SPILCD_WR_DATA(0x81);
  
	SPILCD_WR_REG(0x2B);
	SPILCD_WR_DATA(0x00);
	SPILCD_WR_DATA(0x01);
	SPILCD_WR_DATA(0x00);
	SPILCD_WR_DATA(0xA0);
	//------------------------------------End ST7735R Gamma Sequence-----------------------------------------//
	SPILCD_WR_REG(0x3A); 
	SPILCD_WR_DATA(0x05);  
	//SPILCD_WR_REG(0x3A);//65k mode
	//LCD_WR_DATA(0x05);
	SPILCD_WR_REG(0x29);//Display on
	SPILCD_Clear(BACK_COLOR);
}

//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//SPILCD DRIVER  LV1层    ----   LV1 在LV0的基础上实现
//打点
//清屏
//填充
//画线
//矩形边框
//画园

//函数名：SPILCD_Init
//参  数：X Y 坐标 
//        在X Y上打点
void SPILCD_DrawPoint(uint16_t x,uint16_t y)
{
  SPILCD_SetWindow(x,x+1,y,y+1);//设置光标位置 
	SPILCD_WriteRAM_Prepare();     //开始写入GRAM	 
	SPILCD_WriteRAM(POINT_COLOR);
} 	 

//函数名：SPILCD_Clear
//参  数：Color 颜色      
void SPILCD_Clear(uint16_t Color)
{
	uint32_t index=0;      
	SPILCD_SetWindow(0,SPILCD_W-1,0,SPILCD_H-1);	 
	SPILCD_WriteRAM_Prepare();     //开始写入GRAM	 	  
	for(index=0;index<SPILCD_W*SPILCD_H;index++)
	{
		SPILCD_WriteRAM(Color);//显示所填充的颜色. 
	}
}  
//函数名：SPILCD_Fill
//参  数：起始终点坐标
void SPILCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color)
{                    
	uint32_t n;
	//设置窗口										
  SPILCD_SetWindow(xsta,xend,ysta,yend);
	SPILCD_WriteRAM_Prepare();  //开始写入GRAM	 	   	   
	n=(uint32_t)(yend-ysta+1)*(xend-xsta+1);    
	while(n--){SPILCD_WriteRAM(color);}//显示所填充的颜色. 
	//恢复设置
	SPILCD_SetWindow(0,SPILCD_W-1,0,SPILCD_H-1);	    
}
//函数名：SPILCD_DrawLine
//参  数：起始终点坐标
void SPILCD_DrawLine(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	uint16_t t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 
	delta_x=x2-x1; //计算坐标增量 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //设置单步方向 
	else if(delta_x==0)incx=0;//垂直线 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//水平线 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//画线输出 
	{  
		SPILCD_DrawPoint(uRow,uCol);//画点 
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
} 
//函数名：SPILCD_DrawRectangle
//参  数：起始终点坐标
void SPILCD_DrawRectangle(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	SPILCD_DrawLine(x1,y1,x2,y1);
	SPILCD_DrawLine(x1,y1,x1,y2);
	SPILCD_DrawLine(x1,y2,x2,y2);
	SPILCD_DrawLine(x2,y1,x2,y2);
}
//函数名：SPIDraw_Circle
//参  数：
//(x,y):中心点
//r    :半径
void SPIDraw_Circle(uint16_t x0,uint16_t y0,uint8_t r)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //判断下个点位置的标志
	while(a<=b)
	{
		SPILCD_DrawPoint(x0-b,y0-a);             //3           
		SPILCD_DrawPoint(x0+b,y0-a);             //0           
		SPILCD_DrawPoint(x0-a,y0+b);             //1       
		SPILCD_DrawPoint(x0-b,y0-a);             //7           
		SPILCD_DrawPoint(x0-a,y0-b);             //2             
		SPILCD_DrawPoint(x0+b,y0+a);             //4               
		SPILCD_DrawPoint(x0+a,y0-b);             //5
		SPILCD_DrawPoint(x0+a,y0+b);             //6 
		SPILCD_DrawPoint(x0-b,y0+a);             
		a++;
		//使用Bresenham算法画圆     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 
		SPILCD_DrawPoint(x0+a,y0+b);
	}
}
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//SPILCD DRIVER  LV2层    ----   LV1 在LV0的基础上实现
//单字符显示
//字符串显示
//数字显示

//函数名：SPILCD_ShowChar
//参  数：
//(x,y): 
//num:要显示的字符:" "--->"~"
//size:字体大小 12/16
//mode:叠加方式(1)还是非叠加方式(0)
void SPILCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t font,uint8_t mode)
{       
	uint8_t temp;
	uint8_t pos,t;  
	uint8_t size; 
	size=fontsizetable[font];	//找到字体大小
  if(x>(SPILCD_W-size/2)||y>(SPILCD_H-size))return;	    
	//设置窗口	
	SPILCD_SetWindow(x,x+size/2-1,y,y+size-1);									
	SPILCD_WriteRAM_Prepare();        //开始写入GRAM	   
	num=num-' ';//得到偏移后的值
	
	if(!mode) //非叠加方式
	{	
		for(pos=0;pos<size;pos++)
		{
			if(font==ASCII1206)temp=asc2_1206[num][pos];//调用1206字体
			else if(font==ASCII1608) temp=asc2_1608[num][pos];		 //调用1608字体
			else	 temp=asc2_1608c[num][pos];	//调通调用艺术字体
			for(t=0;t<size/2;t++)
		   {                 
		        if(temp&0x01)
				{
					SPILCD_WriteRAM(POINT_COLOR);
				}else SPILCD_WriteRAM(BACK_COLOR);	        
		        temp>>=1; 
		    }
		}	
	}
	else//叠加方式
	
	{
		for(pos=0;pos<size;pos++) //按行打出 一共size个行
		{
			if(font==ASCII1206)temp=asc2_1206[num][pos];//调用1206字体
			else if(font==ASCII1608) temp=asc2_1608[num][pos];		 //调用1608字体
			else	 temp=asc2_1608c[num][pos];	//调通调用艺术字体
			for(t=0;t<(size/2);t++)  //打印每行
		   {     
		        if((temp>>t)&0x01)
						{
							SPILCD_DrawPoint(x+t,y+pos);//画一个点  
						}	
		   }
		}
	}	    
	//恢复窗体大小	 
	SPILCD_SetWindow(0,SPILCD_W-1,0,SPILCD_H-1);	 
}  
//m^n函数
uint32_t mypow(uint8_t m,uint8_t n)
{
	uint32_t result=1;	 
	while(n--)result*=m;    
	return result;
}			 


//函数名：SPILCD_ShowNum
//参  数：
//(x,y): 
//num:要显示的字符:" "--->"~"
//len :数字的位数
//size:字体大小
//num:数值(0~4294967295);	 
void SPILCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t font)
{         	
	uint8_t t,temp;
	uint8_t enshow=0;
	uint8_t size;
	size=fontsizetable[font];						   
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				SPILCD_ShowChar(x+(size/2)*t,y,' ',font,0);
				continue;
			}else enshow=1; 
		 	 
		}
	 	SPILCD_ShowChar(x+(size/2)*t,y,temp+'0',font,0); 
	}
} 
//函数名：LCD_ShowString
//参  数：
//x,y:起点坐标  
//*p:字符串起始地址
//用16字体
void LCD_ShowString(uint16_t x,uint16_t y,const char *p)
{         	 
    while(*p!='\0')
    {       
        if(x>(SPILCD_W-fontsizetable[ASCII1206]/2)){x=0;y+=fontsizetable[ASCII1206];}
        if(y>(SPILCD_H-fontsizetable[ASCII1206])){y=x=0;SPILCD_Clear(BACK_COLOR);}
        SPILCD_ShowChar(x,y,*p,ASCII1206,1);
        x+=fontsizetable[ASCII1206]/2;
        p++;
    }  
}





