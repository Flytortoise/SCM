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
利用动态扫描和定时器1在数码管上显示
出从765432开始以1/10秒的速度往下递减
直至765398并保持显示此数，与此同时利
用定时器0以500MS速度进行流水灯从上至
下移动，当数码管上数减到停止时，实验
板上流水灯也停止然后全部开始闪烁，3秒
后（用T0定时）流水灯全部关闭、数码管上
显示出"HELLO"。到此保持住。
设晶振频率为12MHz。
*/
/*********************************************************/
#include<reg52.h>  //52单片机头文件
#include <intrins.h> //包含有左右循环移位子函数的库
#define uint unsigned int    //宏定义
#define uchar unsigned char  //宏定义
sbit dula=P2^6;
sbit wela=P2^7;
uchar code table[]={   //显示数据编码
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71,
0x76,0x79,0x38,0x3f,0};
uchar temp,t0,t1,bai,shi,ge,flag,flag1;
uint shu;
void init();              //函数声明
void display(uchar aa,uchar bb,uchar cc,uchar bai,uchar shi,uchar ge);
void delay(uint z)     //延时子函数
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
void main()          //主函数
{
	init();
	while(1)
	{
		if(flag1!=1)   //如果flagi不再等于1则显示数据
			display(7,6,5,bai,shi,ge);
		else
			display(16,17,18,18,19,20);	  //否则显示hello
	}
}

void init()          //初始化函数
{
	shu=432;
	temp=0xfe;
	P1=temp;
	TMOD=0x11;
	TH0=(65536-50000)/256;  //定时器初始化
	TL0=(65536-50000)%256;
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	EA=1;
	ET0=1;
	ET1=1;
	TR0=1;
	TR1=1;
}

void timer0() interrupt 1   //定时器0中断
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	t0++;
	if(flag!=1)          //flag不等于1时进行流水灯
		{
		if(t0==10)
			{
				t0=1;
				temp=_crol_(temp,1);
				P1=temp;
			}
		}
	else              //否则进行灯闪烁
		{
			if(t0%4==0)  //小灯每200毫秒变化一次
				P1=~P1;
			if(t0==60)
			{
				TR0=0;   //3秒后关闭定时器0，关闭灯，并置flag=1
				P1=0xff;
				flag1=1;
			}
		}	
}

void timer1() interrupt 3  //定时器1中断函数
{
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	t1++;
	if(t1==2)
		{
			t1=0;
			shu--;
			bai=shu/100;
			shi=shu%100/10;
			ge=shu%10;
			if(shu==398)    //当到398时把原来T0中的数清除，重新加裁初值让小灯闪烁
				{
					TR0=0;
					TH0=(65536-50000)/256;
					TL0=(65536-50000)%256;
					TR0=1;
					flag=1;
					t0=0;
					P1=0xff;
					TR1=0;
				}	
		}	
}

void display(uchar aa,uchar bb,uchar cc,uchar bai,uchar shi,uchar ge) //显示子函数
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
        dula=1;
		P0=table[bai];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xf7;
		wela=0;
		delay(1);

		dula=1;
		P0=table[shi];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xef;
		wela=0;
		delay(1);

		dula=1;
		P0=table[ge];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xdf;
		wela=0;
		delay(1);
}
