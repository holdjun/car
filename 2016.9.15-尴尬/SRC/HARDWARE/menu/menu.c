#include "menu.h"
#include "oled.h"
#include "define.h"
#include "delay.h"
#include "pit.h"
#include "ftm.h"
#include "all.h"


unsigned char yiwei(int8_t x,int8_t i)
{
		if(i<=6&i>=0)
		{
			return(x);
		}
		if(i>=8){
		return(x+6-i);
		}
}


/******************************主界面显示********************************/
void Menu_Show(void)
{
	
	OLED_Write_Char(0, yiwei(yw,yw), 43);
	OLED_Write_String(2,yiwei(0,yw),"7   ");
	OLED_Write_String(2,yiwei(2,yw),"15  ");
	OLED_Write_String(2,yiwei(4,yw),"25  ");
	OLED_Write_String(2,yiwei(6,yw),"40  ");
	OLED_Write_String(2,yiwei(8,yw),"88  ");
	OLED_Write_String(2,yiwei(10,yw),"I   ");
	OLED_Write_String(2,yiwei(12,yw),"II  ");
	OLED_Write_String(2,yiwei(14,yw),"FTM1");
	OLED_Write_String(2,yiwei(16,yw),"FTM2");
	OLED_Write_String(2,yiwei(18,yw),"FTM3");
	OLED_Write_String(2,yiwei(20,yw),"SD");
	OLED_Write_String(4,yiwei(20,yw),"  ");
	OLED_Write_Num2(7,yiwei(0,yw),a1);
	OLED_Write_String(9,yiwei(0,yw),"  ");
	OLED_Write_Num2(7,yiwei(2,yw),a2);
	OLED_Write_String(9,yiwei(2,yw),"  ");
	OLED_Write_Num2(7,yiwei(4,yw),a3);
	OLED_Write_String(9,yiwei(4,yw),"  ");
	OLED_Write_Num2(7,yiwei(6,yw),a4);
	OLED_Write_String(9,yiwei(6,yw),"  ");
	OLED_Write_Num2(7,yiwei(8,yw),a5);
	OLED_Write_String(9,yiwei(8,yw),"  ");
	OLED_Write_Num2(7,yiwei(10,yw),a6);
	OLED_Write_String(9,yiwei(10,yw),"  ");
	OLED_Write_Num2(7,yiwei(12,yw),a7);
	OLED_Write_String(9,yiwei(12,yw),"  ");
	OLED_Write_Num4(7,yiwei(14,yw),FTMDuty_1);
	OLED_Write_Num4(7,yiwei(16,yw),FTMDuty_2);
	OLED_Write_Num4(7,yiwei(18,yw),FTMDuty_3);
	OLED_Write_String(7,yiwei(20,yw),"    ");
	
	//上移
	if(Key_up==0)
	{
		DelayMs(100);
		if(Key_up==0)
		{
			OLED_Write_Char(0,yiwei(yw,yw), ' ');
			yw=yw-2;
			if(yw==-2)
				yw=20;
		}
	}
	
	//下移
	if(Key_down==0)
	{
		DelayMs(100);
		if(Key_down==0)
		{
			OLED_Write_Char(0,yiwei(yw,yw), ' ');
			yw=yw+2;
			if(yw==22)
				yw=0;
		}
	}
	
	//a1
	if(yiwei(yw,yw)==yiwei(0,yw))
	{
		//加
		if(Key_right==0)
		{
			DelayMs(50);
			if(Key_right==0)
			{
				a1++;
				if(a1>=50)a1=0;
			}
		}
		//减
		if(Key_left==0)
		{
			DelayMs(50);
			if(Key_left==0)
			{
				a1--;
				if(a1<=0) a1=50;
			}
		}
	}
	//a2
	if(yiwei(yw,yw)==yiwei(2,yw))
	{
		//加
		if(Key_right==0)
		{
			DelayMs(50);
			if(Key_right==0)
			{
				a2++;
				if(a2>=50)a2=0;
			}
		}
		//减
		if(Key_left==0)
		{
			DelayMs(50);
			if(Key_left==0)
			{
				a2--;
				if(a2<=0) a2=50;
			}
		}
	}
	//a3
	if(yiwei(yw,yw)==yiwei(4,yw))
	{
		//加
		if(Key_right==0)
		{
			DelayMs(50);
			if(Key_right==0)
			{
				a3++;
				if(a3>=50)a3=0;
			}
		}
		//减
		if(Key_left==0)
		{
			DelayMs(50);
			if(Key_left==0)
			{
				a3--;
				if(a3<=0) a3=50;
			}
		}
	}
	//a4
	if(yiwei(yw,yw)==yiwei(6,yw))
	{
		//加
		if(Key_right==0)
		{
			DelayMs(50);
			if(Key_right==0)
			{
				a4++;
				if(a4>=50)a4=0;
			}
		}
		//减
		if(Key_left==0)
		{
			DelayMs(50);
			if(Key_left==0)
			{
				a4--;
				if(a4<=0) a4=50;
			}
		}
	}
	//a5
	if(yiwei(yw,yw)==yiwei(8,yw))
	{
		//加
		if(Key_right==0)
		{
			DelayMs(50);
			if(Key_right==0)
			{
				a5++;
				if(a5>=50)a5=0;
			}
		}
		//减
		if(Key_left==0)
		{
			DelayMs(50);
			if(Key_left==0)
			{
				a5--;
				if(a5<=0) a5=50;
			}
		}
	}
	//a6
	if(yiwei(yw,yw)==yiwei(10,yw))
	{
		//加
		if(Key_right==0)
		{
			DelayMs(50);
			if(Key_right==0)
			{
				a6++;
				if(a6>=50)a6=0;
			}
		}
		//减
		if(Key_left==0)
		{
			DelayMs(50);
			if(Key_left==0)
			{
				a6--;
				if(a6<=0) a6=50;
			}
		}
	}
	//a7
	if(yiwei(yw,yw)==yiwei(12,yw))
	{
		//加
		if(Key_right==0)
		{
			DelayMs(50);
			if(Key_right==0)
			{
				a7++;
				if(a7>=50) a7=0;
			}
		}
		//减
		if(Key_left==0)
		{
			DelayMs(50);
			if(Key_left==0)
			{
				a7--;
				if(a7<=0) a7=50;
			}
		}
	}
	//FTMDuty_1
	if(yiwei(yw,yw)==yiwei(14,yw))
	{
		//加
		if(Key_right==0)
		{
			DelayMs(50);
			if(Key_right==0)
			{
				FTMDuty_1+=50;
				if(FTMDuty_1>=3000)FTMDuty_1=3000;
			}
		}
		//减
		if(Key_left==0)
		{
			DelayMs(50);
			if(Key_left==0)
			{
				FTMDuty_1-=50;
				if(FTMDuty_1<=0) FTMDuty_1=0;
			}
		}
	}
	
	//FTMDuty_2
	if(yiwei(yw,yw)==yiwei(16,yw))
	{
		//加
		if(Key_right==0)
		{
			DelayMs(50);
			if(Key_right==0)
			{
				FTMDuty_2+=50;
				if(FTMDuty_2>=3000)FTMDuty_2 = 3000;
			}
		}
		//减
		if(Key_left==0)
		{
			DelayMs(50);
			if(Key_left==0)
			{
				FTMDuty_2-=50;
				if(FTMDuty_2<=0) FTMDuty_2=0;
			}
		}
	}
	
	//FTMDuty_3
	if(yiwei(yw,yw)==yiwei(18,yw))
	{
		//加
		if(Key_right==0)
		{
			DelayMs(50);
			if(Key_right==0)
			{
				FTMDuty_3+=50;
				if(FTMDuty_3>=3000)FTMDuty_3 = 3000;
			}
		}
		//减
		if(Key_left==0)
		{
			DelayMs(50);
			if(Key_left==0)
			{
				FTMDuty_3-=50;
				if(FTMDuty_3<=0) FTMDuty_3=0;
			}
		}
	}
	//SD
	if(yiwei(yw,yw)==yiwei(20,yw))
	{
		if(Key_right==0)
		{
			DelayMs(50);
			if(Key_right==0)
			{
				OLED_Clear();
				SD_D=0;
				flag_sd_d=1;
			}
		}
	}
	//打开ccd测试
	if(Key_2==0)
	{
		DelayMs(100);
		if(Key_2==0)
		{
			OLED_Clear();
			flag_test=1;
			SD_X=0;
			PIT_Start(PIT1);
			FTM_PWM_ChangeDuty(FTM0_CH3_PA6,FTMDuty_1);
		}
	}
	//发车
	if(Key_1==0)
	{
		DelayMs(50);
		if(Key_1==0)
		{
			OLED_Clear();
			flag_run=1;
			PIT_Start(PIT1);
			FTM_PWM_ChangeDuty(FTM0_CH3_PA6,FTMDuty_1);
		}
	}
	
}

//退出
void Menu_Quit(void)
{
	if(Key_2 == 0)
	{
		DelayMs(100);
		if(Key_2 == 0)
		{
			OLED_Clear();
			flag_test=0;
//			flag_sd_x=0;
			PIT_Stop(PIT1);
			FTM_PWM_ChangeDuty(FTM0_CH3_PA6,0);
		}
	}
}
//开启SD卡写入
void Menu_SD_X(void)
{
	if(Key_1 == 0)
	{
		DelayMs(100);
		if(Key_1 == 0)
		{
			flag_sd_x=1;
		}
	}
}

