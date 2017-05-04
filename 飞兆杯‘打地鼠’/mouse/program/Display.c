#include <reg52.h>
#include "Delay.h"
#include "Display.h"

unsigned char code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};

void Display_Time(unsigned char a, unsigned char b)
{
	dula=1;
	P0=table[a];
	dula=0;		
	P0=0xff;		
	wela=1;
	P0=0xfe;
	wela=0;
	delay(1);

	dula=1;
	P0=table[b];
	dula=0;
	P0=0xff;
	wela=1;
	P0=0xfd;
	wela=0;
	delay(1);
}

void Display_Score(unsigned char a, unsigned char b)
{
	dula=1;
	P0=table[a];
	dula=0;		
	P0=0xff;		
	wela=1;
	P0=0xef;
	wela=0;
	delay(1);

	dula=1;
	P0=table[b];
	dula=0;
	P0=0xff;
	wela=1;
	P0=0xdf;
	wela=0;
	delay(1);
}

void Display_Time_Score(unsigned char time1, unsigned char time2,unsigned char score1, unsigned char score2)
{
	dula=1;
	P0=table[time1];
	dula=0;		
	P0=0xff;		
	wela=1;
	P0=0xfe;
	wela=0;
	delay(1);

	dula=1;
	P0=table[time2];
	dula=0;
	P0=0xff;
	wela=1;
	P0=0xfd;
	wela=0;
	delay(1);
	
	dula=1;
	P0=table[score1];
	dula=0;		
	P0=0xff;		
	wela=1;
	P0=0xef;
	wela=0;
	delay(1);

	dula=1;
	P0=table[score2];
	dula=0;
	P0=0xff;
	wela=1;
	P0=0xdf;
	wela=0;
	delay(1);
}