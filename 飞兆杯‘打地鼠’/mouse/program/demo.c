#include <reg52.h>
#include <intrins.h>
#include "Key.h"
#include "LED.h"
#include "demo.h"
#include "Delay.h"
#include "Display.h"

#define MAX_TIME 30

uchar led_light1 = 0;
uchar led_light2 = 0;
uchar Display_1 = 0;
uchar Display_2 = 0;
uchar Second_1 = 0;


uchar Led_On = 1;
uchar Display_On = 0;
uchar Second_On = 0;

uchar Time = 0;
uchar Score = 0;

uchar Mouse;
uint k;
uint flag;

void Init();
void BEGIN();	//开始阶段，所有LED闪烁三次，蜂鸣器响三次
void Sure();	//确认,按开始键，进入游戏
void First();	//第一关
void Sure_Next();	//按确认键进入下一关
void Second();	//第二关
void Sure_End();	//结束

void main()
{
	Init();
	//BEGIN();
	Sure();
	First();
	Sure_Next();	
	Second();
	
	while(1)
	{
		Sure_End();
	}
}

void time0() interrupt 1
{	
	if(Led_On)
	{
		TH0 = (65536-50000)/256;		//50ms
		TL0 = (65536-50000)%256;
		led_light1++;	
	}
	
	if(Display_On)	//倒计时
	{
		TH0 = (65536-10000)/256;		//10ms
		TL0 = (65536-10000)%256;
		Display_1++;
		Display_Time_Score(Time/10,Time%10,Score/10,Score%10);
		if(Display_1 == 100)
		{
			Display_1 = 0;
			Time--;
		}
		
		if(Time == 0)
		{
			Display_1 = 0;
			Display_On = 0;
		}
	}

	
}

void time1() interrupt 3
{
	TH1 = (65536-50000)/256;		//50ms
	TL1 = (65536-50000)%256;
	if(Second_On)
	{		
		Second_1++;
		if(Second_1 == 40)
		{
			Second_1 = 0;
			flag = 0;
			P1 = 0xff;
			Mouse = _crol_(Mouse,1);		//循环左移
			k++;
		}
	}	
}


void Init()
{
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	TH0 = (65536-50000)/256;		//50ms
	TL0 = (65536-50000)%256;
	
	ET1 = 1;
	TR1 = 1;
	TMOD = 0X11;
	TH1 = (65536-50000)/256;		//50ms
	TL1 = (65536-50000)%256;
	
	LED_Init();
	
	DEEP = 1;	
}

void BEGIN()
{
	DEEP = 0;
	while(1)
	{
		if(led_light1 == 20)	//闪烁三次
		{
			led_light1 = 0;
			led_light2++;
			LED_Light();
			DEEP = ~DEEP;
			if(led_light2 == 5)
			{
				ET0 = 0;
				DEEP = 1;	//关闭
				Led_On = 0;
				break;
			}		
		}	
	}
}

void Sure()
{
	LED_Now();
	while(Key() != 16);
	LED_Close();
}

void First()
{
	Mouse = 0xfe;
	k = 1;
	
	Time = MAX_TIME;
	Score = 0;
	
	//游戏环节
	Display_On = 1;
	for(k = 1; Time != 0 ; k++)
	{ 	
		if(k == 9)
		{
			k = 1;
		}
		
		P1 = Mouse;
	
		while(Key() != k && Time != 0);
		if(Time == 0)
		{
			break;
		}
		DEEP = ~DEEP;
		Score++;
		P1 = 0xff;
		Delay_100ms();
		Mouse = _crol_(Mouse,1);		//循环左移
		DEEP = ~DEEP;
	}
	
}

void Sure_Next()
{
	LED_Now();
	while(Key() != 16)
	{
		Display_Score(Score/10,Score%10);
	}
	LED_Close();
}

void Second()
{
	uchar temp;
	Mouse = 0xfe;
	k = 1;
	flag = 1;
	
	Time = MAX_TIME;
	Score = 0;
	
	//游戏环节
	Display_On = 1;
	Second_On = 1;
	while(Time != 0)
	{ 	
		flag = 1;
		if(k == 9)
		{
			k = 1;
		}
		
		P1 = Mouse;
		
		do
		{
			temp = Key();
		}while(temp == 0 && flag != 0);
		
		if(temp != 0 && temp != k)
		{
			if(Score > 0)
			{
				Score--;
			}
		}
		else
		{
			if(flag)
			{
				DEEP = ~DEEP;
				Score++;
				P1 = 0xff;
				Delay_100ms();
				Mouse = _crol_(Mouse,1);		//循环左移
				k++;
				DEEP = ~DEEP;
			}
		}
	}
}

void Sure_End()
{
	Sure_Next();
}
