/*
 * Tasks.c
 *
 * Created: 12/10/2020 10:27:00 ص
 *  Author: mo
 */ 
#include "Tasks.h"

static uint8_t flag;
static uint8_t u8_motor_state;
static uint8_t u8_counter;
void Task1(void)
{/*
	if(pushButtonGetStatus(BTN_0))
	{
		u8_counter++;
		if (u8_counter <= 50)
		{
			u8_motor_state=UNHOLD;
			
		}else if(pushButtonGetStatus(BTN_0)== Released && u8_counter > 50 && u8_counter <= 100)
		{
			flag=0;

		}
		if (pushButtonGetStatus(BTN_0)==Pressed)
		{
			if(flag == 0)
			{
				u8_motor_state=FIFTY_PRECENT_PWM;
				flag = 1;
			}
			
		}else if (u8_counter > 100 && u8_counter < 255)
		{
			u8_motor_state=PRESSED_AND_HOLD;
			
		}else{u8_counter=0;
	u8_motor_state=0;}
	

}*/
/*two times routine*/
}

static uint32_t u32l_Time[9];
void Task2(void)
{static uint8_t u8_Co;
		static uint8_t u8_STATE;
		if (u8_Co < 9)
		{
				Icu_ReadTime(ICU_TIMER_CH0,ICU_RISE_TO_RISE,&u32l_Time[u8_Co]);
						Icu_ReadTime(ICU_TIMER_CH0,ICU_RISE_TO_FALL,&u32l_Time[u8_Co+1]);
								Icu_ReadTime(ICU_TIMER_CH0,ICU_FALE_TO_RISE,&u32l_Time[u8_Co+2]);
								u8_Co += 3;
				
		}else{u8_Co=0;}
		

	if(u32l_Time[0] >= 10 && u32l_Time[0] <=200 && u32l_Time[1] >= 10 && u32l_Time[1] <=200){
	u8_STATE=FIFTY_PRECENT_PWM;
		PORTC_DATA = 255;
	}
	if(u8_STATE==FIFTY_PRECENT_PWM)
	{
		Motor_Start(MOTOR_1,50);
	}
		
	
}