/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 26/9/2023         ********/ 
/************** SWC       :LED                ********/
/************** Version   : 1.0               ********/ 
/*****************************************************/
#ifndef  LED_CONFIG_H
#define  LED_CONFIG_H
/*Port of Led */
/*choose DIO_PORTA_ID
         DIO_PORTB_ID
         DIO_PORTC_ID
         DIO_PORTD_ID */

#define    LED_u8_PORT_LED1            DIO_PORTA_ID
#define    LED_u8_PORT_LED2            DIO_PORTA_ID
#define    LED_u8_PORT_LED3            DIO_PORTA_ID
#define    LED_u8_PORT_LED4            DIO_PORTA_ID
#define    LED_u8_PORT_LED5            DIO_PORTA_ID
#define    LED_u8_PORT_LED6            DIO_PORTA_ID
#define    LED_u8_PORT_LED7            DIO_PORTA_ID

/*PINs of Led */
/*choose DIO_PIN0_ID
         DIO_PIN1_ID
         DIO_PIN2_ID
         DIO_PIN3_ID
         DIO_PIN4_ID
         DIO_PIN5_ID
         DIO_PIN6_ID
         DIO_PIN7_ID
          */

#define  LED_u8_Pin_LED1                DIO_PIN3_ID
#define  LED_u8_Pin_LED2                DIO_PIN4_ID
#define  LED_u8_Pin_LED3                DIO_PIN5_ID
#define  LED_u8_Pin_LED4                DIO_PIN6_ID
#define  LED_u8_Pin_LED5                DIO_PIN7_ID






#endif 