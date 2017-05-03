#include<reg52.h>
sbit D0=P1^0;
typedef unsigned int uint;
void relay()
{
	uint i;
	for(i=0;i<32000;i++)
		;	
}

void main()
{
	uint a;
	while (1)
	{
		for(a=0;a<10;a++)
		{
		D0=0;
		relay();
		D0=1;
		relay();
		}
		while(1);
	}
}
