#ifndef __MENU_H__
#define __MENU_H__


#include "sys.h"

#define DEF_Name  "DEFA"
#define DEF_Value  Default
#define DEF_SUB    1

struct Menu_Select  //
{
	char name[5];			 //
	uint16_t *va;			 //
	uint16_t sub:15;  	//
};

struct ModeStruct //
{
    uint32_t OLED_Image_Live:1;//oled????? 1        
          
	uint32_t Read_Live:1;// ??????         2    

    uint32_t Uart_Read_SD:1;//????SD???         3

    uint32_t OLED_Read_SD:1;//??SD????       4

	uint32_t Write_SD:1; //?????SD?           5          
                                                                                   
	uint32_t NRF_UART_Link:1;//????              6  ????      

    uint32_t NRF_UART_Read_SD:1;//????SD??       7 ????

    uint32_t INI_Write:1;//??Flash?????          8  

    uint32_t INI_Read:1;//??Flash?????             9    
};	

#define GetMode()          Mode_Temp=(uint16_t)*((uint32_t *)&Mode);       \
                            for(All_Temp_i=0;All_Temp_i<32;All_Temp_i++)   \
                            {                                              \
                                 if(Mode_Temp>>All_Temp_i & 0x01)          \
                                 {                                         \
                                     break;                                \
                                 }                                         \
                            }                                              \
                            if(All_Temp_i!=32) MODE=All_Temp_i+1;             
                                                                              
#define SetMode()         if(MODE!=0 && MODE <= 9){ Mode_Temp=(1<<(MODE%33-1));Mode=*((struct ModeStruct *)&Mode_Temp);}  

//---------------------------------------------------------------------------------------
#define All_Count 23 //number 


#if(All_Count)
#define name0          "Mode"       //
#define name0_value    Mode	        //
#define name0_sub      DEF_SUB		  //               


#define name1          "PturnL"
#define name1_value    PtL
#define name1_sub      1


#define name2          "DturnL"
#define name2_value    DtL
#define name2_sub      1

#define name3          "PturnR"
#define name3_value    PtR
#define name3_sub      1

#define name4          "DturnR"
#define name4_value    DtR
#define name4_sub      1

#define name5          "speedS"
#define name5_value    speed_s
#define name5_sub      5

#define name6          "Time"
#define name6_value    time_set
#define name6_sub      5

#define name7          "speedT"
#define name7_value    speed_turn
#define name7_sub      5


#define name8          "ZhangAL"
#define name8_value    pwmSteerObstructL
#define name8_sub      1

#define name10          "ZhangAR"
#define name10_value    pwmSteerObstructR
#define name10_sub      1

#define name9          "ZhanAnL"
#define name9_value    ZA_changshuL
#define name9_sub      DEF_SUB

#define name11          "ZhanAnR"
#define name11_value    ZA_changshuR
#define name11_sub      DEF_SUB

#define name12          "Protect"
#define name12_value    protect
#define name12_sub      1

#define name13          "ZD P"
#define name13_value    ZD_P
#define name13_sub      1

#define name14          "ZD D"
#define name14_value    ZD_D
#define name14_sub      1

#define name15          "rampCnt"
#define name15_value    rampCnt
#define name15_sub      1

#define name16          "rampS"
#define name16_value    rampSpeed
#define name16_sub      10

#define name17          "endTime"
#define name17_value    endTime
#define name17_sub      1

#define name18          "spinto"
#define name18_value    speedInto
#define name18_sub      5

#define name19          "ObstrL"
#define name19_value    pwmSteerObstructLeft
#define name19_sub      DEF_SUB

#define name20          "ObstrR"
#define name20_value    pwmSteerObstructRight
#define name20_sub      DEF_SUB

#define name21          "ObstrL2"
#define name21_value    pwmSteerObstructLeft2 
#define name21_sub      1

#define name22          "ObstrR2"
#define name22_value    pwmSteerObstructRight2
#define name22_sub      1

#define name23          "Pv into"
#define name23_value    Pv_into
#define name23_sub      1

#define name24          "Iv into"
#define name24_value    Iv_into
#define name24_sub      1

#define name25          "Pv slow"
#define name25_value    Pv_slow
#define name25_sub      1

#define name26          "Iv slow"
#define name26_value    Iv_slow
#define name26_sub      1

#define name27           "into"
#define name27_value    into
#define name27_sub      DEF_SUB

#define name28          "PvRturn"
#define name28_value    PvR_turn
#define name28_sub      DEF_SUB

#define name29          "IvRturn"
#define name29_value    IvR_turn
#define name29_sub      DEF_SUB

#define name30          "PvOutWh"
#define name30_value    PvOutsideWheel
#define name30_sub      1

#define name31          "IvOutWh"
#define name31_value    IvOutsideWheel
#define name31_sub      1

//#define name32          DEF_Name
//#define name32_value    DEF_Value
//#define name32_sub      DEF_SUB
//#define name32_type     UINT

