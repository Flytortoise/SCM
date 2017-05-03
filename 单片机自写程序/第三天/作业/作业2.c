//题目的本意是一秒钟流动10次，太快了。

#include<reg52.h>
typedef unsigned int uint;
typedef unsigned char uchar;
uint code a[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
uint k,i;
void main()
{
	k=0;
	i=0;
	EA=1;
	ET1=1;
	TR1=1;
	TMOD=0X10;
	P1=a[0];
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;

	while(1)
	{	
		if(i%2==0)
			P1=0xff;
		else
			P1=a[k];
		
	}
}

void time1() interrupt	3
{
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	i++;
		
		if(i==20)
			{
				k++;
				i=0;
			}
		if(k==8)
			k=0;
	
}
