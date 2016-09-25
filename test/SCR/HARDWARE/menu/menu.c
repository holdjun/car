#include "menu.h"
#include "sys.h"
#include "oled.h"
#include "gpio.h"
#include "delay.h"
#include "string.h"
#include "Mydefine.h"


uint8_t hang = 1;

struct Menu_Select Allnum[All_Count];
uint16_t  Default=0;

void Menu_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct1;
	
//	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_4;                    //
//	GPIO_InitStruct1.GPIO_InitState = Bit_SET;
//	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
//	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP; //
//	GPIO_InitStruct1.GPIOx = PTA;
//	GPIO_Init(&GPIO_InitStruct1);

	GPIO_InitStruct1.GPIO_Pin = Key_left_PIN;                    //
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU; //上拉输入
	GPIO_InitStruct1.GPIOx = Key_left_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = Key_down_PIN;                    //up
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU; //上拉输入
	GPIO_InitStruct1.GPIOx = Key_down_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = Key_right_PIN;                    //
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU; //上拉输入
	GPIO_InitStruct1.GPIOx = Key_right_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = Key_up_PIN;                    //down
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU; //上拉输入
	GPIO_InitStruct1.GPIOx = Key_up_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	
//	GPIO_InitStruct1.GPIO_Pin = Key_in_PIN;                    //按键
//	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
//	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
//	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU; //上拉输入
//	GPIO_InitStruct1.GPIOx = Key_in_PORT;
//	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = Key_1_PIN;                    //按键
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU; //上拉输入
	GPIO_InitStruct1.GPIOx = Key_1_PORT;
	GPIO_Init(&GPIO_InitStruct1);

#if(All_Count >= 1)
   strcpy(Allnum[0].name, name0);  //
   Allnum[0].va = (uint16_t*)&(name0_value);	//
   Allnum[0].sub = name0_sub;      //
#endif


#if(All_Count >= 2)
   strcpy(Allnum[1].name, name1);
   Allnum[1].va = (uint16_t*)&(name1_value);			
   Allnum[1].sub = name1_sub;
#endif


#if(All_Count >= 3)
   strcpy(Allnum[2].name, name2);
   Allnum[2].va = (uint16_t*)&(name2_value);			
   Allnum[2].sub = name2_sub;
#endif


#if(All_Count >= 4)
   strcpy(Allnum[3].name, name3);
   Allnum[3].va = (uint16_t*)&(name3_value);			
   Allnum[3].sub = name3_sub;
#endif


#if(All_Count >= 5)
   strcpy(Allnum[4].name, name4);
   Allnum[4].va = (uint16_t*)&(name4_value);			
   Allnum[4].sub = name4_sub;
#endif


#if(All_Count >= 6)
   strcpy(Allnum[5].name, name5);
   Allnum[5].va = (uint16_t*)&(name5_value);			
   Allnum[5].sub = name5_sub;
#endif


#if(All_Count >= 7)
   strcpy(Allnum[6].name, name6);
   Allnum[6].va = (uint16_t*)&(name6_value);			
   Allnum[6].sub = name6_sub;
#endif


#if(All_Count >= 8)
   strcpy(Allnum[7].name, name7);
   Allnum[7].va = (uint16_t*)&(name7_value);			
   Allnum[7].sub = name7_sub;
#endif


#if(All_Count >= 9)
   strcpy(Allnum[8].name, name8);
   Allnum[8].va = (uint16_t*)&(name8_value);			
   Allnum[8].sub = name8_sub;
#endif


#if(All_Count >= 10)
   strcpy(Allnum[9].name, name9);
   Allnum[9].va = (uint16_t*)&(name9_value);			
   Allnum[9].sub = name9_sub;
#endif


#if(All_Count >= 11)
   strcpy(Allnum[10].name, name10);
   Allnum[10].va = (uint16_t*)&(name10_value);			
   Allnum[10].sub = name10_sub;
#endif


#if(All_Count >= 12)
   strcpy(Allnum[11].name, name11);
   Allnum[11].va = (uint16_t*)&(name11_value);			
   Allnum[11].sub = name11_sub;
