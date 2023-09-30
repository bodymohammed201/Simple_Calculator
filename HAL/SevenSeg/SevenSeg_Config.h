
/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 26/9/2023         ********/
/************** SWC       :SevenSeg             ********/
/************** Version   : 1.0               ********/
/*****************************************************/

#ifndef HAL_SEVENSEG_SEVENSEG_CONFIG_H_
#define HAL_SEVENSEG_SEVENSEG_CONFIG_H_
/*LCD MODE */

/*Options : 1- SevenSeg_8BIT_WITHOUT_DECODER
 *          2- SevenSeg_4BIT_WITH_DECODER */
#define  SevenSeg_MODE  SevenSeg_8BIT_WITHOUT_DECODER

/*Port of Pins if mode 8Bit without decoder  */
/*choose DIO_PORTA_ID
         DIO_PORTB_ID
         DIO_PORTC_ID
         DIO_PORTD_ID */

#define  SevenSeg_u8_PORT_8_BIT        DIO_PORTC_ID
/*Port of Pins if mode 4Bit with decoder  */
/*choose DIO_PORTA_ID
         DIO_PORTB_ID
         DIO_PORTC_ID
         DIO_PORTD_ID */

#define  SevenSeg_u8_PORT_4_BIT         DIO_PORTD_ID
/*PIN  */
/*choose DIO_PIN0_ID
         DIO_PIN1_ID
         DIO_PIN2_ID
         DIO_PIN3_ID
         DIO_PIN4_ID
         DIO_PIN5_ID
         DIO_PIN6_ID
         DIO_PIN7_ID
          */

#define  SevenSeg_u8_Pin0          DIO_PIN0_ID
#define  SevenSeg_u8_Pin1          DIO_PIN1_ID
#define  SevenSeg_u8_Pin2          DIO_PIN2_ID
#define  SevenSeg_u8_Pin3          DIO_PIN3_ID

#endif /* HAL_SEVENSEG_SEVENSEG_CONFIG_H_ */
