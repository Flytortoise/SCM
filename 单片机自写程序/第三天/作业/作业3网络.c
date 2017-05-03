#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
uint flag=0;
uint fre;
uchar tt=0;
sbit beep=P2^3;
void main()
{ 
  beep=0;
  TMOD=0x11;
  TH0=(65536-50000)/256;
  TL0=(65535-50000)%256;
  TH1=(65536-fre)/256;
  TL1=(65535-fre)%256;
  EA=1;
  ET0=1;
  TR0=1;
  ET1=1;
  TR1=1;
  while(1) ;
}
void time1() interrupt 3
{
    TH1=(65536-50000)/256;
    TL1=(65535-50000)%256; 
    flag++;
    if(flag==320)
   {
    flag=0;
   }
  }
void time0() interrupt 1
{
    TR0=0;
    TH0=(65536-fre)/256;
    TL0=(65535-fre)%256;
   if (flag<40)
  {
     tt++;
    if(tt==10)
     {
      tt=0;
      fre=50000;
      beep=~beep;
     }
   }
   if(flag>=40&&flag<80)
  {
   fre=50000;
   beep=~beep;
  }
  if(flag>=80&&flag<120)
  {
   fre=10000;
   beep=~beep;
  }
  if(flag>=120&&flag<160)
  {
  fre=5000;
  beep=~beep;
  }
  if(flag>=160&&flag<200)
  {
   fre=2500;
   beep=~beep;
  }
  if(flag>=200&&flag<240)
  {
   fre=1250;
   beep=~beep;
  }
  if(flag>=240&&flag<280)
  {
   fre=625;
   beep=~beep;
  }
   if(flag>=280&&flag<320)
  {
   fre=500;
   beep=~beep;
   }
  TR0=1;
  }