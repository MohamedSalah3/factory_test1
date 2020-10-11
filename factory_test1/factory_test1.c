/*
 * factory_test1.c
 *
 * Created: 24/09/2020 07:24:04 ص
 *  Author: mo
 */ 

#include "motor.h"
#include "pushButton.h"
#include "SOS.h"
void system_init(void){	
SOS_Init (&TMU_Configuration);
SOS_Create_Task(Task1,1,0,1);
DIO_init(&ALL_Motor);
PORTB_DIR=0;
Motor_Init(MOTOR_1|MOTOR_2);
Motor_Direction(MOTOR_1|MOTOR_2,MOTOR_FORWARD);
}

int main(void)
{
  system_init();
    while(1)
    {
	 SOS_Run();
	
	Motor_Start(MOTOR_1|MOTOR_2 , 10);/*ON*/
			Motor_Start(MOTOR_1|MOTOR_2 , 50);/*half speed*/
				Motor_Start(MOTOR_1|MOTOR_2 , 100);/*full speed*/
					Motor_Start(MOTOR_1|MOTOR_2 , 0);/*off*/
	    //TODO:: Please write your application code 
    }
}