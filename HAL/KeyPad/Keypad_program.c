
/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 26/9/2023         ********/ 
/************** SWC       :KeyPad             ********/
/************** Version   : 1.0               ********/ 
/*****************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
/*MCAL*/
#include "../../MCAL/DIO/DIO_Interface.h"

#include "KeyPad_Interface.h"
#include "KeyPad_Private.h"
#include "KeyPad_Config.h" 

 const u8 KeyPad_Au8Keys[4][4]= KeyPad_keys;
 const u8 KeyPad_Au8Rows[4]=    {KEYPAD_u8_PinR0,
	                       KEYPAD_u8_PinR1,
	                       KEYPAD_u8_PinR2,
	                       KEYPAD_u8_PinR3};
						   
 const u8 KeyPad_Au8Columns[4]= {KEYPAD_u8_PinC0,
	                       KEYPAD_u8_PinC1,
	                       KEYPAD_u8_PinC2,
	                       KEYPAD_u8_PinC3};     
						   
u8 Keypad_u8GetKeyState(u8 *Copy_pu8ReturnedKey){
	*Copy_pu8ReturnedKey = KEYPAD_u8_KEY_NOT_PRESSED;
	u8 ret = R_OK;
	u8 Local_u8RowsCounter = 0;
	u8 Local_u8ColumnsCounter = 0,flag= 0 ;
	if(Copy_pu8ReturnedKey==NULL){
		ret = R_NOT_OK;
	}
	else {
		
		/*Activation each row */ 
		for(Local_u8RowsCounter=0;Local_u8RowsCounter<=3;Local_u8RowsCounter++){
			DIO_u8SetPinValue(KEYPAD_u8_PORT_ROWS,KeyPad_Au8Rows[Local_u8RowsCounter],DIO_PIN_LOW);
			/*check which input pin is zero  */
			for(Local_u8ColumnsCounter=0;Local_u8ColumnsCounter<=3;Local_u8ColumnsCounter++){
				u8 Local_u8PinValue ;
				DIO_u8GetPinValue(KEYPAD_u8_PORT_COLUMNS,KeyPad_Au8Columns[Local_u8ColumnsCounter],&Local_u8PinValue);
				if(Local_u8PinValue== DIO_PIN_LOW){
					_delay_ms(20);  //for debouncing 
					DIO_u8GetPinValue(KEYPAD_u8_PORT_COLUMNS,KeyPad_Au8Columns[Local_u8ColumnsCounter],&Local_u8PinValue);
					while(Local_u8PinValue == DIO_PIN_LOW){
						DIO_u8GetPinValue(KEYPAD_u8_PORT_COLUMNS,KeyPad_Au8Columns[Local_u8ColumnsCounter],&Local_u8PinValue);
					}
					flag=1;
					*Copy_pu8ReturnedKey = KeyPad_Au8Keys[Local_u8RowsCounter][Local_u8ColumnsCounter];
					break;
					
				}
			}
			DIO_u8SetPinValue(KEYPAD_u8_PORT_ROWS,KeyPad_Au8Rows[Local_u8RowsCounter],DIO_PIN_HIGH);
			if(flag== 1 ){
				break;
			}
		}
		
		ret = R_OK;
	}
	
	
	return ret ; 
}
