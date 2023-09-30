
/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 26/9/2023         ********/
/************** SWC       :SevenSeg             ********/
/************** Version   : 1.0               ********/
/*****************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
/*MCAL*/
#include "../../MCAL/DIO/DIO_Interface.h"

#include "SevenSeg_Interface.h"
#include "SevenSeg_Private.h"
#include "SevenSeg_Config.h"
u8 SevenSeg_u8SendNumber(u8  Copy_Pu8Number){
	u8 ret = R_OK;
#if SevenSeg_MODE == SevenSeg_8BIT_WITHOUT_DECODER
  switch(Copy_Pu8Number){
  case 0 : DIO_u8SetPortValue(SevenSeg_u8_PORT_8_BIT,SEVENSEG_NUM_ZERO);
	  break;
  case 1 : DIO_u8SetPortValue(SevenSeg_u8_PORT_8_BIT,SEVENSEG_NUM_ONE);
 	  break;

  case 2 : DIO_u8SetPortValue(SevenSeg_u8_PORT_8_BIT,SEVENSEG_NUM_TWO);
 	  break;
  case 3:  DIO_u8SetPortValue(SevenSeg_u8_PORT_8_BIT,SEVENSEG_NUM_THREE);
 	  break;
  case 4 : DIO_u8SetPortValue(SevenSeg_u8_PORT_8_BIT,SEVENSEG_NUM_FOUR);
 	  break;
  case 5 : DIO_u8SetPortValue(SevenSeg_u8_PORT_8_BIT,SEVENSEG_NUM_FIVE);
 	  break;
  case 6 : DIO_u8SetPortValue(SevenSeg_u8_PORT_8_BIT,SEVENSEG_NUM_SIX);
 	  break;
  case 7 : DIO_u8SetPortValue(SevenSeg_u8_PORT_8_BIT,SEVENSEG_NUM_SEVEN);
 	  break;
  case 8 : DIO_u8SetPortValue(SevenSeg_u8_PORT_8_BIT,SEVENSEG_NUM_EIGHT);
 	  break;
  case 9 : DIO_u8SetPortValue(SevenSeg_u8_PORT_8_BIT,SEVENSEG_NUM_NINE);
 	  break;
  default : ret = R_NOT_OK;
  }


#elif SevenSeg_MODE == SevenSeg_4BIT_WITH_DECODER
    DIO_u8SetPinValue(SevenSeg_u8_PORT_4_BIT,SevenSeg_u8_Pin0,GET_BIT(Copy_Pu8Number,0));
  	  DIO_u8SetPinValue(SevenSeg_u8_PORT_4_BIT,SevenSeg_u8_Pin1,GET_BIT(Copy_Pu8Number,1));
  	  DIO_u8SetPinValue(SevenSeg_u8_PORT_4_BIT,SevenSeg_u8_Pin2,GET_BIT(Copy_Pu8Number,2));
  	  DIO_u8SetPinValue(SevenSeg_u8_PORT_4_BIT,SevenSeg_u8_Pin3,GET_BIT(Copy_Pu8Number,3));

#endif
	return ret ;
}
  void helper_4_Bit(u8  Copy_Pu8Number){

  }
