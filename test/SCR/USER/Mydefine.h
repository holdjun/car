#ifndef __MYDEFINE_H__
#define __MYDEFINE_H__

#include "sys.h"

#define beep     PAout(19)       //蜂鸣
/****************************/
//ccd1
#define CCD_SI_PORT    PTB
#define CCD_SI_PIN     (5)
#define ccd_SI         PBout(5)

#define CCD_CLK_PORT   PTB
#define CCD_CLK_PIN    (6)
#define ccd_clk        PBout(6)

#define CCD_SWITCH_PORT PTC
#define CCD_SWITCH_PIN  (3)
#define ccdSwitch       PCout(3) 

//ccd2

#define CCD_SI2_PORT   PTB
#define CCD_SI2_PIN    (8)
#define ccd_SI2        PBout(8)

#define CCD_CLK2_PORT  PTB
#define CCD_CLK2_PIN   (9)
#define ccd_clk2       PBout(9)

#define CCD2_SWITCH_PORT PTC
#define CCD2_SWITCH_PIN  (2)
#define ccd2Switch       PCout(2)
/**************************/

#define Key_left_PORT     PTD
#define Key_left_PIN      (11)
#define Key_left          PDin(11)

#define Key_right_PORT    PTD
#define Key_right_PIN     (9)
#define Key_right         PDin(9)

#define Key_up_PORT       PTD
#define Key_up_PIN        (8)
#define Key_up            PDin(8)

#define Key_down_PORT     PTD
#define Key_down_PIN      (10)
#define Key_down          PDin(10)

//#define Key_in_PORT       PTD
//#define Key_in_PIN        (12)
//#define Key_in            PDin(12)

#define Key_1_PORT        PTD
#define Key_1_PIN         (12)
#define Key_1             PDin(12)

/*************/
#define steer_pin         FTM2_CH0_PA10
/****************/
///*舵机初值 左右值*/
#define pwm_steer_min    1195
#define pwm_steer_center 1344
#define pwm_steer_max    1530

////shuaiShuai
//#define pwm_steer_min    1347
//#define pwm_steer_center 1479
//#define pwm_steer_max    1607

/**************/

#define Turn 1
#define Straight 0


#define differentialL 2
#define differentialR 3
#define differentialSmallL 4
#define differentialSmallR 5

extern uint16_t Mode;              //模式
extern uint16_t protect;           //是否保护
extern uint8_t time_set;           //时间设定
extern uint32_t time;              //时间变量
extern uint32_t k;                 //sd变量
extern uint8_t Dummy;              //DMA采集除bug
extern uint8_t ccd_show;           //ccd显示变量
extern uint8_t flag_longstraight;  //是否入弯减速


extern uint8_t flag_ccd_10ms;          //中断ccd采集标志
extern uint8_t flag_v_20ms;             //中断速度控制标志2



extern uint8_t P[128];             //ccd采集到的点
extern uint8_t P2[128];            //ccd2采集到的点
extern uint8_t Send_Data[292];     //发送数据
extern uint8_t oled_data[8][128];  //oled上显示的点
extern uint8_t center;             //中线
extern uint8_t value;            //ccd阈值
extern uint8_t valueLast;       //上一场阈值
extern uint8_t minLast;          //上一场最小值
extern uint8_t max , min ;
extern uint8_t leftLast;        //上一场左线
extern uint8_t rightLast;       //上一场右线
extern uint8_t s;                  //赛道宽度
extern uint8_t saoxian;            //扫线起始点
extern uint8_t flagCrossEnter;   //十字模式
extern uint8_t flagCrossCenter;   //十字给64标志
extern uint8_t flagCrossClear;    //十字清除标志
extern uint8_t flagDiu;         //丢线标志
extern uint8_t flagDiu2;        //
extern uint8_t flag_obstruct;      //障碍
extern uint8_t flag_obstruct_cntL; //障碍计数
extern uint8_t flag_obstruct_cntR; //障碍计数
extern uint16_t straight;          //直道判定标志
extern uint8_t flag_out;           //全丢计数 保护
extern uint8_t element;            //赛道元素
extern uint8_t centerRecord[10];  //连续十场中线
extern uint8_t flagCrossRecord;
extern uint8_t average_value[5];
extern uint8_t average_over;
extern uint8_t flagMissRecord;
extern uint8_t lineValueMax;
extern uint8_t lineValueMin;
extern uint8_t endLeftLine;
extern uint8_t endRightLine;
extern uint8_t end;


