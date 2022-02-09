#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "SREG.h"

/*Implementation of enabling global interrupt function*/
void SREG_Enable(void){
	SET_BIT(SREG,SREG_ENABLE);
}

/*Implementation of disabling global interrupt function*/
void SREG_Disable(void){
	CLR_BIT(SREG,SREG_ENABLE);
}
