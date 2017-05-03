//完成8个LED灯从低位到高位依次变化的功能
#include<reg52.h>
void ys(void)
{
	unsigned char m,n;
	for(m=0;m<100;m++)
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
			ys();	
		}
	}
}
