/*
 * KPD_init.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Eslam
 */
#ifndef HAL_KPD_KPD_INIT_H_
#define HAL_KPD_KPD_INIT_H_
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_init.h"
#include <util/delay.h>

#define KPD_PORT PORTC
#define ROW    4
#define Column 4



void HKPD_voidInit();
u8 HKPD_u8GetPressesKey();

#endif /* HAL_KPD_KPD_INIT_H_ */
