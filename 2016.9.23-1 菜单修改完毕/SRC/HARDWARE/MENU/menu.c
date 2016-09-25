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


   #if(Number_All >= 31)
      strcpy(Menu_name[30].name, name30);
      Menu_name[30].num = name30_num;			
      Menu_name[30].sub = name30_sub;
   #endif


   #if(Number_All >= 32)
      strcpy(Menu_name[31].name, name31);
      Menu_name[31].num = name31_num;			
      Menu_name[31].sub = name31_sub;
   #endif


   #if(Number_All >= 33)
      strcpy(Menu_name[32].name, name32);
      Menu_name[32].num = name32_num;			
      Menu_name[32].sub = name32_sub;
   #endif


   #if(Number_All >= 34)
      strcpy(Menu_name[33].name, name33);
      Menu_name[33].num = name33_num;			
      Menu_name[33].sub = name33_sub;
   #endif


   #if(Number_All >= 35)
      strcpy(Menu_name[34].name, name34);
      Menu_name[34].num = name34_num;			
      Menu_name[34].sub = name34_sub;
   #endif


   #if(Number_All >= 36)
      strcpy(Menu_name[35].name, name35);
      Menu_name[35].num = name35_num;			
      Menu_name[35].sub = name35_sub;
   #endif


   #if(Number_All >= 37)
      strcpy(Menu_name[36].name, name36);
      Menu_name[36].num = name36_num;			
      Menu_name[36].sub = name36_sub;
   #endif


   #if(Number_All >= 38)
      strcpy(Menu_name[37].name, name37);
      Menu_name[37].num = name37_num;			
      Menu_name[37].sub = name37_sub;
   #endif


   #if(Number_All >= 39)
      strcpy(Menu_name[38].name, name38);
      Menu_name[38].num = name38_num;			
      Menu_name[38].sub = name38_sub;
   #endif


   #if(Number_All >= 40)
      strcpy(Menu_name[39].name, name39);
      Menu_name[39].num = name39_num;			
      Menu_name[39].sub = name39_sub;
   #endif


   #if(Number_All >= 41)
      strcpy(Menu_name[40].name, name40);
      Menu_name[40].num = name40_num;			
      Menu_name[40].sub = name40_sub;
   #endif


   #if(Number_All >= 42)
      strcpy(Menu_name[41].name, name41);
      Menu_name[41].num = name41_num;			
      Menu_name[41].sub = name41_sub;
   #endif


   #if(Number_All >= 43)
      strcpy(Menu_name[42].name, name42);
      Menu_name[42].num = name42_num;			
      Menu_name[42].sub = name42_sub;
   #endif


   #if(Number_All >= 44)
      strcpy(Menu_name[43].name, name43);
      Menu_name[43].num = name43_num;			
      Menu_name[43].sub = name43_sub;
   #endif


   #if(Number_All >= 45)
      strcpy(Menu_name[44].name, name44);
      Menu_name[44].num = name44_num;			
      Menu_name[44].sub = name44_sub;
   #endif


   #if(Number_All >= 46)
      strcpy(Menu_name[45].name, name45);
      Menu_name[45].num = name45_num;			
      Menu_name[45].sub = name45_sub;
   #endif


   #if(Number_All >= 47)
      strcpy(Menu_name[46].name, name46);
      Menu_name[46].num = name46_num;			
      Menu_name[46].sub = name46_sub;
   #endif


   #if(Number_All >= 48)
      strcpy(Menu_name[47].name, name47);
      Menu_name[47].num = name47_num;			
      Menu_name[47].sub = name47_sub;
   #endif


   #if(Number_All >= 49)
      strcpy(Menu_name[48].name, name48);
      Menu_name[48].num = name48_num;			
      Menu_name[48].sub = name48_sub;
   #endif


   #if(Number_All >= 50)
      strcpy(Menu_name[49].name, name49);
      Menu_name[49].num = name49_num;			
      Menu_name[49].sub = name49_sub;
   #endif


   #if(Number_All >= 51)
      strcpy(Menu_name[50].name, name50);
      Menu_name[50].num = name50_num;			
      Menu_name[50].sub = name50_sub;
   #endif


   #if(Number_All >= 52)
      strcpy(Menu_name[51].name, name51);
      Menu_name[51].num = name51_num;			
      Menu_name[51].sub = name51_sub;
   #endif


   #if(Number_All >= 53)
      strcpy(Menu_name[52].name, name52);
      Menu_name[52].num = name52_num;			
      Menu_name[52].sub = name52_sub;
   #endif


   #if(Number_All >= 54)
      strcpy(Menu_name[53].name, name53);
      Menu_name[53].num = name53_num;			
      Menu_name[53].sub = name53_sub;
   #endif


   #if(Number_All >= 55)
      strcpy(Menu_name[54].name, name54);
      Menu_name[54].num = name54_num;			
      Menu_name[54].sub = name54_sub;
   #endif


   #if(Number_All >= 56)
      strcpy(Menu_name[55].name, name55);
      Menu_name[55].num = name55_num;			
      Menu_name[55].sub = name55_sub;
   #endif


   #if(Number_All >= 57)
      strcpy(Menu_name[56].name, name56);
      Menu_name[56].num = name56_num;			
      Menu_name[56].sub = name56_sub;
   #endif


   #if(Number_All >= 58)
      strcpy(Menu_name[57].name, name57);
      Menu_name[57].num = name57_num;			
      Menu_name[57].sub = name57_sub;
   #endif


   #if(Number_All >= 59)
      strcpy(Menu_name[58].name, name58);
      Menu_name[58].num = name58_num;			
      Menu_name[58].sub = name58_sub;
   #endif


   #if(Number_All >= 60)
      strcpy(Menu_name[59].name, name59);
      Menu_name[59].num = name59_num;			
      Menu_name[59].sub = name59_sub;
   #endif


   #if(Number_All >= 61)
      strcpy(Menu_name[60].name, name60);
      Menu_name[60].num = name60_num;			
      Menu_name[60].sub = name60_sub;
   #endif


   #if(Number_All >= 62)
      strcpy(Menu_name[61].name, name61);
      Menu_name[61].num = name61_num;			
      Menu_name[61].sub = name61_sub;
   #endif


   #if(Number_All >= 63)
      strcpy(Menu_name[62].name, name62);
      Menu_name[62].num = name62_num;			
      Menu_name[62].sub = name62_sub;
   #endif


   #if(Number_All >= 64)
      strcpy(Menu_name[63].name, name63);
      Menu_name[63].num = name63_num;			
      Menu_name[63].sub = name63_sub;
   #endif


   #if(Number_All >= 65)
      strcpy(Menu_name[64].name, name64);
      Menu_name[64].num = name64_num;			
      Menu_name[64].sub = name64_sub;
   #endif


   #if(Number_All >= 66)
      strcpy(Menu_name[65].name, name65);
      Menu_name[65].num = name65_num;			
      Menu_name[65].sub = name65_sub;
   #endif


   #if(Number_All >= 67)
      strcpy(Menu_name[66].name, name66);
      Menu_name[66].num = name66_num;			
      Menu_name[66].sub = name66_sub;
   #endif


   #if(Number_All >= 68)
      strcpy(Menu_name[67].name, name67);
      Menu_name[67].num = name67_num;			
      Menu_name[67].sub = name67_sub;
   #endif


   #if(Number_All >= 69)
      strcpy(Menu_name[68].name, name68);
      Menu_name[68].num = name68_num;			
      Menu_name[68].sub = name68_sub;
   #endif


   #if(Number_All >= 70)
      strcpy(Menu_name[69].name, name69);
      Menu_name[69].num = name69_num;			
      Menu_name[69].sub = name69_sub;
   #endif


   #if(Number_All >= 71)
      strcpy(Menu_name[70].name, name70);
      Menu_name[70].num = name70_num;			
      Menu_name[70].sub = name70_sub;
   #endif


   #if(Number_All >= 72)
      strcpy(Menu_name[71].name, name71);
      Menu_name[71].num = name71_num;			
      Menu_name[71].sub = name71_sub;
   #endif


   #if(Number_All >= 73)
      strcpy(Menu_name[72].name, name72);
      Menu_name[72].num = name72_num;			
      Menu_name[72].sub = name72_sub;
   #endif


   #if(Number_All >= 74)
      strcpy(Menu_name[73].name, name73);
      Menu_name[73].num = name73_num;			
      Menu_name[73].sub = name73_sub;
   #endif


   #if(Number_All >= 75)
      strcpy(Menu_name[74].name, name74);
      Menu_name[74].num = name74_num;			
      Menu_name[74].sub = name74_sub;
   #endif


   #if(Number_All >= 76)
      strcpy(Menu_name[75].name, name75);
      Menu_name[75].num = name75_num;			
      Menu_name[75].sub = name75_sub;
   #endif


   #if(Number_All >= 77)
      strcpy(Menu_name[76].name, name76);
      Menu_name[76].num = name76_num;			
      Menu_name[76].sub = name76_sub;
   #endif


   #if(Number_All >= 78)
      strcpy(Menu_name[77].name, name77);
      Menu_name[77].num = name77_num;			
      Menu_name[77].sub = name77_sub;
   #endif


   #if(Number_All >= 79)
      strcpy(Menu_name[78].name, name78);
      Menu_name[78].num = name78_num;			
      Menu_name[78].sub = name78_sub;
   #endif


   #if(Number_All >= 80)
      strcpy(Menu_name[79].name, name79);
      Menu_name[79].num = name79_num;			
      Menu_name[79].sub = name79_sub;
   #endif


   #if(Number_All >= 81)
      strcpy(Menu_name[80].name, name80);
      Menu_name[80].num = name80_num;			
      Menu_name[80].sub = name80_sub;
   #endif


   #if(Number_All >= 82)
      strcpy(Menu_name[81].name, name81);
      Menu_name[81].num = name81_num;			
      Menu_name[81].sub = name81_sub;
   #endif


   #if(Number_All >= 83)
      strcpy(Menu_name[82].name, name82);
      Menu_name[82].num = name82_num;			
      Menu_name[82].sub = name82_sub;
   #endif


   #if(Number_All >= 84)
      strcpy(Menu_name[83].name, name83);
      Menu_name[83].num = name83_num;			
      Menu_name[83].sub = name83_sub;
   #endif


   #if(Number_All >= 85)
      strcpy(Menu_name[84].name, name84);
      Menu_name[84].num = name84_num;			
      Menu_name[84].sub = name84_sub;
   #endif


   #if(Number_All >= 86)
      strcpy(Menu_name[85].name, name85);
      Menu_name[85].num = name85_num;			
      Menu_name[85].sub = name85_sub;
   #endif


   #if(Number_All >= 87)
      strcpy(Menu_name[86].name, name86);
      Menu_name[86].num = name86_num;			
      Menu_name[86].sub = name86_sub;
   #endif


   #if(Number_All >= 88)
      strcpy(Menu_name[87].name, name87);
      Menu_name[87].num = name87_num;			
      Menu_name[87].sub = name87_sub;
   #endif


   #if(Number_All >= 89)
      strcpy(Menu_name[88].name, name88);
      Menu_name[88].num = name88_num;			
      Menu_name[88].sub = name88_sub;
   #endif


   #if(Number_All >= 90)
      strcpy(Menu_name[89].name, name89);
      Menu_name[89].num = name89_num;			
      Menu_name[89].sub = name89_sub;
   #endif


   #if(Number_All >= 91)
      strcpy(Menu_name[90].name, name90);
      Menu_name[90].num = name90_num;			
      Menu_name[90].sub = name90_sub;
   #endif


   #if(Number_All >= 92)
      strcpy(Menu_name[91].name, name91);
      Menu_name[91].num = name91_num;			
      Menu_name[91].sub = name91_sub;
   #endif


   #if(Number_All >= 93)
      strcpy(Menu_name[92].name, name92);
      Menu_name[92].num = name92_num;			
      Menu_name[92].sub = name92_sub;
   #endif


   #if(Number_All >= 94)
      strcpy(Menu_name[93].name, name93);
      Menu_name[93].num = name93_num;			
      Menu_name[93].sub = name93_sub;
   #endif


   #if(Number_All >= 95)
      strcpy(Menu_name[94].name, name94);
      Menu_name[94].num = name94_num;			
      Menu_name[94].sub = name94_sub;
   #endif


   #if(Number_All >= 96)
      strcpy(Menu_name[95].name, name95);
      Menu_name[95].num = name95_num;			
      Menu_name[95].sub = name95_sub;
   #endif


   #if(Number_All >= 97)
      strcpy(Menu_name[96].name, name96);
      Menu_name[96].num = name96_num;			
      Menu_name[96].sub = name96_sub;
   #endif


   #if(Number_All >= 98)
      strcpy(Menu_name[97].name, name97);
      Menu_name[97].num = name97_num;			
      Menu_name[97].sub = name97_sub;
   #endif


   #if(Number_All >= 99)
      strcpy(Menu_name[98].name, name98);
      Menu_name[98].num = name98_num;			
      Menu_name[98].sub = name98_sub;
   #endif


   #if(Number_All >= 100)
      strcpy(Menu_name[99].name, name99);
      Menu_name[99].num = name99_num;			
      Menu_name[99].sub = name99_sub;
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

	#if(Number_All >= 31)
      name30_num = Menu_name[30].num;
   #endif

	#if(Number_All >= 32)
      name31_num = Menu_name[31].num;
   #endif

	#if(Number_All >= 33)
      name32_num = Menu_name[32].num;
   #endif

	#if(Number_All >= 34)
      name33_num = Menu_name[33].num;
   #endif

	#if(Number_All >= 35)
      name34_num = Menu_name[34].num;
   #endif

	#if(Number_All >= 36)
      name35_num = Menu_name[35].num;
   #endif

	#if(Number_All >= 37)
      name36_num = Menu_name[36].num;
   #endif

	#if(Number_All >= 38)
      name37_num = Menu_name[37].num;
   #endif

	#if(Number_All >= 39)
      name38_num = Menu_name[38].num;
   #endif

	#if(Number_All >= 40)
      name39_num = Menu_name[39].num;
   #endif

	#if(Number_All >= 41)
      name40_num = Menu_name[40].num;
   #endif

	#if(Number_All >= 42)
      name41_num = Menu_name[41].num;
   #endif

	#if(Number_All >= 43)
      name42_num = Menu_name[42].num;
   #endif

	#if(Number_All >= 44)
      name43_num = Menu_name[43].num;
   #endif

	#if(Number_All >= 45)
      name44_num = Menu_name[44].num;
   #endif

	#if(Number_All >= 46)
      name45_num = Menu_name[45].num;
   #endif

	#if(Number_All >= 47)
      name46_num = Menu_name[46].num;
   #endif

	#if(Number_All >= 48)
      name47_num = Menu_name[47].num;
   #endif

	#if(Number_All >= 49)
      name48_num = Menu_name[48].num;
   #endif

	#if(Number_All >= 50)
      name49_num = Menu_name[49].num;
   #endif

	#if(Number_All >= 51)
      name50_num = Menu_name[50].num;
   #endif

	#if(Number_All >= 52)
      name51_num = Menu_name[51].num;
   #endif

	#if(Number_All >= 53)
      name52_num = Menu_name[52].num;
   #endif

	#if(Number_All >= 54)
      name53_num = Menu_name[53].num;
   #endif

	#if(Number_All >= 55)
      name54_num = Menu_name[54].num;
   #endif

	#if(Number_All >= 56)
      name55_num = Menu_name[55].num;
   #endif

	#if(Number_All >= 57)
      name56_num = Menu_name[56].num;
   #endif

	#if(Number_All >= 58)
      name57_num = Menu_name[57].num;
   #endif

	#if(Number_All >= 59)
      name58_num = Menu_name[58].num;
   #endif

	#if(Number_All >= 60)
      name59_num = Menu_name[59].num;
   #endif

	#if(Number_All >= 61)
      name60_num = Menu_name[60].num;
   #endif

	#if(Number_All >= 62)
      name61_num = Menu_name[61].num;
   #endif

	#if(Number_All >= 63)
      name62_num = Menu_name[62].num;
   #endif

	#if(Number_All >= 64)
      name63_num = Menu_name[63].num;
   #endif

	#if(Number_All >= 65)
      name64_num = Menu_name[64].num;
   #endif

	#if(Number_All >= 66)
      name65_num = Menu_name[65].num;
   #endif

	#if(Number_All >= 67)
      name66_num = Menu_name[66].num;
   #endif

	#if(Number_All >= 68)
      name67_num = Menu_name[67].num;
   #endif

	#if(Number_All >= 69)
      name68_num = Menu_name[68].num;
   #endif

	#if(Number_All >= 70)
      name69_num = Menu_name[69].num;
   #endif

	#if(Number_All >= 71)
      name70_num = Menu_name[70].num;
   #endif

	#if(Number_All >= 72)
      name71_num = Menu_name[71].num;
   #endif

	#if(Number_All >= 73)
      name72_num = Menu_name[72].num;
   #endif

	#if(Number_All >= 74)
      name73_num = Menu_name[73].num;
   #endif

	#if(Number_All >= 75)
      name74_num = Menu_name[74].num;
   #endif

	#if(Number_All >= 76)
      name75_num = Menu_name[75].num;
   #endif

	#if(Number_All >= 77)
      name76_num = Menu_name[76].num;
   #endif

	#if(Number_All >= 78)
      name77_num = Menu_name[77].num;
   #endif

	#if(Number_All >= 79)
      name78_num = Menu_name[78].num;
   #endif

	#if(Number_All >= 80)
      name79_num = Menu_name[79].num;
   #endif

	#if(Number_All >= 81)
      name80_num = Menu_name[80].num;
   #endif

	#if(Number_All >= 82)
      name81_num = Menu_name[81].num;
   #endif

	#if(Number_All >= 83)
      name82_num = Menu_name[82].num;
   #endif

	#if(Number_All >= 84)
      name83_num = Menu_name[83].num;
   #endif

	#if(Number_All >= 85)
      name84_num = Menu_name[84].num;
   #endif

	#if(Number_All >= 86)
      name85_num = Menu_name[85].num;
   #endif

	#if(Number_All >= 87)
      name86_num = Menu_name[86].num;
   #endif

	#if(Number_All >= 88)
      name87_num = Menu_name[87].num;
   #endif

	#if(Number_All >= 89)
      name88_num = Menu_name[88].num;
   #endif

	#if(Number_All >= 90)
      name89_num = Menu_name[89].num;
   #endif

	#if(Number_All >= 91)
      name90_num = Menu_name[90].num;
   #endif

	#if(Number_All >= 92)
      name91_num = Menu_name[91].num;
   #endif

	#if(Number_All >= 93)
      name92_num = Menu_name[92].num;
   #endif

	#if(Number_All >= 94)
      name93_num = Menu_name[93].num;
   #endif

	#if(Number_All >= 95)
      name94_num = Menu_name[94].num;
   #endif

	#if(Number_All >= 96)
      name95_num = Menu_name[95].num;
   #endif

	#if(Number_All >= 97)
      name96_num = Menu_name[96].num;
   #endif

	#if(Number_All >= 98)
      name97_num = Menu_name[97].num;
   #endif

	#if(Number_All >= 99)
      name98_num = Menu_name[98].num;
   #endif

	#if(Number_All >= 100)
      name99_num = Menu_name[99].num;
   #endif
}

void anjian_menu(void)
{
	uint8_t final_hang = 0,page = 0;
	
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
			OLED_Write_Num4(11,(i - 1)*2,Menu_name[i - 1 + 4 * page].num);
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

