#ifndef DISPLAY_H_
#define DISPLAY_H_

sbit dula = P2^6;
sbit wela = P2^7;




void Display_Time(unsigned char a, unsigned char b);
void Display_Score(unsigned char a, unsigned char b);
void Display_Time_Score(unsigned char time1, unsigned char time2,unsigned char score1, unsigned char score2);

#endif 