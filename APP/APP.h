/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 1/10/2023         ********/
/************** SWC       : Calculator        ********/
/************** Version   : 1.0               ********/
/*****************************************************/

#ifndef APP_APP_H_
#define APP_APP_H_

#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KeyPad/Keypad_Interface.h"
#include "../HAL/LED/Led_Interface.h"
#include "../HAL/SevenSeg/SevenSeg_Interface.h"
#include <util/delay.h>
#include <math.h>
u8 checkPassword(u8 arr1[],u8 arr2[],u8 size);
u32  calcSum(u8 arr1[],u8 arr2[],u8 size1,u8 size2);
u32  calcMult(u8 arr1[],u8 arr2[],u8 size1,u8 size2);
u32  calcSub(u8 arr1[],u8 arr2[],u8 size1,u8 size2);
u32  calcDivision(u8 arr1[],u8 arr2[],u8 size1,u8 size2);

#endif /* APP_APP_H_ */
