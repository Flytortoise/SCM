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
		uint k,j,i;
		for(i=0;i<8;i++)
		{
			uchar a=0xfe;
			for(k=8;k>0;k--)
			{ 	P1=a;
				DEEP=0;
				//for(j=0;j<5;j++)
				relay();
				P1=0xff;
				DEEP=1;
				//for(j=0;j<5;j++)
				relay();
				a=_crol_(a,1);		//Ñ­»·×óÒÆ
			}
			a=0x7f;
			for(k=8;k>0;k--)
			{ 	P1=a;
				DEEP=0;
				//for(j=0;j<5;j++)
				relay();
				P1=0xff;
				DEEP=1;
				//for(j=0;j<5;j++)
				relay();
				a=_cror_(a,1);		//Ñ­»·ÓÒÒÆ
			}
		}
		while(1);
	}
}

