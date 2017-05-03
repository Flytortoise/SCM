//完成在按键按下后从低到高一次点亮8个LED灯并且循环的功能
#include<reg52.h>
sbit s1 = P3^4;

void ys(void)
{
	unsigned int a;
	for(a=0;a<10000;a++)
		;
}

void main(void)
{
	unsigned char i;
	i=0;
	while(1)
	{
		if(s1==0)
		{
			ys();
			if(s1==1)
				i++;
			if(i==9)
				i=1;
		}
		switch(i)
		{
			case 1:P1=0xfe;
								break;
			case 2:P1=0xfd;
								break;
			case 3:P1=0xfb;
								break;
			case 4:P1=0xf7;
								break;
			case 5:P1=0xef;
								break;
			case 6:P1=0xdf;
								break;
			case 7:P1=0xbf;
								break;
			case 8:P1=0x7f;
								break;
			default:P1=0xff;
		}
	}
}
