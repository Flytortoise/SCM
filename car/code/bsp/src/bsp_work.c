#include "bsp.h"

void Stop()
{
   M1A=0;                                  
   M1B=0;                                  
   M2A=0;                                  
   M2B=0;

}

void Run()
{
   M1A=1;                                   
   M1B=0;                                   
   M2A=1;                                   
   M2B=0;
}

void Down()
{
   M1A=0;                                   
   M1B=1;                                   
   M2A=0;                                   
   M2B=1;
}

void Left()
{
   M1A=0;                                   
   M1B=1;                                   
   M2A=1;                                   
   M2B=0;
}

void Right()
{
   M1A=1;                                   
   M1B=0;                                   
   M2A=0;                                   
   M2B=1;
}

void ControlCar(unsigned char ConType)    //电机控制
{
	Stop();
	switch(ConType)                       //判断模式
	{
		case 1:                           //前进
		{ 
			LeftLed = 0 ;
			Run();
			break;
		}
		
		case 2: 						     
		{ 
			LeftLed = 1 ; 	 
			Down();                               
			break;
		}
		
		case 3:                         
		{ 
			Left();                              
			break;
		}
		
		case 4:                          
		{ 
			Right();                                									  //M2????
			break;
		}
		
		case 8:                       
		{
			Stop();
			break;                              
		}
	}
}

void ControlCar_yaokong(unsigned char ConType)  //遥控
{
 
	Stop();
	switch(ConType)                         
	{
		case 1:                         
		{ 
			Stop();						      
			Delay1ms(150);
			LeftLed = 0 ;
			Run();
			break;
		}
		
		case 2:                      
		{ 
			Stop();							      
			Delay1ms(150);
			LeftLed = 1 ; 	 
			Down();                               
			break;
		}
		
		case 3:                          
		{ 
			Stop();								 
			Delay1ms(150); 
			Left();                               
			break;
		}
		
		case 4:                     
		{ 
			Stop();								 
			Delay1ms(150);
			Right();                                
			break;
		}
		
		case 8:                   
		{
			Stop();
			break;                                
		}
	}
}

void Robot_Avoidance()       //壁障           
{

	LeftLed = LeftIR;                        
	RightLed =RightIR;                     
	FontLled = FontIR; 

	if(FontIR == 0)                        
	{
		ControlCar(8);                       
		delay_nms (300);					   
		ControlCar(2);					  
		delay_nms (1000);					  
		ControlCar(3);					  
		delay_nms (1800);	
	}
	else
	{
		ControlCar(1);                     
		delay_nms (10);
	}
	
	ControlCar(1);
}

void Robot_Traction()    //循迹                
{
	LeftLed = LeftIR;                       
	RightLed = RightIR;                      
	FontLled = FontIR; 
	//SB1=LeftIR;
	if(LeftIR == 0 && RightIR == 0)    
	{
		ControlCar(1);                     
		delay_nms (10);
	}

	else if(LeftIR == 0 && RightIR == 1)		 
	{
		ControlCar(3);                      
		delay_nms (10);
	}

	else if(LeftIR == 1 && RightIR == 0)		
	{
		ControlCar(4);                      
		delay_nms (10);
	}
	
	ControlCar(8);
}