#endif


#if(All_Count >= 13)
   strcpy(Allnum[12].name, name12);
   Allnum[12].va = (uint16_t*)&(name12_value);			
   Allnum[12].sub = name12_sub;
#endif


#if(All_Count >= 14)
   strcpy(Allnum[13].name, name13);
   Allnum[13].va = (uint16_t*)&(name13_value);			
   Allnum[13].sub = name13_sub;
#endif


#if(All_Count >= 15)
   strcpy(Allnum[14].name, name14);
   Allnum[14].va = (uint16_t*)&(name14_value);			
   Allnum[14].sub = name14_sub;
#endif


#if(All_Count >= 16)
   strcpy(Allnum[15].name, name15);
   Allnum[15].va = (uint16_t*)&(name15_value);			
   Allnum[15].sub = name15_sub;
#endif


#if(All_Count >= 17)
   strcpy(Allnum[16].name, name16);
   Allnum[16].va = (uint16_t*)&(name16_value);			
   Allnum[16].sub = name16_sub;
#endif


#if(All_Count >= 18)
   strcpy(Allnum[17].name, name17);
   Allnum[17].va = (uint16_t*)&(name17_value);			
   Allnum[17].sub = name17_sub;
#endif


#if(All_Count >= 19)
   strcpy(Allnum[18].name, name18);
   Allnum[18].va = (uint16_t*)&(name18_value);			
   Allnum[18].sub = name18_sub;
#endif


#if(All_Count >= 20)
   strcpy(Allnum[19].name, name19);
   Allnum[19].va = (uint16_t*)&(name19_value);			
   Allnum[19].sub = name19_sub;
#endif


#if(All_Count >= 21)
   strcpy(Allnum[20].name, name20);
   Allnum[20].va = (uint16_t*)&(name20_value);			
   Allnum[20].sub = name20_sub;
#endif


#if(All_Count >= 22)
   strcpy(Allnum[21].name, name21);
   Allnum[21].va = (uint16_t*)&(name21_value);			
   Allnum[21].sub = name21_sub;
#endif


#if(All_Count >= 23)
   strcpy(Allnum[22].name, name22);
   Allnum[22].va = (uint16_t*)&(name22_value);			
   Allnum[22].sub = name22_sub;
#endif


#if(All_Count >= 24)
   strcpy(Allnum[23].name, name23);
   Allnum[23].va = (uint16_t*)&(name23_value);			
   Allnum[23].sub = name23_sub;
#endif


#if(All_Count >= 25)
   strcpy(Allnum[24].name, name24);
   Allnum[24].va = (uint16_t*)&(name24_value);			
   Allnum[24].sub = name24_sub;
#endif


#if(All_Count >= 26)
   strcpy(Allnum[25].name, name25);
   Allnum[25].va = (uint16_t*)&(name25_value);			
   Allnum[25].sub = name25_sub;
#endif


#if(All_Count >= 27)
   strcpy(Allnum[26].name, name26);
   Allnum[26].va = (uint16_t*)&(name26_value);			
   Allnum[26].sub = name26_sub;
#endif


#if(All_Count >= 28)
   strcpy(Allnum[27].name, name27);
   Allnum[27].va = (uint16_t*)&(name27_value);			
   Allnum[27].sub = name27_sub;
#endif


#if(All_Count >= 29)
   strcpy(Allnum[28].name, name28);
   Allnum[28].va = (uint16_t*)&(name28_value);			
   Allnum[28].sub = name28_sub;
#endif


#if(All_Count >= 30)
   strcpy(Allnum[29].name, name29);
   Allnum[29].va = (uint16_t*)&(name29_value);			
   Allnum[29].sub = name29_sub;
#endif


#if(All_Count >= 31)
   strcpy(Allnum[30].name, name30);
   Allnum[30].va = (uint16_t*)&(name30_value);			
   Allnum[30].sub = name30_sub;
#endif


#if(All_Count >= 32)
   strcpy(Allnum[31].name, name31);
   Allnum[31].va = (uint16_t*)&(name31_value);			
   Allnum[31].sub = name31_sub;
#endif


