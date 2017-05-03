#include<reg52.h>
#include <intrins.h>
#define uint unsigned int 
#define uchar unsigned char 
uchar temp,num,num1;
sbit beep=P2^3;
sbit d0=P1^1;
sbit d1=P1^2;
sbit d2=P1^3;
sbit d3=P1^4;
void delay(uint);

void main()
{
	d0=0;
	d1=0;
	d2=0;
	d3=0;
	delay(10000);
        temp=0xfe;
	while(1)
	{	
	for(num1=0;num1<3;num1++)
		{	
		for(num=0;num<8;num++)
		{
			P1=temp;
			beep=0;
			delay(100);
			temp=_crol_(temp,1);
			P1=0xff;
			beep=1;
			delay(100);	
		}
		}
for(num1=0;num1<3;num1++)
		{	
		for(num=0;num<8;num++)
		{
			P1=temp;
			beep=0;
			delay(100);
			temp=_cror_(temp,1);
			P1=0xff;
			beep=1;
			delay(100);	
		}
		}
		while(1);
	}
}

void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);	
}