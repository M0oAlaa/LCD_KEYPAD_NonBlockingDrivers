#ifndef _LCD_PRIVATE_H_
#define _LCD_PRIVATE_H_

#define LCD_8bitMODE	1 //8 bit mode: send data to LCD by 8 bits (D0 to D7)
#define LCD_4bitMODE	2 //4 bit mode: send data to LCD by 4 bits (D4 to D7)

#define PORTA	*((volatile char*)0x3B)//LCD_PORT register

#define FortyDalay	20

#define Init_By_Zero		0
#define FourBits			4

#define CLR_Command			0x01
#define ModeFourBit			0x02
#define LineCtrl_Command	0x28
#define CursorCtrl_Command	0x0c
#define ShiftCursorCtrl		0x06
#define SecLineCursor		0x40
#define LCD_FirstLine		0
#define LCD_SecLine			1

#define One		1
#define Ten		10
#endif
