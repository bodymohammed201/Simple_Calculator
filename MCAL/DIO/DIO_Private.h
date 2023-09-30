
/*****************************************************/
/************** Name      : Abdullah Mohammed ********/
/************** Date      : 24/9/2023         ********/ 
/************** SWC       : DIO               ********/ 
/************** Version   : 1.0               ********/ 
/*****************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

               /*REGA*/
#define   DIO_PORTA  (*((volatile u8*)(0x3B)))  
#define   DIO_DDRA   (*((volatile u8*)(0x3A)))  
#define   DIO_PINA   (*((volatile u8*)(0x39)))  
               /*REGB*/
#define   DIO_PORTB  (*((volatile u8*)(0x38)))  
#define   DIO_DDRB   (*((volatile u8*)(0x37)))  
#define   DIO_PINB   (*((volatile u8*)(0x36))) 
               /*REGC*/
#define   DIO_PORTC  (*((volatile u8*)(0x35)))   
#define   DIO_DDRC   (*((volatile u8*)(0x34))) 
#define   DIO_PINC   (*((volatile u8*)(0x33))) 
               /*REGD*/
#define   DIO_PORTD  (*((volatile u8*)(0x32))) 	
#define   DIO_DDRD   (*((volatile u8*)(0x31)))	
#define   DIO_PIND   (*((volatile u8*)(0x30)))
  
#define   DIO_MAX_PIN_SIZE      7
#define   DIO_MAX_PORT_SIZE     3 
  
       /*MAcros fo pin directions*/
	#define            DIO_u8_INITIAL_OUTPUT     1 
    #define            DIO_u8_INITIAL_INPUT      0
	   /*MAcros fo pin valus*/ 
	#define            DIO_u8_OUTPUT_HIGH        1 
    #define            DIO_u8_OUTPUT_LOW         0
	#define            DIO_u8_INPUT_PULL_UP      1
    #define            DIO_u8_INPUT_FLOATING     0
	
    #define Conc(b7,b6,b5,b4,b3,b2,b1,b0)        Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
	
	#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)   0b##b7##b6##b5##b4##b3##b2##b1##b0
#endif
