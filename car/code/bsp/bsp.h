#ifndef BSP_H_
#define BSP_H_

//ϵͳͷ�ļ�
#include <reg52.h>
#include <math.h>
#include <string.h>
#include <intrins.h>

#include "bsp_work.h"
#include "bsp_delay.h"
#include "bsp_ir.h"
#include "bsp_int.h"

#define ShowPort P2  

//�Զ��庯��
void bsp_init();	//�����ʼ��

sbit LeftLed=P2^0;                        //��ǰ����
sbit RightLed=P0^7;                       //��ǰ����
sbit FontLled=P1^7;

sbit LeftIR=P3^5;                         //��ǰ������
sbit RightIR=P3^6;                        //��ǰ������
sbit FontIR=P3^7;                         //��ǰ������

sbit M1A=P0^0;                            //���������A
sbit M1B=P0^1;                            //���������B

sbit M2A=P0^2;                            //�Ҳ�������A
sbit M2B=P0^3;                            //�Ҳ�������B

sbit SB1=P0^6;                            //������
sbit IRIN=P3^3;                           //�������ͷ

extern unsigned char code  LedShowData[];
extern unsigned char code  RecvData[];
extern unsigned char IRCOM[7];
extern unsigned int LedFlash;                         
extern bit EnableLight;         


#endif