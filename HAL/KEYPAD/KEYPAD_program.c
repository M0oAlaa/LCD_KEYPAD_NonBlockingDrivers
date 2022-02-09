/***********************************************************/
/***********************************************************/
/******************** Author : Mohamed Alaa ****************/
/******************** Layer : HAL **************************/
/******************** Driver : KEYPAD **********************/
/***********************************************************/
/***********************************************************/
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMERS/TIMERS_interface.h"
#include "../../MCAL/SREG/SREG.h"

#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "KEYPAD_interface.h"

uint8_t global_u8Flag=NOK;
uint8_t global_u8KeepState=RELEASED;

void KPD_init(void)
{
#if KEYPAD_T == KEYPAD3_3
	/*Set columns & Rows Direction*/
	DIO_SETpinDir(KPD_PORT,KPD_COLUMN0_PIN,DIO_OUTPUT);
	DIO_SETpinDir(KPD_PORT,KPD_COLUMN1_PIN,DIO_OUTPUT);
	DIO_SETpinDir(KPD_PORT,KPD_COLUMN2_PIN,DIO_OUTPUT);
	DIO_SETpinDir(KPD_PORT,KPD_ROW0_PIN,DIO_INPUT);
	DIO_SETpinDir(KPD_PORT,KPD_ROW1_PIN,DIO_INPUT);
	DIO_SETpinDir(KPD_PORT,KPD_ROW2_PIN,DIO_INPUT);

	/*Set Rows to work in pull up mode*/
	DIO_SETpinVal(KPD_PORT,KPD_ROW0_PIN,DIO_HIGH);
	DIO_SETpinVal(KPD_PORT,KPD_ROW1_PIN,DIO_HIGH);
	DIO_SETpinVal(KPD_PORT,KPD_ROW2_PIN,DIO_HIGH);

	/*Deactivate columns by setting them high*/
	DIO_SETpinVal(KPD_PORT,KPD_COLUMN0_PIN,DIO_HIGH);
	DIO_SETpinVal(KPD_PORT,KPD_COLUMN1_PIN,DIO_HIGH);
	DIO_SETpinVal(KPD_PORT,KPD_COLUMN2_PIN,DIO_HIGH);

#elif KEYPAD_T == KEYPAD4_3
	/*Set columns & Rows Direction*/
	DIO_SETpinDir(KPD_PORT,KPD_COLUMN0_PIN,DIO_OUTPUT);
	DIO_SETpinDir(KPD_PORT,KPD_COLUMN1_PIN,DIO_OUTPUT);
	DIO_SETpinDir(KPD_PORT,KPD_COLUMN2_PIN,DIO_OUTPUT);
	DIO_SETpinDir(KPD_PORT,KPD_ROW0_PIN,DIO_INPUT);
	DIO_SETpinDir(KPD_PORT,KPD_ROW1_PIN,DIO_INPUT);
	DIO_SETpinDir(KPD_PORT,KPD_ROW2_PIN,DIO_INPUT);
	DIO_SETpinDir(KPD_PORT,KPD_ROW3_PIN,DIO_INPUT);

	/*Set Rows to work in pull up mode*/
	DIO_SETpinVal(KPD_PORT,KPD_ROW0_PIN,DIO_HIGH);
	DIO_SETpinVal(KPD_PORT,KPD_ROW1_PIN,DIO_HIGH);
	DIO_SETpinVal(KPD_PORT,KPD_ROW2_PIN,DIO_HIGH);
	DIO_SETpinVal(KPD_PORT,KPD_ROW3_PIN,DIO_HIGH);

	/*Deactivate columns by setting them high*/
	DIO_SETpinVal(KPD_PORT,KPD_COLUMN0_PIN,DIO_HIGH);
	DIO_SETpinVal(KPD_PORT,KPD_COLUMN1_PIN,DIO_HIGH);
	DIO_SETpinVal(KPD_PORT,KPD_COLUMN2_PIN,DIO_HIGH);
#endif
}

/*Static function to make delay 20 ms*/
static void TwintyMiliSecDelay(void)
{
	/*static local variable keep its result*/
	static uint8_t local_u8Counter=0;
	/*Increase counter*/
	local_u8Counter++;
	/*Check if the counter reach target "20 ms"*/
	if(local_u8Counter==Delay_counts)
	{
		/*Set the global flag by OK to notice that the delay has finished*/
		global_u8Flag=OK;
	}
	else
	{
		/*Set the global flag by NotOK to notice that the delay has not finished yet*/
		global_u8Flag=NOK;
	}
}

/*Static function to check if the delay finished or not*/
static uint8_t KPD_StatusRead(void)
{
	static uint8_t local_u8Status=NOK;
	if(global_u8Flag==OK)
	{
		global_u8Flag=NOK;
		local_u8Status=OK;
	}
	else if(global_u8Flag==NOK)
	{
		local_u8Status=NOK;
	}
	return local_u8Status;
}

