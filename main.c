#include "APP/APP.h"


void main(void)
{
	/*A local variable to get Application initialization correctly*/
	uint8_t local_u8AppRead;
	while(1)
	{
		/*APP initialization*/
		local_u8AppRead=APP_init();
		/*If APP initialization has finished*/
		if(local_u8AppRead == OK)
		{
			/*Run the program*/
			APP_prog();
		}
		else
		{
			//do nothing
		}
	}
}

