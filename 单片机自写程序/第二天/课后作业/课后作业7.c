#include<reg52.h>
#include <intrins.h>
sbit D0=P1^0;
typedef unsigned int uint;
typedef unsigned char uchar;
void relay()
{
	uint i;
	for(i=0;i<18500;i++)
		;	
}		//100ms ���ӳ�

void main()
{
	while(1)
	{
		uint k,j,i;
		for(i=0;i<3;i++)		//����������ż����
		{	
			P1=0X55;
			for(j=0;j<3;j++)
				relay();
			P1=0XAA;
			for(j=0;j<3;j++)
				relay();
		}
		P1=0XFF;			//��λ
		for(i=0;i<3;i++)		//����ѭ������
		{
			uchar a=0xfe;
			for(k=8;k>0;k--)
			{ 	P1=a;
				for(j=0;j<3;j++)
				relay();
				P1=0xff;
				for(j=0;j<3;j++)
				relay();
				a=_crol_(a,1);		//ѭ������
			}
			a=0x7f;
			for(k=8;k>0;k--)
			{ 	P1=a;
				for(j=0;j<3;j++)
				relay();
				P1=0xff;
				for(j=0;j<3;j++)
				relay();
				a=_cror_(a,1);		//ѭ������
			}
		}
		P1=0XFF;			//��λ
		for(i=0;i<3;i++)		//���������м�
		{
			P1=0x7e;
			for(j=0;j<3;j++)
				relay();
			P1=0xbd;
			for(j=0;j<3;j++)
				relay();
			P1=0xdb;
			for(j=0;j<3;j++)
				relay();
			P1=0xe7;
			for(j=0;j<3;j++)
				relay();
		}
		P1=0XFF;			//��λ
		for(i=0;i<3;i++)		//���м�������
		{
			P1=0xe7;
			for(j=0;j<3;j++)
				relay();
			P1=0xdb;
			for(j=0;j<3;j++)
				relay();
			P1=0xbd;
			for(j=0;j<3;j++)
				relay();
			P1=0x7e;
			for(j=0;j<3;j++)
				relay();
		}
		P1=0XFF;			//��λ
		for(i=0;i<3;i++)		//ȫ��˸
		{
			P1=0x00;
			for(j=0;j<3;j++)
				relay();
			P1=0xff;
			for(j=0;j<3;j++)
				relay();
		}
		while(1);
	}
}

