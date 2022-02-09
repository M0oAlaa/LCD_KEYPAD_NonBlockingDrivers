#include "../../APP/STD_TYPES.h"

#include "PORT_register.h"
#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_interface.h"

void PORT_INIT(void)
{
	/*Send the desired direction of each pin to each port*/
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;

	/*Send the desired initial value of each pin to each port*/
	PORTA=PORTA_VAL;
	PORTB=PORTB_VAL;
	PORTC=PORTC_VAL;
	PORTD=PORTD_VAL;
}
