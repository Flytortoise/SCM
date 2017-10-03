#include "bsp.h"

void INIT1_Init()
{
	IT1 = 1;
	EA = 1;
	//EX1 = 1;
}

void Init_Int0(void)
{
   IT0=1;
   EX0=1;
   EA=1;

}