#ifndef __DS1302_H_
#define __DS1302_H_



//---����ȫ�ֺ���---//
void Ds1302Write(uchar addr, uchar dat);
uchar Ds1302Read(uchar addr);
void Ds1302Init();
void Ds1302ReadTime();

//---����ȫ�ֱ���--//
extern uchar TIME[7];	//����ȫ�ֱ���

#endif