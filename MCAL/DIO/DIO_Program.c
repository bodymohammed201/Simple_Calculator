
/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 24/9/2023         ********/ 
/************** SWC       : DIO               ********/ 
/************** Version   : 1.0               ********/ 
/*****************************************************/
/*lib layer*/


/*MCAL Layer*/
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*PIN CONFG*/ 
u8 DIO_u8SetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinDirection){
	u8 Local_u8ErrorState = R_OK;
	if(Copy_u8PortId > DIO_MAX_PORT_SIZE ||Copy_u8PinId > DIO_MAX_PIN_SIZE){
		Local_u8ErrorState = R_NOT_OK;
	}
	else{
		switch (Copy_u8PortId){
			case DIO_PORTA_ID :   
			if(Copy_u8PinDirection==DIO_PIN_OUTPUT){ 
				SET_BIT(DIO_DDRA,Copy_u8PinId);
				
			}
			else if(Copy_u8PinDirection==DIO_PIN_INPUT){
				CLR_BIT(DIO_DDRA,Copy_u8PinId);
			}
			break;
			
			case DIO_PORTB_ID :
			if(Copy_u8PinDirection==DIO_PIN_OUTPUT){ 
				SET_BIT(DIO_DDRA,Copy_u8PinId);
				
			}
			else if(Copy_u8PinDirection==DIO_PIN_INPUT){
				CLR_BIT(DIO_DDRA,Copy_u8PinId);
			}
			break;
			case DIO_PORTC_ID :
				if(Copy_u8PinDirection==DIO_PIN_OUTPUT){ 
								SET_BIT(DIO_DDRA,Copy_u8PinId);
								
							}
							else if(Copy_u8PinDirection==DIO_PIN_INPUT){
								CLR_BIT(DIO_DDRA,Copy_u8PinId);
							}
			break;
			case DIO_PORTD_ID :
				if(Copy_u8PinDirection==DIO_PIN_OUTPUT){ 
								SET_BIT(DIO_DDRA,Copy_u8PinId);
								
							}
							else if(Copy_u8PinDirection==DIO_PIN_INPUT){
								CLR_BIT(DIO_DDRA,Copy_u8PinId);
							}
			break;
			default : Local_u8ErrorState = R_NOT_OK;

		}
			Local_u8ErrorState = R_OK;
	}
return 	Local_u8ErrorState;
}
u8 DIO_u8SetPinValue    (u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinValue){
		u8 Local_u8ErrorState = R_OK;
	if(Copy_u8PortId > DIO_MAX_PORT_SIZE ||Copy_u8PinId > DIO_MAX_PIN_SIZE){
		Local_u8ErrorState = R_NOT_OK;
	}
	else{
		switch (Copy_u8PortId){
			case DIO_PORTA_ID : 
			if(Copy_u8PinValue==DIO_PIN_LOW){
				CLR_BIT(DIO_PORTA,Copy_u8PinId);
			}
			else if(Copy_u8PinValue==DIO_PIN_HIGH){
				SET_BIT(DIO_PORTA,Copy_u8PinId);
			}
			break;
			
			case DIO_PORTB_ID :
			if(Copy_u8PinValue==DIO_PIN_LOW){
				CLR_BIT(DIO_PORTB,Copy_u8PinId);
			}
			else if(Copy_u8PinValue==DIO_PIN_HIGH){
				SET_BIT(DIO_PORTB,Copy_u8PinId);
			}
			break;
			case DIO_PORTC_ID :
			if(Copy_u8PinValue==DIO_PIN_LOW){
				CLR_BIT(DIO_PORTC,Copy_u8PinId);
			}
			else if(Copy_u8PinValue==DIO_PIN_HIGH){
				SET_BIT(DIO_PORTC,Copy_u8PinId);
			}
			break;
			case DIO_PORTD_ID :
			if(Copy_u8PinValue==DIO_PIN_LOW){
				CLR_BIT(DIO_PORTD,Copy_u8PinId);
			}
			else if(Copy_u8PinValue==DIO_PIN_HIGH){
				SET_BIT(DIO_PORTD,Copy_u8PinId);
			}
			break;
			default : Local_u8ErrorState = R_NOT_OK;

		}
			Local_u8ErrorState = R_OK;
	}
return 	Local_u8ErrorState;
}
u8 DIO_u8GetPinValue    (u8 Copy_u8PortId,u8 Copy_u8PinId,u8 *Copy_Pu8ReturnedPinValue){
		u8 Local_u8ErrorState = R_OK;
		u8 Local_u8PinValue;
	if(Copy_u8PortId > DIO_MAX_PORT_SIZE ||Copy_u8PinId > DIO_MAX_PIN_SIZE || Copy_Pu8ReturnedPinValue ==NULL ){
		Local_u8ErrorState = R_NOT_OK;

	}
	else{
		switch (Copy_u8PortId){
			case DIO_PORTA_ID : 
			Local_u8PinValue=GET_BIT(DIO_PINA,Copy_u8PinId);
			if(Local_u8PinValue==0){
			*Copy_Pu8ReturnedPinValue = DIO_PIN_LOW;
			}
			else{
			*Copy_Pu8ReturnedPinValue = DIO_PIN_HIGH;
			}
			break;
			
			case DIO_PORTB_ID :
			Local_u8PinValue=GET_BIT(DIO_PINB,Copy_u8PinId);
			if(Local_u8PinValue==0){
			*Copy_Pu8ReturnedPinValue = DIO_PIN_LOW;
			}
			else{
			*Copy_Pu8ReturnedPinValue = DIO_PIN_HIGH;
			}
			break;
			case DIO_PORTC_ID :
			Local_u8PinValue=GET_BIT(DIO_PINC,Copy_u8PinId);
			if(Local_u8PinValue==0){
			*Copy_Pu8ReturnedPinValue = DIO_PIN_LOW;
			}
			else{
			*Copy_Pu8ReturnedPinValue = DIO_PIN_HIGH;
			}
			break;
			case DIO_PORTD_ID :
			Local_u8PinValue=GET_BIT(DIO_PIND,Copy_u8PinId);
			if(Local_u8PinValue==0){
			*Copy_Pu8ReturnedPinValue = DIO_PIN_LOW;
			}
			else{
			*Copy_Pu8ReturnedPinValue = DIO_PIN_HIGH;
			}
			break;
			default : Local_u8ErrorState = R_NOT_OK;

		}
			Local_u8ErrorState = R_OK;
	}
return 	Local_u8ErrorState;
}

                       /*PORT CONGG*/
