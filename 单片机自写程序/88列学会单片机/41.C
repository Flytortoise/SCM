//实现一个按键控制LED不同延时时间的功能
#include<reg52.h>
unsigned char ID;
sbit S1 = P3^7;
void ys()
{
	unsigned char i,j;
	for(i=0;i<200;i++)
	for(j=0;j<100;j++)
		;
}

void main()
{
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	TMOD = 0X01;                                                                   
	TH0 = 256-200;
	TL0 = 256-200;
	ID = 0;
	while(1)
	{
		switch(ID)
		{
			case 0 :P1=0XFE; break;
			case 1 :P1=0XFd; break;
			case 2 :P1=0XFb; break;
			case 3 :P1=0XF7; break;	
		}
	}
}

void time0(void) interrupt 1 using 1
{
	TR0 = 0;
	P3 = 0xff;
	if(S1 == 0)
	{
		ys();
		if(S1 == 0)
		ID++;
	}
	if(ID == 4)
	ID = 0;
	TR0 =1;
}
