/**	
 * |----------------------------------------------------------------------
 * | Copyright (C) Tilen Majerle, 2014
 * | 
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |  
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * | 
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |----------------------------------------------------------------------
 */
#include "tm_stm32f4_keypad.h"
#include "gpioController.h"
#include "stm32f7xx_hal_gpio.h"
/* Pins configuration, columns are outputs */
#define KEYPAD_COLUMN_1_HIGH		digitalWrite(KEYPAD_COLUMN_1_NUM, 1)
#define KEYPAD_COLUMN_1_LOW			digitalWrite(KEYPAD_COLUMN_1_NUM, 0)
#define KEYPAD_COLUMN_2_HIGH		digitalWrite(KEYPAD_COLUMN_2_NUM, 1)
#define KEYPAD_COLUMN_2_LOW			digitalWrite(KEYPAD_COLUMN_2_NUM, 0)
#define KEYPAD_COLUMN_3_HIGH		digitalWrite(KEYPAD_COLUMN_3_NUM, 1)
#define KEYPAD_COLUMN_3_LOW			digitalWrite(KEYPAD_COLUMN_3_NUM, 0)
#define KEYPAD_COLUMN_4_HIGH		digitalWrite(KEYPAD_COLUMN_4_NUM, 1)
#define KEYPAD_COLUMN_4_LOW			digitalWrite(KEYPAD_COLUMN_4_NUM, 0)

/* Read input pins */
#define KEYPAD_ROW_1_CHECK			(!digitalRead(KEYPAD_ROW_1_NUM))
#define KEYPAD_ROW_2_CHECK			(!digitalRead(KEYPAD_ROW_2_NUM))
#define KEYPAD_ROW_3_CHECK			(!digitalRead(KEYPAD_ROW_3_NUM))
#define KEYPAD_ROW_4_CHECK			(!digitalRead(KEYPAD_ROW_4_NUM))

uint8_t KEYPAD_INT_Buttons[4][4] = {
	{0x01, 0x02, 0x03, 0x0C},
	{0x04, 0x05, 0x06, 0x0D},
	{0x07, 0x08, 0x09, 0x0E},
	{0x0A, 0x00, 0x0B, 0x0F},
};

/* Private functions */
void TM_KEYPAD_INT_SetColumn(uint8_t column);
uint8_t TM_KEYPAD_INT_CheckRow(uint8_t column);
uint8_t TM_KEYPAD_INT_Read(void);

/* Private variables */
TM_KEYPAD_Type_t TM_KEYPAD_INT_KeypadType;
static TM_KEYPAD_Button_t KeypadStatus = TM_KEYPAD_Button_NOPRESSED;

void TM_KEYPAD_Init(TM_KEYPAD_Type_t type) {
	/* Set keyboard type */
	TM_KEYPAD_INT_KeypadType = type;
	
	/* Columns are output */
	/* Column 1 */
	initGPIO(KEYPAD_COLUMN_1_NUM, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP,  GPIO_SPEED_MEDIUM);
	/* Column 2 */
	initGPIO(KEYPAD_COLUMN_2_NUM, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP,  GPIO_SPEED_MEDIUM);
	/* Column 3 */
	initGPIO(KEYPAD_COLUMN_3_NUM, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP,  GPIO_SPEED_MEDIUM);
	/* Column 3 */
	if (TM_KEYPAD_INT_KeypadType == TM_KEYPAD_Type_Large) {
		initGPIO(KEYPAD_COLUMN_4_NUM, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP,  GPIO_SPEED_MEDIUM);
	}
	
	/* Rows are inputs */
	/* Row 1 */
	initGPIO(KEYPAD_ROW_1_NUM, GPIO_MODE_INPUT, GPIO_PULLUP,  GPIO_SPEED_MEDIUM);
	/* Row 2 */
	initGPIO(KEYPAD_ROW_2_NUM, GPIO_MODE_INPUT, GPIO_PULLUP,  GPIO_SPEED_MEDIUM);
	/* Row 3 */
	initGPIO(KEYPAD_ROW_3_NUM, GPIO_MODE_INPUT, GPIO_PULLUP,  GPIO_SPEED_MEDIUM);
	/* Row 4 */
	initGPIO(KEYPAD_ROW_4_NUM, GPIO_MODE_INPUT, GPIO_PULLUP,  GPIO_SPEED_MEDIUM);
	
	/* All columns high */
	TM_KEYPAD_INT_SetColumn(0);
}