//#define name33          DEF_Name
//#define name33_value    DEF_Value
//#define name33_sub      DEF_SUB
//#define name33_type     UINT

//#define name34          DEF_Name
//#define name34_value    DEF_Value
//#define name34_sub      DEF_SUB
//#define name34_type     UINT

//#define name35          DEF_Name
//#define name35_value    DEF_Value
//#define name35_sub      DEF_SUB
//#define name35_type     UINT

//#define name36          DEF_Name
//#define name36_value    DEF_Value
//#define name36_sub      DEF_SUB
//#define name36_type     UINT

//#define name37          DEF_Name
//#define name37_value    DEF_Value
//#define name37_sub      DEF_SUB
//#define name37_type     UINT

//#define name38          DEF_Name
//#define name38_value    DEF_Value
//#define name38_sub      DEF_SUB
//#define name38_type     UINT

//#define name39          DEF_Name
//#define name39_value    DEF_Value
//#define name39_sub      DEF_SUB
//#define name39_type     UINT

//#define name40          DEF_Name
//#define name40_value    DEF_Value
//#define name40_sub      DEF_SUB
//#define name40_type     UINT

//#define name41          DEF_Name
//#define name41_value    DEF_Value
//#define name41_sub      DEF_SUB
//#define name41_type     UINT

//#define name42          DEF_Name
//#define name42_value    DEF_Value
//#define name42_sub      DEF_SUB
//#define name42_type     UINT

//#define name43          DEF_Name
//#define name43_value    DEF_Value
//#define name43_sub      DEF_SUB
//#define name43_type     UINT

//#define name44          DEF_Name
//#define name44_value    DEF_Value
//#define name44_sub      DEF_SUB
//#define name44_type     UINT

//#define name45          DEF_Name
//#define name45_value    DEF_Value
//#define name45_sub      DEF_SUB
//#define name45_type     UINT

//#define name46          DEF_Name
//#define name46_value    DEF_Value
//#define name46_sub      DEF_SUB
//#define name46_type     UINT

//#define name47          DEF_Name
//#define name47_value    DEF_Value
//#define name47_sub      DEF_SUB
//#define name47_type     UINT

//#define name48          DEF_Name
//#define name48_value    DEF_Value
//#define name48_sub      DEF_SUB
//#define name48_type     UINT

//#define name49          DEF_Name
//#define name49_value    DEF_Value
//#define name49_sub      DEF_SUB
//#define name49_type     UINT

//#define name50          DEF_Name
//#define name50_value    DEF_Value
//#define name50_sub      DEF_SUB
//#define name50_type     UINT

//#define name51          DEF_Name
//#define name51_value    DEF_Value
//#define name51_sub      DEF_SUB
//#define name51_type     UINT

//#define name52          DEF_Name
//#define name52_value    DEF_Value
//#define name52_sub      DEF_SUB
//#define name52_type     UINT

//#define name53          DEF_Name
//#define name53_value    DEF_Value
//#define name53_sub      DEF_SUB
//#define name53_type     UINT

//#define name54          DEF_Name
//#define name54_value    DEF_Value
//#define name54_sub      DEF_SUB
//#define name54_type     UINT

//#define name55          DEF_Name
//#define name55_value    DEF_Value
//#define name55_sub      DEF_SUB
//#define name55_type     UINT

//#define name56          DEF_Name
//#define name56_value    DEF_Value
//#define name56_sub      DEF_SUB
//#define name56_type     UINT

//#define name57          DEF_Name
//#define name57_value    DEF_Value
//#define name57_sub      DEF_SUB
//#define name57_type     UINT

//#define name58          DEF_Name
//#define name58_value    DEF_Value
//#define name58_sub      DEF_SUB
//#define name58_type     UINT

//#define name59          DEF_Name
//#define name59_value    DEF_Value
//#define name59_sub      DEF_SUB
//#define name59_type     UINT

//#define name60          DEF_Name
//#define name60_value    DEF_Value
//#define name60_sub      DEF_SUB
//#define name60_type     UINT

//#define name61          DEF_Name
//#define name61_value    DEF_Value
//#define name61_sub      DEF_SUB
//#define name61_type     UINT

//#define name62          DEF_Name
//#define name62_value    DEF_Value
//#define name62_sub      DEF_SUB
//#define name62_type     UINT

//#define name63          DEF_Name
//#define name63_value    DEF_Value
//#define name63_sub      DEF_SUB
//#define name63_type     UINT

//#define name64          DEF_Name
//#define name64_value    DEF_Value
//#define name64_sub      DEF_SUB
//#define name64_type     UINT

//#define name65          DEF_Name
//#define name65_value    DEF_Value
//#define name65_sub      DEF_SUB
//#define name65_type     UINT

//#define name66          DEF_Name
//#define name66_value    DEF_Value
//#define name66_sub      DEF_SUB
//#define name66_type     UINT

