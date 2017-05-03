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
		uint k,j,i,b;
		uchar a=0xfe;
		for(b=0;b<5;b++)
		{
			for(i=0;i<2;i++)
			{
				
				for(k=8;k>1;k--)
				{ 	P1=a;
				
					for(j=0;j<2;j++)
					relay();
					P1=0xff;
					
					for(j=0;j<2;j++)
					relay();
					a=_crol_(a,1);		//Ñ­»·×óÒÆ
				}
				//a=0x7f;
				for(k=8;k>1;k--)
				{ 	P1=a;
			
					for(j=0;j<2;j++)
					relay();
					P1=0xff;
				
					for(j=0;j<2;j++)
					relay();
					a=_cror_(a,1);		//Ñ­»·ÓÒÒÆ
				}
			}
			P1=a;
			for(j=0;j<2;j++)
				relay();
			P1=0xff;
				
			for(i=0;i<5;i++)
			{
				for(j=0;j<3;j++)
					relay();
				P1=0X00;
				for(j=0;j<3;j++)
					relay();
				P1=0XFF;
			}
		}
		while(1);
	}
}