//#if(All_Count >= 33)
//   strcpy(Allnum[32].name, name32);
//   Allnum[32].va = (uint16_t*)&(name32_value);			
//   Allnum[32].sub = name32_sub;
//   Allnum[32].type = name32_type;
//#endif


//#if(All_Count >= 34)
//   strcpy(Allnum[33].name, name33);
//   Allnum[33].va = (uint16_t*)&(name33_value);			
//   Allnum[33].sub = name33_sub;
//   Allnum[33].type = name33_type;
//#endif


//#if(All_Count >= 35)
//   strcpy(Allnum[34].name, name34);
//   Allnum[34].va = (uint16_t*)&(name34_value);			
//   Allnum[34].sub = name34_sub;
//   Allnum[34].type = name34_type;
//#endif


//#if(All_Count >= 36)
//   strcpy(Allnum[35].name, name35);
//   Allnum[35].va = (uint16_t*)&(name35_value);			
//   Allnum[35].sub = name35_sub;
//   Allnum[35].type = name35_type;
//#endif


//#if(All_Count >= 37)
//   strcpy(Allnum[36].name, name36);
//   Allnum[36].va = (uint16_t*)&(name36_value);			
//   Allnum[36].sub = name36_sub;
//   Allnum[36].type = name36_type;
//#endif


//#if(All_Count >= 38)
//   strcpy(Allnum[37].name, name37);
//   Allnum[37].va = (uint16_t*)&(name37_value);			
//   Allnum[37].sub = name37_sub;
//   Allnum[37].type = name37_type;
//#endif


//#if(All_Count >= 39)
//   strcpy(Allnum[38].name, name38);
//   Allnum[38].va = (uint16_t*)&(name38_value);			
//   Allnum[38].sub = name38_sub;
//   Allnum[38].type = name38_type;
//#endif


//#if(All_Count >= 40)
//   strcpy(Allnum[39].name, name39);
//   Allnum[39].va = (uint16_t*)&(name39_value);			
//   Allnum[39].sub = name39_sub;
//   Allnum[39].type = name39_type;
//#endif


//#if(All_Count >= 41)
//   strcpy(Allnum[40].name, name40);
//   Allnum[40].va = (uint16_t*)&(name40_value);			
//   Allnum[40].sub = name40_sub;
//   Allnum[40].type = name40_type;
//#endif


//#if(All_Count >= 42)
//   strcpy(Allnum[41].name, name41);
//   Allnum[41].va = (uint16_t*)&(name41_value);			
//   Allnum[41].sub = name41_sub;
//   Allnum[41].type = name41_type;
//#endif


//#if(All_Count >= 43)
//   strcpy(Allnum[42].name, name42);
//   Allnum[42].va = (uint16_t*)&(name42_value);			
//   Allnum[42].sub = name42_sub;
//   Allnum[42].type = name42_type;
//#endif


//#if(All_Count >= 44)
//   strcpy(Allnum[43].name, name43);
//   Allnum[43].va = (uint16_t*)&(name43_value);			
//   Allnum[43].sub = name43_sub;
//   Allnum[43].type = name43_type;
//#endif


//#if(All_Count >= 45)
//   strcpy(Allnum[44].name, name44);
//   Allnum[44].va = (uint16_t*)&(name44_value);			
//   Allnum[44].sub = name44_sub;
//   Allnum[44].type = name44_type;
//#endif


//#if(All_Count >= 46)
//   strcpy(Allnum[45].name, name45);
//   Allnum[45].va = (uint16_t*)&(name45_value);			
//   Allnum[45].sub = name45_sub;
//   Allnum[45].type = name45_type;
//#endif


//#if(All_Count >= 47)
//   strcpy(Allnum[46].name, name46);
//   Allnum[46].va = (uint16_t*)&(name46_value);			
//   Allnum[46].sub = name46_sub;
//   Allnum[46].type = name46_type;
//#endif


//#if(All_Count >= 48)
//   strcpy(Allnum[47].name, name47);
//   Allnum[47].va = (uint16_t*)&(name47_value);			
//   Allnum[47].sub = name47_sub;
//   Allnum[47].type = name47_type;
//#endif


