/***********************************************************/
/***********************************************************/
/******************** Author : Mohamed Alaa ****************/
/******************** Layer : HAL **************************/
/******************** Driver : KEYPAD **********************/
/***********************************************************/
/***********************************************************/
#ifndef _KEYPAD_H_
#define _KEYPAD_H_

/*Keypad initialization*/
void KPD_init(void);

/*Get Pressed key function takes void and return number*/
uint8_t KPD_u8GetPressedKey(uint8_t* KEY);

#endif