uint8_t KPD_u8GetPressedKey(uint8_t* KEY)
{
#if KEYPAD_T == KEYPAD3_3
	uint8_t local_u8ReadState;//local variable to check the delay finished
	static uint8_t ButtonState=RELEASED;//Button state
	static uint8_t KPD_Arr[Row_num][Column_num]=KPD_Arr_Val;//arrays of keypad
	static uint8_t KPD_ROWS[Row_num]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN};//array of rows
	static uint8_t KPD_COLUMNS[Column_num]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN};//array of columns
	uint8_t KPD_ROWS_Index,KPD_COLUMNS_Index,ROW_PIN_State;//local variables of rows and column index and row state

	/*Iterate to active each column and check the row's value*/
	for(KPD_COLUMNS_Index=0;KPD_COLUMNS_Index<Column_num;KPD_COLUMNS_Index++)
	{
		/*Activate Columns*/
		DIO_SETpinVal(KPD_PORT,KPD_COLUMNS[KPD_COLUMNS_Index],DIO_LOW);
		/*Iterate to check row's values*/
		for(KPD_ROWS_Index=0;KPD_ROWS_Index<Row_num;KPD_ROWS_Index++)
		{
			/*get the row state*/
			DIO_GETpinVal(KPD_PORT,KPD_ROWS[KPD_ROWS_Index],&ROW_PIN_State);
			/*if button pressed*/
			if(ROW_PIN_State==PRESSED)
			{
				/*Set button in PRESSED Mode*/
				ButtonState = PRESSED;
			}
			/*Deal with button states*/
			switch(ButtonState)
			{
			/*when button state pressed*/
			case PRESSED:
				/*push the pressed key to the user*/
				*KEY=KPD_Arr[KPD_ROWS_Index][KPD_COLUMNS_Index];
				/*bouncing handling*/
				/*Enable the global interrupt*/
				SREG_Enable();
				/*Initialize timer 0*/
				TimerInit(TIMER0);
				/*Start timer 0*/
				TIMER_START(TIMER0);
				/*Call back*/
				TIMER0_callback(&TwintyMiliSecDelay);
				/*Set button state in DEBOUNCING Mode*/
				ButtonState = DEBOUNCING;
				break;
			/*De-bouncing*/
			case DEBOUNCING:
				/*Check if the delay finished*/
				local_u8ReadState=KPD_StatusRead();
				/*if no*/
				if(local_u8ReadState == NOK)
				{
					//do nothing
				}
				/*if yes*/
				else if(local_u8ReadState == OK)
				{
					/*Stop timer 0*/
					TIMER_STOP(TIMER0);
					/*Stop the global interrupt*/
					SREG_Disable();
					/*Set button state in RELEASED Mode*/
					ButtonState = RELEASED;
					/*return OK*/
					return OK;
				}
				break;
			}
		}
		/*Deactivate current column*/
		DIO_SETpinVal(KPD_PORT,KPD_COLUMNS[KPD_COLUMNS_Index],DIO_HIGH);
	}
	/*return NotOK*/
	return NOK;

#elif KEYPAD_T == KEYPAD4_3
	uint8_t local_u8Pressed=KPD_NO_Pressed;//The initial value of the key is not pressed
	static uint8_t KPD_Arr[Row_num4_3][Column_num4_3]=KPD_Arr_Val4_3;//arrays of keypad
	static uint8_t KPD_ROWS[Row_num4_3]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};//array of rows
	static uint8_t KPD_COLUMNS[Column_num4_3]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN};//array of columns
	uint8_t KPD_ROWS_Index,KPD_COLUMNS_Index,ROW_PIN_State;//local variables of rows and colum index and row state

	/*Interate to active each column and check the row's value*/
	for(KPD_COLUMNS_Index=0;KPD_COLUMNS_Index<Column_num4_3;KPD_COLUMNS_Index++)
	{
		/*Activate Columns*/
		DIO_SETpinVal(KPD_PORT,KPD_COLUMNS[KPD_COLUMNS_Index],DIO_LOW);
		/*Iterate to check row's values*/
		for(KPD_ROWS_Index=0;KPD_ROWS_Index<Row_num4_3;KPD_ROWS_Index++)
		{
			/*get the row state*/
			DIO_GETpinVal(KPD_PORT,KPD_ROWS[KPD_ROWS_Index],&ROW_PIN_State);
			/*if button pressed*/
			if(DIO_LOW==ROW_PIN_State)
			{
				/*put the button number in key value*/
				local_u8Pressed=KPD_Arr[KPD_ROWS_Index][KPD_COLUMNS_Index];
				/*If user want to keep the key value*/
				if(KPD_STATE == POOLING)
				{
					/*Polling until key released*/
					while(DIO_LOW==ROW_PIN_State)
					{
						DIO_GETpinVal(KPD_PORT,KPD_ROWS[KPD_ROWS_Index],&ROW_PIN_State);
					}
				}
				else
				{
					//do nothing
				}
				/*deactivate the column*/
				DIO_SETpinVal(KPD_PORT,KPD_COLUMNS[KPD_COLUMNS_Index],DIO_HIGH);
				return local_u8Pressed;
			}
		}
		/*Deactivate current column*/
		DIO_SETpinVal(KPD_PORT,KPD_COLUMNS[KPD_COLUMNS_Index],DIO_HIGH);
	}

	return local_u8Pressed;
#endif
}
