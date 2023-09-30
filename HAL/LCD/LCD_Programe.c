
/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 26/9/2023         ********/ 
/************** SWC       : LCD               ********/
/************** Version   : 1.0               ********/ 
/*****************************************************/
/*lib*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
/*MCAL*/
#include "../../MCAL/DIO/DIO_Interface.h"
/*HAL*/
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"

void LCD_voidInit(void){
#if LCD_MODE == LCD_8BIT
   _delay_ms(35);
/*function set cmnd */
LCD_voidSendCmnd(0b00111000);	
	_delay_us(50);
	/*display on / off control*/
	LCD_voidSendCmnd(0b00001111);	
	_delay_us(50);
	/*display clear*/
	LCD_voidSendCmnd(0b00000001);	
	_delay_ms(2);
    /*Entry mode set*/
	LCD_voidSendCmnd(0b00000110);
#elif LCD_MODE == LCD_4BIT
	  _delay_ms(35);
	/*function set cmnd */
	  /*  step1 Rs = 0 */
	  	DIO_u8SetPinValue(LCD_u8_PORTRs,LCD_u8_PinRs,DIO_PIN_LOW);
	  	/*        RW = 0 */
	  	DIO_u8SetPinValue(LCD_u8_PORTRW,LCD_u8_PinRW,DIO_PIN_LOW);
	  	DIO_u8SetPinValue(LCD_u8_PORTD4,LCD_u8_PIND4,0);
	  	DIO_u8SetPinValue(LCD_u8_PORTD5,LCD_u8_PIND5,1);
	  	DIO_u8SetPinValue(LCD_u8_PORTD6,LCD_u8_PIND6,0);
	  	DIO_u8SetPinValue(LCD_u8_PORTD7,LCD_u8_PIND7,0);
		DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_HIGH);
						/*  E= 0         */
	     	_delay_us(1);
		DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_LOW);

	   LCD_voidSendCmnd(0b00101000);
		_delay_us(50);
		/*display on / off control*/
		LCD_voidSendCmnd(0b00001111);
		_delay_us(50);
		/*display clear*/
		LCD_voidSendCmnd(0b00000001);
		_delay_ms(2);
	    /*Entry mode set*/
		LCD_voidSendCmnd(0b00000110);


#endif
}
void LCD_voidSendCmnd(u8 Copy_u8Cmnd){
#if LCD_MODE == LCD_8BIT
	/*  step1 Rs = 0 */
	DIO_u8SetPinValue(LCD_u8_PORTRs,LCD_u8_PinRs,DIO_PIN_LOW);
	/*        RW = 0 */
	DIO_u8SetPinValue(LCD_u8_PORTRW,LCD_u8_PinRW,DIO_PIN_LOW);
	/* write command */
	DIO_u8SetPortValue(LCD_u8_PORTData,Copy_u8Cmnd);
	/*  E= 1         */
	DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_HIGH);
	/*  E= 0         */
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_LOW);

#elif LCD_MODE == LCD_4BIT
	DIO_u8SetPinValue(LCD_u8_PORTRs,LCD_u8_PinRs,DIO_PIN_LOW);
	DIO_u8SetPinValue(LCD_u8_PORTRW,LCD_u8_PinRW,DIO_PIN_LOW);
	DIO_u8SetPinValue(LCD_u8_PORTD4,LCD_u8_PIND4,GET_BIT(Copy_u8Cmnd,4));
	DIO_u8SetPinValue(LCD_u8_PORTD5,LCD_u8_PIND5,GET_BIT(Copy_u8Cmnd,5));
	DIO_u8SetPinValue(LCD_u8_PORTD6,LCD_u8_PIND6,GET_BIT(Copy_u8Cmnd,6));
	DIO_u8SetPinValue(LCD_u8_PORTD7,LCD_u8_PIND7,GET_BIT(Copy_u8Cmnd,7));

	DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_HIGH);
		/*  E= 0         */
		_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_LOW);
	        DIO_u8SetPinValue(LCD_u8_PORTRs,LCD_u8_PinRs,DIO_PIN_LOW);
	        DIO_u8SetPinValue(LCD_u8_PORTRW,LCD_u8_PinRW,DIO_PIN_LOW);
		    DIO_u8SetPinValue(LCD_u8_PORTD4,LCD_u8_PIND4,GET_BIT(Copy_u8Cmnd,0));
			DIO_u8SetPinValue(LCD_u8_PORTD5,LCD_u8_PIND5,GET_BIT(Copy_u8Cmnd,1));
			DIO_u8SetPinValue(LCD_u8_PORTD6,LCD_u8_PIND6,GET_BIT(Copy_u8Cmnd,2));
			DIO_u8SetPinValue(LCD_u8_PORTD7,LCD_u8_PIND7,GET_BIT(Copy_u8Cmnd,3));

	DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_HIGH);
					/*  E= 0         */
     	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_LOW);
