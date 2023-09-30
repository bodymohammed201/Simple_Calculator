
/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 26/9/2023         ********/
/************** SWC       :SevenSeg             ********/
/************** Version   : 1.0               ********/
/*****************************************************/
#ifndef HAL_SEVENSEG_SEVENSEG_INTERFACE_H_
#define HAL_SEVENSEG_SEVENSEG_INTERFACE_H_
#if SevenSeg_MODE==SevenSeg_8BIT_WITHOUT_DECODER
#define SEVENSEG_NUM_ZERO          0b00111111
#define SEVENSEG_NUM_ONE           0b00000110
#define SEVENSEG_NUM_TWO           0b01011011
#define SEVENSEG_NUM_THREE         0b01001111
#define SEVENSEG_NUM_FOUR          0b01100110
#define SEVENSEG_NUM_FIVE          0b01101101
#define SEVENSEG_NUM_SIX           0b01111101
#define SEVENSEG_NUM_SEVEN         0b00000111
#define SEVENSEG_NUM_EIGHT         0b01111111
#define SEVENSEG_NUM_NINE          0b01101111

#elif SevenSeg_MODE==SevenSeg_4BIT_WITH_DECODER


#endif
u8 SevenSeg_u8SendNumber(u8  Copy_Pu8Number);

#endif /* HAL_SEVENSEG_SEVENSEG_INTERFACE_H_ */
