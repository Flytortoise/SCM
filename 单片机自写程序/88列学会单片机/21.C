//完成以定时器T0为延时并以中断的形式实现LED闪烁的功能
#include<reg52.h>
sbit D1 = P1^0;
void main()
{
	EA = 1;
	ET0 = 1;
	TMOD = 0X01;
	TH0 = (65536 - 50000)/256;
	TH0 = (65536 - 50000)%256;
	TR0 = 1;
	while(1)
		;
}

void time0(void) interrupt 1 using 0
{
	D1 = ~D1;
	TH0 = (65536 - 50000)/256;
	TH0 = (65536 - 50000)%256;
	
}
