//单片机PWM控制LED
#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
uchar PWM;
sbit deep = P2^3;
void Beep();
void delayms(uchar ms);
void delay(uchar t);
void main()
{
	P3 = 0xff;
	TMOD = 0x21;	//T1为工作方式3，T0为工作方式1
	TH0 = 0xfc;
	TL0 = 0x66;
	EA = 1;
	ET0 = 1;
	ET1 = 1;
	TR0 = 1;
	while(1)
	{
		if(PWM != 255)
		{
			PWM++;
			delayms(10);	//中断在延时产生，由于占空比不断变化，会看见不同的亮度
		}
		else Beep();

	}
}

void timer0() interrupt 1
{
	TR1 = 0;
	TH0 = 0xfc;
	TL0 = 0x66;
	TH1 = PWM;
	TR1 = 1;
	P1 = 0X00;
}

void timer1() interrupt 3
{
	TR1 = 0;
	P1 = 0XFF;
}

void Beep()
{
	uchar i;
	for(i=0;i<100;i++)
	{
		delay(100);
		deep = ~deep;
	}
	deep = 1;
	delayms(100);
}

void delayms(uchar ms)
{
	uchar i;
	while(ms--)
	{
		for(i=0;i<120;i++)
			;
	}

}

void delay(uchar t)
{
	while(t--);
}
