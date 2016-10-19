/***********************************************************************************************
//CH_Kinetis驱动库  V2.3   
//作者    :YANDLD 
//E-MAIL  :yandld@126.com
//修改日期:2013/2/14
//版本：V2.3
//淘宝：http://upcmcu.taobao.com
//QQ    1453363089
//Copyright(C) YANDLD 2012-2022
//All rights reserved
************************************************************************************************/
#ifndef __LED_H__
#define __LED_H__
#include "gpio.h"

//LED头文件
//IO 口
#define LED0_PORT PTB
#define LED1_PORT PTB
#define LED2_PORT PTB
#define LED3_PORT PTB
#define LED4_PORT PTB
#define LED5_PORT PTB
#define LED6_PORT PTB
#define LED7_PORT PTB
//引脚
#define LED0_PIN  0
#define LED1_PIN  1
#define LED2_PIN  2
#define LED3_PIN  3
#define LED4_PIN  4
#define LED5_PIN  5
#define LED6_PIN  6
#define LED7_PIN  7
//位宏
#define LED0      PDout(LED0_PIN) 
#define LED1      PDout(LED1_PIN)
#define LED2      PDout(LED2_PIN)
#define LED3      PDout(LED3_PIN)
#define LED4      PDout(LED4_PIN)
#define LED5      PDout(LED5_PIN)
#define LED6      PDout(LED6_PIN)
#define LED7      PDout(LED7_PIN)
void LED_Init(void);
#endif
