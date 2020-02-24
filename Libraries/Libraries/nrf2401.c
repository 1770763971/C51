//**********************************
//   NRF24L01+ģ�鷢�����
//      ��8��LED����
//   Txz001 2012.05.16
//**********************************
#include "common.h"
#include "key.h"
#include "delay.h"
#include "nrf2401.h"




extern uchar KeyValue1;

//*********************NRF24L01��������****************************

sbit CE=P1^0;
sbit CSN =P3^7;
sbit SCK =P3^6;
sbit MOSI =P2^2;
sbit MISO =P2^0;
sbit IRQ =P3^3;

sbit led2=P2^1;
sbit led1 =P2^0;

//*****************NRF24L01����**********************
#define TX_ADR_WIDTH    5    //���͵�ַ��� 5�ֽ�
#define RX_ADR_WIDTH    5    //���յ�ַ��� 5�ֽ�
#define TX_PLOAD_WIDTH  32   //�������ݿ�� 32�ֽ�
#define RX_PLOAD_WIDTH  32   //�������ݵĿ�� 32�ֽ�
uchar const TX_ADDRESS[TX_ADR_WIDTH]= {0xff,0xff,0xff,0xff,0xff}; //���ص�ַ
uchar const RX_ADDRESS[RX_ADR_WIDTH]= {0xff,0xff,0xff,0xff,0xff}; //���յ�ַ
//*****************NRF24L01�Ĵ���ָ��*******************
#define READ_REG        0x00   // ���Ĵ���ָ��
#define WRITE_REG       0x20  // д�Ĵ���ָ��
#define RD_RX_PLOAD     0x61   // ��ȡ��������ָ��
#define WR_TX_PLOAD     0xA0   // д��������ָ��
#define FLUSH_TX        0xE1   //��շ��ͻ�����
//**************SPI(nRF24L01)�Ĵ�����ַ����*****************
#define CONFIG          0x00  // �����շ�״̬��CRCУ��ģʽ�Լ��շ�״̬��Ӧ��ʽ
#define EN_AA           0x01  // �Զ�Ӧ��������
#define EN_RXADDR       0x02  // �����ŵ�����
#define SETUP_AW        0x03  // �շ���ַ�������
#define SETUP_RETR      0x04  // �Զ��ط���������
#define RF_CH           0x05  // ����Ƶ������
#define RF_SETUP        0x06  // �������ʡ����Ĺ�������
#define STATUS          0x07  // ״̬�Ĵ���
#define OBSERVE_TX      0x08  // ���ͼ�⹦��
#define CD              0x09  // ��ַ���            
#define RX_ADDR_P0      0x0A  // Ƶ��0�������ݵ�ַ
#define RX_ADDR_P1      0x0B  // Ƶ��1�������ݵ�ַ
#define RX_ADDR_P2      0x0C  // Ƶ��2�������ݵ�ַ
#define RX_ADDR_P3      0x0D  // Ƶ��3�������ݵ�ַ
#define RX_ADDR_P4      0x0E  // Ƶ��4�������ݵ�ַ
#define RX_ADDR_P5      0x0F  // Ƶ��5�������ݵ�ַ
#define TX_ADDR         0x10  // ���͵�ַ�Ĵ���
#define RX_PW_P0        0x11  // ����Ƶ��0�������ݳ���
#define RX_PW_P1        0x12  // ����Ƶ��0�������ݳ���
#define RX_PW_P2        0x13  // ����Ƶ��0�������ݳ���
#define RX_PW_P3        0x14  // ����Ƶ��0�������ݳ���
#define RX_PW_P4        0x15  // ����Ƶ��0�������ݳ���
#define RX_PW_P5        0x16  // ����Ƶ��0�������ݳ���
#define FIFO_STATUS     0x17  // FIFOջ��ջ��״̬�Ĵ�������

