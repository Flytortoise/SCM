//完成独立式按键利用软件消抖点亮第一个LED
#include<reg52.h>
sbit S1 = P3^7;
sbit LED = P1^0;
void ys()
{
	unsigned char i,j;
	for(i=0;i<100;i++)
	for(j=0;j<100;j++)
		;
}

void mian()
{
	LED = 0;
	while(1)
	{
		if(S1 == 0)
		{
			ys();
			if(S1 == 0)
			LED = !LED;
		}
	}
}
