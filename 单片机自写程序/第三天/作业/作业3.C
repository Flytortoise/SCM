//按照题目需要，K应该=6，要对很多处经行修改，且难以听出差异，所以改为了1.8S

#include<reg52.h>
typedef unsigned int uint;
typedef unsigned char uchar;
sbit DEEP=P2^3;
uint k,i,j,t;
void main()
{
	k=0;
	i=0;
	j=0;
	EA=1;
	ET1=1;
	ET0=1;
	TR1=1;
	TR0=1;
	TMOD=0X11;

	TH1=(65536-30000)/256;
	TL1=(65536-30000)%256;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	while(1){};
}

void time1() interrupt	3
{
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	k++;
	if(k==360)		//K=6
	{	
		k=0;
		i=50000;
	}
}
void time0() interrupt	1
{	
	TH0=(65536-i)/256;
	TL0=(65536-i)%256;
	t++;
	if(k<40)
	{
		if(t=10)
		{
			t=0;
			i=50000;
			DEEP=~DEEP;
			
		}
	}
	if(k>40&&k<80)
	{
		t=0;
		i=50000;
		DEEP=~DEEP;
		
	}
	if(k>80&&k<120)
	{
		i=10000;
		DEEP=~DEEP;
	
	}
	if(k>120&&k<160)
	{
		i=5000;
		DEEP=~DEEP;
		
	}
	if(k>160&&k<200)
	{
		i=2500;
		DEEP=~DEEP;
	
	}
	if(k>200&&k<240)
	{
		i=1250;
		DEEP=~DEEP;
		
	}
	if(k>240&&k<280)
	{
		i=625;
		DEEP=~DEEP;
	
	}
	if(k>280&&k<320)
	{
		i=500;
		DEEP=~DEEP;
		
	}
}
