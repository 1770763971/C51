//**********************************
//   NRF24L01+模块发射程序
//      用8个LED调试
//   Txz001 2012.05.16
//**********************************

#ifndef _NRF2401_H_
#define _NRF2401_H_







int  KEYDOWN1();
//*********************NRF24L01函数定义****************************

void init_NRF24L01(void);   //模块初始化函数
uchar SPI_RW(uchar reg);    //基本SPI读写时序
uchar SPI_Read(uchar reg);  //从寄存器reg读一个字节
void SetRX_Mode(void);      //设置接收模式
uchar SPI_RW_Reg(uchar reg, uchar value);  //向寄存器写一个字节
uchar SPI_Read_Buf(uchar reg, uchar *pBuf, uchar uchars); // 从缓冲器读出uchars字节的数据
uchar SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars); //向缓冲器写进uchars字节的数据
void nRF24L01_TxPacket(uchar * tx_buf); //启动一次发送
uchar nRF24L01_RxPacket(uchar * rx_buf);//读取接收的数据，放入rx_buf数组
//***********NRF24L01模块IO端口定义******************

#endif