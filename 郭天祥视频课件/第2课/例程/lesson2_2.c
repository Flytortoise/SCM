#include<reg52.h>
#define uint unsigned int 
#define uchar unsigned char 
sbit D1=P1^0;
//void delay();
void delay(uint);
void main()
{
	while(1)
	{
		D1=0;
		delay(100);
		D1=1;
		delay(100);	
	}
}
/*
void delay()
{
	uint x,y;
	for(x=100;x>0;x--)
		for(y=600;y>0;y--);	
}*/
void delay(uint z)
{
	uint x;
	uchar y;
	for(x=z;x>0;x--)
		for(y=20;y>0;y--);	
}
