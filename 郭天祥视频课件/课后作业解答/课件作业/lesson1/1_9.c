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
                                                           
// 尝试让第一个发光管闪烁.(程序看不懂没关系，后面章节会有详细讲解)
// 适用 TX-1C单片机实验板
// 晶振为11.0592M

/*********************************************************/
#include<reg52.h>  //52单片机头文件
sbit led1=P1^0;    //单片机管脚位声明
void main()		   //主函数
{
	unsigned int i; //定义一个int型变量
	while(1)
	{
		i=50000;    //变量赋初值为50000
		led1=0;			//点亮灯
		while(i--);     //延时
		i=50000;
		led1=1;         //熄灭灯
		while(i--);   		
	}  

}
