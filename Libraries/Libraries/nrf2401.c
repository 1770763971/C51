//**********************************
//   NRF24L01+模块发射程序
//      用8个LED调试
//   Txz001 2012.05.16
//**********************************
#include "common.h"
#include "key.h"
#include "delay.h"
#include "nrf2401.h"




extern uchar KeyValue1;

//*********************NRF24L01函数定义****************************

sbit CE=P1^0;
sbit CSN =P3^7;
sbit SCK =P3^6;
sbit MOSI =P2^2;
sbit MISO =P2^0;
sbit IRQ =P3^3;

sbit led2=P2^1;
sbit led1 =P2^0;

//*****************NRF24L01常量**********************
#define TX_ADR_WIDTH    5    //发送地址宽度 5字节
#define RX_ADR_WIDTH    5    //接收地址宽度 5字节
#define TX_PLOAD_WIDTH  32   //发送数据宽度 32字节
#define RX_PLOAD_WIDTH  32   //接收数据的宽度 32字节
uchar const TX_ADDRESS[TX_ADR_WIDTH]= {0xff,0xff,0xff,0xff,0xff}; //本地地址
uchar const RX_ADDRESS[RX_ADR_WIDTH]= {0xff,0xff,0xff,0xff,0xff}; //接收地址
//*****************NRF24L01寄存器指令*******************
#define READ_REG        0x00   // 读寄存器指令
#define WRITE_REG       0x20  // 写寄存器指令
#define RD_RX_PLOAD     0x61   // 读取接收数据指令
#define WR_TX_PLOAD     0xA0   // 写待发数据指令
#define FLUSH_TX        0xE1   //清空发送缓冲区
//**************SPI(nRF24L01)寄存器地址常量*****************
#define CONFIG          0x00  // 配置收发状态，CRC校验模式以及收发状态响应方式
#define EN_AA           0x01  // 自动应答功能设置
#define EN_RXADDR       0x02  // 可用信道设置
#define SETUP_AW        0x03  // 收发地址宽度设置
#define SETUP_RETR      0x04  // 自动重发功能设置
#define RF_CH           0x05  // 工作频率设置
#define RF_SETUP        0x06  // 发射速率、功耗功能设置
#define STATUS          0x07  // 状态寄存器
#define OBSERVE_TX      0x08  // 发送监测功能
#define CD              0x09  // 地址检测            
#define RX_ADDR_P0      0x0A  // 频道0接收数据地址
#define RX_ADDR_P1      0x0B  // 频道1接收数据地址
#define RX_ADDR_P2      0x0C  // 频道2接收数据地址
#define RX_ADDR_P3      0x0D  // 频道3接收数据地址
#define RX_ADDR_P4      0x0E  // 频道4接收数据地址
#define RX_ADDR_P5      0x0F  // 频道5接收数据地址
#define TX_ADDR         0x10  // 发送地址寄存器
#define RX_PW_P0        0x11  // 接收频道0接收数据长度
#define RX_PW_P1        0x12  // 接收频道0接收数据长度
#define RX_PW_P2        0x13  // 接收频道0接收数据长度
#define RX_PW_P3        0x14  // 接收频道0接收数据长度
#define RX_PW_P4        0x15  // 接收频道0接收数据长度
#define RX_PW_P5        0x16  // 接收频道0接收数据长度
#define FIFO_STATUS     0x17  // FIFO栈入栈出状态寄存器设置

