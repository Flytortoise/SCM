#include<reg52.h>
sbit dula=P2^6;
sbit wela=P2^7;

void main()
{
	wela=1;
	P0=0xc0;
	wela=0;
			
	dula=1;
	P0=0x06;
	dula=0;
	while(1);
}

