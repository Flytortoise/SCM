#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
uchar code table[]="ÖÐ¹ú";
uchar code table1[]="WWW.TXMCU.COM";
sbit lcden=P3^4;
sbit lcdrs=P3^5;
sbit dula=P2^6;
sbit wela=P2^7;
uchar num;


void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
void write_com(uchar com)
{
	lcdrs=0;
	P0=com;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;
}

void write_data(uchar date)
{
	lcdrs=1;
	P0=date;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;
}
void init()
{
	dula=0;
	wela=0;
	lcden=0;
	write_com(0x38);
	write_com(0x0e);
	write_com(0x06);
	write_com(0x01);
	write_com(0x80+0x10);
}
void main()
{
	init();
	for(num=0;num<11;num++)
	{
		write_data(table[num]);
		delay(20);
	}
//	write_com(1);
	write_com(0x80+0x53);
	for(num=0;num<13;num++)
	{
		write_data(table1[num]);
		delay(20);
	}
	for(num=0;num<16;num++)
	{
		write_com(0x18);
		delay(20);
	}
	while(1);
}