//#if(All_Count >= 49)
//   strcpy(Allnum[48].name, name48);
//   Allnum[48].va = (uint16_t*)&(name48_value);			
//   Allnum[48].sub = name48_sub;
//   Allnum[48].type = name48_type;
//#endif


//#if(All_Count >= 50)
//   strcpy(Allnum[49].name, name49);
//   Allnum[49].va = (uint16_t*)&(name49_value);			
//   Allnum[49].sub = name49_sub;
//   Allnum[49].type = name49_type;
//#endif


//#if(All_Count >= 51)
//   strcpy(Allnum[50].name, name50);
//   Allnum[50].va = (uint16_t*)&(name50_value);			
//   Allnum[50].sub = name50_sub;
//   Allnum[50].type = name50_type;
//#endif


//#if(All_Count >= 52)
//   strcpy(Allnum[51].name, name51);
//   Allnum[51].va = (uint16_t*)&(name51_value);			
//   Allnum[51].sub = name51_sub;
//   Allnum[51].type = name51_type;
//#endif


//#if(All_Count >= 53)
//   strcpy(Allnum[52].name, name52);
//   Allnum[52].va = (uint16_t*)&(name52_value);			
//   Allnum[52].sub = name52_sub;
//   Allnum[52].type = name52_type;
//#endif


//#if(All_Count >= 54)
//   strcpy(Allnum[53].name, name53);
//   Allnum[53].va = (uint16_t*)&(name53_value);			
//   Allnum[53].sub = name53_sub;
//   Allnum[53].type = name53_type;
//#endif


//#if(All_Count >= 55)
//   strcpy(Allnum[54].name, name54);
//   Allnum[54].va = (uint16_t*)&(name54_value);			
//   Allnum[54].sub = name54_sub;
//   Allnum[54].type = name54_type;
//#endif


//#if(All_Count >= 56)
//   strcpy(Allnum[55].name, name55);
//   Allnum[55].va = (uint16_t*)&(name55_value);			
//   Allnum[55].sub = name55_sub;
//   Allnum[55].type = name55_type;
//#endif


//#if(All_Count >= 57)
//   strcpy(Allnum[56].name, name56);
//   Allnum[56].va = (uint16_t*)&(name56_value);			
//   Allnum[56].sub = name56_sub;
//   Allnum[56].type = name56_type;
//#endif


//#if(All_Count >= 58)
//   strcpy(Allnum[57].name, name57);
//   Allnum[57].va = (uint16_t*)&(name57_value);			
//   Allnum[57].sub = name57_sub;
//   Allnum[57].type = name57_type;
//#endif


//#if(All_Count >= 59)
//   strcpy(Allnum[58].name, name58);
//   Allnum[58].va = (uint16_t*)&(name58_value);			
//   Allnum[58].sub = name58_sub;
//   Allnum[58].type = name58_type;
//#endif


//#if(All_Count >= 60)
//   strcpy(Allnum[59].name, name59);
//   Allnum[59].va = (uint16_t*)&(name59_value);			
//   Allnum[59].sub = name59_sub;
//   Allnum[59].type = name59_type;
//#endif


//#if(All_Count >= 61)
//   strcpy(Allnum[60].name, name60);
//   Allnum[60].va = (uint16_t*)&(name60_value);			
//   Allnum[60].sub = name60_sub;
//   Allnum[60].type = name60_type;
//#endif


//#if(All_Count >= 62)
//   strcpy(Allnum[61].name, name61);
//   Allnum[61].va = (uint16_t*)&(name61_value);			
//   Allnum[61].sub = name61_sub;
//   Allnum[61].type = name61_type;
//#endif


//#if(All_Count >= 63)
//   strcpy(Allnum[62].name, name62);
//   Allnum[62].va = (uint16_t*)&(name62_value);			
//   Allnum[62].sub = name62_sub;
//   Allnum[62].type = name62_type;
//#endif


//#if(All_Count >= 64)
//   strcpy(Allnum[63].name, name63);
//   Allnum[63].va = (uint16_t*)&(name63_value);			
//   Allnum[63].sub = name63_sub;
//   Allnum[63].type = name63_type;
//#endif


