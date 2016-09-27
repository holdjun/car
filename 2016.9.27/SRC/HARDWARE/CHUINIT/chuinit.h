#ifndef __CHUINIT_H__
#define __CHUINIT_H__

#include "gpio.h"

//KEY**************************
#define Key_left_PORT     PTA
#define Key_left_PIN      (8)
#define Key_left          PAin(8)

#define Key_right_PORT    PTA
#define Key_right_PIN     (9)
#define Key_right         PAin(9)

#define Key_up_PORT       PTA
#define Key_up_PIN        (15)
#define Key_up            PAin(15)

#define Key_down_PORT     PTA
#define Key_down_PIN      (5)
#define Key_down          PAin(5)

#define Key_1_PORT        PTA
#define Key_1_PIN         (6)
#define Key_1             PAin(6)

//#define Key_2_PORT        PTA
//#define Key_2_PIN         (9)
//#define Key_2             PAin(9)
//*******************************

//CCD**************************

#define CCD_SI_PORT    PTB
#define CCD_SI_PIN     (5)
#define CCD_SI         PBout(5)

#define CCD_CLK_PORT   PTB
#define CCD_CLK_PIN    (6)
#define CCD_CLK        PBout(6)
//*****************************

void chuinit_Init(void);

#endif
