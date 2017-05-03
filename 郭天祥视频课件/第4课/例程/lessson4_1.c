#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar temp,aa,num;
sbit dula=P2^6;
sbit wela=P2^7;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
void delay(uint z);
void main()
{
	num=0;
	aa=0;
	TMOD=0x01;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;
	ET0=1;
	TR0=1;
	temp=0xfe;
	P1=temp;
	dula=1;
	P0=table[0];
	dula=0;
	wela=1;
	P0=0xc0;
	wela=0;
	while(1)
	{
		delay(1000);
		temp=_crol_(temp,1);
		P1=temp;
	/*	if(aa==40)
			{
				aa=0;
				num++;
				if(num==16)
					num=0;
				dula=1;
				P0=table[num];
				dula=0;		
			}	*/	
	}
}

void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}

void timer0() interrupt 1 
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	aa++;
		if(aa==40)
			{
				aa=0;
				num++;
				if(num==16)
					num=0;
				dula=1;
				P0=table[num];
				dula=0;		
			}	
}
