//完成8个LED灯依次变化的功能
#include<reg52.h>
void ys(void)
{
	unsigned char m,n;
	for(m=0;m<200;m++)
	for(n=0;n<250;n++)
			;
}

void main(void)
{
	unsigned char code Tab[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
	unsigned char *p[] = {&Tab[0],&Tab[1],&Tab[2],&Tab[3],&Tab[4],&Tab[5],&Tab[6],&Tab[7]};
	unsigned char i;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			P1 = *p[i];
			ys();
		}
	}
}
