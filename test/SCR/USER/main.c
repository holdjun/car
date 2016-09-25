#include "sys.h"
#include "gpio.h"
#include "delay.h"
#include "led.h"
#include "wdog.h"
#include "pit.h"
#include "dma.h"
#include "ftm.h"
#include "lptm.h"
#include "key.h"
#include "adc.h"
#include "tsi.h"
#include "spi.h"
#include "i2c.h"
#include "pdb.h"
#include "sd.h"
#include "flash.h"
#include "spilcd.h"
#include "stdio.h"
#include "nrf2401.h"
#include "uart.h"
#include "oled.h"
#include "data_sent.h"
#include "math.h"
#include "L3G4200D.h"
#include "menu.h"
#include "dmacnt.h"
#include "Mydefine.h"
#include "ccd.h"

uint16_t Mode = 0;           //模式
uint16_t protect = 0;        //是否保护
uint8_t time_set = 20;       //时间设定
uint32_t time=0;             //时间变量
uint32_t k;                  //sd变量
uint8_t Dummy = 0;           //DMA采集除bug
uint8_t ccd_show = 1;        //ccd显示变量
uint8_t flag_longstraight;   //是否入弯减速


uint8_t flag_ccd_10ms=0;          //中断ccd采集标志
uint8_t flag_v_20ms;             //中断速度控制标志2


uint8_t P[128];              //ccd1采集到的点
uint8_t P2[128];             //ccd2采集到的点
uint8_t Send_Data[292];      //发送数据
uint8_t oled_data[8][128];   //oled上显示的点
uint8_t center=64;           //中线
uint8_t value;             //ccd阈值
uint8_t valueLast;        //上一场阈值
uint8_t max, min;            //
uint8_t minLast;           //上一场最小值
uint8_t leftLast=0;       //上一场左线
uint8_t rightLast=128;    //上一场右线
uint8_t s=20;                //赛道宽度
uint8_t saoxian=64;          //扫线起始点
uint8_t flagCrossEnter = 0;  //十字模式
uint8_t flagCrossCenter=0;  //十字给64标志
uint8_t flagCrossClear=0;   //十字清除标志
uint8_t flagDiu=0;        //丢线标志
uint8_t flagDiu2;         //
uint8_t flag_obstruct;       //障碍
uint8_t flag_obstruct_cntL;  //障碍计数
uint8_t flag_obstruct_cntR;  //障碍计数
uint16_t straight=0;         //直道判定标志
uint8_t flag_out;            //全丢计数 保护
uint8_t element=0;           //赛道元素
uint8_t centerRecord[10] = {64,64,64,64,64,64,64,64,64,64};  //连续十场中线
uint8_t flagCrossRecord = 0;
uint8_t average_value[5];
uint8_t average_over = 0;     //平均阈值计算完成
uint8_t flagMissRecord = 0;
uint8_t lineValueMax = 0;
uint8_t lineValueMin = 0;
uint8_t endLeftLine = 0;
uint8_t endRightLine = 0;
uint8_t end = 0;
uint16_t endTime = 12;
uint8_t endCnt = 0;
uint8_t endLineValue = 0;

uint8_t center2 = 64;        //ccd2的中线
uint8_t value2;              //ccd2阈值
uint8_t value2_last;         //ccd2阈值
uint8_t left2_last;          //
uint8_t right2_last;         //
uint8_t s2;                  //ccd2赛道宽度
uint8_t flag_miss;           //ccd2丢线标记
uint8_t flag_miss_record;    //
uint8_t flag_cross2;         //ccd2十字
uint8_t flag_cross2_deal;    //ccd2十字处理
uint8_t flag_cross2_record;  //记录十字的转向
uint8_t min2_last;           //
uint8_t max2 = 0;            //
uint8_t min2 = 255;          //
uint8_t saoxian2 = 64;       //ccd2扫线
uint8_t center2_record[10] = {64,64,64,64,64,64,64,64,64,64};  //ccd2过去十场
uint8_t flag_black2;
uint8_t average_value2[5];
uint8_t valueLast2;
uint8_t flagBlackCnt = 0;

