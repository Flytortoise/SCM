//花样流水灯
#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int

uchar code tab1[] = {0xfc,0xf9,0xf3,0xe7,0xcf,0x9f,0x3f,0x7f,0xff};


void delay(uint x)
{
	uchar i;
	while(x--)
	{
		for(i=0;i<120;i++);
	}
}

void main()
{
	uchar i;
	while(1)
	{
		for(i=0;i<9;i++)
		{
			P1=tab1[i];
			delay(100);

		}	
	}
}

