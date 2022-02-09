#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMERS_register.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"
#include "TIMERS_interface.h"
#define INTR_ATTRS used,externally_visible

void(* TIMER0CALLBACK)(void);
void(* TIMER2CALLBACK)(void);

void TimerInit(uint8_t TIMER){
if( TIMER == TIMER0)
{
#if MODE0 == NORMAL
	/*Normal Mode*/
	CLR_BIT(TIMERS_TCCR0,TCCR0_WGM00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_WGM01);
#elif MODE0 == PWM_PHASE_CORRECT
	/*Phase correct*/
	SET_BIT(TIMERS_TCCR0,TCCR0_WGM00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_WGM01);

#elif MODE0 == CTC
	/*CTC*/
	CLR_BIT(TIMERS_TCCR0,TCCR0_WGM00);
	SET_BIT(TIMERS_TCCR0,TCCR0_WGM01);

#elif MODE0 == PWM_FAST
	/*Fast PWM*/
	SET_BIT(TIMERS_TCCR0,TCCR0_WGM00);
	SET_BIT(TIMERS_TCCR0,TCCR0_WGM01);
#endif

#if PRESCALAR0 == NO_PRESCALAR
	/*Select NO prescalar*/
	SET_BIT(TIMERS_TCCR0,TCCR0_CS00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS01);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS02);
#elif PRESCALAR0 == DIV_8
	/*select prescaler (Divide by 8)*/
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS00);
	SET_BIT(TIMERS_TCCR0,TCCR0_CS01);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS02);
#elif PRESCALAR0 == DIV_64
	/*select prescaler (Divide by 64)*/
	SET_BIT(TIMERS_TCCR0,TCCR0_CS00);
	SET_BIT(TIMERS_TCCR0,TCCR0_CS01);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS02);

#elif PRESCALAR0 == DIV_256
	/*select prescaler (Divide by 256)*/
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS01);
	SET_BIT(TIMERS_TCCR0,TCCR0_CS02);

#elif PRESCALAR0 == DIV_1024
	/*select prescaler (Divide by 1024)*/
	SET_BIT(TIMERS_TCCR0,TCCR0_CS00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS01);
	SET_BIT(TIMERS_TCCR0,TCCR0_CS02);
#endif
}

if( TIMER == TIMER2)
{
#if MODE2 == NORMAL
	/*Normal Mode*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_WGM20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_WGM21);
#elif MODE2 == PWM_PHASE_CORRECT
	/*Phase Correct Mode*/
	SET_BIT(TIMERS_TCCR2,TCCR2_WGM20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_WGM21);
#elif MODE2 == CTC
	/*CTC Mode*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_WGM20);
	SET_BIT(TIMERS_TCCR2,TCCR2_WGM21);
#elif MODE2 == PWM_FAST
	/*Fast PWM Mode*/
	SET_BIT(TIMERS_TCCR2,TCCR2_WGM20);
	SET_BIT(TIMERS_TCCR2,TCCR2_WGM21);
#endif

#if PRESCALAR2 == NO_PRESCALAR
	/*select No prescaler*/
	SET_BIT(TIMERS_TCCR2,TCCR2_CS20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS21);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR2 == DIV_8
	/*select prescaler (Divide by 8)*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS20);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS21);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR2 == DIV_32
	/*select prescaler (Divide by 32)*/
	SET_BIT(TIMERS_TCCR2,TCCR2_CS20);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS21);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR2 == DIV_64
	/*select prescaler (Divide by 64)*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS21);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR2 == DIV_128
	/*select prescaler (Divide by 128)*/
	SET_BIT(TIMERS_TCCR2,TCCR2_CS20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS21);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR2 == DIV_256
	/*select prescaler (Divide by 256)*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS20);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS21);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR2 == DIV_1024
	/*select prescaler (Divide by 1024)*/
	SET_BIT(TIMERS_TCCR2,TCCR2_CS20);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS21);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS22);
#endif
}
}//End of TIMER init Function

/*Implementation of Start timer*/
void TIMER_START(uint8_t TIMER)
{
	/*If select timer0*/
	if(TIMER==TIMER0)
	{
		/*If select normal mode*/
		if(MODE0==NORMAL)
		{
			SET_BIT(TIMERS_TIMSK,TIMSK_TOIE0);
		}
		/*If select ctc mode*/
		else if(MODE0== CTC)
		{
			SET_BIT(TIMERS_TIMSK,TIMSK_OCIE0);
		}
	}
	/*If select timer2*/
	else if(TIMER==TIMER2)
	{
		/*If select normal mode*/
		if(MODE2==NORMAL)
		{
			SET_BIT(TIMERS_TIMSK,TIMSK_TOIE2);
		}
		/*If select ctc mode*/
		else if(MODE2== CTC)
		{
			SET_BIT(TIMERS_TIMSK,TIMSK_OCIE2);
		}
	}
}//End of Start function

