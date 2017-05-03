#include<reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit dula=P2^6;
sbit wela=P2^7;

uchar code num[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f};//字符

uchar code hello[]={
0x76,0x79,0x38,0x38,0x3f};//HELLO

void delay(uint z)	//延时程序
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}

void display2()
{
	
	wela=1;
	P0=0xfe;
	wela=0;
	P0=0xff;
	dula=1;
	P0=hello[0];
	dula=0;
	delay(1);

	wela=1;
	P0=0xfd;
	wela=0;
	P0=0xff;
	dula=1;
	P0=hello[1];
	dula=0;
	delay(1);

	wela=1;
	P0=0xfb;
	wela=0;
	P0=0xff;
	dula=1;
	P0=hello[2];
	dula=0;
	delay(1);

	wela=1;
	P0=0xf7;
	wela=0;
	P0=0xff;
	dula=1;
	P0=hello[3];
	dula=0;
	delay(1);

	wela=1;
	P0=0xef;
	wela=0;
	P0=0xff;
	dula=1;
	P0=hello[4];
	dula=0;
	delay(1);
}

void display1(uint x,uint y,uint z)//显示程序
{
	wela=1;
	P0=0xfe;
	wela=0;
	P0=0xff;
	dula=1;
	P0=num[7];
	dula=0;
	delay(1);

	wela=1;
	P0=0xfd;
	wela=0;
	P0=0xff;
	dula=1;
	P0=num[6];
	dula=0;
	delay(1);
	
	wela=1;
	P0=0xfb;
	wela=0;
	P0=0xff;
	dula=1;
	P0=num[5];
	dula=0;
	delay(1);

	wela=1;
	P0=0xf7;
	wela=0;
	P0=0xff;
	dula=1;
	P0=num[z];
	dula=0;
	delay(1);

	wela=1;
	P0=0xef;
	wela=0;
	P0=0xff;
	dula=1;
	P0=num[y];
	dula=0;
	delay(1);

	wela=1;
	P0=0xdf;
	wela=0;
	P0=0xff;
	dula=1;
	P0=num[x];
	dula=0;
	delay(1);


}

uint i,j,x,y,z,aa,flag,flag1;
uint k=432;
uint t=0xfe;
void main()
{
	EA=1;
	ET0=1;
	ET1=1;
	TMOD=0X11;
	TR0=1;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	TR1=1;
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	while(1)
	{
		if(flag1!=1)
			display1(x,y,z);
				
		else
				display2();
			
			
	}

}

void time1() interrupt 3
{
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	aa++;
	if(aa==2)
	{
	aa=0;
	x=k%10;
	y=k%100/10;
	z=k/100;
	
	if(k==398)
		{
			TR0=0;
			TH0=(65536-50000)/256;
			TL0=(65536-50000)%256;
			TR0=1;
			flag=1;
			j=0;
			P1=0xff;
			TR1=0;
		}k--;

	}
	
	
}


void time0() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	j++;
	if(flag==0)
	{
		if(j==10)
		{	
		j=0;
		P1=t;
		t=_crol_(t,1);
		}
	}
	else
	{
		if(j%4==0)
				P1=~P1;
		if(j==60)
		{
			TR0=0;
			P1=0xff;
			flag1=1;
		}
	}

}	




