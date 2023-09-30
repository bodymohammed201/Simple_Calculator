
/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 26/9/2023         ********/ 
/************** SWC       : LCD               ********/
/************** Version   : 1.0               ********/ 
/*****************************************************/
 
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H
/*Port of Rs */
/*choose DIO_PORTA_ID
         DIO_PORTB_ID
         DIO_PORTC_ID
         DIO_PORTD_ID */

#define  LCD_u8_PORTRs         DIO_PORTA_ID

/*Port of RW */


#define  LCD_u8_PORTRW         DIO_PORTA_ID

/*Port of Enable */


#define  LCD_u8_PORTEnable     DIO_PORTA_ID

/* For 8 Bit initialization */
/*Port of Data */

#define  LCD_u8_PORTData       DIO_PORTC_ID


/* For 4 Bit initialization */
/*Port of D4*/
#define  LCD_u8_PORTD4         DIO_PORTC_ID
/*Port of D5*/
#define  LCD_u8_PORTD5         DIO_PORTC_ID
/*Port of D6*/
#define  LCD_u8_PORTD6         DIO_PORTC_ID
/*Port of D7*/
#define  LCD_u8_PORTD7         DIO_PORTC_ID

/*PIN of RS */
/*choose DIO_PIN0_ID
         DIO_PIN1_ID
         DIO_PIN2_ID
         DIO_PIN3_ID
         DIO_PIN4_ID
         DIO_PIN5_ID
         DIO_PIN6_ID
         DIO_PIN7_ID
          */

#define  LCD_u8_PinRs           DIO_PIN0_ID
/*PIN of RW */


#define  LCD_u8_PinRW           DIO_PIN1_ID

/*PIN of Enable */

#define  LCD_u8_PinEnable       DIO_PIN2_ID


/* For 4 Bit initialization */
/*Port of D4*/
#define  LCD_u8_PIND4         DIO_PIN4_ID
/*Port of D5*/
#define  LCD_u8_PIND5         DIO_PIN5_ID
/*Port of D6*/
#define  LCD_u8_PIND6         DIO_PIN6_ID
/*Port of D7*/
#define  LCD_u8_PIND7         DIO_PIN7_ID

/*LCD MODE */

/*Options : 1- LCD_8BIT
 *          2- LCD_4BIT */
#define LCD_MODE  LCD_4BIT
#endif
