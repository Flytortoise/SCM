//采用定时中断控制不同的按键实现LED流水灯状态切换
#include<reg52.h>
sbit S1 = P3^4;
sbit S2 = P3^5;
sbit S3 = P3^6;
sbit S4 = P3^7;
unsigned char key;
void ys()
{
	unsigned char i,j;
	for(i=0;i<250;i++)
	for(j=0;j<250;j++)
		;
}

void ys30ms()
{
	unsigned char i,j;
	for(i=0;i<100;i++)
	for(j=0;j<100;j++)
		;
}

void zxled()
{
	P1 = 0xfe;
	ys();
	P1 = 0xfd;
	ys();
	P1 = 0xfb;
	ys();
	P1 = 0xf7;
	ys();
	P1 = 0xef;
	ys();
	P1 = 0xdf;
	ys();
	P1 = 0xbf;
	ys();
	P1 = 0x7f;
	ys();
	P1 = 0xff;
	P1 = 0xfe;
	ys();
}

void fxled()
{
	P1 = 0x7f;
	ys();
	P1 = 0xbf;
	ys();
	P1 = 0xdf;
	ys();
	P1 = 0xef;
	ys();
	P1 = 0xf7;
	ys();
	P1 = 0xfb;
	ys();
	P1 = 0xfd;
	ys();
	P1 = 0xfe;
	ys();
}

void stop()
{
	P1 = 0xff;
}

void ssled()
{
	P1 = 0xff;
	ys();
	P1 = 0x00;
	ys();
	P1 = 0xff;
	ys();
	P1 = 0x00;
	ys();
	P1 = 0xff;
	ys();
	P1 = 0x00;
	ys();
	P1 = 0xff;
	ys();
	P1 = 0x00;
	ys();
	P1 = 0xff;
	ys();
	P1 = 0x00;
	ys();
}



void main()
{
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	TMOD = 0X01;
	TH0 = (65536-1000)/256;
	TL0 = (65536-1000)%256;
	key = 0;
	while(1)
	{
		switch(key)
		{
			case 1 :zxled();break;
			case 2 :fxled();break;
			case 3 :stop();break;
			case 4 :ssled();break;
		}	
	}
}

void time0_serve() interrupt 1 using 1
{
	if((P3&0xf0) != 0xf0)
	{	
		ys30ms();
		if(S1 == 0)
		key = 1;
		if(S2 == 0)
		key = 2;
		if(S3 == 0)
		key = 3;
		if(S4 == 0)
		key = 4;
	}
	TH0 = (65536-1000)/256;
	TL0 = (65536-1000)%256;
}
