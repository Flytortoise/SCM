#ifndef BSP_WORK_H
#define BSP_WORK_H

void Stop();
void Run();
void Down();
void Left();
void Right();

void ControlCar(unsigned char ConType);
void ControlCar_yaokong(unsigned char ConType);  //Ò£¿Ø
void Robot_Avoidance();
void Robot_Traction();


#endif