/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 26/9/2023         ********/ 
/************** SWC       :LED                ********/
/************** Version   : 1.0               ********/ 
/*****************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
/*MCAL*/
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Led_Interface.h"
#include "Led_Private.h"
#include "Led_Config.h"

void Led_voidTurnOn(u8 Copy_u8PortID,u8 Copy_u8PINID){
	DIO_u8SetPinValue(Copy_u8PortID,Copy_u8PINID,DIO_PIN_HIGH);
	
}
void Led_voidTurnOff(u8 Copy_u8PortID,u8 Copy_u8PINID){
	DIO_u8SetPinValue(Copy_u8PortID,Copy_u8PINID,DIO_PIN_LOW);
	
}
