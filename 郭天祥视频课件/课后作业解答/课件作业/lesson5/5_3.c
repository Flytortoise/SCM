#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit dula=P2^6;
sbit wela=P2^7;
sbit key1=P3^4;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
uchar temp;
uint num,num1;
void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
uint keyscan();
void display(uchar,uchar,uchar);
void main()
{
	dula=1;
	P0=0;
	dula=0;
	wela=1;
	P0=0xc0;
	wela=0;
	while(1)
	{
		num1=keyscan();
		display(num1/100,num1%100/10,num1%10);
	}
}
void display(uchar aa,uchar bb,uchar cc)
{
        dula=1;
		P0=table[aa];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xfe;
		wela=0;
		delay(1);

       	dula=1;
		P0=table[bb];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xfd;
		wela=0;
		delay(1);

       dula=1;
		P0=table[cc];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xfb;
		wela=0;
		delay(1);
}
uint keyscan()
{
	P3=0xfe;
	temp=P3;
	temp=temp&0xf0;
	while(temp!=0xf0)
	{
		delay(5);
		temp=P3;
		temp=temp&0xf0;
		while(temp!=0xf0)
		{
			temp=P3;
		switch(temp)
		{
			case 0xee:num=1;
				break;
			case 0xde:num=4;
				break;
			case 0xbe:num=9;
				break;
			case 0x7e:num=16;
				break;
		}
		while(temp!=0xf0)
		{
			temp=P3;
			temp=temp&0xf0;
		}
		}
	}

	P3=0xfd;
	temp=P3;
	temp=temp&0xf0;
	while(temp!=0xf0)
	{
		delay(5);
		temp=P3;
		temp=temp&0xf0;
		while(temp!=0xf0)
		{
			temp=P3;
		switch(temp)
		{
			case 0xed:num=25;
				break;
			case 0xdd:num=36;
				break;
			case 0xbd:num=49;
				break;
			case 0x7d:num=64;
				break;
		}
		while(temp!=0xf0)
		{
			temp=P3;
			temp=temp&0xf0;
		}
		}
	}


	P3=0xfb;
	temp=P3;
	temp=temp&0xf0;
	while(temp!=0xf0)
	{
		delay(5);
		temp=P3;
		temp=temp&0xf0;
		while(temp!=0xf0)
		{
			temp=P3;
		switch(temp)
		{
			case 0xeb:num=81;
				break;
			case 0xdb:num=100;
				break;
			case 0xbb:num=121;
				break;
			case 0x7b:num=144;
				break;
		}
		while(temp!=0xf0)
		{
			temp=P3;
			temp=temp&0xf0;
		}
		}
	}


	P3=0xf7;
	temp=P3;
	temp=temp&0xf0;
	while(temp!=0xf0)
	{
		delay(5);
		temp=P3;
		temp=temp&0xf0;
		while(temp!=0xf0)
		{
			temp=P3;
		switch(temp)
		{
			case 0xe7:num=169;
				break;
			case 0xd7:num=196;
				break;
			case 0xb7:num=225;
				break;
			case 0x77:num=256;
				break;
		}
		while(temp!=0xf0)
		{
			temp=P3;
			temp=temp&0xf0;
		}
		}
	}
return num;
}

