#include "ccd.h"
#include "gpio.h"
#include "adc.h"
#include "delay.h"
#include "uart.h"
#include "pit.h"
#include "oled.h"
#include "ftm.h"
#include "define.h"
#include "chuinit.h"


unsigned char AverageValue;
/*************************************************************************
*
*  º¯ÊýÃû³Æ£ºvoid DelayNs(void)
*  ¹¦ÄÜËµÃ÷£ºCCDÑÓÊ±³ÌÐò 200ns
*  ²ÎÊýËµÃ÷£º
*  º¯Êý·µ»Ø£ºÎÞ
*  ÐÞ¸ÄÊ±¼ä£º
*  ±¸    ×¢£º
*************************************************************************/
void DelayNs(void)
{	
	uint8_t i;
	for(i = 0;i < 1;i++)
	{
		__nop();
		__nop();
	}
}
/*************************************************************************
*
*  º¯ÊýÃû³Æ£ºPixelAverage
*  ¹¦ÄÜËµÃ÷£ºÇóÊý×éµÄ¾ùÖµ³ÌÐò
*  ²ÎÊýËµÃ÷£º
*  º¯Êý·µ»Ø£ºÎÞ
*  ÐÞ¸ÄÊ±¼ä£º
*  ±¸    ×¢£º
*************************************************************************/
uint8_t PixelAverage(uint8_t len, uint8_t *data) 
{
  uint8_t i;
  unsigned int sum = 0;
  for(i = 0; i<len; i++) {
    sum = sum + *data++;
  }
  return ((uint8_t)(sum / len));
}


/*************************************************************************
*
*  º¯ÊýÃû³Æ£ºStartIntegration
*  ¹¦ÄÜËµÃ÷£ºCCDÆô¶¯³ÌÐò
*  ²ÎÊýËµÃ÷£º
*  º¯Êý·µ»Ø£ºÎÞ
*  ÐÞ¸ÄÊ±¼ä£º
*  ±¸    ×¢£º
*************************************************************************/
void StartIntegration(void)
{
	uint8_t i;
	
	CCD_SI = 1;
	DelayNs();
	CCD_CLK = 1;
	DelayNs();
	CCD_SI = 0;
	DelayNs();
	CCD_CLK = 0;

	for(i=0;i<127;i++)
	{
		DelayNs();
		DelayNs();
		CCD_CLK = 1;
		DelayNs();
		DelayNs();
		CCD_CLK = 0;
	}		
	DelayNs();
  DelayNs();
  CCD_CLK = 1;           /* CLK = 1 */
  DelayNs();
  DelayNs();
  CCD_CLK = 0;         /* CLK = 0 */
}

/*************************************************************************
*
*  º¯ÊýÃû³Æ£ºImageCapture
*  ¹¦ÄÜËµÃ÷£ºCCD²ÉÑù³ÌÐò
*  ²ÎÊýËµÃ÷£º* ImageData   ²ÉÑùÊý×é
*  º¯Êý·µ»Ø£ºÎÞ
*  ÐÞ¸ÄÊ±¼ä£º
*  ±¸    ×¢£º
*ImageData =  ad_once(ADC1, AD6a, ADC_8bit);
*************************************************************************/
void ImageCapture(uint8_t * ImageData) 
{
    uint8_t i;
    extern uint8_t AtemP ;

    CCD_SI=1;            /* SI  = 1 */
    DelayNs();
		CCD_CLK=1;           /* CLK = 1 */
    DelayNs();
    CCD_SI=0;            /* SI  = 0 */
    DelayNs();

    //Delay 10us for sample the first pixel
    /**/
		DelayUs(10);

    //Sampling Pixel 1

    *ImageData =  ADC_GetConversionValue(ADC1_SE10_PB4);
    ImageData ++ ;
    CCD_CLK=0;            /* CLK = 0 */

    for(i=0; i<127; i++) 
		{
      DelayNs();
      DelayNs();
      CCD_CLK=1;        /* CLK = 1 */
      DelayNs();
      DelayNs();

      *ImageData =  ADC_GetConversionValue(ADC1_SE10_PB4);
      ImageData ++ ;
      CCD_CLK=0;       /* CLK = 0 */
    }
    DelayNs();
    DelayNs();
    CCD_CLK=1;           /* CLK = 1 */
    DelayNs();
    DelayNs();
    CCD_CLK=0;           /* CLK = 0 */
}

