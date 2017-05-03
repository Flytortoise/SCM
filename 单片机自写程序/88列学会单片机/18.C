//完成LED灯依次变化
#include<reg52.h>
void ys(void)
{
	unsigned char m,n;
	for(m=0;m<200;m++)
	for(n=0;n<250;n++)
			;
}

void led (unsigned char a[8])
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		P1 = a[i];
		ys();
	}
}

void main(void)
{
	unsigned char Tab[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
	led(Tab);
}
