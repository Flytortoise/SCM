#include <reg52.h>
#include "Deep.h"

void Deep_Init();
{
		DEEP = 1;	
}

void Deep_Work()
{
		DEEP = 0;		//��
		Delay_1s();
		DEEP = ~DEEP;
}