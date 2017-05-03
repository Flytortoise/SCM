//完成8个LED灯从右往左依次变化的功能
#include<reg52.h>
void ys(void)
{
	unsigned char m,n;
	for(m=0;m<100;m++)
	for(n=0;n<200;n++)
			;
}

void main(void)
{
	do 
	{
		P1=0xfe;
		ys();
		P1=0xfd;
		ys();
		P1=0xfb;
				ys();
		P1=0xf7;
				ys();
		P1=0xef;
				ys();
		P1=0xdf;
				ys();
		P1=0xbf;
				ys();
		P1=0x7f;
				ys();
	}
	while(1);
}