#endif
}
void LCD_voidSendChar(u8 Copy_u8Char){
#if LCD_MODE == LCD_8BIT
	/*  step1 Rs = 1 */
	DIO_u8SetPinValue(LCD_u8_PORTRs,LCD_u8_PinRs,DIO_PIN_HIGH);
	/*        RW = 0 */
	DIO_u8SetPinValue(LCD_u8_PORTRW,LCD_u8_PinRW,DIO_PIN_LOW);
	/* write command */
	DIO_u8SetPortValue(LCD_u8_PORTData,Copy_u8Char);
	/*  E= 1         */
	DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_HIGH);
	/*  E= 0         */
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_LOW);
#elif LCD_MODE == LCD_4BIT
	DIO_u8SetPinValue(LCD_u8_PORTRs,LCD_u8_PinRs,DIO_PIN_HIGH);
	DIO_u8SetPinValue(LCD_u8_PORTRW,LCD_u8_PinRW,DIO_PIN_LOW);
	DIO_u8SetPinValue(LCD_u8_PORTD4,LCD_u8_PIND4,GET_BIT(Copy_u8Char,4));
	DIO_u8SetPinValue(LCD_u8_PORTD5,LCD_u8_PIND5,GET_BIT(Copy_u8Char,5));
	DIO_u8SetPinValue(LCD_u8_PORTD6,LCD_u8_PIND6,GET_BIT(Copy_u8Char,6));
	DIO_u8SetPinValue(LCD_u8_PORTD7,LCD_u8_PIND7,GET_BIT(Copy_u8Char,7));
	
	DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_HIGH);
		/*  E= 0         */
		_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_LOW);
	        DIO_u8SetPinValue(LCD_u8_PORTRs,LCD_u8_PinRs,DIO_PIN_HIGH);
	        DIO_u8SetPinValue(LCD_u8_PORTRW,LCD_u8_PinRW,DIO_PIN_LOW);
		    DIO_u8SetPinValue(LCD_u8_PORTD4,LCD_u8_PIND4,GET_BIT(Copy_u8Char,0));
			DIO_u8SetPinValue(LCD_u8_PORTD5,LCD_u8_PIND5,GET_BIT(Copy_u8Char,1));
			DIO_u8SetPinValue(LCD_u8_PORTD6,LCD_u8_PIND6,GET_BIT(Copy_u8Char,2));
			DIO_u8SetPinValue(LCD_u8_PORTD7,LCD_u8_PIND7,GET_BIT(Copy_u8Char,3));

	DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_HIGH);
					/*  E= 0         */
     	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_PORTEnable,LCD_u8_PinEnable,DIO_PIN_LOW);


#endif
}
void LCD_voidSendString (u8* Copy_Pu8String){
	while(*Copy_Pu8String!='\0'){
		LCD_voidSendChar(*Copy_Pu8String);
		_delay_ms(20);
		(Copy_Pu8String)++;
	}
}
void LCD_voidSendNumber (u32 Copy_u32Number){
	u8 arr[10],i=0;
	while(Copy_u32Number){
	       u32 value = Copy_u32Number ;
	       value = Copy_u32Number %10;
	       arr[i]= value;
	       Copy_u32Number/=10;
	       i++;

	    }
	for(int j = i-1;j>=0;j--){
		LCD_voidSendChar(arr[j]+48);
		_delay_ms(100);
	}

}
void LCD_voidGoToXY (u8 Copy_u8LineNumber,u8 Copy_u8Location){

	switch(Copy_u8LineNumber){

	case LCD_LINE1 : LCD_voidSendCmnd(LCD_ADDRESS_LINE1+Copy_u8Location);
	break;
	case LCD_LINE2 : LCD_voidSendCmnd(LCD_ADDRESS_LINE2+Copy_u8Location);
	break;


	}
}
void LCD_voidGoToCGRAM (u8 Copy_u8CharNumber){
	switch(Copy_u8CharNumber){
	case 0 : LCD_voidSendCmnd(0b01000000);
	break;
	case 1 : LCD_voidSendCmnd(0b01000000+8);
	break;
	case 2 : LCD_voidSendCmnd(0b01000000+16);
	break;
	case 3 : LCD_voidSendCmnd(0b01000000+24);
	break;
	case 4 : LCD_voidSendCmnd(0b01000000+32);
	break;
	case 5 : LCD_voidSendCmnd(0b01000000+40);
	break;
	case 6 : LCD_voidSendCmnd(0b01000000+48);
	break;
	case 7 : LCD_voidSendCmnd(0b01000000+56);
	break;
	}

}
void LCD_voidSendSpecialChar (u8 Copy_Au8DronChar[8] ){
	for(int i = 0; i<8;i++){
		LCD_voidSendChar(Copy_Au8DronChar[i]);
	}
}
void LCD_Clear(void){
	LCD_voidSendCmnd(0b00000001);
}
