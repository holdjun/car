
#ifndef _CCD_H_
#define _CCD_H_

#include "gpio.h"
#include "dma.h"


void StartIntegration(void) ;
void ImageCapture(unsigned char * ImageData) ;
void SendHex(unsigned char hex) ;
void SamplingDelay(void) ;
void CCD_Init(void) ;
void CalculateIntegrationTime(void) ;
void SendImageData(unsigned char * ImageData) ;
void ccd_collect(void);
void oled_collect(void);
void oled_show(void);
uint8_t PixelAverage(uint8_t len, uint8_t *data);
void DT(void);
void erzhi(void);
void LB(void);
void CCD_HeiXian(void);
void OLED_ZhongXian(void);


#endif

