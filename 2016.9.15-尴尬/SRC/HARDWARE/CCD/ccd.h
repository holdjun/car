
#ifndef _CCD_H_
#define _CCD_H_

#include "gpio.h"
#include "dma.h"

void DelayNs(void);
void CCD_ImageCapture(unsigned char * ImageData) ;
void oled_collect(void);
void oled_show(void);
void DT(void);
void erzhi(void);
void LB(void);
void CCD_Image(void);

#endif

