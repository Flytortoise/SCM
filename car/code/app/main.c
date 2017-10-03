#include "bsp.h"
unsigned char code  LedShowData[]={0x03,0x9F,0x25,0x0D,0x99,  
                                   0x49,0x41,0x1F,0x01,0x19};//0,1,2,3,4,5,6,7,8,9
unsigned char code  RecvData[]={0x19,0x46,0x15,0x43,0x44,0x40,0x0D,0x0E,0x00,0x0F};
unsigned char IRCOM[7];
                     
bit EnableLight = 0;                                    
                               
unsigned char temp = 1;
sbit key1 = P3^2;

void main()
{
	int RunFlag=0;     
	bsp_init();
	                                                             	                                            
	ControlCar(8);                         
	while(1)                                
	{
		if(key1 == 0)
		{
			delay_nms(10);
			if(key1 == 0)
			{
				temp++;
				while(!key1);
			}
		}
		
		if(temp > 3)
		{
			temp = 1;
		}
		
		switch(temp)
		{
			case 1:	
				ShowPort = LedShowData[1];			
				EX1 = 1;
			break;
			
			case 2: 
				ShowPort = LedShowData[2];
				Robot_Avoidance();
				EX1 = 0;
			break;
			
			case 3: 
				ShowPort = LedShowData[3];
				Robot_Traction();
				EX1 = 0;

			break;
		}
	}
}