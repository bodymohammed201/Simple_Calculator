/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 26/9/2023         ********/ 
/************** SWC       :KeyPad             ********/
/************** Version   : 1.0               ********/ 
/*****************************************************/
#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H
#define KEYPAD_u8_KEY_NOT_PRESSED     0xff
u8 Keypad_u8GetKeyState(u8 * Copy_pu8ReturnedKey);

#endif 
