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
���ö�̬ɨ�跽������λ���������ʾ���ȶ���654321.
ʱ��Ƶ��Ϊ11.0592M
*/
/*********************************************************/
#include<reg52.h>  //52��Ƭ��ͷ�ļ�
#include <intrins.h> //����������ѭ����λ�Ӻ����Ŀ�
#define uint unsigned int    //�궨��
#define uchar unsigned char  //�궨��
sbit dula=P2^6;       //����ܶ�ѡ�����
sbit wela=P2^7;       ////�����λѡ�����
uchar code table[]={   //�������ʾ����
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
void display(uchar,uchar,uchar,uchar,uchar,uchar); //��������
void delay(uint);
void main()
{
	while(1)
	{
		display(6,5,4,3,2,1);         //ʼ����ʾ
	}
}

void display(uchar one,uchar two,uchar three,uchar four,uchar five,uchar six)
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

void delay(uint z)       //��ʱ�Ӻ���
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
