#ifndef _TIMERS_REGISTER_H_
#define _TIMERS_REGISTER_H_

#define TIMERS_TCCR0	*((volatile char*)0x53)
#define TCCR0_CS00		0
#define TCCR0_CS01		1
#define TCCR0_CS02		2
#define TCCR0_WGM01		3
#define TCCR0_COM00		4
#define TCCR0_COM01		5
#define TCCR0_WGM00		6

#define TIMERS_TCCR2	*((volatile char*)0x45)
#define TCCR2_CS20		0
#define TCCR2_CS21		1
#define TCCR2_CS22		2
#define TCCR2_WGM21		3
#define TCCR2_COM20		4
#define TCCR2_COM21		5
#define TCCR2_WGM20		6

#define TIMERS_TCNT0	*((volatile char*)0x52)
#define TIMERS_TCNT2	*((volatile char*)0x44)

#define TIMERS_OCR0		*((volatile char*)0x5C)
#define TIMERS_OCR2		*((volatile char*)0x43)

#define TIMERS_TIFR		*((volatile char*)0x58)
#define TIFR_TOV0		0
#define TIFR_OCF0		1
#define TIFR_TOV2		6
#define TIFR_OCF2		7

#define TIMERS_TIMSK	*((volatile char*)0x59)
#define TIMSK_TOIE0		0
#define TIMSK_OCIE0		1
#define TIMSK_TOIE2		6
#define TIMSK_OCIE2		7


#endif