TM_KEYPAD_Button_t TM_KEYPAD_Read(void) {
	TM_KEYPAD_Button_t temp;
	
	/* Get keypad status */
	temp = KeypadStatus;
	
	/* Reset keypad status */
	KeypadStatus = TM_KEYPAD_Button_NOPRESSED;
	
	return (TM_KEYPAD_Button_t) TM_KEYPAD_INT_Read();
}

/* Private */
void TM_KEYPAD_INT_SetColumn(uint8_t column) {
	/* Set rows high */
	KEYPAD_COLUMN_1_HIGH;
	KEYPAD_COLUMN_2_HIGH;
	KEYPAD_COLUMN_3_HIGH;
	if (TM_KEYPAD_INT_KeypadType == TM_KEYPAD_Type_Large) {
		KEYPAD_COLUMN_4_HIGH;
	}
	
	/* Set column low */
	if (column == 1) {
		KEYPAD_COLUMN_1_LOW;
	}
	if (column == 2) {
		KEYPAD_COLUMN_2_LOW;
	}
	if (column == 3) {
		KEYPAD_COLUMN_3_LOW;
	}
	if (column == 4) {
		KEYPAD_COLUMN_4_LOW;
	}
}

uint8_t TM_KEYPAD_INT_CheckRow(uint8_t column) {
	/* Read rows */
	
	/* Scan row 1 */
	if (KEYPAD_ROW_1_CHECK) {
		return KEYPAD_INT_Buttons[0][column - 1];	
	}
	/* Scan row 2 */
	if (KEYPAD_ROW_2_CHECK) {
		return KEYPAD_INT_Buttons[1][column - 1];
	}
	/* Scan row 3 */
	if (KEYPAD_ROW_3_CHECK) {
		return KEYPAD_INT_Buttons[2][column - 1];
	}
	/* Scan row 4 */
	if (TM_KEYPAD_INT_KeypadType == TM_KEYPAD_Type_Large && KEYPAD_ROW_4_CHECK) {
		return KEYPAD_INT_Buttons[3][column - 1];
	}
	
	/* Not pressed */
	return KEYPAD_NO_PRESSED;
}

uint8_t TM_KEYPAD_INT_Read(void) {
	uint8_t check;
	/* Set row 1 to LOW */
	TM_KEYPAD_INT_SetColumn(1);
	/* Check rows */
	check = TM_KEYPAD_INT_CheckRow(1);
	if (check != KEYPAD_NO_PRESSED) {
		return check;
	}
	
	/* Set row 2 to LOW */
	TM_KEYPAD_INT_SetColumn(2);
	/* Check columns */
	check = TM_KEYPAD_INT_CheckRow(2);
	if (check != KEYPAD_NO_PRESSED) {
		return check;
	}
	
	/* Set row 3 to LOW */
	TM_KEYPAD_INT_SetColumn(3);
	/* Check columns */
	check = TM_KEYPAD_INT_CheckRow(3);
	if (check != KEYPAD_NO_PRESSED) {
		return check;
	}

	if (TM_KEYPAD_INT_KeypadType == TM_KEYPAD_Type_Large) {
		/* Set column 4 to LOW */
		TM_KEYPAD_INT_SetColumn(4);
		/* Check rows */
		check = TM_KEYPAD_INT_CheckRow(4);
		if (check != KEYPAD_NO_PRESSED) {
			return check;
		}
	}
	
	/* Not pressed */
	return KEYPAD_NO_PRESSED;
}

void TM_KEYPAD_Update(void) {
	static uint16_t millis = 0;
	
	/* Every X ms read */
	if (++millis >= KEYPAD_READ_INTERVAL && KeypadStatus == TM_KEYPAD_Button_NOPRESSED) {
		/* Reset */
		millis = 0;
		
		/* Read keyboard */
		KeypadStatus = (TM_KEYPAD_Button_t) TM_KEYPAD_INT_Read();
	}
}

