/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 26/9/2023         ********/ 
/************** SWC       :KeyPad             ********/
/************** Version   : 1.0               ********/ 
/*****************************************************/

/*Port of Rows */
/*choose DIO_PORTA_ID
         DIO_PORTB_ID
         DIO_PORTC_ID
         DIO_PORTD_ID */

#define  KEYPAD_u8_PORT_ROWS            DIO_PORTD_ID

/*Port of coulmns */
#define  KEYPAD_u8_PORT_COLUMNS         DIO_PORTD_ID
/*PINs of ROWS */
/*choose DIO_PIN0_ID
         DIO_PIN1_ID
         DIO_PIN2_ID
         DIO_PIN3_ID
         DIO_PIN4_ID
         DIO_PIN5_ID
         DIO_PIN6_ID
         DIO_PIN7_ID
          */

#define  KEYPAD_u8_PinR0           DIO_PIN0_ID
#define  KEYPAD_u8_PinR1           DIO_PIN1_ID
#define  KEYPAD_u8_PinR2           DIO_PIN2_ID
#define  KEYPAD_u8_PinR3           DIO_PIN3_ID
/*PINs of ColumnS */
#define  KEYPAD_u8_PinC0           DIO_PIN4_ID
#define  KEYPAD_u8_PinC1           DIO_PIN5_ID
#define  KEYPAD_u8_PinC2           DIO_PIN6_ID
#define  KEYPAD_u8_PinC3           DIO_PIN7_ID
#define  KeyPad_keys              {{'7','8','9','/'  },\
                                   {'4','5','6','*'  }, \
						           {'1','2','3','-'  }, \
						           {'^','0','=','+'}}

