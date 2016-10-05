#ifndef _MENU_H_
#define _MENU_H_

#include "sys.h"

#define Number_All  7

struct Menu_Select
{
	char name[6];
	uint16_t num;
	uint16_t sub;
};

#if(Number_All >= 1)
#define name0    	"FTM1"    
#define name0_num   FTMDuty_1 
#define name0_sub   50
#endif 

#if(Number_All >= 2)
#define name1    	"FTM2"      
#define name1_num   FTMDuty_2
#define name1_sub   50
#endif   

#if(Number_All >= 3)
#define name2    	"AI"      
#define name2_num   a1 
#define name2_sub   1
#endif   

#if(Number_All >= 4)
#define name3    	"BI"      
#define name3_num   a2 
#define name3_sub   1
#endif   

#if(Number_All >= 5)
#define name4    	"CI"      
#define name4_num   a3 
#define name4_sub   1
#endif   

#if(Number_All >= 6)
#define name5    	"DI"      
#define name5_num   a4 
#define name5_sub   1
#endif   

#if(Number_All >= 7)
#define name6    	"EI"      
#define name6_num   a5 
#define name6_sub   1
#endif   

#if(Number_All >= 8)
#define name7    	"TIME"      
#define name7_num   a6 
#define name7_sub   1
#endif   

#if(Number_All >= 9)
#define name8    	"FTM2"      
#define name8_num   FTMDuty 
#define name8_sub   50
#endif     

#if(Number_All >= 10)
#define name9    	"name3"      
#define name9_num   a8 
#define name9_sub   50
#endif  

#if(Number_All >= 11)
#define name10    	"name2"      
#define name10_num  a9  
#define name10_sub  1
#endif  

#if(Number_All >= 12)
#define name11    	"name"      
#define name11_num  num  
#define name11_sub  sub
#endif    

#if(Number_All >= 13)
#define name12    	"name"      
#define name12_num  num  
#define name12_sub  sub
#endif    

#if(Number_All >= 14)
#define name13    	"name"       
#define name13_num  num  
#define name13_sub  sub
#endif    

#if(Number_All >= 15)
#define name14    	"name"       
#define name14_num  num  
#define name14_sub  sub
#endif    

#if(Number_All >= 16)
#define name15    	"name"      
#define name15_num  num  
#define name15_sub  sub
#endif    

#if(Number_All >= 17)
#define name16    	"name"      
#define name16_num  num  
#define name16_sub  sub
#endif    

#if(Number_All >= 18)
#define name17    	"name"      
#define name17_num  num  
#define name17_sub  sub
#endif    

#if(Number_All >= 19)
#define name18    	"name"      
#define name18_num  num  
#define name18_sub  sub
#endif    

#if(Number_All >= 20)
#define name19    	"name"      
#define name19_num  num  
#define name19_sub  sub
#endif    

#if(Number_All >= 21)
#define name20    	"name"      
#define name20_num  num  
#define name20_sub  sub
#endif    

#if(Number_All >= 22)
#define name21    	"name"      
#define name21_num  num   
#define name21_sub  sub
#endif    

#if(Number_All >= 23)
#define name22    	"name"      
#define name22_num  num  
#define name22_sub  sub
#endif    

#if(Number_All >= 24)
#define name23    	"name"       
#define name23_num  num  
#define name23_sub  sub
#endif    

#if(Number_All >= 25)
#define name24    	"name"       
#define name24_num  num  
#define name24_sub  sub
#endif    

#if(Number_All >= 26)
#define name25    	"name"       
#define name25_num  num  
#define name25_sub  sub
#endif    

#if(Number_All >= 27)
#define name26    	"name"       
#define name26_num  num  
#define name26_sub  sub
#endif    

#if(Number_All >= 28)
#define name27    	"name"       
#define name27_num  num  
#define name27_sub  sub
#endif    

#if(Number_All >= 29)
#define name28    	"name"      
#define name28_num  num  
#define name28_sub  sub
#endif    

#if(Number_All >= 30)
#define name29    	"name"      
#define name29_num  num  
#define name29_sub  sub
#endif    

void Menu_Init(void);
void anjian_menu(void);

#endif
