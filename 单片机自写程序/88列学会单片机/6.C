//完成8个LED灯左右循环一次变化的功能
#include<reg52.h>
unsigned char i;
unsigned char temp;
unsigned char a,b;

void ys(void)
{
	unsigned char m,n,s;
	for(m=20;m>0;m--)
	for(n=20;n>0;n--)
	for(s=248;s>0;s--)
		;
}

void main(void)
{
	while(1)
	{
		temp=0xfe;
		P1=temp;
		ys();
		for(i=1;i<8;i++)
		{
			a = temp << i;	
			b = temp >> (8-i);	//产生循环左移效果
			P1 = a|b;
			ys();
		}
		for(i=1;i<8;i++)
		{
			a = temp >> i;
			b = temp << (8-i);	//产生循环右移效果
			P1 = a|b;
			ys();
		}
	}
}
