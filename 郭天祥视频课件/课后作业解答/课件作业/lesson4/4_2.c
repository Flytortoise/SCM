/*******************************************************************/
/* TX-1C单片机实验板实验例程        							   */
/* 2007年8月第二期培训班课后习题详解							   */
/* 作者：郭天祥      											   */
/* 邮箱：txmcu@163.com 										  	   */
/* 网站：www.txmcu.com(天祥电子)    							   */
/*【版权】Copyright(C)天祥电子 www.txmcu.com  All Rights Reserved  */
/*【声明】此程序仅用于学习与参考，引用请注明版权和作者信息！       */
/*                                                                 */
/*******************************************************************/
/*                                                          
用动态扫描方法和定时器1在数码管的前三位显示出秒表，
精确到1%秒，即最后一位显示1%秒，一直循环下去
设时钟频率为12M
*/
/*********************************************************/
#include<reg52.h>  //52单片机头文件
#include <intrins.h> //包含有左右循环移位子函数的库
#define uint unsigned int    //宏定义
#define uchar unsigned char  //宏定义
sbit dula=P2^6;       //数码管段选锁存端
sbit wela=P2^7;       ////数码管位选锁存端
uchar ge,shi,bai;
uint tt;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
void display(uchar,uchar,uchar); //函数声明
void delay(uint);
void main()
{
	TMOD=0x10;//设置定时器1为工作方式1
	TH1=(65536-10000)/256;
	TL1=(65536-10000)%256;
	EA=1;//开总中断
	ET1=1;//开定时器1中断
	TR1=1;//启动定时器1
	while(1)
	{
		display(bai,shi,ge);
	}
}


void exter0() interrupt 3   // 定时器1中断
{
	TH1=(65536-10000)/256;
	TL1=(65536-10000)%256;
	tt++;
	if(tt==1000)
	tt=0;
	bai=tt/100;
	shi=tt%100/10;
	ge=tt%10;
}

void display(uchar one,uchar two,uchar three)
{
        dula=1;
		P0=table[one];   //送段数据
		dula=0;
		P0=0xff;		//送位数据前关闭所有显示，防止打开位选锁存后段选数据通过位选锁存器
		wela=1;
		P0=0xfe;
		wela=0;
		delay(1);

		dula=1;
		P0=table[two];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xfd;
		wela=0;
		delay(1);

		dula=1;
		P0=table[three];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xfb;
		wela=0;
		delay(1);
}

void delay(uint z)       //延时子函数
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
