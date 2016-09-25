#include "L3G4200D.h"
#include "sys.h"
#include "gpio.h"



/***********************************************************************************************
 功能：初始化
 形参：0
 返回：0
 详解：
************************************************************************************************/
void SPI_init()
{
	CS=1;
	SCL=1;
	SPI_Write(CTRL_REG1,0x0f);
	SPI_Write(CTRL_REG2,0x00);
	SPI_Write(CTRL_REG3,0x08);
	SPI_Write(CTRL_REG4,0x30);
	SPI_Write(CTRL_REG5,0x00);
}
/***********************************************************************************************
 功能：spi读
 形参：地址高8位和低8位
 返回：陀螺仪值
 详解：
************************************************************************************************/
uint16_t SPI_Read(uint8_t add1,uint8_t add2)
{
	uint8_t i;
	uint16_t temp1=0;
	uint16_t temp2=0;
	uint16_t temp=0;
	add1|=0x80;
	add2|=0x80;
	CS=0;
	for(i=0;i<8;i++)   //写入数据寄存器地址
		{
			SCL=0;
			if(add1<<i&0x80)
			{
				SDA=1;
			}
			else
			{
				SDA=0;
			}
			SCL=1;
		}
	SDA=1;
	for(i=0;i<8;i++)    //读取数据
		{
			temp1<<=1;
			SCL=0;
			if(SDO==1)
			{
				temp1|=0x01;
			}
			else
			{
				temp1&=~0x01;
			}
			SCL=1;
		}
		CS=1;
		SDA=1;
		
		CS=0;
	for(i=0;i<8;i++)   //写入数据寄存器地址
		{
			SCL=0;
			if(add2<<i&0x80)
			{
				SDA=1;
			}
			else
			{
				SDA=0;
			}
			SCL=1;
		}
	SDA=1;
	for(i=0;i<8;i++)    //读取数据
		{
			temp2<<=1;
			SCL=0;
			if(SDO==1)
			{
				temp2|=0x01;
			}
			else
			{
				temp2&=~0x01;
			}
			SCL=1;
		}
	CS=1;
	SDA=1;
	temp=temp1;
	temp<<=8;
	temp|=temp2;
	
	return temp+32767;
}
/***********************************************************************************************
 功能：spi写
 形参：输入寄存器地址和写入数据
 返回：0
 详解：
************************************************************************************************/
void SPI_Write(uint8_t add,uint8_t data)
{
	uint8_t i;
	CS=0;
	for(i=0;i<8;i++)
	{
		SCL=0;
		if(add<<i&0x80)
			{
				SDA=1;
			}
			else
			{
				SDA=0;
			}
		SCL=1;
	}
	for(i=0;i<8;i++)
	{
		SCL=0;
		if(data<<i&0x80)
			{
				SDA=1;
			}
			else
			{
				SDA=0;
			}
		SCL=1;
	}
	SDA=1;
	CS=1;
}