//#if(All_Count >= 65)
//   strcpy(Allnum[64].name, name64);
//   Allnum[64].va = (uint16_t*)&(name64_value);			
//   Allnum[64].sub = name64_sub;
//   Allnum[64].type = name64_type;
//#endif


//#if(All_Count >= 66)
//   strcpy(Allnum[65].name, name65);
//   Allnum[65].va = (uint16_t*)&(name65_value);			
//   Allnum[65].sub = name65_sub;
//   Allnum[65].type = name65_type;
//#endif


//#if(All_Count >= 67)
//   strcpy(Allnum[66].name, name66);
//   Allnum[66].va = (uint16_t*)&(name66_value);			
//   Allnum[66].sub = name66_sub;
//   Allnum[66].type = name66_type;
//#endif


//#if(All_Count >= 68)
//   strcpy(Allnum[67].name, name67);
//   Allnum[67].va = (uint16_t*)&(name67_value);			
//   Allnum[67].sub = name67_sub;
//   Allnum[67].type = name67_type;
//#endif


//#if(All_Count >= 69)
//   strcpy(Allnum[68].name, name68);
//   Allnum[68].va = (uint16_t*)&(name68_value);			
//   Allnum[68].sub = name68_sub;
//   Allnum[68].type = name68_type;
//#endif


//#if(All_Count >= 70)
//   strcpy(Allnum[69].name, name69);
//   Allnum[69].va = (uint16_t*)&(name69_value);			
//   Allnum[69].sub = name69_sub;
//   Allnum[69].type = name69_type;
//#endif


//#if(All_Count >= 71)
//   strcpy(Allnum[70].name, name70);
//   Allnum[70].va = (uint16_t*)&(name70_value);			
//   Allnum[70].sub = name70_sub;
//   Allnum[70].type = name70_type;
//#endif


//#if(All_Count >= 72)
//   strcpy(Allnum[71].name, name71);
//   Allnum[71].va = (uint16_t*)&(name71_value);			
//   Allnum[71].sub = name71_sub;
//   Allnum[71].type = name71_type;
//#endif


//#if(All_Count >= 73)
//   strcpy(Allnum[72].name, name72);
//   Allnum[72].va = (uint16_t*)&(name72_value);			
//   Allnum[72].sub = name72_sub;
//   Allnum[72].type = name72_type;
//#endif


//#if(All_Count >= 74)
//   strcpy(Allnum[73].name, name73);
//   Allnum[73].va = (uint16_t*)&(name73_value);			
//   Allnum[73].sub = name73_sub;
//   Allnum[73].type = name73_type;
//#endif


//#if(All_Count >= 75)
//   strcpy(Allnum[74].name, name74);
//   Allnum[74].va = (uint16_t*)&(name74_value);			
//   Allnum[74].sub = name74_sub;
//   Allnum[74].type = name74_type;
//#endif


//#if(All_Count >= 76)
//   strcpy(Allnum[75].name, name75);
//   Allnum[75].va = (uint16_t*)&(name75_value);			
//   Allnum[75].sub = name75_sub;
//   Allnum[75].type = name75_type;
//#endif


//#if(All_Count >= 77)
//   strcpy(Allnum[76].name, name76);
//   Allnum[76].va = (uint16_t*)&(name76_value);			
//   Allnum[76].sub = name76_sub;
//   Allnum[76].type = name76_type;
//#endif


//#if(All_Count >= 78)
//   strcpy(Allnum[77].name, name77);
//   Allnum[77].va = (uint16_t*)&(name77_value);			
//   Allnum[77].sub = name77_sub;
//   Allnum[77].type = name77_type;
//#endif


//#if(All_Count >= 79)
//   strcpy(Allnum[78].name, name78);
//   Allnum[78].va = (uint16_t*)&(name78_value);			
//   Allnum[78].sub = name78_sub;
//   Allnum[78].type = name78_type;
//#endif


//#if(All_Count >= 80)
//   strcpy(Allnum[79].name, name79);
//   Allnum[79].va = (uint16_t*)&(name79_value);			
//   Allnum[79].sub = name79_sub;
//   Allnum[79].type = name79_type;
//#endif


