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
                                                           
// 用位操作点亮最后一个发光管.
// 适用 TX-1C单片机实验板
// 晶振为11.0592M

/*********************************************************/
#include<reg52.h>  //52单片机头文件
sbit led8=P1^7;    //单片机管脚位声明
void main()		   //主函数
{
	led8=0;			//将单片机P1.7口清零
	while(1);       //程序停止在这里，在后面会讲到为什么这样写。
}
