#include<reg51.h>
sbit wela=P2^7;
sbit dula=P2^6;
sbit dawr=P3^6;
sbit csda=P3^2;
unsigned char a,j,k;
void delay(unsigned char i)
{
  for(j=i;j>0;j--)
    for(k=125;k>0;k--);
}

void main()
{
  wela=0;
  dula=0;
  csda=0;
  a=0;
  dawr=0;
  while(1)
  {
	  P0=a;
	  P1=~a;
   // dawr=1;
	  delay(50);
	  a++;
}

  //wela=0;
  //P0=0xff;
  //wela=1;
 // wela=0;

}
