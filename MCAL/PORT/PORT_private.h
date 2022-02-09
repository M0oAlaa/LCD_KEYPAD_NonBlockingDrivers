/**********************************************************************/
/**********************************************************************/
/*****************		Author: Mohamed Alaa	***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	PORT			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef _PORT_PRIVATE_H_
#define _PORT_PRIVATE_H_

/*Function like macro to help for concatination*/
#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)			Conc_Header(b7,b6,b5,b4,b3,b2,b1,b0)
/*Concatinate port's bits*/
#define Conc_Header(b7,b6,b5,b4,b3,b2,b1,b0)	0b##b7##b6##b5##b4##b3##b2##b1##b0

/*Access the direction of each pin in each port*/
#define PORTA_DIR		Conc(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTB_DIR		Conc(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTC_DIR		Conc(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTD_DIR		Conc(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)

/*Access the initial value of each pin in each port*/
#define PORTA_VAL		Conc(PORTA_PIN7_VAL,PORTA_PIN6_VAL,PORTA_PIN5_VAL,PORTA_PIN4_VAL,PORTA_PIN3_VAL,PORTA_PIN2_VAL,PORTA_PIN1_VAL,PORTA_PIN0_VAL)
#define PORTB_VAL		Conc(PORTB_PIN7_VAL,PORTB_PIN6_VAL,PORTB_PIN5_VAL,PORTB_PIN4_VAL,PORTB_PIN3_VAL,PORTB_PIN2_VAL,PORTB_PIN1_VAL,PORTB_PIN0_VAL)
#define PORTC_VAL		Conc(PORTC_PIN7_VAL,PORTC_PIN6_VAL,PORTC_PIN5_VAL,PORTC_PIN4_VAL,PORTC_PIN3_VAL,PORTC_PIN2_VAL,PORTC_PIN1_VAL,PORTC_PIN0_VAL)
#define PORTD_VAL		Conc(PORTD_PIN7_VAL,PORTD_PIN6_VAL,PORTD_PIN5_VAL,PORTD_PIN4_VAL,PORTD_PIN3_VAL,PORTD_PIN2_VAL,PORTD_PIN1_VAL,PORTD_PIN0_VAL)


#endif
