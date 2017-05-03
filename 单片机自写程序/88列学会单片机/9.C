//完成在按键按下后，相应的LED灯点亮，松开熄灭
#include<reg52.h>
sbit S1 = P3^4;
sbit S2 = P3^5;
void main(void)
{
	while(1)
	{
		if(S1==0)
			P1=0x0f;
		if(S2==0)
			P1=0xf0;
	}
}

//这条程序不对，需要按键检测和松手检测
