

/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 24/9/2023         ********/ 
/************** SWC       : DIO               ********/ 
/************** Version   : 1.0               ********/ 
/*****************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
#include "../../LIB/STD_TYPES.h"
/*macros for ports */
#define DIO_PORTA_ID          0
#define DIO_PORTB_ID          1
#define DIO_PORTC_ID          2 
#define DIO_PORTD_ID          3  
/*macros for pins */          
#define DIO_PIN0_ID           0 
#define DIO_PIN1_ID           1 
#define DIO_PIN2_ID           2 
#define DIO_PIN3_ID           3 
#define DIO_PIN4_ID           4 
#define DIO_PIN5_ID           5 
#define DIO_PIN6_ID           6 
#define DIO_PIN7_ID           7
/* pin direction*/            
#define DIO_PIN_OUTPUT        1
#define DIO_PIN_INPUT         0
/*Pin valus */                
#define DIO_PIN_LOW           0
#define DIO_PIN_HIGH          1
/* Port direction*/  
#define DIO_PORT_OUTPUT       1  
#define DIO_PORT_INPUT        0
/*PORT valus */                
#define DIO_PORT_LOW       0x00
#define DIO_PORT_HIGH      0xFF

void DIO_VoidInit(void);
                    /*PIN CONFG*/ 
u8 DIO_u8SetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinDirection);
u8 DIO_u8SetPinValue    (u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinValue);
u8 DIO_u8GetPinValue    (u8 Copy_u8PortId,u8 Copy_u8PinId,u8 *Copy_Pu8ReturnedPinValue);

                    /*PORT CONGG*/
u8 DIO_u8SetPortDirection(u8 Copy_u8PortId,u8 Copy_u8PortDirection);
u8 DIO_u8SetPortValue    (u8 Copy_u8PortId,u8 Copy_u8PortValue);
u8 DIO_u8GetPortValue    (u8 Copy_u8PortId,u8 *Copy_Pu8ReturnedPortValue);


#endif
