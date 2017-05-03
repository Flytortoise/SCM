/*******************************************************************/
/* TX-1C��Ƭ��ʵ���ʵ������        							   */
/* 2007��8�µڶ�����ѵ��κ�ϰ�����							   */
/* ���ߣ�������      											   */
/* ���䣺txmcu@163.com 										  	   */
/* ��վ��www.txmcu.com(�������)    							   */
/*����Ȩ��Copyright(C)������� www.txmcu.com  All Rights Reserved  */
/*���������˳��������ѧϰ��ο���������ע����Ȩ��������Ϣ��       */
/*                                                                 */
/*******************************************************************/
/*                                                          
���ö�̬ɨ��Ͷ�ʱ��1�����������ʾ
����765432��ʼ��1/10����ٶ����µݼ�
ֱ��765398��������ʾ���������ͬʱ��
�ö�ʱ��0��500MS�ٶȽ�����ˮ�ƴ�����
���ƶ������������������ֹͣʱ��ʵ��
������ˮ��ҲֹͣȻ��ȫ����ʼ��˸��3��
����T0��ʱ����ˮ��ȫ���رա��������
��ʾ��"HELLO"�����˱���ס��
�辧��Ƶ��Ϊ12MHz��
*/
/*********************************************************/
#include<reg52.h>  //52��Ƭ��ͷ�ļ�
#include <intrins.h> //����������ѭ����λ�Ӻ����Ŀ�
#define uint unsigned int    //�궨��
#define uchar unsigned char  //�궨��
sbit dula=P2^6;
sbit wela=P2^7;
uchar code table[]={   //��ʾ���ݱ���
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71,
0x76,0x79,0x38,0x3f,0};
uchar temp,t0,t1,bai,shi,ge,flag,flag1;
uint shu;
void init();              //��������
void display(uchar aa,uchar bb,uchar cc,uchar bai,uchar shi,uchar ge);
void delay(uint z)     //��ʱ�Ӻ���
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
void main()          //������
{
	init();
	while(1)
	{
		if(flag1!=1)   //���flagi���ٵ���1����ʾ����
			display(7,6,5,bai,shi,ge);
		else
			display(16,17,18,18,19,20);	  //������ʾhello
	}
}

void init()          //��ʼ������
{
	shu=432;
	temp=0xfe;
	P1=temp;
	TMOD=0x11;
	TH0=(65536-50000)/256;  //��ʱ����ʼ��
	TL0=(65536-50000)%256;
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	EA=1;
	ET0=1;
	ET1=1;
	TR0=1;
	TR1=1;
}

void timer0() interrupt 1   //��ʱ��0�ж�
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	t0++;
	if(flag!=1)          //flag������1ʱ������ˮ��
		{
		if(t0==10)
			{
				t0=1;
				temp=_crol_(temp,1);
				P1=temp;
			}
		}
	else              //������е���˸
		{
			if(t0%4==0)  //С��ÿ200����仯һ��
				P1=~P1;
			if(t0==60)
			{
				TR0=0;   //3���رն�ʱ��0���رյƣ�����flag=1
				P1=0xff;
				flag1=1;
			}
		}	
}

void timer1() interrupt 3  //��ʱ��1�жϺ���
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
			if(shu==398)    //����398ʱ��ԭ��T0�е�����������¼Ӳó�ֵ��С����˸
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

void display(uchar aa,uchar bb,uchar cc,uchar bai,uchar shi,uchar ge) //��ʾ�Ӻ���
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
