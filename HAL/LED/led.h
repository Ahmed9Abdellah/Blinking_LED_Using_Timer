

#ifndef LED_H_
#define LED_H_

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#define LED_PORT DIO_PORTA
#define LED_PIN DIO_PIN1

void LED_init(u8  LedPort,u8  LedPin,u8 Direction);
void LED_toggle(u8 LedPort,u8 LedPin);
#endif /* LED_H_ */
