//完成以T1为延时实现LED闪烁的功能
#include<reg52.h>
sbit D1 = P1^0;
sbit D2 = P1^1;
unsigned char a1,a2;
void main()
{
	EA = 1;
	ET1 = 1;
	TMOD= 0X10;
	TH1 = (65536 - 50000)/256;
	TL1 = (65536 - 50000)%256;
	TR1 = 1;
	a1 = 0;
	a2 = 0;
	while(1);
}

void time1(void) interrupt 3 using 0
{
	a1++;
	a2++;
	if(a1==2)
	{
		D1 = ~D1;
		a1 = 0;
	}
	if(a2==8)
	{
		D2 = ~D2;
		a2 = 0;
	}
	TH1 = (65536 - 50000)/256;
	TL1 = (65536 - 50000)%256;
}
