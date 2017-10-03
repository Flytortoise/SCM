#ifndef BSP_H_
#define BSP_H_

//系统头文件
#include <reg52.h>
#include <math.h>
#include <string.h>
#include <intrins.h>

#include "bsp_work.h"
#include "bsp_delay.h"
#include "bsp_ir.h"
#include "bsp_int.h"

#define ShowPort P2  

//自定义函数
void bsp_init();	//外设初始化

sbit LeftLed=P2^0;                        //左前方灯
sbit RightLed=P0^7;                       //右前方灯
sbit FontLled=P1^7;

sbit LeftIR=P3^5;                         //左前方红外
sbit RightIR=P3^6;                        //右前方红外
sbit FontIR=P3^7;                         //正前方红外

sbit M1A=P0^0;                            //左侧电机驱动A
sbit M1B=P0^1;                            //左侧电机驱动B

sbit M2A=P0^2;                            //右侧电机驱动A
sbit M2B=P0^3;                            //右侧电机驱动B

sbit SB1=P0^6;                            //蜂鸣器
sbit IRIN=P3^3;                           //红外接收头

extern unsigned char code  LedShowData[];
extern unsigned char code  RecvData[];
extern unsigned char IRCOM[7];
extern unsigned int LedFlash;                         
extern bit EnableLight;         


#endif