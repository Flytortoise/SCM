//独立式键盘控制，实现按下S1后点亮一个LED
#include<reg52.h>
sbit S1 = P3^7;
sbit LED = P1^0;
void main()
{
	LED = 0;
	while(1)
	{
		if(S1==0)
		LED = !LED;
	}
}
