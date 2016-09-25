#ifndef _CCD_H_
#define _CCD_H_

#include "sys.h"

void ccd_Init(void);
void ccd_collect(void);
void ccd2_collect(void);
void oled_collect(void);
void oled_collect2(void);
void oled_show(void);
void CCDImage_process(void);



#endif
