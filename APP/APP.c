#include "APP.h"

uint8_t APP_init(void)
{
	/*local variable to check initialization has finished*/
	uint8_t local_u8LCD_StatusRead;
	/*some static local flags to make sure that the initialization of KPD and LCD has done once*/
	static uint8_t local_u8KPDinitFlag=NOK;
	static uint8_t local_u8LCDinitFlag=NOK;
	if(local_u8KPDinitFlag == NOK)
	{
		/*Initialization of KEYPAD*/
		KPD_init();
		/*Trigger the KPD flag*/
		local_u8KPDinitFlag=OK;
	}
	if(local_u8LCDinitFlag == NOK)
	{
		/*Initialization of LCD*/
		local_u8LCD_StatusRead=LCD_init();
		if(local_u8LCD_StatusRead==OK)
		{
			/*Trigger the KPD flag*/
			local_u8LCDinitFlag=OK;
			return OK;
		}
		else
		{
			return NOK;
		}
	}
}

void APP_prog(void)
{
	uint8_t local_u8KPDRead=NOK;
	uint8_t local_u8Val;
	/*Write a string at line 1 in LCD*/
	LCD_sendStrData("Pressed Key is:");
	/*Go to the beginning of line 2*/
	LCD_GoToXY(1,0);
	while(1)
	{
		/*Get KPD read*/
		local_u8KPDRead=KPD_u8GetPressedKey(&local_u8Val);
		/*If key Pressed*/
		if(local_u8KPDRead!=NOK)
		{
			/*Display KPD button number*/
			LCD_WriteNumber(local_u8Val);
		}
		else
		{
			//do nothing
		}
	}
}
