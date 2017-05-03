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
利用动态扫描方法在六位数码管上显示出稳定的654321.
时钟频率为11.0592M
*/
/*********************************************************/
#include<reg52.h>  //52单片机头文件
#include <intrins.h> //包含有左右循环移位子函数的库
#define uint unsigned int    //宏定义
#define uchar unsigned char  //宏定义
sbit dula=P2^6;       //数码管段选锁存端
sbit wela=P2^7;       ////数码管位选锁存端
uchar code table[]={   //数码管显示编码
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
void display(uchar,uchar,uchar,uchar,uchar,uchar); //函数声明
void delay(uint);
void main()
{
	while(1)
	{
		display(6,5,4,3,2,1);         //始终显示
	}
}

void display(uchar one,uchar two,uchar three,uchar four,uchar five,uchar six)
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

		dula=1;
		P0=table[four];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xf7;
		wela=0;
		delay(1);

		dula=1;
		P0=table[five];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xef;
		wela=0;
		delay(1);

		dula=1;
		P0=table[six];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xdf;
		wela=0;
		delay(1);
}

void delay(uint z)       //延时子函数
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
