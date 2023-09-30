
/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 1/10/2023         ********/
/************** SWC       : Calculator        ********/
/************** Version   : 1.0               ********/
/*****************************************************/
#include "APP.h"

int main (void){
	DIO_VoidInit();
	LCD_voidInit();
    u8 keypadNum,ret,NumberOfGigits=0 ;
    u8 Password[16];
    u8 Check_Password[16];
    u8 FirstNum[4];
    u8 SecondNum[4];
    u8 counter =0;


LCD_voidGoToXY(LCD_LINE1,1);
LCD_voidSendString("Set Password");
while(1)
{
	           do
	           {
	                ret=Keypad_u8GetKeyState(&keypadNum);

	           }while(keypadNum==KEYPAD_u8_KEY_NOT_PRESSED);

	           if(keypadNum=='^')  break;   //buttom ON/C
	           NumberOfGigits++;
	           Password[NumberOfGigits]= (keypadNum-48);


	           LCD_voidGoToXY(LCD_LINE2,NumberOfGigits);
	           LCD_voidSendChar(keypadNum);
	           _delay_ms(200);
	           LCD_voidGoToXY(LCD_LINE2,NumberOfGigits);
	           LCD_voidSendChar('*');

}

 while(1)
 {
	         LCD_Clear();
	         _delay_ms(100);
	        LCD_voidGoToXY(LCD_LINE1,1);
	        LCD_voidSendString("Check Password");
	        counter = 0 ;
	        while(1){
	        do{
	        	ret=Keypad_u8GetKeyState(&keypadNum);
	        }while(keypadNum==KEYPAD_u8_KEY_NOT_PRESSED);
	        if(keypadNum=='^')  break;
	        counter++;
	        Check_Password[counter]= (keypadNum-48);


	        LCD_voidGoToXY(LCD_LINE2,counter);
	        LCD_voidSendChar(keypadNum);
	        _delay_ms(200);
	        LCD_voidGoToXY(LCD_LINE2,counter);
	        LCD_voidSendChar('*');
	        }
	       if(checkPassword(Check_Password,Password,NumberOfGigits)){
	       		LCD_Clear();
	       		LCD_voidGoToXY(LCD_LINE1,1);
	       			LCD_voidSendString("Loading");
	       			for(int i = 0 ;i<4;i++){
	       				LCD_voidGoToXY(LCD_LINE1,8+i);
	       				LCD_voidSendChar('.');
	       		_delay_ms(200);
	       	}
	       	_delay_ms(200);
	       	LCD_Clear();
	       		LCD_voidGoToXY(LCD_LINE1,0);
			LCD_voidSendString("Welcome to ");
			LCD_voidGoToXY(LCD_LINE2,0);
			LCD_voidSendString("Your Calaculator ");
			_delay_ms(300);
			LCD_Clear();
			LCD_voidGoToXY(LCD_LINE1,0);
			while(1){
				LCD_Clear();

			counter = 0;
			u8 Operation=0;
while(1){

			do{
				ret=Keypad_u8GetKeyState(&keypadNum);
			}while(keypadNum==KEYPAD_u8_KEY_NOT_PRESSED);
			if(keypadNum == '+'||keypadNum=='-'||keypadNum=='*'||keypadNum=='/'){
				Operation = (char)keypadNum;
				LCD_voidGoToXY(LCD_LINE1,counter);
				LCD_voidSendChar(keypadNum);
				_delay_ms(200);
				break;
			}
			FirstNum[counter]=(int)(keypadNum-48);

				LCD_voidGoToXY(LCD_LINE1,counter);
				LCD_voidSendChar(keypadNum);
				counter++;
		}
    u8 counter2 = counter+1;
    u8 counter3 = 0;
	while(1){

					do{
						ret=Keypad_u8GetKeyState(&keypadNum);
					}while(keypadNum==KEYPAD_u8_KEY_NOT_PRESSED);
					if(keypadNum == '='){

						LCD_voidGoToXY(LCD_LINE1,counter2+1);
						LCD_voidSendChar(keypadNum);
						_delay_ms(200);
						break;
	       					}
	       					SecondNum[counter3]=(int)(keypadNum-48);

	       					LCD_voidGoToXY(LCD_LINE1,counter2);
	       					LCD_voidSendChar(keypadNum);
	       					counter2++;
	       				    counter3++;
	       				}
	        LCD_voidGoToXY(LCD_LINE1,counter2+3);

	        if(Operation=='+'){

	        	LCD_voidSendNumber((u32)calcSum(FirstNum,SecondNum,counter,counter3)) ;
	        }
	        else if (Operation=='-'){
	        	LCD_voidSendNumber((u32)calcSub(FirstNum,SecondNum,counter,counter3)) ;
	        }
	        else if (Operation=='*'){
	        		LCD_voidSendNumber((u32)calcMult(FirstNum,SecondNum,counter,counter3)) ;
	        	}
	        else if (Operation=='/'){
	        	u32 ret = calcDivision(FirstNum,SecondNum,counter,counter3);
	        	if(ret==2){
	        		LCD_voidSendString("Infinity");
	        	}
	        	else{
	        		LCD_voidSendNumber((u32)ret) ;
	        	}
	        	}

	       	_delay_ms(2000);
	       	LCD_Clear();
}

 }
	        else{
	        	LCD_Clear();
	        	LCD_voidGoToXY(LCD_LINE1,1);
	        	LCD_voidSendString("Wrong Password");
	        	_delay_ms(200);
	        	LCD_voidGoToXY(LCD_LINE2,0);
	        	LCD_voidSendString("Please Try Again");
	        	_delay_ms(200);

	}

}

}
u8 checkPassword(u8 arr1[],u8 arr2[],u8 size){
	u8 ret = 1 ;
	for(int i = 1;i<size+1;i++){
		if(arr1[i]==arr2[i]){
			ret++;
		}
	}
	if(ret==size+1){
		ret=1;
	}
	else{
		ret = 0;
	}
	return ret ;
}
 u32  calcSum(u8 arr1[],u8 arr2[],u8 size1,u8 size2){
	   u16 Number1 = arr1[0],Number2=arr2[0];
	 	for(int i =1;i<size1;i++){
	 		Number1 = Number1*10 + arr1[i];
	 	}
	 	for(int i =1;i<size2;i++){
	 	 		Number2 = Number2*10 + arr2[i];
	 	 	}
	 	return (Number1+ Number2);
}
 u32 calcSub(u8 arr1[],u8 arr2[],u8 size1,u8 size2){
 	   u16 Number1 = arr1[0];
 	   u16 Number2= arr2[0];
 	for(int i =1;i<size1;i++){
 		Number1 = Number1*10 + arr1[i];
 	}
 	for(int i =1;i<size2;i++){
 	 		Number2 = Number2*10 + arr2[i];
 	 	}
 	return (Number1- Number2);
 }
 u32  calcMult(u8 arr1[],u8 arr2[],u8 size1,u8 size2){
	   u16 Number1 = arr1[0],Number2=arr2[0];
	 	for(int i =1;i<size1;i++){
	 		Number1 = Number1*10 + arr1[i];
	 	}
	 	for(int i =1;i<size2;i++){
	 	 		Number2= Number2*10 + arr2[i];
	 	 	}
	 	return (Number1*Number2);
 }
 u32  calcDivision(u8 arr1[],u8 arr2[],u8 size1,u8 size2){
	   u16 Number1 = arr1[0],Number2=arr2[0];
	   u32 flag= 0;
	 	for(int i =1;i<size1;i++){
	 		Number1 = Number1*10 + arr1[i];
	 	}
	 	for(int i =1;i<size2;i++){
	 	 		Number2 = Number2*10 + arr2[i];
	 	 	}
	 	if(Number2!=0){
	 	return (Number1/Number2);
	 	}
	 	else{
	 		flag = 2 ;
	 		return flag;
	 	}
 }
