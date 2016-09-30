#ifndef _MENU_H_
#define _MENU_H_

#include "gpio.h"

extern uint8_t a;
extern uint16_t 
			T_XuanZhe_Hang_Buff ,
			T_YuZhi_Max ,
			DingShi_ShiJian,
//			ZhangAi_PianYi_Liang,
//			JianSu_ChangShu,
//			JianSu_Hang,

			T_P_ZD ,
			T_P_WD ,
			T_P_X_S ,
			T_P_D_S ,
			T_P_PoDao ,
			T_P_Z_Ai ,
//			
//			T_P_DiuXian_P ,
//			
			T_D_ZD ,
			T_D_WD ,
			T_D_X_S ,
			T_D_D_S ,
			T_D_PoDao ,
			T_D_Z_Ai ,


			V_ZhiDao ,
			V_WanDao ,
			V_X_S ,
			V_D_S ,
			V_PoDao ,
			V_Z_Ai ,
//			
//			V_RuWan,
//			T_P_Ru_W,
			T_D_Ru_W
			;
//			T_ShiZi_GS,


struct DEFMENU
{
	char      name[6];
	uint16_t* Data;
	uint8_t   DataCount ;
};
//************************************************************************************************
#define MENU_NUM    40			//	40(max)    14                                                           

//************************************************************************************************
#if(MENU_NUM)
#if(MENU_NUM >= 1)
#define         name1            	 " V.ZD "// hang 
#define         MENUDATA1            V_ZhiDao
#define         MENUDATA1_COUNT      10
#define         Menu_Mode1_1         430
#define         Menu_Mode2_1         350
#define         Menu_Mode3_1         200
#endif
#if(MENU_NUM >= 2)                   
#define         name2                " V.WD "
#define         MENUDATA2            V_WanDao
#define         MENUDATA2_COUNT      10
#define         Menu_Mode1_2         250
#define         Menu_Mode2_2         280
#define         Menu_Mode3_2         200
#endif
#if(MENU_NUM >= 3)
#define         name3                "V.X.S "
#define         MENUDATA3            V_X_S
#define         MENUDATA3_COUNT      10
#define         Menu_Mode1_3         250
#define         Menu_Mode2_3         250
#define         Menu_Mode3_3         200
#endif
#if(MENU_NUM >= 4)
#define         name4                "V.D.S "
#define         MENUDATA4            V_D_S
#define         MENUDATA4_COUNT      10
#define         Menu_Mode1_4         37
#define         Menu_Mode2_4         40
#define         Menu_Mode3_4         40
#endif
#if(MENU_NUM >= 5)
#define         name5                "V.P.D "//
#define         MENUDATA5            V_PoDao
#define         MENUDATA5_COUNT      10
#define         Menu_Mode1_5         56
#define         Menu_Mode2_5         75
#define         Menu_Mode3_5         50
#endif
#if(MENU_NUM >= 6)
#define         name6                "V.Z.Ai"//
#define         MENUDATA6            V_Z_Ai
#define         MENUDATA6_COUNT      10
#define         Menu_Mode1_6         50
#define         Menu_Mode2_6         60
#define         Menu_Mode3_6         50
#endif
#if(MENU_NUM >= 7)
#define         name7                "T.P.ZD"//
#define         MENUDATA7            T_P_ZD//
#define         MENUDATA7_COUNT      1
#define         Menu_Mode1_7         30
#define         Menu_Mode2_7         30
#define         Menu_Mode3_7         30
#endif
#if(MENU_NUM >= 8)
#define         name8                "T.P.WD"//
#define         MENUDATA8            T_P_WD//
#define         MENUDATA8_COUNT      1
#define         Menu_Mode1_8         200
#define         Menu_Mode2_8         100
#define         Menu_Mode3_8         100
#endif
#if(MENU_NUM >= 9)
#define         name9                "T.P.XS"//
#define         MENUDATA9            T_P_X_S//
#define         MENUDATA9_COUNT      1
#define         Menu_Mode1_9         15
#define         Menu_Mode2_9         75
#define         Menu_Mode3_9         15
#endif
#if(MENU_NUM >= 10)
#define         name10               "T.P.DS"//
#define         MENUDATA10            T_P_D_S//
#define         MENUDATA10_COUNT      1
#define         Menu_Mode1_10         1
#define         Menu_Mode2_10         1
#define         Menu_Mode3_10         1
#endif
#if(MENU_NUM >= 11)
#define         name11                "T.P.PD"//T.P.DX
#define         MENUDATA11            T_P_PoDao//T_P_DiuXian_P
#define         MENUDATA11_COUNT      1
#define         Menu_Mode1_11         38
#define         Menu_Mode2_11         30
#define         Menu_Mode3_11         30
#endif
#if(MENU_NUM >= 12)
#define         name12                "P.Z.Ai"
#define         MENUDATA12            T_P_Z_Ai
#define         MENUDATA12_COUNT      1
#define         Menu_Mode1_12         60
#define         Menu_Mode2_12         60
#define         Menu_Mode3_12         60
#endif
#if(MENU_NUM >= 13)
#define         name13                "T.D.ZD"
#define         MENUDATA13            T_D_ZD
#define         MENUDATA13_COUNT      1
#define         Menu_Mode1_13         20
#define         Menu_Mode2_13         20
#define         Menu_Mode3_13         20
#endif
#if(MENU_NUM >= 14)
#define         name14                "T.D.WD"
#define         MENUDATA14            T_D_WD
#define         MENUDATA14_COUNT      1
#define         Menu_Mode1_14         60
#define         Menu_Mode2_14         60
#define         Menu_Mode3_14         60
#endif
#if(MENU_NUM >= 15)
#define         name15                "T.D.XS"
#define         MENUDATA15            T_D_X_S
#define         MENUDATA15_COUNT      1
#define         Menu_Mode1_15         100
#define         Menu_Mode2_15         145
#define         Menu_Mode3_15         100
#endif
#if(MENU_NUM >= 16)
#define         name16                "T.D.DS"
#define         MENUDATA16            T_D_D_S
#define         MENUDATA16_COUNT      1
#define         Menu_Mode1_16         430
#define         Menu_Mode2_16         350
#define         Menu_Mode3_16         200
#endif
#if(MENU_NUM >= 17)
#define         name17                "T.D.PD"
#define         MENUDATA17            T_D_PoDao
#define         MENUDATA17_COUNT      1
#define         Menu_Mode1_17         15
#define         Menu_Mode2_17         15
#define         Menu_Mode3_17         15
#endif
#if(MENU_NUM >= 18)
#define         name18                "D.Z.Ai"
#define         MENUDATA18            T_D_Z_Ai
#define         MENUDATA18_COUNT      1
#define         Menu_Mode1_18         40
#define         Menu_Mode2_18         40
#define         Menu_Mode3_18         40
#endif
#if(MENU_NUM >= 19)
#define         name19                "T.P.RW"
#define         MENUDATA19            a//T_P_Ru_W//T_P_DiuXian_P
#define         MENUDATA19_COUNT      1
#define         Menu_Mode1_19         430
#define         Menu_Mode2_19         350
#define         Menu_Mode3_19         200
#endif
#if(MENU_NUM >= 20)
#define         name20                "T.D.RW"//V.RWan
#define         MENUDATA20            a//T_D_Ru_W//V_RuWan
#define         MENUDATA20_COUNT      1
#define         Menu_Mode1_20         60
#define         Menu_Mode2_20         90
#define         Menu_Mode3_20         120
#endif
#if(MENU_NUM >= 21)
#define         name21                "JS_GeS"
#define         MENUDATA21            a//JianSu_ChangShu
#define         MENUDATA21_COUNT      1
#define         Menu_Mode1_21         9
#define         Menu_Mode2_21         12
#define         Menu_Mode3_21         9
#endif
#if(MENU_NUM >= 22)
#define         name22                "JS.Row"
#define         MENUDATA22            a//JianSu_Hang
#define         MENUDATA22_COUNT      1
#define         Menu_Mode1_22         133
#define         Menu_Mode2_22         133
#define         Menu_Mode3_22         133
#endif
#if(MENU_NUM >= 23)
#define         name23                "a     "
#define         MENUDATA23            a
#define         MENUDATA23_COUNT      1
#define         Menu_Mode1_23         0
#define         Menu_Mode2_23         0
#define         Menu_Mode3_23         0
#endif
#if(MENU_NUM >= 24)
#define         name24                "a     "		
#define         MENUDATA24            a
#define         MENUDATA24_COUNT      1
#define         Menu_Mode1_24         1
#define         Menu_Mode2_24         10
#define         Menu_Mode3_24         1
#endif
#if(MENU_NUM >= 25)
#define         name25                "a     "	//SZ.GS 
#define         MENUDATA25            a//T_ShiZi_GS
#define         MENUDATA25_COUNT      1
#define         Menu_Mode1_25         a
#define         Menu_Mode2_25         a
#define         Menu_Mode3_25         a
#endif
#if(MENU_NUM >= 26)
#define         name26                "a     "
#define         MENUDATA26            a
#define         MENUDATA26_COUNT      1
#define         Menu_Mode1_26         a
#define         Menu_Mode2_26         a
#define         Menu_Mode3_26         a
#endif
#if(MENU_NUM >= 27)
#define         name27                "a     "
#define         MENUDATA27            a
#define         MENUDATA27_COUNT      1
#define         Menu_Mode1_27         a
#define         Menu_Mode2_27         a
#define         Menu_Mode3_27         a
#endif
#if(MENU_NUM >= 28)
#define         name28                "a     "
#define         MENUDATA28            a
#define         MENUDATA28_COUNT      1
#define         Menu_Mode1_28         a
#define         Menu_Mode2_28         a
#define         Menu_Mode3_28         a
#endif
#if(MENU_NUM >= 29)
#define         name29                "a     "
#define         MENUDATA29            a
#define         MENUDATA29_COUNT      1
#define         Menu_Mode1_29         a
#define         Menu_Mode2_29         a
#define         Menu_Mode3_29         a
#endif
#if(MENU_NUM >= 30)
#define         name30                "a     "
#define         MENUDATA30            a
#define         MENUDATA30_COUNT      1
#define         Menu_Mode1_30         a
#define         Menu_Mode2_30         a
#define         Menu_Mode3_30         a
#endif
#if(MENU_NUM >= 31)
#define         name31                "a     "
#define         MENUDATA31            a
#define         MENUDATA31_COUNT      1
#define         Menu_Mode1_31         a
#define         Menu_Mode2_31         a
#define         Menu_Mode3_31         a
#endif
#if(MENU_NUM >= 32)
#define         name32                "a     "
#define         MENUDATA32            a
#define         MENUDATA32_COUNT      1
#define         Menu_Mode1_32         a
#define         Menu_Mode2_32         a
#define         Menu_Mode3_32         a
#endif
#if(MENU_NUM >= 33)
#define         name33                "a     "
#define         MENUDATA33            a
#define         MENUDATA33_COUNT      1
#define         Menu_Mode1_33         a
#define         Menu_Mode2_33         a
#define         Menu_Mode3_33         a
#endif
#if(MENU_NUM >= 34)
#define         name34                "a     "
#define         MENUDATA34            a
#define         MENUDATA34_COUNT      0
#define         Menu_Mode1_34         a
#define         Menu_Mode2_34         a
#define         Menu_Mode3_34         a
#endif
#if(MENU_NUM >= 35)
#define         name35                "a     "
#define         MENUDATA35            a
#define         MENUDATA35_COUNT      1
#define         Menu_Mode1_35         a
#define         Menu_Mode2_35         a
#define         Menu_Mode3_35         a
#endif
#if(MENU_NUM >= 36)
#define         name36                "a     "
#define         MENUDATA36            a
#define         MENUDATA36_COUNT      1
#define         Menu_Mode1_36         a
#define         Menu_Mode2_36         a
#define         Menu_Mode3_36         a
#endif
#if(MENU_NUM >= 37)
#define         name37                "Z.Ai.`"
#define         MENUDATA37            a//ZhangAi_PianYi_Liang
#define         MENUDATA37_COUNT      1
#define         Menu_Mode1_37         3
#define         Menu_Mode2_37         3
#define         Menu_Mode3_37         2
#endif
#if(MENU_NUM >= 38)
#define         name38                "T.XZ.H"
#define         MENUDATA38            T_XuanZhe_Hang_Buff//T_XuanZhe_Down_Hang
#define         MENUDATA38_COUNT      1
#define         Menu_Mode1_38         9
#define         Menu_Mode2_38         12
#define         Menu_Mode3_38         15
#endif
#if(MENU_NUM >= 39)
#define         name39                "YZ.Max"
#define         MENUDATA39            T_YuZhi_Max
#define         MENUDATA39_COUNT      1
#define         Menu_Mode1_39         136
#define         Menu_Mode2_39         136
#define         Menu_Mode3_39         136
#endif
#if(MENU_NUM >= 40)
#define         name40                "DS.TC "
#define         MENUDATA40            DingShi_ShiJian
#define         MENUDATA40_COUNT      1
#define         Menu_Mode1_40         0
#define         Menu_Mode2_40         0
#define         Menu_Mode3_40         0
#endif
#endif
//************************************************************************************************

//************************************************************************************************
void menu (void );
void Menu_Init (void );
//************************************************************************************************

#endif 
//**************************************************************************

