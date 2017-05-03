#include<reg52.h>
#include <intrins.h>
#define uint unsigned int    //宏定义
#define uchar unsigned char  //宏定义
sbit dula=P2^6;		//申明U1锁存器的锁存端
sbit wela=P2^7;		//申明U2锁存器的锁存端
sbit adwr=P3^6;		//定义AD的WR端口
sbit adrd=P3^7;		//定义AD的RD端口
uchar adval;
void delay(uint z)     //延时子函数
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
void main()
{
	wela=1;
	P0=0x7f;           //置CSAD为0，选通ADCS 以后不必再管ADCS
	wela=0;
	TMOD=0x20;//设置定时器1为工作方式2
	TH1=0xe8; //波特率设置为1200
	TL1=0xe8;
	TR1=1;
	SM0=0;
	SM1=1;
	REN=1;
	while(1)
	{
		adwr=1;
		_nop_();
		adwr=0;			//启动AD转换
		_nop_();
		adwr=1;
		delay(500);
		P1=0xff;                    //读取P1口之前先给其写全1 
		adrd=1;                    //选通ADCS
		_nop_();	
		adrd=0;                     //AD读使能
		_nop_();
		adval=P1;			//AD数据读取赋给P1口
		delay(500);
		SBUF=adval;
		while(!TI);
		TI=0;
		
	}
}