#include <reg52.h>
#include "Delay.h"

void delay(int z)		//ÑÓ³Ù1msµÄ±¶Êý
{
	int x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}

void Delay_1ms()
{
		int i;
		for(i = 110; i > 0; i--);
}

void Delay_100ms()
{
		int i;
		for(i = 0; i < 100; i++)
		{
				Delay_1ms();
		}
}

void Delay_1s()
{
    int i;
		for(i = 0; i < 10; i++)
		{
				Delay_100ms();
		}
}