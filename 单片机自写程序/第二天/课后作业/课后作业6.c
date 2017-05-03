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
}		//100ms µÄÑÓ³Ù

void main()
{
	while(1)
	{
		uint k,j,i,b,c,d,e;
		uchar a;
		
		for(e=0;e<3;e++)
		{
			b=0xfe;
			c=1;
			d=8;
			for(i=0;i<8;i++)
			{
				a=b;
				for(k=d;k>0;k--)
				{ 	P1=a;
				
					for(j=0;j<3;j++)
					relay();
					P1=0xff;
	
					for(j=0;j<3;j++)
					relay();
					a=_crol_(a,1);		//Ñ­»·×óÒÆ
				}
				b=b-2*c;
				d--;
				c=2*c;
			}
		}	
		while(1);
	}
}

