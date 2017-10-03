#include "bsp.h"

void IR_IN() interrupt 2 using 0                      
{
	unsigned char j,k,N=0;                              

	EX1 = 0;                                              
	delayms(15);                                        
	if (IRIN==1)                                       
	{  
		EX1 =1;                                         
		return;                                         
	} 
						   
	while (!IRIN)                                       
	{
	  delayms(1);                                     
	}

	for (j=0;j<4;j++)                                  
	{ 
		for (k=0;k<8;k++)                                 
		{
		   while (IRIN)                                   
		   {
				delayms(1);                                  
		   }
		   
		   while (!IRIN)                                  
		   {
				delayms(1);                                  
		   }

		   while (IRIN)                                   
		   {
				delayms(1);                                  
				N++;                                         
				if (N>=30)                                   
				{ 
					EX1=1;                                     
					return;                                     
				}                   
		   }
										   
		  IRCOM[j]=IRCOM[j] >> 1;                         
		 
		  if (N>=8)                                        
		  {
				IRCOM[j] = IRCOM[j] | 0x80;                  
		  } 
		  
		  N=0;                                            
		}
	}

	if (IRCOM[2]!=~IRCOM[3])                            //?????????
	{ 
		EX1=1;                                           //??????
		return;                                          //??
	}

	for(j=0;j<10;j++)                                   //????????
	{
	  if(IRCOM[2]==RecvData[j])                       //??????
	  {
	   // ControlCar(j);
			ControlCar_yaokong(j);                               //?????????
	  }
	} 
	
	EX1 = 1;                                           //????? 
} 