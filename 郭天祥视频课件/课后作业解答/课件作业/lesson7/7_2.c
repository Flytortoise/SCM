#include<reg52.h>
unsigned char flag,a,num,num1;
sbit beep=P2^3;
void main()
{

	TMOD=0x20;//设置定时器1为工作方式2
	TH1=0xf4;
	TL1=0xf4;
	TR1=1;
	SM0=0;
	SM1=1;
	REN=1;
	EA=1;
	ES=1;
	while(1)
	{
		if(flag==1)
		{
			ES=0;
			flag=0;
			num1++;
			if(num1==255)
				num1=0;
			SBUF=num1;
			while(!TI);
			TI=0;
			SBUF=a;
			while(!TI);
			TI=0;
			ES=1;
		}
	}
}

void ser() interrupt 4
{
	RI=0;
	a=SBUF;
	flag=1;
}

