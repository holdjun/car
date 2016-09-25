#ifndef __DEFINE_H__
#define __DEFINE_H__

#include "sys.h"
#include "data_sent.h"


extern Data_Type *Sent_Data;
extern uint8_t TIME1flag_20ms;

extern unsigned char AverageValue;
extern int i,q;
extern uint16_t FTMDuty;
extern uint16_t FTMDuty_1;
extern uint16_t FTMDuty_2;
extern int a1,a2,a3,a4,a5;

extern uint8_t Pixel[128];
extern uint8_t oled_data[8][128];
extern uint8_t Send_Data[200];
extern int16_t sendData[200];	

extern uint8_t Right;
extern uint8_t Left;
extern uint8_t Center;
extern uint8_t Budao;
extern uint8_t Saoxian;
extern uint8_t Leixin;
extern uint8_t hang;

extern uint32_t SD_X;
extern uint32_t SD_D;

extern uint8_t Flag;
extern uint8_t SD_Flag;


#endif
