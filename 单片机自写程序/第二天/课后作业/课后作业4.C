#include<reg52.h>
#include <intrins.h>

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
		uint k,a=0xff;
		for(;a>=0;a--)
		{
			for(k=10;k>0;k--)
			relay();
			P1=a;
		}
		
		while(1);
	}
}

