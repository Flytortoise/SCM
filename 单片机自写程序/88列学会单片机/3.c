//采用不同的数据类型进行演示操作，从中理解不同的数据类型的定义
#include<reg52.h>
void int_ys(void)
{
	unsigned int m;
	for(m=0;m<30000;m++)
			; 
}

void char_ys(void)
{
	unsigned char i,j;
	for(i=0;i<200;i++)
		for(j=0;j<180;j++)
			;
}

void main(void)
{
	unsigned char i;
	while(1)
	{
		for(i=0;i<3;i++)
		{
			P1=0xfe;
			int_ys();
			P1=0xff;
			int_ys();
		}
		for(i=0;i<3;i++)
		{
			P1=0xfe;
			char_ys();
			P1=0xff;
			char_ys();
		}
	}
}
