//**********************************
//   NRF24L01+ģ�鷢�����
//      ��8��LED����
//   Txz001 2012.05.16
//**********************************

#ifndef _NRF2401_H_
#define _NRF2401_H_







int  KEYDOWN1();
//*********************NRF24L01��������****************************

void init_NRF24L01(void);   //ģ���ʼ������
uchar SPI_RW(uchar reg);    //����SPI��дʱ��
uchar SPI_Read(uchar reg);  //�ӼĴ���reg��һ���ֽ�
void SetRX_Mode(void);      //���ý���ģʽ
uchar SPI_RW_Reg(uchar reg, uchar value);  //��Ĵ���дһ���ֽ�
uchar SPI_Read_Buf(uchar reg, uchar *pBuf, uchar uchars); // �ӻ���������uchars�ֽڵ�����
uchar SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars); //�򻺳���д��uchars�ֽڵ�����
void nRF24L01_TxPacket(uchar * tx_buf); //����һ�η���
uchar nRF24L01_RxPacket(uchar * rx_buf);//��ȡ���յ����ݣ�����rx_buf����
//***********NRF24L01ģ��IO�˿ڶ���******************

#endif