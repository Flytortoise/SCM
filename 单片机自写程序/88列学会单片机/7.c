//ģ������Ƽӷ��ӵ�Ƭ���������LED��
#include<reg52.h>
void ys(void)
{
	unsigned int a;
	for(a=0;a<20000;a++)
			;
}

void main(void)
{
	unsigned char i;
	for(i=0;i<255;i++)
	{
		P1=i;
		ys();
	}
}
