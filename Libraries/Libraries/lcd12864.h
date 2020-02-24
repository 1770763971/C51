#ifndef __LCD12864_H__
#define __LCD12864_H__


void lcd_init(void);
void gushi_display();
void clrscreen();
void shuxian();
void Frame(); 
void Disp_H_Line();
void lcdfill(unsigned char disdata);	
void clrgdram(); 
void Disp_Img(unsigned char code *img);
void ceshi();
void hzkdis(unsigned char code *s); 
void CGRAM();
void write_data(unsigned char Dispdata);
void write_com(unsigned char cmdcode);
void chk_busy();


#endif