uint8_t center_new = 64;
uint8_t center_new_last = 64;
uint8_t flag_cross_ture = 0;
uint8_t staticS = 0;  
uint8_t staticS2 = 0;
uint8_t averageS[5];
uint8_t averageS2[5];
uint8_t flagRamp = 0;
uint8_t flagObstructAvoid = 0;
uint16_t flagRampAvoid = 0;
uint8_t turnRecord = 0;
uint8_t valueUpdata = 0;
uint8_t rampCnt = 25;
uint8_t valueAvoid = 0;
uint8_t maxRecord = 0;
uint8_t max2Record = 0;



uint16_t pwm_steer=pwm_steer_center;     //舵机
uint16_t pwm_steer_last=pwm_steer_center;//上一场舵机占空比
uint16_t pwm_ten=5000;       //十字占空比
int16_t pwm_left=5000;           //左轮占空比
int16_t pwm_right=5000;          //右轮占空比
int16_t pwm_left_last=4000;      //上一场左路占空比
int16_t pwm_right_last=4000;     //上一场右路占空比
int16_t e2L;                     //速度前两场偏差
int16_t e1L;                     //速度前一场偏差
int16_t e2R;                     //速度前两场偏差
int16_t e1R;                     //速度前一场偏差
uint16_t dmacntl;            //左轮速度CNT
uint16_t dmacntr;            //右轮速度CNT
uint16_t cntl[4];            //四次采集
uint16_t cntr[4];            //四次采集
uint16_t Pv_into=75;         //速度P
uint16_t Iv_into=45;         //速度I
uint16_t Pv_straight=110;     //速度P
uint16_t Iv_straight=45;     //速度I
uint16_t PvL_turn=60;         //速度P
uint16_t IvL_turn=30;         //速度I
uint16_t PvR_turn=60;         //速度P
uint16_t IvR_turn=30;         //速度I
uint16_t Dv=0;               //速度D
uint16_t PtR=28;             //右转P
uint16_t DtR=27;             //右转D
uint16_t PtL=28;             //左转P
uint16_t DtL=27;             //左转D
uint16_t ZD_P = 11;          //直道P
uint16_t ZD_D = 10;          //直道D
uint16_t Pvdif=10;           //差速
uint16_t speed_set_l=0;      //左轮设定目标
uint16_t speed_set_r=0;      //右轮设定目标
uint16_t speed_s=210;        //直道速度
uint16_t speed_turn=150;     //转弯速度
uint8_t  flag_differential;  //差速
uint8_t  into = 17;          //
uint8_t  speed_recordL[3];      //
uint8_t  speed_recordR[3];      //
uint16_t speed_now;           //左右轮速度和
uint16_t speedInto=90;        //入弯速度
uint16_t pwmSteerObstructL=125;        
uint16_t pwmSteerObstructR=125;       
uint16_t ZA_changshuL = 8;    //障碍场数
uint16_t ZA_changshuR = 8;    //
uint8_t flag_into = 0;       //入弯道
uint16_t Pv_slow = 50;
uint16_t Iv_slow = 30;
uint8_t flag_pidfenduanL = 0;
uint8_t flag_pidfenduanR = 0;
uint16_t rampSpeed = 90;
uint8_t speedSlowCntL = 0;
uint8_t speedSlowCntR = 0;
uint16_t PvOutsideWheel = 90;
uint16_t IvOutsideWheel = 45;
uint8_t flagObstructL = 0;
uint8_t flagObstructR = 0;
uint8_t beforeRampCnt = 0;
uint8_t left,right;
uint8_t left2,right2;
int8_t kLeft[5];
int8_t kRight[5];
int8_t kSumLeft = 0;
int8_t kSumRight = 0;
uint8_t flagObstructL2 = 0;
uint8_t flagObstructR2 = 0;
uint8_t isFlagObstruct = 0;
//uint16_t pwmSteerObstructLeft = 60;
//uint16_t pwmSteerObstructRight = 60;
//uint16_t pwmSteerObstructLeft2 = 50;
//uint16_t pwmSteerObstructRight2 = 50;
uint16_t pwmSteerObstructLeft = 35;
uint16_t pwmSteerObstructRight = 35;
uint16_t pwmSteerObstructLeft2 = 50;
uint16_t pwmSteerObstructRight2 = 50;


uint8_t ccdTemp[5];
uint8_t whichCcd;
uint8_t ccdNumber;

