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
�ö�̬ɨ�跽���Ͷ�ʱ��1������ܵ�ǰ��λ��ʾ�����
��ȷ��1%�룬�����һλ��ʾ1%�룬һֱѭ����ȥ
��ʱ��Ƶ��Ϊ12M
*/
/*********************************************************/
#include<reg52.h>  //52��Ƭ��ͷ�ļ�
#include <intrins.h> //����������ѭ����λ�Ӻ����Ŀ�
#define uint unsigned int    //�궨��
#define uchar unsigned char  //�궨��
sbit dula=P2^6;       //����ܶ�ѡ�����
sbit wela=P2^7;       ////�����λѡ�����
uchar ge,shi,bai;
uint tt;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
void display(uchar,uchar,uchar); //��������
void delay(uint);
void main()
{
	TMOD=0x10;//���ö�ʱ��1Ϊ������ʽ1
	TH1=(65536-10000)/256;
	TL1=(65536-10000)%256;
	EA=1;//�����ж�
	ET1=1;//����ʱ��1�ж�
	TR1=1;//������ʱ��1
	while(1)
	{
		display(bai,shi,ge);
	}
}


void exter0() interrupt 3   // ��ʱ��1�ж�
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
		P0=table[one];   //�Ͷ�����
		dula=0;
		P0=0xff;		//��λ����ǰ�ر�������ʾ����ֹ��λѡ������ѡ����ͨ��λѡ������
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

void delay(uint z)       //��ʱ�Ӻ���
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