//#if(All_Count >= 81)
//   strcpy(Allnum[80].name, name80);
//   Allnum[80].va = (uint16_t*)&(name80_value);			
//   Allnum[80].sub = name80_sub;
//   Allnum[80].type = name80_type;
//#endif


//#if(All_Count >= 82)
//   strcpy(Allnum[81].name, name81);
//   Allnum[81].va = (uint16_t*)&(name81_value);			
//   Allnum[81].sub = name81_sub;
//   Allnum[81].type = name81_type;
//#endif


//#if(All_Count >= 83)
//   strcpy(Allnum[82].name, name82);
//   Allnum[82].va = (uint16_t*)&(name82_value);			
//   Allnum[82].sub = name82_sub;
//   Allnum[82].type = name82_type;
//#endif


//#if(All_Count >= 84)
//   strcpy(Allnum[83].name, name83);
//   Allnum[83].va = (uint16_t*)&(name83_value);			
//   Allnum[83].sub = name83_sub;
//   Allnum[83].type = name83_type;
//#endif


//#if(All_Count >= 85)
//   strcpy(Allnum[84].name, name84);
//   Allnum[84].va = (uint16_t*)&(name84_value);			
//   Allnum[84].sub = name84_sub;
//   Allnum[84].type = name84_type;
//#endif


//#if(All_Count >= 86)
//   strcpy(Allnum[85].name, name85);
//   Allnum[85].va = (uint16_t*)&(name85_value);			
//   Allnum[85].sub = name85_sub;
//   Allnum[85].type = name85_type;
//#endif


//#if(All_Count >= 87)
//   strcpy(Allnum[86].name, name86);
//   Allnum[86].va = (uint16_t*)&(name86_value);			
//   Allnum[86].sub = name86_sub;
//   Allnum[86].type = name86_type;
//#endif


//#if(All_Count >= 88)
//   strcpy(Allnum[87].name, name87);
//   Allnum[87].va = (uint16_t*)&(name87_value);			
//   Allnum[87].sub = name87_sub;
//   Allnum[87].type = name87_type;
//#endif


//#if(All_Count >= 89)
//   strcpy(Allnum[88].name, name88);
//   Allnum[88].va = (uint16_t*)&(name88_value);			
//   Allnum[88].sub = name88_sub;
//   Allnum[88].type = name88_type;
//#endif


//#if(All_Count >= 90)
//   strcpy(Allnum[89].name, name89);
//   Allnum[89].va = (uint16_t*)&(name89_value);			
//   Allnum[89].sub = name89_sub;
//   Allnum[89].type = name89_type;
//#endif


//#if(All_Count >= 91)
//   strcpy(Allnum[90].name, name90);
//   Allnum[90].va = (uint16_t*)&(name90_value);			
//   Allnum[90].sub = name90_sub;
//   Allnum[90].type = name90_type;
//#endif


//#if(All_Count >= 92)
//   strcpy(Allnum[91].name, name91);
//   Allnum[91].va = (uint16_t*)&(name91_value);			
//   Allnum[91].sub = name91_sub;
//   Allnum[91].type = name91_type;
//#endif


//#if(All_Count >= 93)
//   strcpy(Allnum[92].name, name92);
//   Allnum[92].va = (uint16_t*)&(name92_value);			
//   Allnum[92].sub = name92_sub;
//   Allnum[92].type = name92_type;
//#endif


//#if(All_Count >= 94)
//   strcpy(Allnum[93].name, name93);
//   Allnum[93].va = (uint16_t*)&(name93_value);			
//   Allnum[93].sub = name93_sub;
//   Allnum[93].type = name93_type;
//#endif


//#if(All_Count >= 95)
//   strcpy(Allnum[94].name, name94);
//   Allnum[94].va = (uint16_t*)&(name94_value);			
//   Allnum[94].sub = name94_sub;
//   Allnum[94].type = name94_type;
//#endif


