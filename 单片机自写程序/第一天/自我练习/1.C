#include<reg52.h>
sbit D0=P1^0;
void main()
{
	unsigned int i;
	for (i=0;i<99999999;i++)
	{
		if(i%1000==0)
			D0=0;
		else
			D0=1;
	}
	
}
