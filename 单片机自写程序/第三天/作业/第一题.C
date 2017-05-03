#include<reg52.h>
typedef unsigned int uint;
typedef unsigned char uchar;
sbit D0=P1^0;
uint k;
void main()
{
	k=0;	
	EA=1;
	ET0=1;
	TR0=1;
	TMOD=0X01;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	while(1)
	{
		if(k==10)
		{
			k=0;
			D0=~D0;
		}	
	}
}

void time0() interrupt 1
{	
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	k++;
	
}
