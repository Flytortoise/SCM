#include "bsp.h"


void Delay1ms(unsigned int i) 
{ 
	unsigned char j,k; 
	do
	{ 
		j = 10; 
		do
		{ 
			k = 50; 
			do
			{ 
				_nop_(); 
			}while(--k);     
		}while(--j); 
	}while(--i); 

} 

void delay_nus(unsigned int i)  
{ 
	i = i/10;
	while(--i);
}   

void delay_nms(unsigned int n)  
{ 
	n=n+1;
	while(--n)  
	delay_nus(900);        
  
}  

void delayms(unsigned char x)                         
{
	unsigned char i;                                    
	while(x--)                                          
	{
		for (i = 0; i<13; i++);                       
	}
}

void Delay()                                         
{ 
	unsigned int DelayTime=30000;                       
	while(DelayTime--);                                                                         
}