/*************************************************************************
*
*  º¯ÊýÃû³Æ£ºCalculateIntegrationTime
*  ¹¦ÄÜËµÃ÷£º¼ÆËãÆØ¹âÊ±¼ä
*  ²ÎÊýËµÃ÷£º
*  º¯Êý·µ»Ø£ºÎÞ
*  ÐÞ¸ÄÊ±¼ä£º
*  ±¸    ×¢£º
*************************************************************************/
/* ÆØ¹âÊ±¼ä£¬µ¥Î»ms */
uint8_t IntegrationTime = 100;
void CalculateIntegrationTime(void)
{						
	/* 128¸öÏñËØµãµÄÆ½¾ùADÖµ */
	uint8_t PixelAverageValue;							
	/* 128¸öÏñËØµãµÄÆ½¾ùµçÑ¹ÖµµÄ10±¶ */
	uint8_t PixelAverageVoltage;						
	/* Éè¶¨Ä¿±êÆ½¾ùµçÑ¹Öµ£¬Êµ¼ÊµçÑ¹µÄ10±¶ */
	uint16_t TargetPixelAverageVoltage = 23;			
	/* Éè¶¨Ä¿±êÆ½¾ùµçÑ¹ÖµÓëÊµ¼ÊÖµµÄÆ«²î£¬Êµ¼ÊµçÑ¹µÄ10±¶ */
	uint16_t PixelAverageVoltageError = 0;				
	/* Éè¶¨Ä¿±êÆ½¾ùµçÑ¹ÖµÔÊÐíµÄÆ«²î£¬Êµ¼ÊµçÑ¹µÄ10±¶ */
	uint16_t TargetPixelAverageVoltageAllowError = 2;

  /* ¼ÆËã128¸öÏñËØµãµÄÆ½¾ùADÖµ */
  PixelAverageValue = PixelAverage(128,P1);
  /* ¼ÆËã128¸öÏñËØµãµÄÆ½¾ùµçÑ¹Öµ,Êµ¼ÊÖµµÄ10±¶ */
  PixelAverageVoltage = (uint8_t)((int)PixelAverageValue * 26 / 200);

  PixelAverageVoltageError = TargetPixelAverageVoltage - PixelAverageVoltage;
  if(PixelAverageVoltageError < -TargetPixelAverageVoltageAllowError) IntegrationTime--;
  if(PixelAverageVoltageError > TargetPixelAverageVoltageAllowError)  IntegrationTime++;
  if(IntegrationTime <= 1)	 IntegrationTime = 1;
  if(IntegrationTime >= 100) IntegrationTime = 100;
}


/***********************************************************************************************
 ¹¦ÄÜ£ºoled²É¼¯
 ÐÎ²Î£º0
 ·µ»Ø£º0
 Ïê½â£º½«ccdµÄADÖµ×ª»»³ÉoledÏÔÊ¾µÄÖµ
************************************************************************************************/
void oled_collect()
{
	uint8_t i,j,flag,flag1;
	for(i = 0;i <= 127;i++)
	{
		flag  = (255 - P1[i]) / 32;
		flag1 = (255 - P1[i]) % 32 / 4;
	  for(j = 7;j >= 4;j--)
			{
				if(j >  flag) oled_data[j][i]=0xff;
				if(j == flag) oled_data[j][i]=0xff<<flag1;
				if(j <  flag) oled_data[j][i]=0x00;
			}
		}
}

/***********************************************************************************************
 ¹¦ÄÜ£ºoledÏÔÊ¾
 ÐÎ²Î£º0
 ·µ»Ø£º0
 Ïê½â£º0
************************************************************************************************/

