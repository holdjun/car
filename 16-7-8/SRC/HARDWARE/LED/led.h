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
#define LED0_PORT PTD
#define LED1_PORT PTD
//引脚
#define LED0_PIN  7
#define LED1_PIN  0
//位宏
#define LED0      PDout(LED0_PIN) 
#define LED1      PDout(LED1_PIN) 
void LED_Init(void);
#endif
