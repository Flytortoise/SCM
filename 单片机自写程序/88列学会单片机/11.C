//完成8个LED灯的按二进制加法依次变化的功能
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
	while(1)
	{
		i = 0;
		while (1)
		{
			P1 = i;
			ys();
			i++;
		}
	}
}
