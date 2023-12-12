

#include "led.h"

void LED_init(u8 ledPort,u8 ledPin,u8 direction)
{
	DIO_SetPinDirection(ledPort,ledPin,DIO_OUTPUT);
}


void LED_toggle(u8 ledPort,u8 ledPin)
{
	DIO_TogglePinValue(ledPort,ledPin);
}