void oled_show()
{
	uint8_t i,j;
	for (i = 7;i >= 4;i--)
	{
		OLED_Set_XY(0,i);
	  for (j = 0;j <= 127;j++) OLED_WrDat(oled_data[i][j]);
	}
}
/****************************¶¯Ì¬È·¶¨ãÐÖµ******************************/
void DT(void)
{
//	uint8_t i,value_max,value_min;
//	extern unsigned char AverageValue;
//	value_max = P1[0];
//	for (i = 2;i < 126;i++) 
//  {
//    if (value_max <= P1[i]) value_max = P1[i];
//  }
//	value_min = P1[0];
//	for (i = 2;i < 126;i++) 
//  {
//    if (value_min >= P1[i]) value_min = P1[i];
//  }
	AverageValue = 100;
	//(value_max+value_min) / 2 + 10;
}
/****************************¶þÖµ»¯******************************/
void erzhi(void)
{
	uint8_t i;
	DT();
	for (i = 0;i <= 128;i++)
  {
    if (P1[i] > AverageValue) P1[i] = 255;
    else 											 	 P1[i] = 0;
  }
}
/*******************************ÂË²¨*************************/
void LB(void)
{
  uint8_t i;
  for (i = 1;i <= 127;i++)
  {
    if (P1[i] == 0 && P1[i] != P1[i-1] && P1[i] != P1[i+1]) 			  P1[i] = 255;
    else if (P1[i] == 255 && P1[i] != P1[i-1] && P1[i] != P1[i+1]) P1[i] = 0;
	}
  for (i = 1;i <= 127;i++)
  {
    if (P1[i] == 0 && P1[i] == P1[i+1] && P1[i] != P1[i-1] && P1[i] != P1[i+2])
    {
      P1[i]   = 255;
      P1[i+1] = 255;
    }
    if (P1[i] == 255 && P1[i] == P1[i+1] && P1[i] != P1[i-1] && P1[i] != P1[i+2])            
    {
      P1[i]   = 0;
      P1[i+1] = 0;
    }
	}
}