/**********************************************
/*������uint SPI_RW(uint uchar)
/*���ܣ�NRF24L01��SPIдʱ��
/**********************************************/
uchar SPI_RW(uchar uuchar)
{
uchar bit_ctr;
    for(bit_ctr=0;bit_ctr<8;bit_ctr++) // ���8��λ
    {
  MOSI = (uuchar & 0x80);     //���uuhar�����λ
  uuchar = (uuchar << 1);     //����һλ
  SCK = 1;                    // ��ʱ�����á�1��
  uuchar |= MISO;             //ͬʱ��ȡSTATUS
  SCK = 0;                //Ȼ���ٽ�ʱ�����á�0��
    }
    return(uuchar);               //���ض�ȡ��ֵ
}
/***********************************************
/*������uchar SPI_Read(uchar reg)
/*���ܣ�NRF24L01��SPI��ȡһ���ֽ�ʱ��
/***********************************************/
uchar SPI_Read(uchar reg)
{
uchar reg_val;
CSN = 0;             //CSN��'0',����ָ�����
SPI_RW(reg);            //дһ��regָ��
reg_val = SPI_RW(0);    //��ȡreg��ֵ��reg_val
CSN = 1;                //CSN��'1',��ʾ����
return(reg_val);        //���ض�ȡ��ֵ
}
/***********************************************
/*���ܣ�NRF24L01дһ���ֽڵ��Ĵ�������
/***********************************************/
uchar SPI_RW_Reg(uchar reg, uchar value)
{
uchar status;
  
CSN = 0;                   // CSN��'0',�������
status = SPI_RW(reg);      //��ָ�����STATUS
SPI_RW(value);             //д����ֵ��reg
CSN = 1;                   // CSN��'1',��ֹ����
return(status);            // return nRF24L01 status uchar
}
/*****************************************************************
/*������uint SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars)
/*����: ����д���ݣ�reg:Ϊ�Ĵ�����ַ��
/*                  pBuf��Ϊ��д�����ݵ�ַ��
/*                  uchars��д�����ݵĸ���
/*****************************************************************/
uchar SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars)
{
uchar status,uchar_ctr;
CSN = 0;            //SPIʹ��        
status = SPI_RW(reg);   
for(uchar_ctr=0; uchar_ctr<uchars; uchar_ctr++) //
  SPI_RW(*pBuf++);
CSN = 1;           //�ر�SPI
return(status);    //  
}
//******************************************
/*NRF24L01��ʼ��
//******************************************/
void init_NRF24L01(void)
{
  delayms(1);
  CE=0;    //  ��Ƶֹͣ����
  CSN=1;   // ֹͣ�Ĵ�����д
  SCK=0;   //ʱ���ź�ֹͣ��д
  IRQ=1;//�жϸ�λ
  SPI_RW_Reg(WRITE_REG + EN_AA, 0x00);      //  Ƶ��0�Զ� ACKӦ���ֹ  
  SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0x00);      //��ֹ�Զ�����
  SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  //  ������յ�ַֻ��Ƶ��0��   
  SPI_RW_Reg(WRITE_REG + RF_CH, 1);        //   �����ŵ�����Ϊ2.4GHZ���շ�����һ��
  SPI_RW_Reg(WRITE_REG + RX_PW_P0, RX_PLOAD_WIDTH); //���ý������ݳ��ȣ���������Ϊ32�ֽ�
  SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);     //���÷�������Ϊ2MHZ�����书��Ϊ���ֵ0dB  
}
/******************************************************
/*������void nRF24L01_TxPacket(unsigned char * tx_buf)
/*���ܣ����� tx_buf������
/*******************************************************/
void nRF24L01_TxPacket(unsigned char * tx_buf)
{
CE=0;   //StandBy Iģʽ  
SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // д���ص�ַ  
SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // װ�ؽ��ն˵�ַ
SPI_Write_Buf(WR_TX_PLOAD, tx_buf, TX_PLOAD_WIDTH);// װ������  
SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);      // IRQ�շ�����ж���Ӧ��16λCRC��������
CE=1;   //�ø�CE���������ݷ���
delayms(1);
led2=~led2;
}













#define GPIO_KEY P1
#define GPIO_DIG P0

uchar KeyValue1;



int KEYDOWN1()
{
	uchar a=0;
	GPIO_KEY=0x0f;	 //0000 1111 ��ʼ״̬  ����λ0	����λ1
	if(GPIO_KEY!=0x0f) //�ж��Ƿ���
	{
		delay(1000);   //����
		if (GPIO_KEY!=0x0f)	 //�ٴ��ж�
		{
			GPIO_KEY=0x0f;	 //����������¸�ֵ	0000 1111
			switch (GPIO_KEY)
			{								 //������
				case 0x07:KeyValue1=0;break;	 // 0000 0111
				case 0x0b:KeyValue1=1;break;	 // 0000 1011
				case 0x0d:KeyValue1=2;break;	 // 0000 1101
				case 0x0e:KeyValue1=3;break;	 // 0000 1110
			}
			GPIO_KEY=0xf0;	 //���¸�ֵ	1111 0000
			switch (GPIO_KEY)
			{										  //������
				case 0x70:KeyValue1=KeyValue1;break;	  // 0111 0000
				case 0xb0:KeyValue1=KeyValue1+4;break;  // 1011 0000
				case 0xd0:KeyValue1=KeyValue1+8;break;  // 1101 0000
				case 0xe0:KeyValue1=KeyValue1+12;break; // 1110 0000
			}
			while ((a<10)&&(GPIO_KEY!=0xf0))	  //�����ɿ����ж�
			{
				delay(1000);
				a++;
			}
			
		}
	}
	return (KeyValue1);
}
