//����ʽ���̿��ƣ�ʵ�ְ���S1�����һ��LED
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
