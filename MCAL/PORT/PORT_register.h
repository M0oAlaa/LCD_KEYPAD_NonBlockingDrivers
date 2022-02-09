/**********************************************************************/
/**********************************************************************/
/*****************		Author: Mohamed Alaa	***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	PORT			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/
#ifndef _PORT_REGISTER_H_
#define _PORT_REGISTER_H_

/*Define control registers*/
#define DDRA	*((volatile char*)0x3A)
#define DDRB	*((volatile char*)0x37)
#define DDRC	*((volatile char*)0x34)
#define DDRD	*((volatile char*)0x31)

/*Define data registers*/
#define PORTA	*((volatile char*)0x3B)
#define PORTB	*((volatile char*)0x38)
#define PORTC	*((volatile char*)0x35)
#define PORTD	*((volatile char*)0x32)

#endif
