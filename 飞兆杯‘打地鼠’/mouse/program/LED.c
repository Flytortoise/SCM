#include <reg52.h>
#include <intrins.h>
#include "LED.h"

void LED_Init()
{
	LED1 = 0;
	LED2 = 0;
	LED3 = 0;
	LED4 = 0;
	LED5 = 0;
	LED6 = 0;
	LED7 = 0;	
	LED8 = 0;
}

void LED_Light()
{
    LED1 =~ LED1;
	LED2 =~ LED2;
	LED3 =~ LED3;
	LED4 =~ LED4;
	LED5 =~ LED5;
	LED6 =~ LED6;
	LED7 =~ LED7;
	LED8 =~ LED8;
}

void LED_Now()
{
	P1 = 0X00;
}

void LED_Close()
{
	P1 = 0XFF;
}

void LED_Flow()
{
	unsigned char a = 0xfe;
	int k;

	for(k = 8;k > 0; k--)
	{ 	
		P1 = a;
		Delay_100ms();
		P1 = 0xff;
		Delay_100ms();
		a = _crol_(a,1);		//Ñ­»·×óÒÆ
	}
}