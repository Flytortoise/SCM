#include<reg52.h>
typedef unsigned int uint;
typedef unsigned char uchar;
sbit dula=P2^6;
sbit wela=P2^7;
uchar code a[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
uint k,i;
void main()
{
	k=0;
	i=0;
	EA=1;
	ET1=1;
	TR1=1;
	TMOD=0X10;
	wela=1;
	P0=0x00;
	wela=0;
	TH1=(65536-30000)/256;
	TL1=(65536-30000)%256;
	while(1){};
}

void time1() interrupt	3
{
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	k++;
	if(k==10)		
	{	
		k=0;
		dula=1;
		P0=a[i];
		dula=0;
		i++;
	}
	if(i==16)
		i=0;
}