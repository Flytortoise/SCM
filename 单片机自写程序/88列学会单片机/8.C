//完成单片机以各端口地址的形式实现对8个LED灯依次从低到高位点亮的功能
#include<reg52.h>
sfr x = 0x90;	//x代表特殊功能寄存器0x90，编译时直接转成特殊功能寄存器,0x90是P1口
void ys(void)
{
	unsigned char i,j;
	for(i=0;i<250;i++)
	for(j=0;j<250;j++)
			;
}

void main(void)
{
	while(1)
	{
		x = 0xfe;
			ys();
		x = 0xfd;
			ys();
		x = 0xfb;
			ys();
		x = 0xf7;
			ys();
		x = 0xef;
			ys();
		x = 0xdf;
			ys();
		x = 0xbf;
			ys();
		x = 0x7f;
			ys();
	}
}
