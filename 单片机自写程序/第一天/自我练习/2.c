#include<reg52.h>
sbit D0=P1^0;
sbit D1=P1^1;
sbit D2=P1^2;
sbit D3=P1^3;
sbit D4=P1^4;
sbit D5=P1^5;
sbit D6=P1^6;
sbit D7=P1^7;
void main()
{
	unsigned int i,j,k;		//i控制灯亮，j控制循环，k控制循环次数
	k=4;
	for(j=0;j<k;j++)
	{
		for (i=500;i<1600;i++)
		{
			if(i%800==0)
				D0=0;
			else
				D0=1;
			if(i%900==0)
				D1=0;
			else
				D1=1;
			if(i%1000==0)
				D2=0;
			else
				D2=1;
			if(i%1100==0)
				D3=0;
			else
				D3=1;
			if(i%1200==0)
				D4=0;
			else
				D4=1;
			if(i%1300==0)
				D5=0;
			else
				D5=1;
			if(i%1400==0)
				D6=0;
			else
				D6=1;
			if(i%1500==0)
				D7=0;
			else
				D7=1;
			
		}
	}
	if (j==k)
	{
		for(i=0;i<8;i++)
		{
			P1=0XFF;
		}
	}
}	
