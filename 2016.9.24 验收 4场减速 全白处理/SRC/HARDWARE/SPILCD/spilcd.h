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
#ifndef __SPILCD_H__
#define __SPILCD_H__
#include "sys.h"
#include "gpio.h"


#define SPILCD_HARDWARE_SUPPORT  (1)
//是否使用硬件SPI驱动加速 需要SPI构件的支持

//SPILCD驱动头文件
//端口宏定义
#define SPILCD_CS_PORT    PTA
#define SPILCD_SDA_PORT   PTA
#define SPILCD_SCL_PORT   PTA
#define SPILCD_RS_PORT    PTE
#define SPILCD_RST_PORT   PTA

#define SPILCD_CS_PIN    14
#define SPILCD_SDA_PIN   16
#define SPILCD_SCL_PIN   15
#define SPILCD_RS_PIN    24
#define SPILCD_RST_PIN   13

#define SPILCD_CS     PAout(SPILCD_CS_PIN)
#define SPILCD_SDA    PAout(SPILCD_SDA_PIN)
#define SPILCD_SCL    PAout(SPILCD_SCL_PIN)
#define SPILCD_RS     PEout(SPILCD_RS_PIN)
#define SPILCD_RST    PAout(SPILCD_RST_PIN)

//液晶屏尺寸定义
#define SPILCD_W 128
#define SPILCD_H 160



//TFTLCD部分外要调用的函数		   
extern uint16_t  POINT_COLOR;//前景色   
extern uint16_t  BACK_COLOR; //背景色
//////////////////////////////////////////////////////////////////////
//字体
#define ASCII1206	  0
#define ASCII1608	  1
#define ASCII1608C	2
//////////////////////////////////////////////////////////////////////
//画笔颜色
#define WHITE						0xFFFF
#define BLACK						0x0000	  
#define BLUE						0x001F  
#define BRED						0XF81F
#define GRED						0XFFE0
#define GBLUE						0X07FF
#define RED							0xF800
#define MAGENTA					0xF81F
#define GREEN						0x07E0
#define CYAN						0x7FFF
#define YELLOW					0xFFE0
#define BROWN						0XBC40 //棕色
#define BRRED						0XFC07 //棕红色
#define GRAY						0X8430 //灰色
//GUI颜色
#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色 
#define LIGHTGREEN     	 0X841F //浅绿色
#define LIGHTGRAY        0XEF5B //浅灰色(PANNEL)
#define LGRAY							0XC618 //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)
////////////////////////////
//本构件实现的接口函数
void LCD_InvDisplayOn(void);
void LCD_InvDisplayOff(void);
void SPILCD_Init(void);
void SPILCD_DrawPoint(uint16_t x,uint16_t y);
void SPILCD_Clear(uint16_t Color);
void SPILCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color);
void SPILCD_DrawLine(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void SPILCD_DrawRectangle(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void SPIDraw_Circle(uint16_t x0,uint16_t y0,uint8_t r);
void SPILCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t font,uint8_t mode);
void SPILCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t font);
void LCD_ShowString(uint16_t x,uint16_t y,const char *p);
#endif