//#define name67          DEF_Name
//#define name67_value    DEF_Value
//#define name67_sub      DEF_SUB
//#define name67_type     UINT

//#define name68          DEF_Name
//#define name68_value    DEF_Value
//#define name68_sub      DEF_SUB
//#define name68_type     UINT

//#define name69          DEF_Name
//#define name69_value    DEF_Value
//#define name69_sub      DEF_SUB
//#define name69_type     UINT

//#define name70          DEF_Name
//#define name70_value    DEF_Value
//#define name70_sub      DEF_SUB
//#define name70_type     UINT

//#define name71          DEF_Name
//#define name71_value    DEF_Value
//#define name71_sub      DEF_SUB
//#define name71_type     UINT

//#define name72          DEF_Name
//#define name72_value    DEF_Value
//#define name72_sub      DEF_SUB
//#define name72_type     UINT

//#define name73          DEF_Name
//#define name73_value    DEF_Value
//#define name73_sub      DEF_SUB
//#define name73_type     UINT

//#define name74          DEF_Name
//#define name74_value    DEF_Value
//#define name74_sub      DEF_SUB
//#define name74_type     UINT

//#define name75          DEF_Name
//#define name75_value    DEF_Value
//#define name75_sub      DEF_SUB
//#define name75_type     UINT

//#define name76          DEF_Name
//#define name76_value    DEF_Value
//#define name76_sub      DEF_SUB
//#define name76_type     UINT

//#define name77          DEF_Name
//#define name77_value    DEF_Value
//#define name77_sub      DEF_SUB
//#define name77_type     UINT

//#define name78          DEF_Name
//#define name78_value    DEF_Value
//#define name78_sub      DEF_SUB
//#define name78_type     UINT

//#define name79          DEF_Name
//#define name79_value    DEF_Value
//#define name79_sub      DEF_SUB
//#define name79_type     UINT

//#define name80          DEF_Name
//#define name80_value    DEF_Value
//#define name80_sub      DEF_SUB
//#define name80_type     UINT

//#define name81          DEF_Name
//#define name81_value    DEF_Value
//#define name81_sub      DEF_SUB
//#define name81_type     UINT

//#define name82          DEF_Name
//#define name82_value    DEF_Value
//#define name82_sub      DEF_SUB
//#define name82_type     UINT

//#define name83          DEF_Name
//#define name83_value    DEF_Value
//#define name83_sub      DEF_SUB
//#define name83_type     UINT

//#define name84          DEF_Name
//#define name84_value    DEF_Value
//#define name84_sub      DEF_SUB
//#define name84_type     UINT

//#define name85          DEF_Name
//#define name85_value    DEF_Value
//#define name85_sub      DEF_SUB
//#define name85_type     UINT

//#define name86          DEF_Name
//#define name86_value    DEF_Value
//#define name86_sub      DEF_SUB
//#define name86_type     UINT

//#define name87          DEF_Name
//#define name87_value    DEF_Value
//#define name87_sub      DEF_SUB
//#define name87_type     UINT

//#define name88          DEF_Name
//#define name88_value    DEF_Value
//#define name88_sub      DEF_SUB
//#define name88_type     UINT

//#define name89          DEF_Name
//#define name89_value    DEF_Value
//#define name89_sub      DEF_SUB
//#define name89_type     UINT

//#define name90          DEF_Name
//#define name90_value    DEF_Value
//#define name90_sub      DEF_SUB
//#define name90_type     UINT

//#define name91          DEF_Name
//#define name91_value    DEF_Value
//#define name91_sub      DEF_SUB
//#define name91_type     UINT

//#define name92          DEF_Name
//#define name92_value    DEF_Value
//#define name92_sub      DEF_SUB
//#define name92_type     UINT

//#define name93          DEF_Name
//#define name93_value    DEF_Value
//#define name93_sub      DEF_SUB
//#define name93_type     UINT

//#define name94          DEF_Name
//#define name94_value    DEF_Value
//#define name94_sub      DEF_SUB
//#define name94_type     UINT

//#define name95          DEF_Name
//#define name95_value    DEF_Value
//#define name95_sub      DEF_SUB
//#define name95_type     UINT

//#define name96          DEF_Name
//#define name96_value    DEF_Value
//#define name96_sub      DEF_SUB
//#define name96_type     UINT

//#define name97          DEF_Name
//#define name97_value    DEF_Value
//#define name97_sub      DEF_SUB
//#define name97_type     UINT

//#define name98          DEF_Name
//#define name98_value    DEF_Value
//#define name98_sub      DEF_SUB
//#define name98_type     UINT

//#define name99          DEF_Name
//#define name99_value    DEF_Value
//#define name99_sub      DEF_SUB
//#define name99_type     UINT

//#define name100          DEF_Name
//#define name100_value    DEF_Value
//#define name100_sub      DEF_SUB
//#define name100_type     UINT

#endif



void Menu_Init(void);   //
void Display_All(void);  //
//uint8_t KeyScan(void);





#endif
