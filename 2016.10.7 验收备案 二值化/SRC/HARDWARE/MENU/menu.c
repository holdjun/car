#include "menu.h"
#include "oled.h"
#include "define.h"
#include "delay.h"
#include "pit.h"
#include "ftm.h"
#include "chuinit.h"
#include "string.h"
#include "define.h"

struct Menu_Select Menu_name[Number_All];

void Menu_Init (void)
{
	
	 #if(Number_All >= 1)
      strcpy(Menu_name[0].name, name0);
      Menu_name[0].num = name0_num;	
      Menu_name[0].sub = name0_sub;
   #endif


   #if(Number_All >= 2)
      strcpy(Menu_name[1].name, name1);
      Menu_name[1].num = name1_num;			
      Menu_name[1].sub = name1_sub;
   #endif


   #if(Number_All >= 3)
      strcpy(Menu_name[2].name, name2);
      Menu_name[2].num = name2_num;			
      Menu_name[2].sub = name2_sub;
   #endif


   #if(Number_All >= 4)
      strcpy(Menu_name[3].name, name3);
      Menu_name[3].num = name3_num;			
      Menu_name[3].sub = name3_sub;
   #endif


   #if(Number_All >= 5)
      strcpy(Menu_name[4].name, name4);
      Menu_name[4].num = name4_num;			
      Menu_name[4].sub = name4_sub;
   #endif


   #if(Number_All >= 6)
      strcpy(Menu_name[5].name, name5);
      Menu_name[5].num = name5_num;			
      Menu_name[5].sub = name5_sub;
   #endif


   #if(Number_All >= 7)
      strcpy(Menu_name[6].name, name6);
      Menu_name[6].num = name6_num;			
      Menu_name[6].sub = name6_sub;
   #endif


   #if(Number_All >= 8)
      strcpy(Menu_name[7].name, name7);
      Menu_name[7].num = name7_num;			
      Menu_name[7].sub = name7_sub;
   #endif


   #if(Number_All >= 9)
      strcpy(Menu_name[8].name, name8);
      Menu_name[8].num = name8_num;			
      Menu_name[8].sub = name8_sub;
   #endif


   #if(Number_All >= 10)
      strcpy(Menu_name[9].name, name9);
      Menu_name[9].num = name9_num;			
      Menu_name[9].sub = name9_sub;
   #endif


   #if(Number_All >= 11)
      strcpy(Menu_name[10].name, name10);
      Menu_name[10].num = name10_num;			
      Menu_name[10].sub = name10_sub;
   #endif


   #if(Number_All >= 12)
      strcpy(Menu_name[11].name, name11);
      Menu_name[11].num = name11_num;			
      Menu_name[11].sub = name11_sub;
   #endif


   #if(Number_All >= 13)
      strcpy(Menu_name[12].name, name12);
      Menu_name[12].num = name12_num;			
      Menu_name[12].sub = name12_sub;
   #endif


   #if(Number_All >= 14)
      strcpy(Menu_name[13].name, name13);
      Menu_name[13].num = name13_num;			
      Menu_name[13].sub = name13_sub;
   #endif


   #if(Number_All >= 15)
      strcpy(Menu_name[14].name, name14);
      Menu_name[14].num = name14_num;			
      Menu_name[14].sub = name14_sub;
   #endif


   #if(Number_All >= 16)
      strcpy(Menu_name[15].name, name15);
      Menu_name[15].num = name15_num;			
      Menu_name[15].sub = name15_sub;
   #endif


   #if(Number_All >= 17)
      strcpy(Menu_name[16].name, name16);
      Menu_name[16].num = name16_num;			
      Menu_name[16].sub = name16_sub;
   #endif


   #if(Number_All >= 18)
      strcpy(Menu_name[17].name, name17);
      Menu_name[17].num = name17_num;			
      Menu_name[17].sub = name17_sub;
   #endif


   #if(Number_All >= 19)
      strcpy(Menu_name[18].name, name18);
      Menu_name[18].num = name18_num;			
      Menu_name[18].sub = name18_sub;
   #endif


   #if(Number_All >= 20)
      strcpy(Menu_name[19].name, name19);
      Menu_name[19].num = name19_num;			
      Menu_name[19].sub = name19_sub;
   #endif


   #if(Number_All >= 21)
      strcpy(Menu_name[20].name, name20);
      Menu_name[20].num = name20_num;			
      Menu_name[20].sub = name20_sub;
   #endif


   #if(Number_All >= 22)
      strcpy(Menu_name[21].name, name21);
      Menu_name[21].num = name21_num;			
      Menu_name[21].sub = name21_sub;
   #endif


   #if(Number_All >= 23)
      strcpy(Menu_name[22].name, name22);
      Menu_name[22].num = name22_num;			
      Menu_name[22].sub = name22_sub;
   #endif


   #if(Number_All >= 24)
      strcpy(Menu_name[23].name, name23);
      Menu_name[23].num = name23_num;			
      Menu_name[23].sub = name23_sub;
   #endif


   #if(Number_All >= 25)
      strcpy(Menu_name[24].name, name24);
      Menu_name[24].num = name24_num;			
      Menu_name[24].sub = name24_sub;
   #endif


   #if(Number_All >= 26)
      strcpy(Menu_name[25].name, name25);
      Menu_name[25].num = name25_num;			
      Menu_name[25].sub = name25_sub;
   #endif


   #if(Number_All >= 27)
      strcpy(Menu_name[26].name, name26);
      Menu_name[26].num = name26_num;			
      Menu_name[26].sub = name26_sub;
   #endif


   #if(Number_All >= 28)
      strcpy(Menu_name[27].name, name27);
      Menu_name[27].num = name27_num;			
      Menu_name[27].sub = name27_sub;
   #endif


   #if(Number_All >= 29)
      strcpy(Menu_name[28].name, name28);
      Menu_name[28].num = name28_num;			
      Menu_name[28].sub = name28_sub;
   #endif


   #if(Number_All >= 30)
      strcpy(Menu_name[29].name, name29);
      Menu_name[29].num = name29_num;			
      Menu_name[29].sub = name29_sub;
   #endif
	 
	#if(Number_All) 
    anjian_menu();
	#endif
	
	#if(Number_All >= 1)
      name0_num = Menu_name[0].num;
   #endif

	#if(Number_All >= 2)
      name1_num = Menu_name[1].num;
   #endif

	#if(Number_All >= 3)
      name2_num = Menu_name[2].num;
   #endif

	#if(Number_All >= 4)
      name3_num = Menu_name[3].num;
   #endif

	#if(Number_All >= 5)
      name4_num = Menu_name[4].num;
   #endif

	#if(Number_All >= 6)
      name5_num = Menu_name[5].num;
   #endif

	#if(Number_All >= 7)
      name6_num = Menu_name[6].num;
   #endif

	#if(Number_All >= 8)
      name7_num = Menu_name[7].num;
   #endif

	#if(Number_All >= 9)
      name8_num = Menu_name[8].num;
   #endif

	#if(Number_All >= 10)
      name9_num = Menu_name[9].num;
   #endif

	#if(Number_All >= 11)
      name10_num = Menu_name[10].num;
   #endif

	#if(Number_All >= 12)
      name11_num = Menu_name[11].num;
   #endif

	#if(Number_All >= 13)
      name12_num = Menu_name[12].num;
   #endif

	#if(Number_All >= 14)
      name13_num = Menu_name[13].num;
   #endif

	#if(Number_All >= 15)
      name14_num = Menu_name[14].num;
   #endif

	#if(Number_All >= 16)
      name15_num = Menu_name[15].num;
   #endif

	#if(Number_All >= 17)
      name16_num = Menu_name[16].num;
   #endif

	#if(Number_All >= 18)
      name17_num = Menu_name[17].num;
   #endif

	#if(Number_All >= 19)
      name18_num = Menu_name[18].num;
   #endif

	#if(Number_All >= 20)
      name19_num = Menu_name[19].num;
   #endif

	#if(Number_All >= 21)
      name20_num = Menu_name[20].num;
   #endif

	#if(Number_All >= 22)
      name21_num = Menu_name[21].num;
   #endif

	#if(Number_All >= 23)
      name22_num = Menu_name[22].num;
   #endif

	#if(Number_All >= 24)
      name23_num = Menu_name[23].num;
   #endif

	#if(Number_All >= 25)
      name24_num = Menu_name[24].num;
   #endif

	#if(Number_All >= 26)
      name25_num = Menu_name[25].num;
   #endif

	#if(Number_All >= 27)
      name26_num = Menu_name[26].num;
   #endif

	#if(Number_All >= 28)
      name27_num = Menu_name[27].num;
   #endif

	#if(Number_All >= 29)
      name28_num = Menu_name[28].num;
   #endif

	#if(Number_All >= 30)
      name29_num = Menu_name[29].num;
   #endif

}

