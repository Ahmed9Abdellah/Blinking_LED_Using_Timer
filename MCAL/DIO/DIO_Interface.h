

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_INPUT 0
#define DIO_OUTPUT 1

#define DIO_LOW 0
#define DIO_HIGH 1


void DIO_SetPinValue(u8 PortNo,u8 PinNo,u8 Value);
void DIO_SetPortValue(u8 PortNo,u8 value);
void DIO_SetPinDirection(u8 PortNo,u8 PinValue,u8 Direction);
void DIO_SetPortDirection(u8 PortNo ,u8 Direction);
void DIO_TogglePinValue(u8 PortNo, u8 PinNo);
void DIO_SetAllDirection(u8 PortNo, u8 Direction);
void DIO_SetAllPort(u8 PortNo,u8 Value);

u8 DIO_GetPortValue(u8 PortNo);
u8 DIO_GetPinValue(u8 PortNo,u8 PinNo);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
