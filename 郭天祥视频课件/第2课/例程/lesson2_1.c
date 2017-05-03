#include<reg52.h>
sbit p1_1=P1^0
unsigned int a
void main()
{
	while(1)
	{	
		a=51000;
		p1_1=0;
		while(a--);
		a=51000;
		while(a--);

		p1_1=1;
		a=51000;
		while(a--);
		a=51000;
		while(a--);
	}
}
