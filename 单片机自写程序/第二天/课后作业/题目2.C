#include<reg52.h>
#include <intrins.h>
sbit D0=P1^0;
sbit DEEP=P2^3;
typedef unsigned int uint;
typedef unsigned char uchar;
void relay()
{
	uint i;
	for(i=0;i<18500;i++)
		;	
}

void main()
{
	while(1)
	{
		uint k,j;
		uchar a=0xfe;
		for(k=64;k>0;k--)
		{ 	P1=a;
			DEEP=0;
			for(j=0;j<5;j++)
			relay();
			P1=0xff;
			DEEP=1;
			for(j=0;j<5;j++)
			relay();
			a=_crol_(a,1);
		}
		while(1);
	}
}


