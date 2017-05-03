//采用不同按键控制不同延时时间的LED流水灯状态切换
#include<reg52.h>
unsigned char ds;
sbit S1 = P3^4;
sbit S2 = P3^5;
sbit S3 = P3^6;
sbit S4 = P3^7;


void ys30ms()
{
	unsigned char i,j;
	for(i=0;i<100;i++)
	for(j=0;j<100;j++)
		;
}


void ys(unsigned char k)
{
	unsigned char x;
	for(x=0;x<k;x++)
		ys30ms();
}

void main()
{
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	TMOD = 0X01;
	TH0 = 256-200;
	TL0 = 256-200;
	ds = 3;
	while(1)
	{
		P1 = 0xfe;
		ys(ds);
		P1 = 0xfd;
		ys(ds);
		P1 = 0xfb;
		ys(ds);
		P1 = 0xf7;
		ys(ds);
		P1 = 0xef;
		ys(ds);
		P1 = 0xdf;
		ys(ds);
		P1 = 0xbf;
		ys(ds);
		P1 = 0x7f;
		ys(ds);
		P1 = 0xff;
	}
}

void time0() interrupt 1 using 1
{

	P3 = 0xff;
	if((P3&0xf0) != 0xf0)
	{	
		ys30ms();
		if(S1 == 0)
			ds = 5;
		if(S2 == 0)
			ds = 15;
		if(S3 == 0)
			ds = 25;
		if(S4 == 0)
			ds = 35;
	}
	TH0 = 256-200;
	TL0 = 256-200;

}
