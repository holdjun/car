#ifndef _MENU_H_
#define _MENU_H_

#include "sys.h"

#define Number_All  9

struct Menu_Select
{
	char name[6];
	uint16_t num;
	uint16_t sub;
};

#if(Number_All)
#define name0    	"AI"    
#define name0_num   a1 
#define name0_sub   1 

#define name1    	"BI"      
#define name1_num   a2
#define name1_sub   1   

#define name2    	"CI"      
#define name2_num   a3 
#define name2_sub   1   

#define name3    	"DI"      
#define name3_num   a4 
#define name3_sub   1   

#define name4    	"EI"      
#define name4_num   a5 
#define name4_sub   1   

#define name5    	"FTM1"      
#define name5_num   FTMDuty_1 
#define name5_sub   50   

#define name6    	"FTM2"      
#define name6_num   FTMDuty_2 
#define name6_sub   50   

#define name7    	"TIME"      
#define name7_num   a6 
#define name7_sub   1   

#define name8    	"FTM2"      
#define name8_num   FTMDuty 
#define name8_sub   50     

#define name9    	"name3"      
#define name9_num   a8 
#define name9_sub   50  

#define name10    	"name2"      
#define name10_num  a9  
#define name10_sub  1  

#define name11    	"name"      
#define name11_num  num  
#define name11_sub  sub    

#define name12    	"name"      
#define name12_num  num  
#define name12_sub  sub    

#define name13    	"name"       
#define name13_num  num  
#define name13_sub  sub    

#define name14    	"name"       
#define name14_num  num  
#define name14_sub  sub    

#define name15    	"name"      
#define name15_num  num  
#define name15_sub  sub    

#define name16    	"name"      
#define name16_num  num  
#define name16_sub  sub    

#define name17    	"name"      
#define name17_num  num  
#define name17_sub  sub    

#define name18    	"name"      
#define name18_num  num  
#define name18_sub  sub    

#define name19    	"name"      
#define name19_num  num  
#define name19_sub  sub    

#define name20    	"name"      
#define name20_num  num  
#define name20_sub  sub    

#define name21    	"name"      
#define name21_num  num   
#define name21_sub  sub    

#define name22    	"name"      
#define name22_num  num  
#define name22_sub  sub    

#define name23    	"name"       
#define name23_num  num  
#define name23_sub  sub    

#define name24    	"name"       
#define name24_num  num  
#define name24_sub  sub    

#define name25    	"name"       
#define name25_num  num  
#define name25_sub  sub    

#define name26    	"name"       
#define name26_num  num  
#define name26_sub  sub    

#define name27    	"name"       
#define name27_num  num  
#define name27_sub  sub    

#define name28    	"name"      
#define name28_num  num  
#define name28_sub  sub    

#define name29    	"name"      
#define name29_num  num  
#define name29_sub  sub    

#define name30    	"name"      
#define name30_num  num  
#define name30_sub  sub    

#define name31    	"name"      
#define name31_num  num  
#define name31_sub  sub    

#define name32    	"name"      
#define name32_num  num  
#define name32_sub  sub   

#define name33    	"name"      
#define name33_num  num  
#define name33_sub  sub   

#define name34    	"name"      
#define name34_num  num  
#define name34_sub  sub   

#define name35    	"name"      
#define name35_num  num  
#define name35_sub  sub   

#define name36    	"name"      
#define name36_num  num  
#define name36_sub  sub   

#define name37    	"name"      
#define name37_num  num  
#define name37_sub  sub   

#define name38    	"name"      
#define name38_num  num  
#define name38_sub  sub   

#define name39    	"name"      
#define name39_num  num  
#define name39_sub  sub   

#define name40    	"name"      
#define name40_num  num  
#define name40_sub  sub   

#define name41    	"name"      
#define name41_num  num  
#define name41_sub  sub   

#define name42    	"name"      
#define name42_num  num  
#define name42_sub  sub   

#define name43    	"name"      
#define name43_num  num  
#define name43_sub  sub   

#define name44    	"name"      
#define name44_num  num  
#define name44_sub  sub   

#define name45    	"name"      
#define name45_num  num  
#define name45_sub  sub   

#define name46    	"name"      
#define name46_num  num  
#define name46_sub  sub   

#define name47    	"name"      
#define name47_num  num  
#define name47_sub  sub   

#define name48    	"name"      
#define name48_num  num  
#define name48_sub  sub   

