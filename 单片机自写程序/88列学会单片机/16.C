//完成8个LED灯依次变化的功能
#include<reg52.h>
unsigned char code Tab[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
void ys(void)
{
	unsigned char m,n;
	for(m=0;m<200;m++)
	for(n=0;n<250;n++)
		;
}

void led(void)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		P1 = Tab[i];
		ys();
	}
}

void main(void)
{
	void (*p)(void);	//函数指针
	p = led;
	while(1)
	{
	(*p)();
	}
}
