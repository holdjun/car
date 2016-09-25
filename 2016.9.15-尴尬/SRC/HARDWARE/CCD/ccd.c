#include "ccd.h"
#include "delay.h"
#include "uart.h"
#include "oled.h"
#include "define.h"
#include "gpio.h"
#include "adc.h"
#include "ftm.h"
#include "pit.h"
#include "all.h"

/*************************************************************************
*
*  函数名称：void DelayNs(void)
*  功能说明：CCD延时程序 200ns
*  参数说明：
*  函数返回：无
*  修改时间：
*  备    注：
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
*  函数名称：ImageCapture
*  功能说明：CCD采样程序
*  参数说明：* ImageData   采样数组
*  函数返回：无
*  修改时间：
*  备    注：
*ImageData =  ad_once(ADC1, AD6a, ADC_8bit);
*************************************************************************/
void CCD_ImageCapture(uint8_t * ImageData) 
{
    uint8_t i;

    CCD_SI = 1;            /* SI  = 1 */
    DelayNs();
		CCD_CLK = 1;           /* CLK = 1 */
    DelayNs();
    CCD_SI = 0;            /* SI  = 0 */
    DelayNs();

    //Delay 10us for sample the first pixel
    /**/
		DelayUs(10);

    //Sampling Pixel 1

    *ImageData =  ADC_GetConversionValue(ADC1_SE10_PB4);
    ImageData ++ ;
    CCD_CLK=0;            /* CLK = 0 */

    for(i = 0; i < 127; i++) 
		{
      DelayNs();
      DelayNs();
      CCD_CLK = 1;        /* CLK = 1 */
      DelayNs();
      DelayNs();

      *ImageData =  ADC_GetConversionValue(ADC1_SE10_PB4);
      ImageData ++ ;
      CCD_CLK = 0;       /* CLK = 0 */
    }
    DelayNs();
    DelayNs();
    CCD_CLK = 1;           /* CLK = 1 */
    DelayNs();
    DelayNs();
    CCD_CLK = 0;           /* CLK = 0 */
		
}

/***********************************************************************************************
 功能：oled采集
 形参：0
 返回：0
 详解：将ccd的AD值转换成oled显示的值
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
				if(j >  flag) oled_data[j][i] = 0xff;
				if(j == flag) oled_data[j][i] = 0xff<<flag1;
				if(j <  flag) oled_data[j][i] = 0x00;
			}
		}
}

/***********************************************************************************************
 功能：oled显示
 形参：0
 返回：0
 详解：0
************************************************************************************************/

