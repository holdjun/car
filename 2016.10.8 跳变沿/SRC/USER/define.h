#ifndef __DEFINE_H__
#define __DEFINE_H__

#include "sys.h"
#include "data_sent.h"


extern unsigned char AverageValue;

extern uint16_t FTMDuty;
extern uint16_t FTMDuty_1;
extern uint16_t FTMDuty_2;

extern uint16_t CenterLast[5];
extern uint16_t Center;
extern uint16_t saoxian;
extern uint16_t Left;
extern uint16_t Right;
extern uint16_t Budao;
extern uint16_t Left_p1;
extern uint16_t Right_p1;
extern uint16_t Left_p2;
extern uint16_t Right_p2;

extern uint16_t hang;
extern uint16_t leixin;
extern uint16_t leixin_last[5];

extern uint8_t flag_black;
extern uint8_t flag_miss;

extern uint16_t black_Value;
extern uint16_t white_Value;

extern uint8_t Cross_flag;
extern uint8_t Cross_flag_wan;
extern uint8_t Cross_flag_time;

extern uint16_t jiasuflag;
extern uint16_t jiansuflag;
extern uint16_t jiansu_Num;
extern uint16_t jiasu_Num;

extern uint16_t zhidaoflag;
extern uint16_t zhidaoflag_save;

extern uint8_t P1[128];
extern uint8_t oled_data[8][128];
extern uint8_t Send_Data[200];
extern int16_t sendData[200];	

extern uint32_t SD_X;
extern uint32_t SD_D;

extern uint8_t Flag;
extern uint8_t SD_Flag;
extern uint8_t TIME1flag_20ms;

#endif