/*****************************
*
*  º¯ÊýÃû³Æ£CCCD_HeiXian
*  ¹¦ÄÜËµÃ÷£º²É¼¯ºÚÏßÎ»ÖÃ½øÐÐºÚÏßµãÊý¼ÆËã
*  ²ÎÊýËµÃ÷£º
*  º¯Êý·µ»Ø£ºÎÞ
*  ÐÞ¸ÄÊ±¼ä£º
*  ±¸    ×¢£º
*************************************************************************/
void CCD_HeiXian(void)
{
	uint8_t i,x1,x2;
	for (i = saoxian;i <= 122;i++)
	{
		Right = i;
		if (P1[i] == 0) break;
	}
	for (i = saoxian;i >= 6;i--)
	{
		Left = i;
		if (P1[i] == 0) break;
	}
	if (Left != 6 && Right != 122 && leixin == 0) Budao = (Right - Left) / 2;
	
	/********************************²¹Ïß´¦Àí********************************/
	
	if (Left != 6 && Right == 122)
	{
		for (i = saoxian; i <= 122; i++)
		{
			Right = i;
			if (P1[i] == 0) break;
		}
		if (Right!= 122) Center = (Right + Left) / 2;
		else
		{
			Center = Left + Budao;
			if (Center > 128) Center = 128;
			if (Center < (Right + Left) / 2) Center = (Right + Left) / 2;
		}
	}

	if (Left == 6 && Right != 122)  
	{
		for (i = saoxian; i >= 6; i--)
		{
				Left = i;
				if(P1[i] == 0) break;
		}
		if (Left != 6) Center = (Right + Left ) / 2;
		else
		{
			if (Right >= Budao) Center = Right - Budao;
			else Center = 0;
			if (Center > (Right + Left) / 2) Center = (Right + Left) / 2;
		}
	}
	
	if (Left != 6 && Right != 122) Center = (Right + Left) / 2;
	
	/********************************ºÚÏß´¦Àí********************************/
	
	if (Right == Left)
	{
		if (flag_black ==0) flag_miss = 1;
	}
	if (flag_miss == 1)
	{
		for (i = saoxian;i <= 122;i++)
		{
			Right = i;
			if (P1[i] == 0)
			{
				flag_miss = 0;
				break;
			}
		}
		for (i = saoxian;i >= 6;i--)
		{
			Left = i;
			if (P1[i] == 0)
			{
				flag_miss = 0;
				break;
			}
		}
		if (Left != 6 && Right == 122)
		{
			Center = Left + Budao;
			if (Center > 128) Center = 128;
			if (Center < (Right + Left) / 2) Center = (Right + Left) / 2;
		}

		if (Left == 6 && Right != 122)  
		{
			if (Right >= Budao) Center = Right - Budao;
			else Center = 0;
			if (Center > (Right + Left) / 2) Center = (Right + Left) / 2;
		}
		
		if (Left != 6 && Right != 122) Center = (Right + Left) / 2;
		
		if (Left == Right)
		{
			flag_black = 0;
			flag_miss = 0;
			Center = CenterLast[0];
		}
	}
	
	
	/********************************Ê®×Ö´¦Àí********************************/
	
	if (Left <= 8 && Right >= 120 && Cross_flag_wan == 1 )
	{
		Cross_flag = 0;
		Cross_flag_time = 0;
		Center = 64;
	}
	if (Left <= 8 && Right >= 120 && Cross_flag_wan == 0 )
	{
		Cross_flag = 1;
		Cross_flag_time = 0;
		Center = 64;
	}
	if (Cross_flag)
	{
		x1 = Left_p2;
		x2 = Right_p2;
		
		if (leixin == 1) Cross_flag_wan = 1;
		if (Cross_flag_time >= 40)
		{
			if (leixin == 0 && leixin_last[0] == 0) //Î
			{
				Cross_flag_wan = 0;
				Cross_flag 		 = 0;
			}
		}
	}
	else
	{
		x1 = Left_p1;
		x2 = Right_p1;
		if (leixin == 0) Cross_flag_wan = 0;
	}
	
	
	/*****************************ÀàÐÍ***************************/
	if (Center > 44 && Center <88 && CenterLast[0] > 44 && CenterLast[0] < 88 )
	{
		leixin = 0;//zhidao
		jiansuflag = 0;
	}
	
	if ((Center <= 44 && Left <= 13) || (Center >=84 && Right >= 115))
	{
		leixin = 1;//wandao
		jiasuflag = 0;
	}
	
	/*********************************************************************/	

	CenterLast[1] = CenterLast[0];
	CenterLast[0] = Center;
	
	leixin_last[0] = leixin;
	
	if (Center  >= 122)  Center = 122;
	if (Center  <= 6) 	 Center = 6;
	
	saoxian = Center;
	if (Cross_flag)
	{
		if (Center <= 63) FTMDuty = 4896 - (63 - Center) * x1;
		if (Center >= 64) FTMDuty = 4896 + (Center - 64) * x2;
	}
	else
	{
		if (Center <= 63) FTMDuty = 4896 - (63 - Center) * (63 - Center) * x1 / 100;
		if (Center >= 64) FTMDuty = 4896 + (Center - 64) * (Center - 64) * x2 / 100;
	}
	if (FTMDuty <= 4000) FTMDuty = 4000;
	if (FTMDuty >= 5800) FTMDuty = 5800;
	
	FTM_PWM_ChangeDuty(FTM0_CH4_PA7,FTMDuty);
}

/*************************************************************************
*
*  º¯ÊýÃû³Æ£COLED_ZhongXian
*  ¹¦ÄÜËµÃ÷£ºÏÔÊ¾ÖÐÏßµÄÎ»ÖÃ
*  ²ÎÊýËµÃ÷£º
*  º¯Êý·µ»Ø£ºÎÞ
*  ÐÞ¸ÄÊ±¼ä£º
*  ±¸    ×¢£º
*************************************************************************/
void OLED_ZhongXian(void)
{
	uint8_t m;
	for (m = 0;m < 3;m++)
	{
		OLED_Set_XY(Center,m);
		OLED_WrDat(0xff);
	}
	for (m = 0;m < 3;m++)
	{
		OLED_Set_XY(Center,m);
		OLED_WrDat(0x00);
	}
}

