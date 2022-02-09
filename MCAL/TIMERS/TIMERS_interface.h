#ifndef _TIMERS_INTERFACE_H_
#define _TIMERS_INTERFACE_H_

#define requiredPWM	30
#define TIMER0		0
#define TIMER2		2

/*Declaration of timer initialization*/
void TimerInit(uint8_t TIMER);

/*Declaration of start timer*/
void TIMER_START(uint8_t TIMER);

/*Declaration of stop timer*/
void TIMER_STOP(uint8_t TIMER);

/*Declaration of get value of timer*/
uint8_t TIMER_GETVALUE(uint8_t TIMER);

/*Declaration of checking overflow flag function*/
uint8_t TIMER_checkOverFlow(uint8_t TIMER);

/*Declaration of controlling overflow flag*/
void TIMER_CLRoverflowFlag(uint8_t TIMER);

/*Declaration of set value of compare match0*/
void TIMER0_SETcompareMatchValue(uint8_t u8_compareValue);

/*Declaration of set value of compare match2*/
void TIMER2_SETcompareMatchValue(uint8_t u8_compareValue);

/*Declaration of timer0 callback function*/
void TIMER0_callback(void(* TIMER_ISR)(void));

/*Declaration of timer2 callback function*/
void TIMER2_callback(void(* TIMER_ISR)(void));



#endif
