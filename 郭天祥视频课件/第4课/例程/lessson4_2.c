#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar temp,aa,numdu,numwe;
sbit dula=P2^6;
sbit wela=P2^7;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
uchar code tablewe[]={
0xfe,0xfd,0xfb,0xf7,0xef,0xdf};
//void delay(uint z);
void main()
{
	numdu=0;
	numwe=0;
	aa=0;
	TMOD=0x01;
	TH0=(65536-5000)/256;
	TL0=(65536-5000)%256;
	EA=1;
	ET0=1;
	TR0=1;
	while(1)
	{
	//	delay(1000);
	//	temp=_crol_(temp,1);
	//	P1=temp;
		if(aa==1)
			{	
				aa=0;
				numdu++;
				if(numdu==7)
					numdu=1;
				dula=1;
				P0=table[numdu];
				dula=0;
				wela=1;
				P0=tablewe[numwe];
				wela=0;
				numwe++;
				if(numwe==6)
					numwe=0;
			}
	}
}
/*
void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}*/

void timer0() interrupt 1 
{
	TH0=(65536-5000)/256;
	TL0=(65536-5000)%256;
	aa++;	
}