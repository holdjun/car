#ifndef __YINJIAO_H__
#define __YINJIAO_H__

#include "gpio.h"

//KEY**************************
#define Key_left_PORT     PTC
#define Key_left_PIN      (14)
#define Key_left          PCin(14)

#define Key_right_PORT    PTC
#define Key_right_PIN     (16)
#define Key_right         PCin(16)

#define Key_up_PORT       PTC
#define Key_up_PIN        (13)
#define Key_up            PCin(13)

#define Key_down_PORT     PTC
#define Key_down_PIN      (15)
#define Key_down          PCin(15)

#define Key_1_PORT        PTC
#define Key_1_PIN         (11)
#define Key_1             PCin(11)

#define Key_2_PORT        PTC
#define Key_2_PIN         (12)
#define Key_2             PCin(12)
//*******************************

//CCD**************************
//#define CCD_AO_PORT    PTB
//#define CCD_AO_PIN     (4)
//#define CCD_AO         PBout(4)

#define CCD_SI_PORT    PTB
#define CCD_SI_PIN     (5)
#define CCD_SI         PBout(5)

#define CCD_CLK_PORT   PTB
#define CCD_CLK_PIN    (6)
#define CCD_CLK        PBout(6)
//*****************************

void YinJiao_Init(void);

#endif