Data_Type DATA_ALL;
extern Data_Type *Sent_Data;

/***************************************************/
void pit_init()
{
	PIT_InitTypeDef PIT_InitStruct1;
	PIT_InitStruct1.PITx = PIT1;          
	PIT_InitStruct1.PIT_Interval = 10;   
	PIT_Init(&PIT_InitStruct1);
	PIT_ITConfig(PIT1,PIT_IT_TIF,ENABLE);
	NVIC_DisableIRQ(PIT1_IRQn);
	
}
/**************************************************/
void DmaInit()
{
	DMA_InitTypeDef DMA_InitStruct1;
	DMA_InitStruct1.Channelx = DMA_CH0;                         //使用DMA0通道  (0-15)
	DMA_InitStruct1.DMAAutoClose = ENABLE;                      //传输完毕后自动关闭
	DMA_InitStruct1.EnableState = DISABLE;                       //初始化后不立即开始传输
	DMA_InitStruct1.MinorLoopLength = 5;                      //传输10次
	DMA_InitStruct1.PeripheralDMAReq  = DMA_MUX2;               //不需要触发源 尽最大努力传输
	DMA_InitStruct1.TransferBytes = 1;                          //每次传输一个字节
	//配置目的地址传输参数
	DMA_InitStruct1.DestBaseAddr = (uint32_t)&ccdTemp;     //指向目的地址
	DMA_InitStruct1.DestDataSize = DMA_DST_8BIT;                //数组为1Byte
	DMA_InitStruct1.DestMajorInc = 0;                           //只执行一次大循环
	DMA_InitStruct1.DestMinorInc = 1;                           //每次传输完地址+1
 
	//配置源地址传输参数
	DMA_InitStruct1.SourceBaseAddr = (uint32_t)&(PTD->PDIR);
	DMA_InitStruct1.SourceDataSize = DMA_SRC_8BIT;
	DMA_InitStruct1.SourceMajorInc = 0;
	DMA_InitStruct1.SourceMinorInc = 0;
	DMA_Init(&DMA_InitStruct1);
	 
	DMA_ITConfig(DMA0, DMA_IT_MAJOR, DMA_CH0,ENABLE); //开启传输完成中断
}
/*****************************************************/
void dmacnt_init()
{
	DMACNT_InitTypeDef DMACNT_InitStruct1;
	DMACNT_InitStruct1.DMACNT_Mode = DMACNT_MODE_RISING;  //上升沿计数
	DMACNT_InitStruct1.DMA_Chl = DMA_CH2;                 //使用通道 0
	DMACNT_InitStruct1.GPIOx = PTB;                       
	DMACNT_InitStruct1.GPIO_Pin =  GPIO_Pin_10;
	DMACNT_Init(&DMACNT_InitStruct1);
	
	DMACNT_InitStruct1.DMACNT_Mode = DMACNT_MODE_RISING;
	DMACNT_InitStruct1.DMA_Chl = DMA_CH1;
	DMACNT_InitStruct1.GPIOx = PTC;
	DMACNT_InitStruct1.GPIO_Pin = GPIO_Pin_4;
	DMACNT_Init(&DMACNT_InitStruct1);
}
/**********************转弯速度控制*****************************/
int main(void)
{
	//初始化系统时钟 使用外部50M晶振 PLL倍频到100M
	SystemClockSetup(ClockSource_EX50M,CoreClock_100M);
	
	DmaInit();
	OLED_Init();
	DelayInit();
	pit_init();
	dmacnt_init();
	ccd_Init();
	
	DataInit();
	Data_Uart_Init();
	
	DelayMs(1000);
	
	NVIC_EnableIRQ(PIT1_IRQn);
	NVIC_EnableIRQ(DMA0_IRQn);
	
	if(Mode==1)    //模式1   ccd图像
	{
		OLED_Clear();
		while(1)
		{
			if(flag_ccd_10ms == 1)
			{
				flag_ccd_10ms = 0;
				ccd_collect();//ccd1采集
				ccd2_collect();//ccd2采集
				CCDImage_process();//图像处理
				oled_collect();//128点转化为二位平面
				oled_show();//oled显示
			}
		}
	}
		

	return 0;
}
void assert_failed(uint8_t* file, uint32_t line)
{
	//断言失败检测
	UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}