/**********************************************
/*函数：uint SPI_RW(uint uchar)
/*功能：NRF24L01的SPI写时序
/**********************************************/
uchar SPI_RW(uchar uuchar)
{
uchar bit_ctr;
    for(bit_ctr=0;bit_ctr<8;bit_ctr++) // 输出8个位
    {
  MOSI = (uuchar & 0x80);     //输出uuhar的最高位
  uuchar = (uuchar << 1);     //左移一位
  SCK = 1;                    // 将时钟线置‘1’
  uuchar |= MISO;             //同时读取STATUS
  SCK = 0;                //然后再将时钟线置‘0’
    }
    return(uuchar);               //返回读取的值
}
/***********************************************
/*函数：uchar SPI_Read(uchar reg)
/*功能：NRF24L01的SPI读取一个字节时序
/***********************************************/
uchar SPI_Read(uchar reg)
{
uchar reg_val;
CSN = 0;             //CSN置'0',允许指令操作
SPI_RW(reg);            //写一条reg指令
reg_val = SPI_RW(0);    //读取reg的值到reg_val
CSN = 1;                //CSN置'1',禁示操作
return(reg_val);        //返回读取的值
}
/***********************************************
/*功能：NRF24L01写一个字节到寄存器函数
/***********************************************/
uchar SPI_RW_Reg(uchar reg, uchar value)
{
uchar status;
  
CSN = 0;                   // CSN置'0',允许操作
status = SPI_RW(reg);      //这指令，并读STATUS
SPI_RW(value);             //写数据值到reg
CSN = 1;                   // CSN置'1',禁止操作
return(status);            // return nRF24L01 status uchar
}
/*****************************************************************
/*函数：uint SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars)
/*功能: 用于写数据：reg:为寄存器地址，
/*                  pBuf：为待写入数据地址，
/*                  uchars：写入数据的个数
/*****************************************************************/
uchar SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars)
{
uchar status,uchar_ctr;
CSN = 0;            //SPI使能        
status = SPI_RW(reg);   
for(uchar_ctr=0; uchar_ctr<uchars; uchar_ctr++) //
  SPI_RW(*pBuf++);
CSN = 1;           //关闭SPI
return(status);    //  
}
//******************************************
/*NRF24L01初始化
//******************************************/
void init_NRF24L01(void)
{
  delayms(1);
  CE=0;    //  射频停止工作
  CSN=1;   // 停止寄存器读写
  SCK=0;   //时种信号停止读写
  IRQ=1;//中断复位
  SPI_RW_Reg(WRITE_REG + EN_AA, 0x00);      //  频道0自动 ACK应答禁止  
  SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0x00);      //禁止自动发送
  SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  //  允许接收地址只有频道0，   
  SPI_RW_Reg(WRITE_REG + RF_CH, 1);        //   设置信道工作为2.4GHZ，收发必须一致
  SPI_RW_Reg(WRITE_REG + RX_PW_P0, RX_PLOAD_WIDTH); //设置接收数据长度，本次设置为32字节
  SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);     //设置发射速率为2MHZ，发射功率为最大值0dB  
}
/******************************************************
/*函数：void nRF24L01_TxPacket(unsigned char * tx_buf)
/*功能：发送 tx_buf中数据
/*******************************************************/
void nRF24L01_TxPacket(unsigned char * tx_buf)
{
CE=0;   //StandBy I模式  
SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // 写本地地址  
SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // 装载接收端地址
SPI_Write_Buf(WR_TX_PLOAD, tx_buf, TX_PLOAD_WIDTH);// 装载数据  
SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);      // IRQ收发完成中断响应，16位CRC，主发送
CE=1;   //置高CE，激发数据发送
delayms(1);
led2=~led2;
}













#define GPIO_KEY P1
#define GPIO_DIG P0

uchar KeyValue1;



int KEYDOWN1()
{
	uchar a=0;
	GPIO_KEY=0x0f;	 //0000 1111 初始状态  高四位0	低四位1
	if(GPIO_KEY!=0x0f) //判断是否按下
	{
		delay(1000);   //消抖
		if (GPIO_KEY!=0x0f)	 //再次判断
		{
			GPIO_KEY=0x0f;	 //保险起见重新赋值	0000 1111
			switch (GPIO_KEY)
			{								 //测试列
				case 0x07:KeyValue1=0;break;	 // 0000 0111
				case 0x0b:KeyValue1=1;break;	 // 0000 1011
				case 0x0d:KeyValue1=2;break;	 // 0000 1101
				case 0x0e:KeyValue1=3;break;	 // 0000 1110
			}
			GPIO_KEY=0xf0;	 //重新赋值	1111 0000
			switch (GPIO_KEY)
			{										  //测试行
				case 0x70:KeyValue1=KeyValue1;break;	  // 0111 0000
				case 0xb0:KeyValue1=KeyValue1+4;break;  // 1011 0000
				case 0xd0:KeyValue1=KeyValue1+8;break;  // 1101 0000
				case 0xe0:KeyValue1=KeyValue1+12;break; // 1110 0000
			}
			while ((a<10)&&(GPIO_KEY!=0xf0))	  //按键松开的判断
			{
				delay(1000);
				a++;
			}
			
		}
	}
	return (KeyValue1);
}