void oled_show()
{
	uint8_t i,j;
	for(i = 7;i >= 4;i--)
	{
		OLED_Set_XY(0,i);
	  for(j = 0;j <= 124;j++)
	    {
				OLED_WrDat(oled_data[i][j]);
			}
	}
}
/****************************动态确定阈值******************************/
void DT(void)
{
	uint8_t i,value_max,value_min;
	value_max = P1[2];
	for(i = 2;i < 126;i++) 
  {
    if(value_max <= P1[i]) value_max =  P1[i];
  }
	value_min = P1[2];
	for(i = 2;i < 126;i++) 
  {
    if(value_min >= P1[i])
    value_min = P1[i];
	}
	Value = (value_max + value_min) / 2 + 10;
}
/****************************二值化******************************/
void erzhi(void)
{
	uint8_t i;
	DT();
	for(i = 2;i <= 125;i++)
  {
    if(P1[i] > Value) P1[i] = 255;
    else							P1[i] = 0;
  }
}
/*******************************滤波*************************/
void LB(void)
{
  unsigned char i;
  for(i = 3;i < 125;i++)
  {
    if(P1[i]==0&&P1[i]!=P1[i-1]&&P1[i]!=P1[i+1]) 				P1[i] = 255;
    else if(P1[i]==250&&P1[i]!=P1[i-1]&&P1[i]!=P1[i+1]) P1[i] = 0;
	}
  for(i=3;i<124;i++)
  {
    if(P1[i]==0&&P1[i]==P1[i+1]&&P1[i]!=P1[i-1]&&P1[i]!=P1[i+2])
    {
      P1[i]   = 255;
      P1[i+1] = 255;
    }
    if(P1[i]==255&&P1[i]==P1[i+1]&&P1[i]!=P1[i-1]&&P1[i]!=P1[i+2])            
    {
      P1[i]		= 0;
      P1[i+1] = 0;
    }
	}
}
/*************************************************************************
*
*  函数名称CCD_Image
*  功能说明：采集黑线位置进行黑线点数计算
*  参数说明：
*  函数返回：无
*  修改时间：
*  备    注：
*************************************************************************/
void CCD_Image(void)
{
	int i;
	uint8_t m;
	
	for(i = Center;i < 126;i++)
	{
		if(P1[i] == 0)
		{
			Right = i;
			break;
		}
	}
	for(i = Center;i > 1;i--)
	{
		if(P1[i] == 0)
		{
			Left = i;
			break;
		}
	}
	
	Center = (Left + Right) / 2;
	if(Left >= 7 && Right <= 120) 		Width = Right - Left;
	if(Center <= 17 || Center >= 110) Center = (Left + Right) / 2;
	
	if(Center <= 63)
	{
		if (63 - Center <= 7) 										FTMDuty = 4400 - (63 - Center) * a1;
		if (63 - Center <= 15 && 63 - Center > 7) FTMDuty = 4400 - (63 - Center) * a2;
		if (63 - Center <= 25 && 63 - Center > 15)FTMDuty = 4400 - (63 - Center) * a3;
		if (63 - Center <= 40 && 63 - Center > 25)FTMDuty = 4400 - (63 - Center) * a4;		
		if (63 - Center > 40)											FTMDuty = 4400 - (63 - Center) * a5;		
		
		FTM_PWM_ChangeDuty(FTM2_CH0_PA10,FTMDuty);
		if(FTMDuty <= 3700) FTMDuty = 3700;
		if((Right-Left)==Width&&Center>60) FTM_PWM_ChangeDuty(FTM2_CH0_PA10,4400);
	}
	if(Center >= 64)
	{
		if (Center - 64 <= 7) FTMDuty = 4400 + (Center - 64) * a1;
		if (Center - 64 <= 15 && Center - 64 > 7) FTMDuty = 4400 + (Center - 64) * a2;
		if (Center - 64 <= 25 && Center - 64 > 15)FTMDuty = 4400 + (Center - 64) * a3;
		if (Center - 64 <= 40 && Center - 64 > 25)FTMDuty = 4400 + (Center - 64) * a4;
		if (Center - 64 > 40)											FTMDuty = 4400 + (Center - 64) * a5;
		FTM_PWM_ChangeDuty(FTM2_CH0_PA10,FTMDuty);
		if(FTMDuty >= 5100) FTMDuty = 5100;
		if((Right-Left)==Width&&Center<67) 				FTM_PWM_ChangeDuty(FTM2_CH0_PA10,4400);
	}
	if(Center>=64)
	{
		if((Center-64)>=3)
		{
			FTM_PWM_ChangeDuty(FTM0_CH3_PA6,FTMDuty_2);
			if(flag_JianSu>0)
			{
				FTM_PWM_ChangeDuty(FTM0_CH3_PA6,0);
				flag_JianSu--;
			}
		}
		if((Center-64)<3)
		{
			FTM_PWM_ChangeDuty(FTM0_CH3_PA6,FTMDuty_1);
			flag_JianSu=5;
		}
	}
	if(Center<=63)
	{
		if((63-Center)>=3)
		{
			FTM_PWM_ChangeDuty(FTM0_CH3_PA6,FTMDuty_2);
			if(flag_JianSu>0)
			{
				FTM_PWM_ChangeDuty(FTM0_CH3_PA6,0);
				flag_JianSu--;
			}
		}
		if((63-Center)<3)
		{
			FTM_PWM_ChangeDuty(FTM0_CH3_PA6,FTMDuty_1);
			flag_JianSu=5;
		}
	}
	
	//显示中线
	for(m = 0;m < 3;m++)
	{
		OLED_Set_XY(Center,m);
		OLED_WrDat(0xff);
	}
	for(m = 0;m < 3;m++)
	{
		OLED_Set_XY(Center,m);
		OLED_WrDat(0x00);
	}
	OLED_Write_Num3(0,2,Center);
	
}