#define name49    	"name"      
#define name49_num  num  
#define name49_sub  sub   

#define name50    	"name"      
#define name50_num  num  
#define name50_sub  sub   

#define name51    	"name"      
#define name51_num  num  
#define name51_sub  sub   

#define name52    	"name"      
#define name52_num  num  
#define name52_sub  sub   

#define name53    	"name"      
#define name53_num  num  
#define name53_sub  sub   

#define name54    	"name"      
#define name54_num  num  
#define name54_sub  sub   

#define name55    	"name"      
#define name55_num  num  
#define name55_sub  sub   

#define name56    	"name"      
#define name56_num  num  
#define name56_sub  sub   

#define name57    	"name"      
#define name57_num  num  
#define name57_sub  sub   

#define name58    	"name"      
#define name58_num  num  
#define name58_sub  sub   

#define name59    	"name"      
#define name59_num  num  
#define name59_sub  sub   

#define name60    	"name"      
#define name60_num  num  
#define name60_sub  sub   

#define name61    	"name"      
#define name61_num  num  
#define name61_sub  sub   

#define name62    	"name"      
#define name62_num  num  
#define name62_sub  sub   

#define name63    	"name"      
#define name63_num  num  
#define name63_sub  sub   

#define name64    	"name"      
#define name64_num  num  
#define name64_sub  sub   

#define name65    	"name"      
#define name65_num  num  
#define name65_sub  sub   

#define name66    	"name"      
#define name66_num  num  
#define name66_sub  sub   

#define name67    	"name"      
#define name67_num  num  
#define name67_sub  sub   

#define name68    	"name"      
#define name68_num  num  
#define name68_sub  sub   

#define name69    	"name"      
#define name69_num  num  
#define name69_sub  sub   

#define name70    	"name"      
#define name70_num  num  
#define name70_sub  sub   

#define name71    	"name"      
#define name71_num  num  
#define name71_sub  sub   

#define name72    	"name"      
#define name72_num  num  
#define name72_sub  sub   

#define name73    	"name"      
#define name73_num  num  
#define name73_sub  sub   

#define name74    	"name"      
#define name74_num  num  
#define name74_sub  sub   

#define name75    	"name"      
#define name75_num  num  
#define name75_sub  sub   

#define name76    	"name"      
#define name76_num  num  
#define name76_sub  sub   

#define name77    	"name"      
#define name77_num  num  
#define name77_sub  sub   

#define name78    	"name"      
#define name78_num  num  
#define name78_sub  sub   

#define name79    	"name"      
#define name79_num  num  
#define name79_sub  sub   

#define name80    	"name"      
#define name80_num  num  
#define name80_sub  sub   

#define name81    	"name"      
#define name81_num  num  
#define name81_sub  sub   

#define name82    	"name"      
#define name82_num  num  
#define name82_sub  sub   

#define name83    	"name"      
#define name83_num  num  
#define name83_sub  sub   

#define name84    	"name"      
#define name84_num  num  
#define name84_sub  sub   

#define name85    	"name"      
#define name85_num  num  
#define name85_sub  sub   

#define name86    	"name"      
#define name86_num  num  
#define name86_sub  sub   

#define name87    	"name"      
#define name87_num  num  
#define name87_sub  sub   

#define name88    	"name"      
#define name88_num  num  
#define name88_sub  sub   

#define name89    	"name"      
#define name89_num  num  
#define name89_sub  sub   

#define name90    	"name"      
#define name90_num  num  
#define name90_sub  sub   

#define name91    	"name"      
#define name91_num  num  
#define name91_sub  sub   

#define name92    	"name"      
#define name92_num  num  
#define name92_sub  sub   

#define name93    	"name"      
#define name93_num  num  
#define name93_sub  sub   

#define name94    	"name"      
#define name94_num  num  
#define name94_sub  sub   

#define name95    	"name"      
#define name95_num  num  
#define name95_sub  sub   

#define name96    	"name"      
#define name96_num  num  
#define name96_sub  sub   

#define name97    	"name"      
#define name97_num  num  
#define name97_sub  sub   

#define name98    	"name"      
#define name98_num  num  
#define name98_sub  sub   

#define name99    	"name"      
#define name99_num  num  
#define name99_sub  sub   

#define name100    	"name"      
#define name100_num num   
#define name100_sub sub    

#endif

void Menu_Init(void);
void anjian_menu(void);

#endif
