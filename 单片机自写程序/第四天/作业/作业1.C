#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
uint table[]={0x7d,0x6d,0x66,
0x4f,0x5b,0x06};
uint table1[]={0xfe,0xfd,0xfb,
0xf7,0xef,0xdf};
sbit dula=P2^6;
sbit wela=P2^7;
void delay(uint a)
{	
	uint x,y;
	for(x=a;x>0;x--)
		for(y=110;y>0;y--);
}


void main()
{
	uint wenum,dunum;
	while(1)
	{
		for(wenum=0,dunum=0;wenum<6&&dunum<6;wenum++,dunum++)
		{
			wela=1;
			P0=table1[wenum];
			wela=0;
			dula=1;
			P0=table[dunum];
			dula=0;
			delay(1);
			wela=1;//Çå³ýÓà»Ô
			P0=0xff;
			wela=0;
		
		}
		if(wenum==6&&dunum==6)
		{
			wenum=dunum=0;
		}
	}
}
