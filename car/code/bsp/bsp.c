#include "bsp.h"

void bsp_init()	//外设初始化
{
	INIT1_Init();
	Init_Int0();
}