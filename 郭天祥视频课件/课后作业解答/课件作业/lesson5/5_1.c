#include<reg52.h> 
#include <intrins.h> 
#define uint unsigned int 
#define uchar unsigned char 
sbit dula=P2^6;
sbit wela=P2^7;
sbit s2=P3^4;
uchar code table[]={ 
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71,
0x76,0x79,0x38,0x3f,0};
uchar flag,t0,ge,shi,bai;
uint shu;
void init();             
void display(uchar aa,uchar bb,uchar cc);
void delay(uint z) 
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
void main()    
{
	init();
	while(1)
	{
		display(bai,shi,ge);
		if(s2==0)
		{
			delay(10);
			if(s2==0)
			{
				TR0=0;
				while(!s2)
					display(bai,shi,ge);
				TR0=1;
			}
		}		
	}
}

void init()        
{
	TMOD=0x01;
	TH0=(65536-10000)/256; 
	TL0=(65536-10000)%256;
	EA=1;
	ET0=1;
	TR0=1;
}

void timer0() interrupt 1 
{
	TH0=(65536-10000)/256;
	TL0=(65536-10000)%256;
	shu++;
	if(shu==1000)
		shu=0;
	bai=shu/100;
	shi=shu%100/10;
	ge=shu%10;
		
}


void display(uchar aa,uchar bb,uchar cc)
{
        dula=1;
		P0=table[aa];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xfe;
		wela=0;
		delay(1);

       	dula=1;
		P0=table[bb];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xfd;
		wela=0;
		delay(1);

       dula=1;
		P0=table[cc];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xfb;
		wela=0;
		delay(1);
}