void anjian_menu(void)
{
	uint8_t final_hang = 0,page = 0,i;
	
	OLED_Clear();
	
	while(Flag == 0)
	{
		//上移
		if(Key_up == 0)
		{
			DelayMs(100);
			if(Key_up == 0)
			{
				hang --;
				if(hang == 0) hang = Number_All;
				OLED_Clear();
			}
		}
		
		//下移
		if(Key_down == 0)
		{
			DelayMs(100);
			if(Key_down == 0)
			{
				hang ++;
				if(hang == Number_All + 1) hang = 1;
				OLED_Clear();
			}
		}
		//加
		if(Key_right == 0)
		{
			DelayMs(100);
			if(Key_right == 0) Menu_name[hang - 1].num = Menu_name[hang - 1].num + Menu_name[hang - 1].sub;
		}
		//减
		if(Key_left == 0)
		{
			DelayMs(100);
			if(Key_left == 0) Menu_name[hang - 1].num = Menu_name[hang - 1].num - Menu_name[hang - 1].sub;
		}
		
		OLED_Write_Char(0,(hang - 1) % 4 * 2,43);   //箭头

		if((Number_All - 1) / 4 > (hang - 1) / 4) 
		{
			page = (hang - 1) / 4;
			final_hang = 4;
		}
		else
		{
			page = (Number_All - 1) / 4;
			final_hang = Number_All % 4;
			if(final_hang == 0) final_hang =4;
		}
		
		for(i = 1;i <= final_hang;i++)  
		{
			OLED_Write_String(2,(i - 1)*2,(uint8_t*)Menu_name[i - 1 + 4 * page].name);
			OLED_Write_Num4(12,(i - 1)*2,Menu_name[i - 1 + 4 * page].num);
		}
		
		//打开ccd测试
		if(Key_1 == 0)
		{
			DelayMs(100);
			if(Key_1 == 0)
			{
				OLED_Clear();
				Flag = 1;
				SD_X = 0;
				PIT_Start(PIT1);
			}
		}
	}
}

