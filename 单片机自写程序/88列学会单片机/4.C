//完成8个LED灯从左到右依次变化
#include<reg52.h>
void ys(void)
{
	unsigned int a;
	for(a=0;a<30000;a++)
		;
}

void main(void)
{
	unsigned char i;
	while(1)
	{
		P1=0xff;
		ys();
		for(i=0;i<8;i++)
		{
			P1=P1>>1;
			ys();
		}
	}
}
