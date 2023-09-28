/*
 * KPD_prog.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Eslam
 */
#include "KPD_init.h"

u8 G_u8Buttons[ROW][Column] = {
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'c','0','=','+'},
};

void HKPD_voidInit(){
	MDIO_voidSetPinDirection(KPD_PORT,0,0);
	MDIO_voidSetPinDirection(KPD_PORT,1,0);
	MDIO_voidSetPinDirection(KPD_PORT,2,0);
	MDIO_voidSetPinDirection(KPD_PORT,3,0);
	MDIO_voidSetPinDirection(KPD_PORT,4,1);
	MDIO_voidSetPinDirection(KPD_PORT,5,1);
	MDIO_voidSetPinDirection(KPD_PORT,6,1);
	MDIO_voidSetPinDirection(KPD_PORT,7,1);
	MDIO_voidSetPortValue(KPD_PORT,0xff);
}

u8 L_u8PressedKey = 0, PinValue;
u8 HKPD_u8GetPressesKey(){
	for(u8 col = 0; col < Column; col++){
		MDIO_voidSetPinValue(KPD_PORT,ROW + col, LOW);
		for(u8 R = 0; R < ROW; R++){
			PinValue = MDIO_u8GetPinValue(KPD_PORT,R);
			if(PinValue == LOW){
				_delay_ms(100);
				L_u8PressedKey = G_u8Buttons[R][col];
				return L_u8PressedKey;
			}
		}
		MDIO_voidSetPinValue(KPD_PORT,ROW + col, HIGH);
	}
}

