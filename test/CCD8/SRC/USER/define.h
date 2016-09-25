#ifndef __DEFINE_H__
#define __DEFINE_H__

#include "sys.h"
#include "data_sent.h"

extern uint16_t FTMDuty;//舵机占空比
extern uint16_t FTMDuty_1;//电机占空比
extern uint16_t FTMDuty_2;
extern uint16_t FTMDuty_3;
extern int8_t a1,a2,a3,a4,a5,a6,a7;//p值
extern int16_t Value;//阈值

extern uint8_t P1[128];//采集数组
extern uint8_t Send_Data[200];
extern uint8_t oled_data[8][128];

extern uint8_t CenterLast[5];//记录过去五场中线位置
extern uint8_t Center;//中线
extern uint8_t LeftLast[5];//记录过去五场左线位置
extern uint8_t Left;//左线
extern uint8_t RightLast[5];//记录过去五场右线位置
extern uint8_t Right;//右线
extern uint8_t Width;//赛道宽度

extern uint8_t flag_test;//测试标志位
extern uint8_t flag_run;//运行标志位
extern uint8_t flag_sd_d;//sd卡读取标志位
extern uint8_t flag_sd_x;//sd卡写入标志位
extern uint8_t flag_20ms;//采集判断标志位
extern uint8_t flag_JianSu;//减速标志位
extern uint8_t flag_ShiZi;//十字标志位

extern uint32_t SD_D;//SD卡扇区
extern uint32_t SD_X;

extern int8_t yw;//菜单移位

extern Data_Type *Sent_Data;

#endif