extern uint8_t center2;             //ccd2的中线
extern uint8_t value2;              //ccd2阈值
extern uint8_t value2_last;         //ccd2阈值
extern uint8_t left2_last;          //
extern uint8_t right2_last;         //
extern uint8_t s2;                  //ccd2赛道宽度
extern uint8_t flag_miss;           //ccd2丢线标记
extern uint8_t flag_miss_record;    //
extern uint8_t flag_cross2;         //ccd2十字
extern uint8_t flag_cross2_deal;    //ccd2十字处理
extern uint8_t flag_cross2_record;  //记录十字的转向
extern uint8_t saoxian2;
extern uint8_t max2;
extern uint8_t min2;
extern uint8_t min2_last;           //
extern uint8_t center2_record[10];  //ccd2过去十场
extern uint8_t flag_black2;
extern uint8_t average_value2[5];
extern uint8_t valueLast2;
extern uint8_t flagBlackCnt;

extern uint8_t center_new;
extern uint8_t center_new_last;
extern uint8_t flag_cross_ture;
extern uint8_t staticS; 
extern uint8_t staticS2;
extern uint8_t averageS[5];
extern uint8_t averageS2[5];
extern uint8_t flagRamp;
extern uint8_t flagObstructAvoid;
extern uint16_t flagRampAvoid;
extern uint8_t turnRecord;
extern uint8_t valueUpdata;
extern uint8_t rampCnt;
extern uint8_t valueAvoid;
extern uint8_t maxRecord;
extern uint8_t max2Record;
extern uint16_t endTime;
extern uint8_t endCnt;
extern uint8_t endLineValue;
extern uint8_t flagObstructL;
extern uint8_t flagObstructR;


extern uint16_t pwm_steer;         //舵机
extern uint16_t pwm_steer_last;    //上一场舵机占空比
extern uint16_t pwm_ten;           //十字占空比
extern int16_t pwm_left;               //左轮占空比
extern int16_t pwm_right;              //右轮占空比
extern int16_t pwm_left_last;          //上一场左路占空比
extern int16_t pwm_right_last;         //上一场右路占空比
extern int16_t e2L;                    //速度前两场偏差
extern int16_t e1L;                    //速度前一场偏差
extern int16_t e2R;                    //速度前两场偏差
extern int16_t e1R;                    //速度前一场偏差
extern uint16_t dmacntl;           //左轮速度CNT
extern uint16_t dmacntr;           //右轮速度CNT
extern uint16_t cntl[4];           //四次采集
extern uint16_t cntr[4];           //四次采集
extern uint16_t Pv_into;         //速度P
extern uint16_t Iv_into;         //速度I
extern uint16_t Pv_straight;     //速度P
extern uint16_t Iv_straight;     //速度I
extern uint16_t PvL_turn;         //速度P
extern uint16_t IvL_turn;         //速度I
extern uint16_t PvR_turn;         //速度P
extern uint16_t IvR_turn;         //速度I
extern uint16_t Dv;                //速度D
extern uint16_t PtR;               //右转P
extern uint16_t DtR;               //右转D
extern uint16_t PtL;               //左转P
extern uint16_t DtL;               //左转D
extern uint16_t ZD_P;
extern uint16_t ZD_D;
extern uint16_t Pvdif;             //差速
extern uint16_t speed_set_l;       //左轮设定目标
extern uint16_t speed_set_r;       //右轮设定目标
extern uint16_t speed_s;           //直道速度
extern uint16_t speed_turn;        //转弯速度
extern uint8_t  flag_differential; //差速
extern uint8_t  into;
extern uint8_t  speed_recordL[3];      //
extern uint8_t  speed_recordR[3];      //
extern uint16_t speed_now;
extern uint16_t speedInto;
extern uint16_t pwmSteerObstructL;
extern uint16_t pwmSteerObstructR;
extern uint16_t ZA_changshuL;
extern uint16_t ZA_changshuR;
extern uint8_t flag_into;       //入弯道
extern uint16_t Pv_slow;
extern uint16_t Iv_slow; 
extern uint8_t flag_pidfenduanL;
extern uint8_t flag_pidfenduanR;
extern uint16_t rampSpeed;
extern uint8_t speedSlowCntL;
extern uint8_t speedSlowCntR;
extern uint16_t PvOutsideWheel;
extern uint16_t IvOutsideWheel;
extern uint8_t beforeRampCnt;
extern uint8_t left,right;
extern uint8_t left2,right2;
extern int8_t kLeft[5];
extern int8_t kRight[5];
extern int8_t kSumLeft;
extern int8_t kSumRight;
extern uint8_t flagObstructL2;
extern uint8_t flagObstructR2;
extern uint8_t isFlagObstruct;
extern uint16_t pwmSteerObstructLeft;
extern uint16_t pwmSteerObstructRight;
extern uint16_t pwmSteerObstructLeft2;
extern uint16_t pwmSteerObstructRight2;
extern uint8_t ccdTemp[5];
extern uint8_t whichCcd;
extern uint8_t ccdNumber;
#endif
