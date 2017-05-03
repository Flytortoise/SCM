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
                                                           
// 第一个发光管以间隔200ms闪烁
// 适用 TX-1C单片机实验板
// 晶振为11.0592M

/*********************************************************/
#include<reg52.h>  //52单片机头文件
#define uint unsigned int    //宏定义
#define uchar unsigned char  //宏定义
sbit led1=P1^0;    //单片机管脚位声明

void delay(uint z)  //延时函数,z的取值为这个函数的延时ms数，如delay(200);大约延时200ms.
{					//delay(500);大约延时500ms.
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);	
}
void main()		    //主函数
{
	while(1)        //大循环
	{
		led1=0;     //点亮小灯
		delay(200); //延时200毫秒
		led1=1;		//熄灭小灯
		delay(200); //延时200毫秒
	}
}