//#if(All_Count >= 96)
//   strcpy(Allnum[95].name, name95);
//   Allnum[95].va = (uint16_t*)&(name95_value);			
//   Allnum[95].sub = name95_sub;
//   Allnum[95].type = name95_type;
//#endif


//#if(All_Count >= 97)
//   strcpy(Allnum[96].name, name96);
//   Allnum[96].va = (uint16_t*)&(name96_value);			
//   Allnum[96].sub = name96_sub;
//   Allnum[96].type = name96_type;
//#endif


//#if(All_Count >= 98)
//   strcpy(Allnum[97].name, name97);
//   Allnum[97].va = (uint16_t*)&(name97_value);			
//   Allnum[97].sub = name97_sub;
//   Allnum[97].type = name97_type;
//#endif


//#if(All_Count >= 99)
//   strcpy(Allnum[98].name, name98);
//   Allnum[98].va = (uint16_t*)&(name98_value);			
//   Allnum[98].sub = name98_sub;
//   Allnum[98].type = name98_type;
//#endif


//#if(All_Count >= 100)
//   strcpy(Allnum[99].name, name99);
//   Allnum[99].va = (uint16_t*)&(name99_value);			
//   Allnum[99].sub = name99_sub;
//   Allnum[99].type = name99_type;
//#endif

#if(All_Count) 
    Display_All();
#endif
}
void Display_All(void)
{
	uint8_t final_hang=0,page=0,i=0;
	
	OLED_Clear();

	while(1)
	{	
		if(Key_up == 0)        //向上一行
		{
			DelayMs(200);
			hang --;								//
			if(hang == 0) hang = All_Count;
			OLED_Clear();
		}
		
		if(Key_down == 0)           //向下一行
		{
			DelayMs(200);
			hang ++;								
			if(hang == (All_Count + 1)) hang = 1;
			OLED_Clear();
		}
		
		if(Key_left == 0)        //自加
		{
			DelayMs(100);
      {
        if(*(Allnum[hang - 1].va) + Allnum[hang - 1].sub <=((1<<16)-1))
        {
		  	   (*(Allnum[hang - 1].va)) = (*(Allnum[hang - 1].va)) + Allnum[hang - 1].sub;//????????
        }
        else
        {
           (*(Allnum[hang - 1].va)) = ((1<<16)-1);//????????
        }
      }
		}
		
		if(Key_right == 0)      //自减
		{
			DelayMs(100);
      {
        if(*(Allnum[hang - 1].va)- Allnum[hang - 1].sub>=0)
        {
			    (*(Allnum[hang - 1].va)) = (*(Allnum[hang - 1].va)) - Allnum[hang - 1].sub;//????????
        }
        else
        {
          (*(Allnum[hang - 1].va)) =0;
        }
      }
			//if((*(Allnum[hang - 1].va))>0xF000) (*(Allnum[hang - 1].va))=0;//????????
		}
		
//		if(Key_in == 0)//翻页
//		{
//			DelayMs(250);
//			page ++;		//
//			if(page > (All_Count - 1) / 4) page = 0;
//			hang = page * 4 + 1;	//
//			OLED_Clear();
//		}
		
		if(Key_1 == 0)//发车
		{
			DelayMs(300);
			OLED_Clear();
			OLED_Write_String(5,3,(uint8_t*)"S:STAT");
			return;
		}
			
		OLED_Write_Char(0,(hang-1)%4*2,43);   //箭头


		
		if((All_Count - 1 )/ 4 > (hang - 1)/ 4) //
		{
			page = (hang - 1)/4;
			final_hang = 4;                   //
		}
		else
		{
			page = (All_Count - 1) / 4;
			final_hang = All_Count%4;
			if(final_hang == 0) final_hang =4;
		}
		
		for(i = 1;i <= final_hang;i++)  //
		{
			OLED_Write_String(2,(i - 1)*2,(uint8_t*)Allnum[i - 1 + 4 * page].name);
			OLED_Write_String(11,(i - 1)*2,(uint8_t*)":");
			OLED_Write_Num4(12,(i - 1)*2,*(Allnum[i - 1 + 4 * page].va));
		}
        
		//ExternModeCon();
	}

	
}



