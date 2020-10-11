/*
 * pushButton.c
 *
 * Created: 17/01/2020 05:27:05 pm
 *  Author: mo
 */
 #include "pushButton.h"
 #include "pushButtonConfig.h"
static uint8_t counter=0;
static uint8_t counter2=0;
static uint8_t flag = 1;
static uint8_t flag2=1;
static uint8_t changelowhigh=0;
static uint8_t changehighlow=0;
static uint8_t arr_u8_instant_state[100];
static uint8_t ret_state; 
 /*
#define BTN_0_GPIO	GPIOB
#define BTN_0_BIT	BIT0

#define BTN_1_GPIO	GPIOB
#define BTN_1_BIT	BIT1

#define BTN_2_GPIO	GPIOA
#define BTN_2_BIT	BIT2

#define BTN_3_GPIO 	GPIOA
#define BTN_3_BIT	BIT3
BTN_0,
	BTN_1,
	BTN_2,
	BTN_3
*/


En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_butotn_id)
{
static uint8_t u8_Button_press[3];
static uint8_t u8_S_button_status[3];
switch(en_butotn_id)
{
case BTN_0:
{DIO_Read(BTN_0_GPIO,BTN_0_BIT,&(u8_Button_press[0]));
if( u8_Button_press[0]== Pressed)
{ 
	(u8_S_button_status[0])++;
	/************************************************************************/
	/*         De bouncing Using Counting Algorithm			                */
	/************************************************************************/
	if( (u8_S_button_status[0]) > 10)
	return Pressed;
	else {return Released;}
}else{return Released;}
break;
}
case BTN_1:
{DIO_Read(BTN_1_GPIO,BTN_1_BIT,&(u8_Button_press[1]));
if( u8_Button_press[1] == Pressed)
{
	(u8_S_button_status[0])++;
	/******************************6******************************************/
	/*         Debouncing Using Counting Algorithm			                */
	/************************************************************************/
	if( (u8_S_button_status[0]) > 50)
return Pressed;
	else {return Released;}
}else{return Released;}
break;
}
case BTN_2:
{DIO_Read(BTN_2_GPIO,BTN_2_BIT,&(u8_Button_press[2]));
if((u8_Button_press[2])== Pressed)
{	(u8_S_button_status[1])++;
	/************************************************************************/
	/*         Debouncing Using Counting Algorithm			                */
	/************************************************************************/
	if( (u8_S_button_status[1]) > 20)
	return Pressed;
else {return Released;}
}else{return Released;}
break;
}



	}


}
/*States 
	state one clicked twice 10100000000
	state two clicked twice multiple times 1010101010
	state 3 clicked and hold 111111111111
	state 4 clicked and resealed 10000000000000000
	*/


uint8_t pushButtonGetState(En_buttonStatus_t status)
{
static uint8_t u8_state_of_Button;

static uint8_t com=0;
	
if (DIO_Read(BTN_0_GPIO,BTN_0_BIT,&arr_u8_instant_state[com]))//pushButtonGetStatus(BTN_0)== Released)
{
	
	if (flag == 0)
	{
	counter++;
	flag = 1;
	}
	counter2=0;
	flag2=0;
}
if (DIO_Read(BTN_0_GPIO,BTN_0_BIT,&arr_u8_instant_state[com])==0)//pushButtonGetStatus(BTN_0) == Pressed)
{	
	if (counter<20)
	{
		ret_state = 0 ;
	}else if(counter >20 && counter<50)
	{
		ret_state=1;
	}else if(counter >50){
		ret_state=3;
	}
		flag = 0;
		counter2++;
		counter=0;
}
if (com<=100)
{
	com++;
}else{
com=0;/*
for (com =0 ;com<100;com++)
{
	if (arr_u8_instant_state[com]==1)
	{
		counter++;
	}else{counter2++;}
	
}
for (com =0 ;com<100;com++)
{
	if (counter<20)
	{
		ret_state = 0 ;
	}else if(counter >20 && counter<50)
	{
		
	}else if(counter >50){
		
	}		
}
	
}

}



*/
}

//arr_u8_instant_state[com++]=counter;



return ret_state;
}/*

uint8_t pushButtonGetState(En_buttonStatus_t status)
{
	if (pushButtonGetStatus(BTN_0)==Pressed)
	{
		counter++;
	}
}*/