void TIMER_STOP(uint8_t TIMER)
{
	/*If select timer0*/
	if(TIMER==TIMER0)
	{
		/*If select normal mode*/
		if(MODE0==NORMAL)
		{
			CLR_BIT(TIMERS_TIMSK,TIMSK_TOIE0);
		}
		/*If select ctc mode*/
		else if(MODE0== CTC)
		{
			CLR_BIT(TIMERS_TIMSK,TIMSK_OCIE0);
		}
	}
	/*If select timer2*/
	else if(TIMER==TIMER2)
	{
		/*If select normal mode*/
		if(MODE2==NORMAL)
		{
			CLR_BIT(TIMERS_TIMSK,TIMSK_TOIE2);
		}
		/*If select ctc mode*/
		else if(MODE2== CTC)
		{
			CLR_BIT(TIMERS_TIMSK,TIMSK_OCIE2);
		}
	}
}//End of Stop function

/*Implementation of Getting timer reading*/
uint8_t TIMER_GETVALUE(uint8_t TIMER)
{
	uint8_t local_u8TimerValue;
	if(TIMER == 0)
	{
		local_u8TimerValue=TIMERS_TCNT0;
	}
	else if(TIMER == 2)
	{
		local_u8TimerValue= TIMERS_TCNT2;
	}
	return local_u8TimerValue;
}

/*Implementation of checking overflow flag*/
uint8_t TIMER_checkOverFlow(uint8_t TIMER)
{
	uint8_t local_u8checkoverflow;
	if(TIMER == 0)
	{
		local_u8checkoverflow=GET_BIT(TIMERS_TIFR,TIFR_TOV0);
		while(local_u8checkoverflow!=1)
		{
			local_u8checkoverflow=GET_BIT(TIMERS_TIFR,TIFR_TOV0);
		}
	}
	else if(TIMER == 2)
	{
		local_u8checkoverflow=GET_BIT(TIMERS_TIFR,TIFR_TOV2);
		while(local_u8checkoverflow!=1)
		{
			local_u8checkoverflow=GET_BIT(TIMERS_TIFR,TIFR_TOV2);
		}
	}
	return local_u8checkoverflow;
}

/*Implementation of clearing overflow flag by set it by 1*/
void TIMER_CLRoverflowFlag(uint8_t TIMER)
{
	if(TIMER == 0)
	{
		SET_BIT(TIMERS_TIFR,TIFR_TOV0);
	}
	else if(TIMER == 2)
	{
		SET_BIT(TIMERS_TIFR,TIFR_TOV2);
	}
}

void TIMER0_SETcompareMatchValue(uint8_t u8_compareValue)
{
	TIMERS_OCR0=u8_compareValue;
}

void TIMER2_SETcompareMatchValue(uint8_t u8_compareValue)
{
	TIMERS_OCR2=u8_compareValue;
}

/*Implementation of timer callback function*/
void TIMER0_callback(void(* TIMER_ISR)(void))
{
	TIMER0CALLBACK=TIMER_ISR;
}//End of Callback function

/*Implementation of timer callback function*/
void TIMER2_callback(void(* TIMER_ISR)(void))
{
	TIMER2CALLBACK=TIMER_ISR;
}//End of Callback function

uint8_t TIMER0_ISR_delay(uint32_t u32_delay,void(* TIMER_ISR)(void))
{
	uint8_t local_u8Error=OK;
	if(TIMER_ISR == NULL)
	{
		local_u8Error=NOK;
	}
	else
	{
		TimerInit(0);
		TIMER_START(0);
		TIMER0CALLBACK=TIMER_ISR;
	}
	return local_u8Error;
}

void __vector_11(void) __attribute__((signal,INTR_ATTRS));
void __vector_11(void)
{
	if(TIMER0CALLBACK!=NULL)
	{
		TIMER0CALLBACK();
	}
}//End of overflow interrupt function function of timer0


void __vector_10(void) __attribute__((signal,INTR_ATTRS));
void __vector_10(void)
{
	if(TIMER0CALLBACK!=NULL)
	{
		TIMER0CALLBACK();
	}
}//End of out compare interrupt function function of timer0

void __vector_5(void) __attribute__((signal,INTR_ATTRS));
void __vector_5(void)
{
	if(TIMER2CALLBACK!=NULL)
	{
		TIMER2CALLBACK();
	}
}//End of overflow interrupt function function of timer2


void __vector_4(void) __attribute__((signal,INTR_ATTRS));
void __vector_4(void)
{
	if(TIMER2CALLBACK!=NULL)
	{
		TIMER2CALLBACK();
	}
}//End of out compare interrupt function function of timer2
