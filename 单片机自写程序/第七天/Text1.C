#include<reg52.h>
#include <intrins.h>
#define uint unsigned int    //�궨��
#define uchar unsigned char  //�궨��
sbit dula=P2^6;		//����U1�������������
sbit wela=P2^7;		//����U2�������������
sbit adwr=P3^6;		//����AD��WR�˿�
sbit adrd=P3^7;		//����AD��RD�˿�
uchar adval;
void delay(uint z)     //��ʱ�Ӻ���
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
void main()
{
	wela=1;
	P0=0x7f;           //��CSADΪ0��ѡͨADCS �Ժ󲻱��ٹ�ADCS
	wela=0;
	TMOD=0x20;//���ö�ʱ��1Ϊ������ʽ2
	TH1=0xe8; //����������Ϊ1200
	TL1=0xe8;
	TR1=1;
	SM0=0;
	SM1=1;
	REN=1;
	while(1)
	{
		adwr=1;
		_nop_();
		adwr=0;			//����ADת��
		_nop_();
		adwr=1;
		delay(500);
		P1=0xff;                    //��ȡP1��֮ǰ�ȸ���дȫ1 
		adrd=1;                    //ѡͨADCS
		_nop_();	
		adrd=0;                     //AD��ʹ��
		_nop_();
		adval=P1;			//AD���ݶ�ȡ����P1��
		delay(500);
		SBUF=adval;
		while(!TI);
		TI=0;
		
	}
}