u8 DIO_u8SetPortDirection(u8 Copy_u8PortId,u8 Copy_u8PortDirection){
		u8 Local_u8ErrorState = R_OK;
	if(Copy_u8PortId > DIO_MAX_PORT_SIZE ){
		Local_u8ErrorState = R_NOT_OK;
	}
	else{
		switch (Copy_u8PortId){
			case DIO_PORTA_ID :   
			if(Copy_u8PortDirection==DIO_PORT_OUTPUT){ 
			   DIO_DDRA = DIO_PORT_HIGH ;
			}
			else if(Copy_u8PortDirection==DIO_PORT_INPUT){
			   DIO_DDRA = DIO_PORT_LOW ;
			}
			break;
			
			case DIO_PORTB_ID :
				if(Copy_u8PortDirection==DIO_PORT_OUTPUT){ 
							   DIO_DDRA = DIO_PORT_HIGH ;
							}
							else if(Copy_u8PortDirection==DIO_PORT_INPUT){
							   DIO_DDRA = DIO_PORT_LOW ;
							}
			break;
			
			case DIO_PORTC_ID :
				if(Copy_u8PortDirection==DIO_PORT_OUTPUT){ 
							   DIO_DDRA = DIO_PORT_HIGH ;
							}
							else if(Copy_u8PortDirection==DIO_PORT_INPUT){
							   DIO_DDRA = DIO_PORT_LOW ;
							}
			break;
			
			case DIO_PORTD_ID :
				if(Copy_u8PortDirection==DIO_PORT_OUTPUT){ 
							   DIO_DDRA = DIO_PORT_HIGH ;
							}
							else if(Copy_u8PortDirection==DIO_PORT_INPUT){
							   DIO_DDRA = DIO_PORT_LOW ;
							}
			break;
			
			default : Local_u8ErrorState = R_NOT_OK;

		}
			Local_u8ErrorState = R_OK;
	}
return 	Local_u8ErrorState;
}
u8 DIO_u8SetPortValue    (u8 Copy_u8PortId,u8 Copy_u8PortValue){
			u8 Local_u8ErrorState = R_OK;
	if(Copy_u8PortId > DIO_MAX_PORT_SIZE ){
		Local_u8ErrorState = R_NOT_OK;
	}
	else{
		switch (Copy_u8PortId){
			case DIO_PORTA_ID :   
			DIO_PORTA = Copy_u8PortValue ;
			break;
			
			case DIO_PORTB_ID :
			DIO_PORTB = Copy_u8PortValue ;
			break;
			
			case DIO_PORTC_ID :
			DIO_PORTC = Copy_u8PortValue ;
			break;
			
			case DIO_PORTD_ID :
			DIO_PORTD = Copy_u8PortValue ;
			break;
			
			default : Local_u8ErrorState = R_NOT_OK;

		}
			Local_u8ErrorState = R_OK;
	}
return 	Local_u8ErrorState;
	
}
u8 DIO_u8GetPortValue    (u8 Copy_u8PortId,u8 *Copy_Pu8ReturnedPortValue){
	u8 Local_u8ErrorState = R_OK;
	if(Copy_u8PortId > DIO_MAX_PORT_SIZE || Copy_Pu8ReturnedPortValue == NULL ){
		Local_u8ErrorState = R_NOT_OK;
	}
	else{
		switch (Copy_u8PortId){
			case DIO_PORTA_ID :   
			*Copy_Pu8ReturnedPortValue= DIO_PINA ;
			break;
			
			case DIO_PORTB_ID :
			*Copy_Pu8ReturnedPortValue= DIO_PINB ;
			break;
			
			case DIO_PORTC_ID :
		*Copy_Pu8ReturnedPortValue= DIO_PINC ;
			break;
			
			case DIO_PORTD_ID :
			*Copy_Pu8ReturnedPortValue= DIO_PIND ;
			break;
			
			default : Local_u8ErrorState = R_NOT_OK;

		}
			Local_u8ErrorState = R_OK;
	}
return 	Local_u8ErrorState;
} 
void DIO_VoidInit(void){
	DIO_DDRA = Conc(DIO_u8_PA7_INITIAL_DIRECTION,DIO_u8_PA6_INITIAL_DIRECTION
	                ,DIO_u8_PA5_INITIAL_DIRECTION,DIO_u8_PA4_INITIAL_DIRECTION
					,DIO_u8_PA3_INITIAL_DIRECTION,DIO_u8_PA2_INITIAL_DIRECTION
					,DIO_u8_PA1_INITIAL_DIRECTION,DIO_u8_PA0_INITIAL_DIRECTION);
					
	DIO_DDRB = Conc(DIO_u8_PB7_INITIAL_DIRECTION,DIO_u8_PB6_INITIAL_DIRECTION
	                ,DIO_u8_PB5_INITIAL_DIRECTION,DIO_u8_PB4_INITIAL_DIRECTION
					,DIO_u8_PB3_INITIAL_DIRECTION,DIO_u8_PB2_INITIAL_DIRECTION
					,DIO_u8_PB1_INITIAL_DIRECTION,DIO_u8_PB0_INITIAL_DIRECTION);
					
    DIO_DDRC = Conc(DIO_u8_PC7_INITIAL_DIRECTION,DIO_u8_PC6_INITIAL_DIRECTION
	                ,DIO_u8_PC5_INITIAL_DIRECTION,DIO_u8_PC4_INITIAL_DIRECTION
					,DIO_u8_PC3_INITIAL_DIRECTION,DIO_u8_PC2_INITIAL_DIRECTION
					,DIO_u8_PC1_INITIAL_DIRECTION,DIO_u8_PC0_INITIAL_DIRECTION);
					
	DIO_DDRD = Conc(DIO_u8_PD7_INITIAL_DIRECTION,DIO_u8_PD6_INITIAL_DIRECTION
	                ,DIO_u8_PD5_INITIAL_DIRECTION,DIO_u8_PD4_INITIAL_DIRECTION
					,DIO_u8_PD3_INITIAL_DIRECTION,DIO_u8_PD2_INITIAL_DIRECTION
					,DIO_u8_PD1_INITIAL_DIRECTION,DIO_u8_PD0_INITIAL_DIRECTION);
					

	DIO_PORTA = Conc(DIO_u8_PA7_INITIAL_VALUES,DIO_u8_PA6_INITIAL_VALUES
	                ,DIO_u8_PA5_INITIAL_VALUES,DIO_u8_PA4_INITIAL_VALUES
					,DIO_u8_PA3_INITIAL_VALUES,DIO_u8_PA2_INITIAL_VALUES
					,DIO_u8_PA1_INITIAL_VALUES,DIO_u8_PA0_INITIAL_VALUES);
					
	DIO_PORTB = Conc(DIO_u8_PB7_INITIAL_VALUES,DIO_u8_PB6_INITIAL_VALUES
	                ,DIO_u8_PB5_INITIAL_VALUES,DIO_u8_PB4_INITIAL_VALUES
					,DIO_u8_PB3_INITIAL_VALUES,DIO_u8_PB2_INITIAL_VALUES
					,DIO_u8_PB1_INITIAL_VALUES,DIO_u8_PB0_INITIAL_VALUES);
					
	DIO_PORTC = Conc(DIO_u8_PC7_INITIAL_VALUES,DIO_u8_PC6_INITIAL_VALUES
	                ,DIO_u8_PC5_INITIAL_VALUES,DIO_u8_PC4_INITIAL_VALUES
					,DIO_u8_PC3_INITIAL_VALUES,DIO_u8_PC2_INITIAL_VALUES
					,DIO_u8_PC1_INITIAL_VALUES,DIO_u8_PC0_INITIAL_VALUES);
					
	DIO_PORTD = Conc(DIO_u8_PD7_INITIAL_VALUES,DIO_u8_PD6_INITIAL_VALUES
	                ,DIO_u8_PD5_INITIAL_VALUES,DIO_u8_PD4_INITIAL_VALUES
					,DIO_u8_PD3_INITIAL_VALUES,DIO_u8_PD2_INITIAL_VALUES
					,DIO_u8_PD1_INITIAL_VALUES,DIO_u8_PD0_INITIAL_VALUES);				
}
