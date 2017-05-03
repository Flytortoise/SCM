#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char

uchar a,i,flag=0,date;
uchar b1,b2,b3,b4,b5,b6;
uint dat=0,buf1,buf2;
sbit dula=P2^6;
sbit wela=P2^7;
uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,				//数码管编码
                        0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void delay(unsigned char i)		//延时程序
{	
	uchar j,k;
  for(j=i;j>0;j--)
    for(k=125;k>0;k--);
}
void UART_init()
{
	TMOD=0x20;
	TH1=0xfd;
	TL1=0xfd;
	TR1=1;
	SM0=0;
	SM1=1;
	REN=1;
	EA=1;
	ES=1;
	PCON=0x80;
}

void display(uint date)			//显示程序
{  
	b1=date/10000;
	b2=date%10000/1000;
	b3=date%1000/100;
	b4=date%100/10;
	b5=date%10;

   P0=table[b1];		//1
   dula=1;
   dula=0;

   P0=0xfe;
   wela=1;
   wela=0;
   delay(5);

   dula=0;
   P0=table[b2];		//2
   dula=1;
   dula=0;

   wela=0;
   P0=0xfd;
   wela=1;
   wela=0;
   delay(5);

   dula=0;
   P0=table[b3];		//3
   dula=1;
   dula=0;

   wela=0;
   P0=0xfb;
   wela=1;
   wela=0;
   delay(5);
        
   dula=0;
   P0=table[b4];		//4
   dula=1;
   dula=0;

   wela=0;
   P0=0xf7;
   wela=1;
   wela=0;
   delay(5);

   dula=0;
   P0=table[b5];		//5
   dula=1;
   dula=0;

   wela=0;
   P0=0xef;
   wela=1;
   wela=0;
   delay(5);




}


void main()		//	主程序
{
	UART_init();

	while(1)
	{

		for(i=0;i<20;i++)
		{
			display(dat);			
		}
 	}
}

void serial() interrupt 4
{
	if(RI)
	{	
		flag++;
		if(flag==1) {buf1=SBUF;}
		if(flag==2)
	 	{
			buf2=SBUF;
			dat=(buf1*256+buf2);
			flag=0;
		}
		RI=0;
	}

}


