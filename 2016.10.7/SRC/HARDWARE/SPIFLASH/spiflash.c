#include "spiflash.h"
#include "gpio.h"
#include "spi.h"
#include "delay.h"
/***********************************************************************************************
//CH_Kinetis驱动库  V2.3   
//作者    :YANDLD 
//E-MAIL  :yandld@126.com
//修改日期:2013/2/14
//版本：V2.3
//淘宝：http://upcmcu.taobao.com
//QQ    1453363089
//Copyright(C) YANDLD 2012-2022
//All rights reserved
************************************************************************************************/

/***********************************************************************************************
 功能：SPI Flash初始化
 形参：0       
 返回：1失败 0 成功
 详解：初始化SPI Flash 需要Kinetis硬件SPI模块的支持
       不使用硬件自带的CS信号，将CS配置为普通GPIO 用软件来模拟CS 
************************************************************************************************/
uint8_t SPI_FLASH_Init(void)
{
	//SPI_Init(SPI_FLASH_PORT,SPI_MASTER,SPI_PCS0,8,SPI_SCK_DIV_16);     //初始化SPI硬件串行接口引擎
	//GPIO_Init(SPI_FLASH_CS_PORT,SPI_FLASH_CS_PIN,GPIO_Mode_Out_PP,Bit_SET,GPIO_IRQC_DISABLE);
	SPI_FLASH_PowerUp();                                //启动设备
	if(SPI_FLASH_GetCapacity() == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/***********************************************************************************************
 功能：使用硬件SPI读写一个字节
 形参：0       
 返回：0
 详解：需要Kinetis硬件SPI模块的支持
************************************************************************************************/
uint8_t SPI_FLASH_ReadWriteByte(uint8_t dat,uint16_t PCS_State)
{
	return SPI_ReadWriteByte(SPI1_PCS0_PB10,dat,PCS_State);
}
/***********************************************************************************************
 功能：读取芯片ID
 形参：0       
 返回：ID
 详解：
************************************************************************************************/
uint16_t SPI_FLASH_ReadID(void)
{
	uint16_t Temp = 0;	  
	/*
	SPI_FLASH_CS=0;				    
	SPI_FLASH_ReadWriteByte(0x90);//发送读取ID命令	    
	SPI_FLASH_ReadWriteByte(0x00); 	    
	SPI_FLASH_ReadWriteByte(0x00); 	    
	SPI_FLASH_ReadWriteByte(0x00); 	 			   
	Temp|=SPI_FLASH_ReadWriteByte(0xFF)<<8;  
	Temp|=SPI_FLASH_ReadWriteByte(0xFF);	 
	SPI_FLASH_CS=1;		
*/
	SPI_FLASH_CS=0;
	SPI_FLASH_ReadWriteByte(0x90,SPI_PCS_Inactive);
	SPI_FLASH_ReadWriteByte(0x00,SPI_PCS_Inactive);
	SPI_FLASH_ReadWriteByte(0x00,SPI_PCS_Inactive);
	SPI_FLASH_ReadWriteByte(0x00,SPI_PCS_Inactive);
	
	Temp |= SPI_FLASH_ReadWriteByte(0xFF,SPI_PCS_Inactive)<<8;
	
	Temp |= SPI_FLASH_ReadWriteByte(0xFF,SPI_PCS_Asserted);
	SPI_FLASH_CS=1;
	return Temp;
}   	
/***********************************************************************************************
 功能：读取SPI_FLASH的状态寄存器
 形参：0       
 返回：状态寄存器值
 详解：
			BIT  7    6   5   4   3   2   1   0
		    	SPR  RV  TB BP2 BP1 BP0 WEL BUSY
				SPR:默认0,状态寄存器保护位,配合WP使用
				TB,BP2,BP1,BP0:FLASH区域写保护设置
				WEL:写使能锁定
				BUSY:忙标记位(1,忙;0,空闲)
				默认:0x00
************************************************************************************************/
uint8_t SPI_FLASH_ReadSR(void)   
{  
	uint8_t byte=0;   
	SPI_FLASH_CS=0;
	SPI_FLASH_ReadWriteByte(W25X_ReadStatusReg,SPI_PCS_Inactive);    //发送读取状态寄存器命令    
	byte=SPI_FLASH_ReadWriteByte(0XFF,SPI_PCS_Asserted);             //读取一个字节   
	SPI_FLASH_CS=1;
	return byte;   
} 
/***********************************************************************************************
 功能：写SPI_FLASH状态寄存器
 形参：写入值   
 返回：0
 详解：只有SPR,TB,BP2,BP1,BP0(bit 7,5,4,3,2)可以写!!!
************************************************************************************************/
void SPI_FLASH_WriteSR(uint8_t sr)   
{   
	SPI_FLASH_CS=0;
	SPI_FLASH_ReadWriteByte(W25X_WriteStatusReg,SPI_PCS_Inactive);   //发送写取状态寄存器命令    
	SPI_FLASH_ReadWriteByte(sr,SPI_PCS_Asserted);               //写入一个字节   
	SPI_FLASH_CS=1;	
}   
/***********************************************************************************************
 功能：等待SPIFLASH忙
 形参：0
 返回：0
 详解：当SPIFLASH工作时候，主机必须等待SPIFLASH工作完成后，才能发送新的命令
************************************************************************************************/
void SPI_FLASH_WaitBusy(void)   
{   
	while((SPI_FLASH_ReadSR()&0x01)==0x01);   // 等待BUSY位清空
}  
/***********************************************************************************************
 功能：写使能
 形参：0
 返回：0
 详解：
************************************************************************************************/
void SPI_FLASH_WriteEnable(void)   
{
	SPI_FLASH_CS=0;                            //使能器件   
  SPI_FLASH_ReadWriteByte(W25X_WriteEnable,SPI_PCS_Asserted);      //发送写使能  
	SPI_FLASH_CS=1;                            //取消片选     	      
} 
/***********************************************************************************************
 功能：写禁止
 形参：0
 返回：0
 详解：
************************************************************************************************/
void SPI_FLASH_WriteDisable(void)   
{  
	SPI_FLASH_CS=0;                            //使能器件   
  SPI_FLASH_ReadWriteByte(W25X_WriteDisable,SPI_PCS_Asserted);     //发送写禁止指令    
	SPI_FLASH_CS=1;                            //取消片选     	      
} 		
/***********************************************************************************************
 功能：读取SPI FLASH  
 形参：pBuffer:数据存储区
			 ReadAddr:开始读取的地址(24bit)
	     NumByteToRead:要读取的字节数(最大65535)
 返回：0
 详解：在指定地址开始读取指定长度的数据
************************************************************************************************/
void SPI_FLASH_Read(uint8_t* pBuffer,uint32_t ReadAddr,uint16_t NumByteToRead)   
{ 
 	uint16_t i;   										    
	SPI_FLASH_CS=0;                            //使能器件   
    SPI_FLASH_ReadWriteByte(W25X_ReadData,SPI_PCS_Inactive);         //发送读取命令   
    SPI_FLASH_ReadWriteByte((uint8_t)((ReadAddr)>>16),SPI_PCS_Inactive);  //发送24bit地址    
    SPI_FLASH_ReadWriteByte((uint8_t)((ReadAddr)>>8),SPI_PCS_Inactive);   
    SPI_FLASH_ReadWriteByte((uint8_t)ReadAddr,SPI_PCS_Inactive);   
    for(i=0;i<NumByteToRead-1;i++)
	  { 
        pBuffer[i]=SPI_FLASH_ReadWriteByte(0XFF,SPI_PCS_Inactive);   //循环读数  
    }
		SPI_FLASH_ReadWriteByte(pBuffer[NumByteToRead],SPI_PCS_Asserted);
	SPI_FLASH_CS=1;  				    	      
}  
/***********************************************************************************************
 功能：写1页的SPIFLASH
 形参：pBuffer:数据存储区
			 ReadAddr:开始读取的地址(24bit)
	     NumByteToRead:要读取的字节数(最大65535)
 返回：0
 详解：NumByteToWrite:要写入的字节数(最大256),该数不应该超过该页的剩余字节数!!!	
			 1个PAGE(最小写单位)256Byte, 16个PAGE组成1个Sector(最小擦除单位)
************************************************************************************************/
void SPI_FLASH_WritePage(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite)
{
 	uint16_t i;  
    SPI_FLASH_WriteEnable();                  //SET WEL 
	SPI_FLASH_CS=0;                            //使能器件   
    SPI_FLASH_ReadWriteByte(W25X_PageProgram,SPI_PCS_Inactive);      //发送写页命令   
    SPI_FLASH_ReadWriteByte((uint8_t)((WriteAddr)>>16),SPI_PCS_Inactive); //发送24bit地址    
    SPI_FLASH_ReadWriteByte((uint8_t)((WriteAddr)>>8),SPI_PCS_Inactive);   
    SPI_FLASH_ReadWriteByte((uint8_t)WriteAddr,SPI_PCS_Inactive);   
    for(i=0;i<NumByteToWrite-1;i++)SPI_FLASH_ReadWriteByte(pBuffer[i],SPI_PCS_Inactive);//循环写数  
	  SPI_FLASH_ReadWriteByte(pBuffer[NumByteToWrite],SPI_PCS_Asserted);
	SPI_FLASH_CS=1;                            //取消片选 
	SPI_FLASH_WaitBusy();					   //等待写入结束
} 
/***********************************************************************************************
 功能：擦除一个扇区
 形参：Dst_Addr:扇区号  不是地址 是地址/4096
 返回：0
 详解：擦除一个扇区的最少时间:150ms
************************************************************************************************/
void SPI_FLASH_EraseSector(uint32_t Dst_Addr)   
{  
	Dst_Addr*=4096;
	SPI_FLASH_WriteEnable();                  //SET WEL 	 
	SPI_FLASH_WaitBusy();   
	SPI_FLASH_CS=0;                            //使能器件   
	SPI_FLASH_ReadWriteByte(W25X_SectorErase,SPI_PCS_Inactive);      //发送扇区擦除指令 
	SPI_FLASH_ReadWriteByte((uint8_t)((Dst_Addr)>>16),SPI_PCS_Inactive);  //发送24bit地址    
	SPI_FLASH_ReadWriteByte((uint8_t)((Dst_Addr)>>8),SPI_PCS_Inactive);   
	SPI_FLASH_ReadWriteByte((uint8_t)Dst_Addr,SPI_PCS_Asserted);  
	SPI_FLASH_CS=1;                            //取消片选     	      
	SPI_FLASH_WaitBusy();   				   //等待擦除完成
}  
/***********************************************************************************************
 功能：无检验写SPI FLASH 
 形参：pBuffer         : 数据存储区
			 WriteAddr       : 开始写入的地址(24bit)
	     NumByteToWrite  :要写入的字节数(最大65535)
 返回：0
 详解：必须确保所写的地址范围内的数据全部为0XFF,否则在非0XFF处写入的数据将失败!
			 具有自动换页功能 
			 在指定地址开始写入指定长度的数据,但是要确保地址不越界!
************************************************************************************************/
void SPI_FLASH_WriteNoCheck(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite)   
{ 			 		 
	uint16_t pageremain;	   
	pageremain=256-WriteAddr%256; //单页剩余的字节数		 	    
	if(NumByteToWrite<=pageremain)pageremain=NumByteToWrite;//不大于256个字节
	while(1)
	{	   
		SPI_FLASH_WritePage(pBuffer,WriteAddr,pageremain);
		if(NumByteToWrite==pageremain)break;//写入结束了
	 	else //NumByteToWrite>pageremain
		{
			pBuffer+=pageremain;
			WriteAddr+=pageremain;	

			NumByteToWrite-=pageremain;			  //减去已经写入了的字节数
			if(NumByteToWrite>256)pageremain=256; //一次可以写入256个字节
			else pageremain=NumByteToWrite; 	  //不够256个字节了
		}
	};	    
} 
/***********************************************************************************************
 功能：写SPIFlash(用户接口)
 形参：pBuffer         : 数据存储区
			 WriteAddr       : 开始写入的地址(24bit)
	     NumByteToWrite  :要写入的字节数(最大65535)
 返回：0
 详解：//该函数带擦除操作!
************************************************************************************************/
uint8_t SPI_FLASH_BUFFER[4096];		 
void SPI_FLASH_Write(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite)   
{ 
	uint32_t secpos;
	uint16_t secoff;
	uint16_t secremain;	   
 	uint16_t i;    
	uint8_t * SPI_FLASH_BUF;	  
	SPI_FLASH_BUF=SPI_FLASH_BUFFER;	     
 	secpos=WriteAddr/4096;//扇区地址  
	secoff=WriteAddr%4096;//在扇区内的偏移
	secremain=4096-secoff;//扇区剩余空间大小   

 	if(NumByteToWrite<=secremain)secremain=NumByteToWrite;//不大于4096个字节
	while(1) 
	{	
		SPI_FLASH_Read(SPI_FLASH_BUF,secpos*4096,4096);//读出整个扇区的内容
		for(i=0;i<secremain;i++)//校验数据
		{
			if(SPI_FLASH_BUF[secoff+i]!=0XFF)break;//需要擦除  	  
		}
		if(i<secremain)//需要擦除
		{
			SPI_FLASH_EraseSector(secpos);//擦除这个扇区
			for(i=0;i<secremain;i++)	   //复制原来的数据
			{
				SPI_FLASH_BUF[i+secoff]=pBuffer[i];	  
			}
			SPI_FLASH_WriteNoCheck(SPI_FLASH_BUF,secpos*4096,4096);//写入整个扇区  
		}else SPI_FLASH_WriteNoCheck(pBuffer,WriteAddr,secremain);//写已经擦除了的,直接写入扇区剩余区间. 				   
		if(NumByteToWrite==secremain)break;//写入结束了
		else//写入未结束
		{
			secpos++;//扇区地址增1
			secoff=0;//偏移位置为0 	 

		   	pBuffer+=secremain;  //指针偏移
			WriteAddr+=secremain;//写地址偏移	   
		   	NumByteToWrite-=secremain;				//字节数递减
			if(NumByteToWrite>4096)secremain=4096;	//下一个扇区还是写不完
			else secremain=NumByteToWrite;			//下一个扇区可以写完了
		}	 
	}	 
}
/***********************************************************************************************
 功能：进入休眠模式
 形参：0
 返回：0
 详解：
************************************************************************************************/
void SPI_FLASH_PowerDown(void)   
{ 
	SPI_FLASH_CS=0;                            //使能器件   
	SPI_FLASH_ReadWriteByte(W25X_PowerDown,SPI_PCS_Asserted);        //发送掉电命令  
	SPI_FLASH_CS=1;                            //取消片选     	      
	DelayUs(3);                               //等待TPD  
}   
/***********************************************************************************************
 功能：退出休眠模式
 形参：0
 返回：0
 详解：
************************************************************************************************/
void SPI_FLASH_PowerUp(void)   
{  
  SPI_ReadWriteByte(SPI1_PCS0_PB10,W25X_ReleasePowerDown,SPI_PCS_Inactive);
	//SPI_FLASH_CS=0;                            //使能器件   
	//SPI_FLASH_ReadWriteByte(W25X_ReleasePowerDown);   //  send W25X_PowerDown command 0xAB    
	//SPI_FLASH_CS=1;                            //取消片选     	      
	DelayUs(3);                               //等待TRES1
}   
/***********************************************************************************************
 功能：获得SPIFlash容量
 形参：0
 返回：容量，单位为Byte
 详解：
************************************************************************************************/
uint32_t SPI_FLASH_GetCapacity(void)
{
	uint16_t id;
	id=SPI_FLASH_ReadID();
	switch (id)
	{
		case W25Q80 : return (1024*1024*1);
		case W25Q16 : return (1024*1024*2);
		case W25Q32 : return (1024*1024*4);
		case W25Q64 : return (1024*1024*8);
		case W25X10 : return (1024*128);
		case W25X20 : return (1024*256);
		case W25X40 : return (1024*512);
		default     : return 0;
	}
}
/***********************************************************************************************
 功能：擦除整个芯片
 形参：0
 返回：0
 详解：等待时间超长...
************************************************************************************************/
void SPI_FLASH_EraseChip(void)   
{                                   
	SPI_FLASH_WriteEnable();                  //SET WEL 
	SPI_FLASH_WaitBusy();   
	SPI_FLASH_CS=0;                            //使能器件   
	SPI_FLASH_ReadWriteByte(W25X_ChipErase,SPI_PCS_Asserted);        //发送片擦除命令  
	SPI_FLASH_CS=1;                            //取消片选     	      
	SPI_FLASH_WaitBusy();   				   //等待芯片擦除结束	
}   

