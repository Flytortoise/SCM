//串行控制流水灯循环点亮
#include<reg52.h>
#include<intrins.h>
unsigned char code Tab[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
sbit CLR = P2^7;	
void ys(void)
{
	unsigned char m,n;
	for(m=0;m<200;m++)
	for(n=0;n<250;n++)
		;
}

void Send(unsigned char dat)
{
	CLR = 0;
	_nop_();
	_nop_();
	CLR = 1;
	SBUF = dat;
	while(TI==0)
		;
	TI = 0;
}

void main()
{
	unsigned char i;
	SCON = 0x00;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			Send(Tab[i]);
			ys();
		}
	}
}

//本题将串口中断TXD(P3.1，串行输出口)，与74LX164相连，P2.7与MR非相连；无该电路板，无法验证
