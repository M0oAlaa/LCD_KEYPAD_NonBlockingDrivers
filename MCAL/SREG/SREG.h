#ifndef _SREG_H_
#define _SREG_H_

#define SREG	*((volatile char*)0x5F)
#define SREG_ENABLE		7 //pin of controlling the global interrupt

/*Declaration of enabling the global interrupt*/
void SREG_Enable(void);

/*Declaration of disabling the global interrupt*/
void SREG_Disable(void);

#endif