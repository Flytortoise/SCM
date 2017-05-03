#include<reg52.h>
unsigned char flag,a,num,benum;
sbit beep=P2^3;
void main()
{

	TMOD=0x21;//设置定时器1为工作方式2
	TH1=0xfd;
	TL1=0xfd;
	TH0=(65536-50000)/255;
	TL0=(65536-50000)%255;
	TR1=1;
	ET0=1;
	SM0=0;
	SM1=1;
	REN=1;
	EA=1;
	ES=1;
	while(1)
	{
		if(flag==1)
		{
			EA=0;
			flag=0;
			TR0=1;
			if(a==1)
				benum=4;
			if(a==2)
				benum=2;
			if(a==3)
				benum=1;
			if(a==4)
			{
				TR0=0;
				beep=1;	
			}
			EA=1;
		}
	}
}

void ser() interrupt 4
{
	RI=0;
	a=SBUF;
	flag=1;
}

void time0() interrupt 1
{
	TH0=(65536-50000)/255;
	TL0=(65536-50000)%255;
	num++;
	if(num>=benum)
	{
		num=0;
		beep=~beep;
	}	
}
