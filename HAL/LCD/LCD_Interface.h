
/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 26/9/2023         ********/ 
/************** SWC       : LCD              ********/
/************** Version   : 1.0               ********/ 
/*****************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#define LCD_LINE1   0
#define LCD_LINE2   1

void LCD_voidInit(void);
void LCD_voidSendCmnd (u8 Copy_u8Cmnd);
void LCD_voidSendChar (u8 Copy_u8Char);
void LCD_voidSendString (u8* Copy_Pu8String);
void LCD_voidSendNumber (u32 Copy_u32Number);
void LCD_voidGoToXY (u8 Copy_u8LineNumber,u8 Copy_u8Location);
void LCD_voidGoToCGRAM (u8 Copy_u8CharNumber);
void LCD_voidSendSpecialChar (u8 Copy_Au8DronChar[8] );
void LCD_Clear(void);
#endif 
