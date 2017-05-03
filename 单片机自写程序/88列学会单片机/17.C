//完成8个LED灯依次变化
#include<reg52.h>
void ys(unsigned char x)
{
	unsigned char m,n;
	for(m=0;m<x;m++)
	for(n=0;n<200;n++)
		;
}

void main(void)
{
	unsigned char i;
	unsigned char code Tab[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
	while(1)
	{
		for(i=0;i<8;i++)
		{
			P1 = Tab[i];
			ys(100);
		}
		for(i=0;i<8;i++)
		{
			P1 = Tab[i];
			ys(250);
		}
	}
}

