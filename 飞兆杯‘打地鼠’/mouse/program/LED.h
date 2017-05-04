#ifndef LED_H_
#define LED_H_

void LED_Init();
void LED_Light();
void LED_Flow();
void LED_Now();
void LED_Close();


sbit LED1 = P1^0;
sbit LED2 = P1^1;
sbit LED3 = P1^2;
sbit LED4 = P1^3;
sbit LED5 = P1^4;
sbit LED6 = P1^5;
sbit LED7 = P1^6;
sbit LED8 = P1^7;
//sbit LED9 =  ;

#endif