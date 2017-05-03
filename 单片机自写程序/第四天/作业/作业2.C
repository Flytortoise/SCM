#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit dula=P2^6;
sbit wela=P2^7;


uchar code table[]={
0xbf,0x86,0xdb,0xcf,
0xe6,0xed,0xfd,0x87,
0xff,0xef};
uchar code table1[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f};
uint j,k,t,s;
uint i=0;

void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}

void main()
{
	
	EA=1;
	ET1=1;
	TMOD=0X10;
	TR1=1;
	TH1=(65536-10000)/256;
	TL1=(65536-10000)%256;
	while(1)
	{
	
	}
}


void time1() interrupt 3
{
	TH1=(65536-10000)/256;
	TL1=(65536-10000)%256;
	i++;
	if(i==1000)
		i=0;
		

	j=i/100;
	k=i%100/10;
	t=i%10;

	wela=1;
	P0=0xf8;
	wela=0;
	P0=0xff;
	dula=1;
	P0=table1[t];
	dula=0;
	delay(1);

	wela=1;
	P0=0xfd;
	wela=0;
	P0=0xff;
	dula=1;
	P0=table1[k];
	dula=0;
	delay(1);

	wela=1;
	P0=0xfe;
	wela=0;
	P0=0xff;
	dula=1;
	P0=table[j];
	dula=0;
	delay(1);

}
