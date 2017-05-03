//实现单个LED灯的闪烁
#include<reg52.h>
void Ys(void)
{
	unsigned int a;
	for(a=0;a<10000;a++);
}

void main(void)
{
	while(1)
	{
		P1=0XFE;
		Ys();
		P1=0XFF;
		Ys();
	}

}
