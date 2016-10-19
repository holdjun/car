
#include "delay.h"
#include "gpio.h"
#include "oled.h"
#include "string.h"
#include "meue.h"
//************************************************************************************************
#define ChangAn_Delay		500
#define Menu_Count_Rate  2
uint16_t Menu_Mode_Default = 0,
        Menu_Null_Default = 0;
struct DEFMENU MY_Menu[MENU_NUM+4];
uint16_t Menu_Mode1 [MENU_NUM+1],
         Menu_Mode2 [MENU_NUM+1],
		 Menu_Mode3 [MENU_NUM+1];
void Menu_Init (void )
{
#if(MENU_NUM == 0)
strcpy(MY_Menu[0].name , "      ");
MY_Menu[0].Data = (uint16_t *)&Menu_Null_Default ;
MY_Menu[0].DataCount = 0;
	
strcpy(MY_Menu[1].name , "Mode ");
MY_Menu[1].Data = (uint16_t *)&Menu_Mode_Default;
MY_Menu[1].DataCount = 1;
	
strcpy(MY_Menu[2].name , "      ");
MY_Menu[2].Data = (uint16_t *)&Menu_Null_Default ;
MY_Menu[2].DataCount = 0;
	
strcpy(MY_Menu[3].name , "      ");
MY_Menu[3].Data = (uint16_t *)&Menu_Null_Default ;
MY_Menu[3].DataCount = 0;
#endif
#if(MENU_NUM)
strcpy(MY_Menu[0].name , "      ");
MY_Menu[0].Data = (uint16_t *)&Menu_Null_Default ;
MY_Menu[0].DataCount = 0;

strcpy(MY_Menu[MENU_NUM + 1].name , "Mode ");
MY_Menu[MENU_NUM + 1].Data = (uint16_t *)&Menu_Mode_Default;
MY_Menu[MENU_NUM + 1].DataCount = 1;

strcpy(MY_Menu[MENU_NUM + 2].name , "      ");
MY_Menu[MENU_NUM + 2].Data = (uint16_t *)&Menu_Null_Default ;
MY_Menu[MENU_NUM + 2].DataCount = 0;

strcpy(MY_Menu[MENU_NUM + 3].name , "      ");
MY_Menu[MENU_NUM + 3].Data = (uint16_t *)&Menu_Null_Default ;
MY_Menu[MENU_NUM + 3].DataCount = 0;
#if(MENU_NUM >= 1)
strcpy(MY_Menu[1].name , name1);
MY_Menu[1].Data = (uint16_t *)&MENUDATA1;
MY_Menu[1].DataCount = MENUDATA1_COUNT;
#endif
#if(MENU_NUM >= 2)
strcpy(MY_Menu[2].name , name2);
MY_Menu[2].Data = (uint16_t *)&MENUDATA2;
MY_Menu[2].DataCount = MENUDATA2_COUNT;
#endif
#if(MENU_NUM >= 3)
strcpy(MY_Menu[3].name , name3);
MY_Menu[3].Data = (uint16_t *)&MENUDATA3;
MY_Menu[3].DataCount = MENUDATA3_COUNT;
#endif
#if(MENU_NUM >= 4)
strcpy(MY_Menu[4].name , name4);
MY_Menu[4].Data = (uint16_t *)&MENUDATA4;
MY_Menu[4].DataCount = MENUDATA4_COUNT;
#endif
#if(MENU_NUM >= 5)
strcpy(MY_Menu[5].name , name5);
MY_Menu[5].Data = (uint16_t *)&MENUDATA5;
MY_Menu[5].DataCount = MENUDATA5_COUNT;
#endif
#if(MENU_NUM >= 6)
strcpy(MY_Menu[6].name , name6);
MY_Menu[6].Data = (uint16_t *)&MENUDATA6;
MY_Menu[6].DataCount = MENUDATA6_COUNT;
#endif
#if(MENU_NUM >= 7)
strcpy(MY_Menu[7].name , name7);
MY_Menu[7].Data = (uint16_t *)&MENUDATA7;
MY_Menu[7].DataCount = MENUDATA7_COUNT;
#endif
#if(MENU_NUM >= 8)
strcpy(MY_Menu[8].name , name8);
MY_Menu[8].Data = (uint16_t *)&MENUDATA8;
MY_Menu[8].DataCount = MENUDATA8_COUNT;
#endif
#if(MENU_NUM >= 9)
strcpy(MY_Menu[9].name , name9);
MY_Menu[9].Data = (uint16_t *)&MENUDATA9;
MY_Menu[9].DataCount = MENUDATA9_COUNT;
#endif
#if(MENU_NUM >= 10)
strcpy(MY_Menu[10].name , name10);
MY_Menu[10].Data = (uint16_t *)&MENUDATA10;
MY_Menu[10].DataCount = MENUDATA10_COUNT;
#endif
#if(MENU_NUM >= 11)
strcpy(MY_Menu[11].name , name11);
MY_Menu[11].Data = (uint16_t *)&MENUDATA11;
MY_Menu[11].DataCount = MENUDATA11_COUNT;
#endif
#if(MENU_NUM >= 12)
strcpy(MY_Menu[12].name , name12);
MY_Menu[12].Data = (uint16_t *)&MENUDATA12;
MY_Menu[12].DataCount = MENUDATA12_COUNT;
#endif
#if(MENU_NUM >= 13)
strcpy(MY_Menu[13].name , name13);
MY_Menu[13].Data = (uint16_t *)&MENUDATA13;
MY_Menu[13].DataCount = MENUDATA13_COUNT;
#endif
#if(MENU_NUM >= 14)
strcpy(MY_Menu[14].name , name14);
MY_Menu[14].Data = (uint16_t *)&MENUDATA14;
MY_Menu[14].DataCount = MENUDATA14_COUNT;
#endif
#if(MENU_NUM >= 15)
strcpy(MY_Menu[15].name , name15);
MY_Menu[15].Data = (uint16_t *)&MENUDATA15;
MY_Menu[15].DataCount = MENUDATA15_COUNT;
#endif
#if(MENU_NUM >= 16)
strcpy(MY_Menu[16].name , name16);
MY_Menu[16].Data = (uint16_t *)&MENUDATA16;
MY_Menu[16].DataCount = MENUDATA16_COUNT;
#endif
#if(MENU_NUM >= 17)
strcpy(MY_Menu[17].name , name17);
MY_Menu[17].Data = (uint16_t *)&MENUDATA17;
MY_Menu[17].DataCount = MENUDATA17_COUNT;
#endif
#if(MENU_NUM >= 18)
strcpy(MY_Menu[18].name , name18);
MY_Menu[18].Data = (uint16_t *)&MENUDATA18;
MY_Menu[18].DataCount = MENUDATA18_COUNT;
#endif
#if(MENU_NUM >= 19)
strcpy(MY_Menu[19].name , name19);
MY_Menu[19].Data = (uint16_t *)&MENUDATA19;
MY_Menu[19].DataCount = MENUDATA19_COUNT;
#endif
#if(MENU_NUM >= 20)
strcpy(MY_Menu[20].name , name20);
MY_Menu[20].Data = (uint16_t *)&MENUDATA20;
MY_Menu[20].DataCount = MENUDATA20_COUNT;
#endif
#if(MENU_NUM >= 21)
strcpy(MY_Menu[21].name , name21);
MY_Menu[21].Data = (uint16_t *)&MENUDATA21;
MY_Menu[21].DataCount = MENUDATA21_COUNT;
#endif
#if(MENU_NUM >= 22)
strcpy(MY_Menu[22].name , name22);
MY_Menu[22].Data = (uint16_t *)&MENUDATA22;
MY_Menu[22].DataCount = MENUDATA22_COUNT;
#endif
#if(MENU_NUM >= 23)
strcpy(MY_Menu[23].name , name23);
MY_Menu[23].Data = (uint16_t *)&MENUDATA23;
MY_Menu[23].DataCount = MENUDATA23_COUNT;
#endif
#if(MENU_NUM >= 24)
strcpy(MY_Menu[24].name , name24);
MY_Menu[24].Data = (uint16_t *)&MENUDATA24;
MY_Menu[24].DataCount = MENUDATA24_COUNT;
#endif
#if(MENU_NUM >= 25)
strcpy(MY_Menu[25].name , name25);
MY_Menu[25].Data = (uint16_t *)&MENUDATA25;
MY_Menu[25].DataCount = MENUDATA25_COUNT;
#endif
#if(MENU_NUM >= 26)
strcpy(MY_Menu[26].name , name26);
MY_Menu[26].Data = (uint16_t *)&MENUDATA26;
MY_Menu[26].DataCount = MENUDATA26_COUNT;
#endif
#if(MENU_NUM >= 27)
strcpy(MY_Menu[27].name , name27);
MY_Menu[27].Data = (uint16_t *)&MENUDATA27;
MY_Menu[27].DataCount = MENUDATA27_COUNT;
#endif
#if(MENU_NUM >= 28)
strcpy(MY_Menu[28].name , name28);
MY_Menu[28].Data = (uint16_t *)&MENUDATA28;
MY_Menu[28].DataCount = MENUDATA28_COUNT;
#endif
#if(MENU_NUM >= 29)
strcpy(MY_Menu[29].name , name29);
MY_Menu[29].Data = (uint16_t *)&MENUDATA29;
MY_Menu[29].DataCount = MENUDATA29_COUNT;
#endif
#if(MENU_NUM >= 30)
strcpy(MY_Menu[30].name , name30);
MY_Menu[30].Data = (uint16_t *)&MENUDATA30;
MY_Menu[30].DataCount = MENUDATA30_COUNT;
#endif
#if(MENU_NUM >= 31)
strcpy(MY_Menu[31].name , name31);
MY_Menu[31].Data = (uint16_t *)&MENUDATA31;
MY_Menu[31].DataCount = MENUDATA31_COUNT;
#endif
#if(MENU_NUM >= 32)
strcpy(MY_Menu[32].name , name32);
MY_Menu[32].Data = (uint16_t *)&MENUDATA32;
MY_Menu[32].DataCount = MENUDATA32_COUNT;
#endif
#if(MENU_NUM >= 33)
strcpy(MY_Menu[33].name , name33);
MY_Menu[33].Data = (uint16_t *)&MENUDATA33;
MY_Menu[33].DataCount = MENUDATA33_COUNT;
#endif
#if(MENU_NUM >= 34)
strcpy(MY_Menu[34].name , name34);
MY_Menu[34].Data = (uint16_t *)&MENUDATA34;
MY_Menu[34].DataCount = MENUDATA34_COUNT;
#endif
#if(MENU_NUM >= 35)
strcpy(MY_Menu[35].name , name35);
MY_Menu[35].Data = (uint16_t *)&MENUDATA35;
MY_Menu[35].DataCount = MENUDATA35_COUNT;
#endif
#if(MENU_NUM >= 36)
strcpy(MY_Menu[36].name , name36);
MY_Menu[36].Data = (uint16_t *)&MENUDATA36;
MY_Menu[36].DataCount = MENUDATA36_COUNT;
#endif
#if(MENU_NUM >= 37)
strcpy(MY_Menu[37].name , name37);
MY_Menu[37].Data = (uint16_t *)&MENUDATA37;
MY_Menu[37].DataCount = MENUDATA37_COUNT;
#endif
#if(MENU_NUM >= 38)
strcpy(MY_Menu[38].name , name38);
MY_Menu[38].Data = (uint16_t *)&MENUDATA38;
MY_Menu[38].DataCount = MENUDATA38_COUNT;
#endif
#if(MENU_NUM >= 39)
strcpy(MY_Menu[39].name , name39);
MY_Menu[39].Data = (uint16_t *)&MENUDATA39;
MY_Menu[39].DataCount = MENUDATA39_COUNT;
#endif
#if(MENU_NUM >= 40)
strcpy(MY_Menu[40].name , name40);
MY_Menu[40].Data = (uint16_t *)&MENUDATA40;
MY_Menu[40].DataCount = MENUDATA40_COUNT;
#endif
#endif
}
//************************************************************************************************
void ZhiMo_Display(void )
{
	uint8_t i = 0,
	        j = 0;
	uint8_t ZhiMo[] = {
            0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xF8,0xF8,0xF0,0xE0,0xC0,0x80,0x00,0x00,
            0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x1F,0x1F,0x0F,0x07,0x03,0x01,0x00,0x00};
	for(i = 0; i<2 ;i++){
		OLED_Set_XY (0,2+i);
		for(j = 0;j<16 ;j++ ){
			OLED_WrDat (ZhiMo[j+i*16]);
		}
	}
}
//************************************************************************************************
void Menu_Handle(uint8_t Re_Data )
{
	static uint8_t Last_Data = 0;
	if(Re_Data != Last_Data ){
	    Last_Data = Re_Data ;
		switch (Re_Data )
		{
			case 1 :
				#if(MENU_NUM)
				#if(MENU_NUM >= 1)
				*MY_Menu[1].Data = Menu_Mode1_1 ;
				#endif
				#if(MENU_NUM >= 2)
				*MY_Menu[2].Data = Menu_Mode1_2 ;
				#endif
				#if(MENU_NUM >= 3)
				*MY_Menu[3].Data = Menu_Mode1_3 ;
				#endif
				#if(MENU_NUM >= 4)
				*MY_Menu[4].Data = Menu_Mode1_4 ;
				#endif
				#if(MENU_NUM >= 5)
				*MY_Menu[5].Data = Menu_Mode1_5 ;
				#endif
				#if(MENU_NUM >= 6)
				*MY_Menu[6].Data = Menu_Mode1_6 ;
				#endif
				#if(MENU_NUM >= 7)
				*MY_Menu[7].Data = Menu_Mode1_7 ;
				#endif
				#if(MENU_NUM >= 8)
				*MY_Menu[8].Data = Menu_Mode1_8 ;
				#endif
				#if(MENU_NUM >= 9)
				*MY_Menu[9].Data = Menu_Mode1_9 ;
				#endif
				#if(MENU_NUM >= 10)
				*MY_Menu[10].Data = Menu_Mode1_10 ;
				#endif
				#if(MENU_NUM >= 11)
				*MY_Menu[11].Data = Menu_Mode1_11 ;
				#endif
				#if(MENU_NUM >= 12)
				*MY_Menu[12].Data = Menu_Mode1_12 ;
				#endif
				#if(MENU_NUM >= 13)
				*MY_Menu[13].Data = Menu_Mode1_13 ;
				#endif
				#if(MENU_NUM >= 14)
				*MY_Menu[14].Data = Menu_Mode1_14 ;
				#endif
				#if(MENU_NUM >= 15)
				*MY_Menu[15].Data = Menu_Mode1_15 ;
				#endif
				#if(MENU_NUM >= 16)
				*MY_Menu[16].Data = Menu_Mode1_16 ;
				#endif
				#if(MENU_NUM >= 17)
				*MY_Menu[17].Data = Menu_Mode1_17 ;
				#endif
				#if(MENU_NUM >= 18)
				*MY_Menu[18].Data = Menu_Mode1_18 ;
				#endif
				#if(MENU_NUM >= 19)
				*MY_Menu[19].Data = Menu_Mode1_19 ;
				#endif
				#if(MENU_NUM >= 20)
				*MY_Menu[20].Data = Menu_Mode1_20 ;
				#endif
				#if(MENU_NUM >= 21)
				*MY_Menu[21].Data = Menu_Mode1_21 ;
				#endif
				#if(MENU_NUM >= 22)
				*MY_Menu[22].Data = Menu_Mode1_22 ;
				#endif
				#if(MENU_NUM >= 23)
				*MY_Menu[23].Data = Menu_Mode1_23 ;
				#endif
				#if(MENU_NUM >= 24)
				*MY_Menu[24].Data = Menu_Mode1_24 ;
				#endif
				#if(MENU_NUM >= 25)
				*MY_Menu[25].Data = Menu_Mode1_25 ;
				#endif
				#if(MENU_NUM >= 26)
				*MY_Menu[26].Data = Menu_Mode1_26 ;
				#endif
				#if(MENU_NUM >= 27)
				*MY_Menu[27].Data = Menu_Mode1_27 ;
				#endif
				#if(MENU_NUM >= 28)
				*MY_Menu[28].Data = Menu_Mode1_28 ;
				#endif
				#if(MENU_NUM >= 29)
				*MY_Menu[29].Data = Menu_Mode1_29 ;
				#endif
				#if(MENU_NUM >= 30)
				*MY_Menu[30].Data = Menu_Mode1_30 ;
				#endif
				#if(MENU_NUM >= 31)
				*MY_Menu[31].Data = Menu_Mode1_31 ;
				#endif
				#if(MENU_NUM >= 32)
				*MY_Menu[32].Data = Menu_Mode1_32 ;
				#endif
				#if(MENU_NUM >= 33)
				*MY_Menu[33].Data = Menu_Mode1_33 ;
				#endif
				#if(MENU_NUM >= 34)
				*MY_Menu[34].Data = Menu_Mode1_34 ;
				#endif
				#if(MENU_NUM >= 35)
				*MY_Menu[35].Data = Menu_Mode1_35 ;
				#endif
				#if(MENU_NUM >= 36)
				*MY_Menu[36].Data = Menu_Mode1_36 ;
				#endif
				#if(MENU_NUM >= 37)
				*MY_Menu[37].Data = Menu_Mode1_37 ;
				#endif
				#if(MENU_NUM >= 38)
				*MY_Menu[38].Data = Menu_Mode1_38 ;
				#endif
				#if(MENU_NUM >= 39)
				*MY_Menu[39].Data = Menu_Mode1_39 ;
				#endif
				#if(MENU_NUM >= 40)
				*MY_Menu[40].Data = Menu_Mode1_40 ;
				#endif
				#endif
				break ;
			case 2 : 
				#if(MENU_NUM)
				#if(MENU_NUM >= 1)
				*MY_Menu[1].Data = Menu_Mode2_1 ;
				#endif
				#if(MENU_NUM >= 2)
				*MY_Menu[2].Data = Menu_Mode2_2 ;
				#endif
				#if(MENU_NUM >= 3)
				*MY_Menu[3].Data = Menu_Mode2_3 ;
				#endif
				#if(MENU_NUM >= 4)
				*MY_Menu[4].Data = Menu_Mode2_4 ;
				#endif
				#if(MENU_NUM >= 5)
				*MY_Menu[5].Data = Menu_Mode2_5 ;
				#endif
				#if(MENU_NUM >= 6)
				*MY_Menu[6].Data = Menu_Mode2_6 ;
				#endif
				#if(MENU_NUM >= 7)
				*MY_Menu[7].Data = Menu_Mode2_7 ;
				#endif
				#if(MENU_NUM >= 8)
				*MY_Menu[8].Data = Menu_Mode2_8 ;
				#endif
				#if(MENU_NUM >= 9)
				*MY_Menu[9].Data = Menu_Mode2_9 ;
				#endif
				#if(MENU_NUM >= 10)
				*MY_Menu[10].Data = Menu_Mode2_10 ;
				#endif
				#if(MENU_NUM >= 11)
				*MY_Menu[11].Data = Menu_Mode2_11 ;
				#endif
				#if(MENU_NUM >= 12)
				*MY_Menu[12].Data = Menu_Mode2_12 ;
				#endif
				#if(MENU_NUM >= 13)
				*MY_Menu[13].Data = Menu_Mode2_13 ;
				#endif
				#if(MENU_NUM >= 14)
				*MY_Menu[14].Data = Menu_Mode2_14 ;
				#endif
				#if(MENU_NUM >= 15)
				*MY_Menu[15].Data = Menu_Mode2_15 ;
				#endif
				#if(MENU_NUM >= 16)
				*MY_Menu[16].Data = Menu_Mode2_16 ;
				#endif
				#if(MENU_NUM >= 17)
				*MY_Menu[17].Data = Menu_Mode2_17 ;
				#endif
				#if(MENU_NUM >= 18)
				*MY_Menu[18].Data = Menu_Mode2_18 ;
				#endif
				#if(MENU_NUM >= 19)
				*MY_Menu[19].Data = Menu_Mode2_19 ;
				#endif
				#if(MENU_NUM >= 20)
				*MY_Menu[20].Data = Menu_Mode2_20 ;
				#endif
				#if(MENU_NUM >= 21)
				*MY_Menu[21].Data = Menu_Mode2_21 ;
				#endif
				#if(MENU_NUM >= 22)
				*MY_Menu[22].Data = Menu_Mode2_22 ;
				#endif
				#if(MENU_NUM >= 23)
				*MY_Menu[23].Data = Menu_Mode2_23 ;
				#endif
				#if(MENU_NUM >= 24)
				*MY_Menu[24].Data = Menu_Mode2_24 ;
				#endif
				#if(MENU_NUM >= 25)
				*MY_Menu[25].Data = Menu_Mode2_25 ;
				#endif
				#if(MENU_NUM >= 26)
				*MY_Menu[26].Data = Menu_Mode2_26 ;
				#endif
				#if(MENU_NUM >= 27)
				*MY_Menu[27].Data = Menu_Mode2_27 ;
				#endif
				#if(MENU_NUM >= 28)
				*MY_Menu[28].Data = Menu_Mode2_28 ;
				#endif
				#if(MENU_NUM >= 29)
				*MY_Menu[29].Data = Menu_Mode2_29 ;
				#endif
				#if(MENU_NUM >= 30)
				*MY_Menu[30].Data = Menu_Mode2_30 ;
				#endif
				#if(MENU_NUM >= 31)
				*MY_Menu[31].Data = Menu_Mode2_31 ;
				#endif
				#if(MENU_NUM >= 32)
				*MY_Menu[32].Data = Menu_Mode2_32 ;
				#endif
				#if(MENU_NUM >= 33)
				*MY_Menu[33].Data = Menu_Mode2_33 ;
				#endif
				#if(MENU_NUM >= 34)
				*MY_Menu[34].Data = Menu_Mode2_34 ;
				#endif
				#if(MENU_NUM >= 35)
				*MY_Menu[35].Data = Menu_Mode2_35 ;
				#endif
				#if(MENU_NUM >= 36)
				*MY_Menu[36].Data = Menu_Mode2_36 ;
				#endif
				#if(MENU_NUM >= 37)
				*MY_Menu[37].Data = Menu_Mode2_37 ;
				#endif
				#if(MENU_NUM >= 38)
				*MY_Menu[38].Data = Menu_Mode2_38 ;
				#endif
				#if(MENU_NUM >= 39)
				*MY_Menu[39].Data = Menu_Mode2_39 ;
				#endif
				#if(MENU_NUM >= 40)
				*MY_Menu[40].Data = Menu_Mode2_40 ;
				#endif
				#endif
				break ;
			case 3 :
				#if(MENU_NUM)
				#if(MENU_NUM >= 1)
				*MY_Menu[1].Data = Menu_Mode3_1 ;
				#endif
				#if(MENU_NUM >= 2)
				*MY_Menu[2].Data = Menu_Mode3_2 ;
				#endif
				#if(MENU_NUM >= 3)
				*MY_Menu[3].Data = Menu_Mode3_3 ;
				#endif
				#if(MENU_NUM >= 4)
				*MY_Menu[4].Data = Menu_Mode3_4 ;
				#endif
				#if(MENU_NUM >= 5)
				*MY_Menu[5].Data = Menu_Mode3_5 ;
				#endif
				#if(MENU_NUM >= 6)
				*MY_Menu[6].Data = Menu_Mode3_6 ;
				#endif
				#if(MENU_NUM >= 7)
				*MY_Menu[7].Data = Menu_Mode3_7 ;
				#endif
				#if(MENU_NUM >= 8)
				*MY_Menu[8].Data = Menu_Mode3_8 ;
				#endif
				#if(MENU_NUM >= 9)
				*MY_Menu[9].Data = Menu_Mode3_9 ;
				#endif
				#if(MENU_NUM >= 10)
				*MY_Menu[10].Data = Menu_Mode3_10 ;
				#endif
				#if(MENU_NUM >= 11)
				*MY_Menu[11].Data = Menu_Mode3_11 ;
				#endif
				#if(MENU_NUM >= 12)
				*MY_Menu[12].Data = Menu_Mode3_12 ;
				#endif
				#if(MENU_NUM >= 13)
				*MY_Menu[13].Data = Menu_Mode3_13 ;
				#endif
				#if(MENU_NUM >= 14)
				*MY_Menu[14].Data = Menu_Mode3_14 ;
				#endif
				#if(MENU_NUM >= 15)
				*MY_Menu[15].Data = Menu_Mode3_15 ;
				#endif
				#if(MENU_NUM >= 16)
				*MY_Menu[16].Data = Menu_Mode3_16 ;
				#endif
				#if(MENU_NUM >= 17)
				*MY_Menu[17].Data = Menu_Mode3_17 ;
				#endif
				#if(MENU_NUM >= 18)
				*MY_Menu[18].Data = Menu_Mode3_18 ;
				#endif
				#if(MENU_NUM >= 19)
				*MY_Menu[19].Data = Menu_Mode3_19 ;
				#endif
				#if(MENU_NUM >= 20)
				*MY_Menu[20].Data = Menu_Mode3_20 ;
				#endif
				#if(MENU_NUM >= 21)
				*MY_Menu[21].Data = Menu_Mode3_21 ;
				#endif
				#if(MENU_NUM >= 22)
				*MY_Menu[22].Data = Menu_Mode3_22 ;
				#endif
				#if(MENU_NUM >= 23)
				*MY_Menu[23].Data = Menu_Mode3_23 ;
				#endif
				#if(MENU_NUM >= 24)
				*MY_Menu[24].Data = Menu_Mode3_24 ;
				#endif
				#if(MENU_NUM >= 25)
				*MY_Menu[25].Data = Menu_Mode3_25 ;
				#endif
				#if(MENU_NUM >= 26)
				*MY_Menu[26].Data = Menu_Mode3_26 ;
				#endif
				#if(MENU_NUM >= 27)
				*MY_Menu[27].Data = Menu_Mode3_27 ;
				#endif
				#if(MENU_NUM >= 28)
				*MY_Menu[28].Data = Menu_Mode3_28 ;
				#endif
				#if(MENU_NUM >= 29)
				*MY_Menu[29].Data = Menu_Mode3_29 ;
				#endif
				#if(MENU_NUM >= 30)
				*MY_Menu[30].Data = Menu_Mode3_30 ;
				#endif
				#if(MENU_NUM >= 31)
				*MY_Menu[31].Data = Menu_Mode3_31 ;
				#endif
				#if(MENU_NUM >= 32)
				*MY_Menu[32].Data = Menu_Mode3_32 ;
				#endif
				#if(MENU_NUM >= 33)
				*MY_Menu[33].Data = Menu_Mode3_33 ;
				#endif
				#if(MENU_NUM >= 34)
				*MY_Menu[34].Data = Menu_Mode3_34 ;
				#endif
				#if(MENU_NUM >= 35)
				*MY_Menu[35].Data = Menu_Mode3_35 ;
				#endif
				#if(MENU_NUM >= 36)
				*MY_Menu[36].Data = Menu_Mode3_36 ;
				#endif
				#if(MENU_NUM >= 37)
				*MY_Menu[37].Data = Menu_Mode3_37 ;
				#endif
				#if(MENU_NUM >= 38)
				*MY_Menu[38].Data = Menu_Mode3_38 ;
				#endif
				#if(MENU_NUM >= 39)
				*MY_Menu[39].Data = Menu_Mode3_39 ;
				#endif
				#if(MENU_NUM >= 40)
				*MY_Menu[40].Data = Menu_Mode3_40 ;
				#endif
				#endif
				break ;
			default :
				break ;
		}
	}
}
//************************************************************************************************
void menu (void )
{
	uint8_t key_state = 0,
	        count = 1;
	OLED_Clear ();
	ZhiMo_Display();
	for( ; ; ){
		key_state = key_scan() ;
		switch (key_state )
		{
			case 0 :
				break ;
			case 1 :    //ZUO              // 按一次
				if((*MY_Menu[count].Data ) == 65535){
					
				}else{
					(*MY_Menu[count].Data )+= MY_Menu[count].DataCount ;
				}
				break ;
			case 2 :    //YOU
				if((*MY_Menu[count].Data ) == 0){
					
				}else{
					(*MY_Menu[count].Data )-= MY_Menu[count].DataCount ;
				}
				break ;
			case 3 :    //SHANG
				count-- ;
				break ;
			case 4 :    //XIA
				count++ ;
				break ;
			case 6 :    //复位	DULI
				key_state =8;			//复位
				break ;
			case 5 :    //ZHONG
			default :
				break ;
		}
		//********************************************************************************************
		Menu_Handle(*MY_Menu[MENU_NUM + 1].Data );
		#if(MENU_NUM == 0)
		    count = 1;
			
			OLED_Write_Char (9,0,' ' );
			OLED_Write_Char (9,2,':' );
			OLED_Write_Char (9,4,':' );
			OLED_Write_Char (9,6,':' );
		
			OLED_Write_String (11,0,(uint8_t *)"     " );
			OLED_Write_Num5 (11,2,*MY_Menu[count].Data );
			OLED_Write_Num5 (11,4,*MY_Menu[count + 1].Data );
			OLED_Write_Num5 (11,6,*MY_Menu[count + 2].Data );
		#endif
		#if(MENU_NUM )
		if(count < 1){
		    count = MENU_NUM + 1;
		}
		if(count > MENU_NUM + 1){
		    count = 1 ;
		}
		
		#if(MENU_NUM == 1)
			switch (count ){
				case MENU_NUM :
					OLED_Write_Char (9,0,' ' );
					OLED_Write_Char (9,2,':' );
					OLED_Write_Char (9,4,':' );
					OLED_Write_Char (9,6,' ' );
				
					OLED_Write_String (11,0,(uint8_t *)"     " );
					OLED_Write_Num5 (11,2,*MY_Menu[count].Data );
					OLED_Write_Num5 (11,4,*MY_Menu[count + 1].Data );
					OLED_Write_String (11,6,(uint8_t *)"     " );
					break ;
				case (MENU_NUM + 1) :
					OLED_Write_Char (9,0,':' );
					OLED_Write_Char (9,2,':' );
					OLED_Write_Char (9,4,' ' );
					OLED_Write_Char (9,6,' ' );
				
					OLED_Write_Num5 (11,0,*MY_Menu[count - 1].Data );
					OLED_Write_Num5 (11,2,*MY_Menu[count].Data );
					OLED_Write_String (11,4,(uint8_t *)"     " );
					OLED_Write_String (11,6,(uint8_t *)"     " );
					break ;
				default :
					OLED_Write_Char (9,0,':' );
					OLED_Write_Char (9,2,':' );
					OLED_Write_Char (9,4,':' );
					OLED_Write_Char (9,6,':' );
				
					OLED_Write_Num5 (11,0,*MY_Menu[count-1].Data );
					OLED_Write_Num5 (11,2,*MY_Menu[count].Data );
					OLED_Write_Num5 (11,4,*MY_Menu[count+1].Data );
					OLED_Write_Num5 (11,6,*MY_Menu[count+2].Data );
					break ;
			}
		#else
			switch (count ){
				case 1 :
					OLED_Write_Char (9,0,' ' );
					OLED_Write_Char (9,2,':' );
					OLED_Write_Char (9,4,':' );
					OLED_Write_Char (9,6,':' );
				
					OLED_Write_String (11,0,(uint8_t *)"     " );
					OLED_Write_Num5 (11,2,*MY_Menu[count].Data );
					OLED_Write_Num5 (11,4,*MY_Menu[count + 1].Data );
					OLED_Write_Num5 (11,6,*MY_Menu[count + 2].Data );
					break ;
				case MENU_NUM :
					OLED_Write_Char (9,0,':' );
					OLED_Write_Char (9,2,':' );
					OLED_Write_Char (9,4,':' );
					OLED_Write_Char (9,6,' ' );
				
					OLED_Write_Num5 (11,0,*MY_Menu[count - 1].Data );
					OLED_Write_Num5 (11,2,*MY_Menu[count].Data );
					OLED_Write_Num5 (11,4,*MY_Menu[count + 1].Data );
					OLED_Write_String (11,6,(uint8_t *)"     " );
					break ;
				case (MENU_NUM + 1) :
					OLED_Write_Char (9,0,':' );
					OLED_Write_Char (9,2,':' );
					OLED_Write_Char (9,4,' ' );
					OLED_Write_Char (9,6,' ' );
				
					OLED_Write_Num5 (11,0,*MY_Menu[count - 1].Data );
					OLED_Write_Num5 (11,2,*MY_Menu[count].Data );
					OLED_Write_String (11,4,(uint8_t *)"     " );
					OLED_Write_String (11,6,(uint8_t *)"     " );
					break ;
				default :
					OLED_Write_Char (9,0,':' );
					OLED_Write_Char (9,2,':' );
					OLED_Write_Char (9,4,':' );
					OLED_Write_Char (9,6,':' );
				
					OLED_Write_Num5 (11,0,*MY_Menu[count-1].Data );
					OLED_Write_Num5 (11,2,*MY_Menu[count].Data );
					OLED_Write_Num5 (11,4,*MY_Menu[count+1].Data );
					OLED_Write_Num5 (11,6,*MY_Menu[count+2].Data );
					break ;
			}
		
		#endif
		#endif
		OLED_Write_String (2,0,(uint8_t *)MY_Menu[count - 1].name );
		OLED_Write_String (2,2,(uint8_t *)MY_Menu[count    ].name );
		OLED_Write_String (2,4,(uint8_t *)MY_Menu[count + 1].name );
		OLED_Write_String (2,6,(uint8_t *)MY_Menu[count + 2].name );
			
		if(key_state  == 8){
		    OLED_Clear ();
			break ;
		}
		DelayMs (10);
	}
}

//************************************************************************************************













