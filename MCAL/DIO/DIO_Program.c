#include"DIO_Interface.h"
#include"DIO_Private.h"


void DIO_SetPinValue(u8 PortNo,u8 PinNo , u8 Value)
{
if(Value==DIO_HIGH)
{
switch(PortNo)
{
case DIO_PORTA:
	SET_BIT(PORTA,PinNo);
break;
case DIO_PORTB:
	SET_BIT(PORTB,PinNo);
	break;
case DIO_PORTC:
	SET_BIT(PORTC,PinNo);
	break;
case DIO_PORTD:
	SET_BIT(PORTD,PinNo);
	break;
}
}
	else if (Value==DIO_LOW)
	{
		switch(PortNo)
		{
		case DIO_PORTA:
			CLR_BIT(PORTA,PinNo);
		break;
		case DIO_PORTB:
			CLR_BIT(PORTB,PinNo);
			break;
		case DIO_PORTC:
			CLR_BIT(PORTC,PinNo);
			break;
		case DIO_PORTD:
			CLR_BIT(PORTD,PinNo);
			break;
		}
	}
}
// Set Pin Direction Whether Output or Input
void DIO_SetPinDirection(u8 PortNo,u8 PinNo , u8 Direction){

if(Direction == DIO_OUTPUT){
	switch(PortNo)
	{
	case DIO_PORTA:
		SET_BIT(DDRA,PinNo);
	break;
	case DIO_PORTB:
		SET_BIT(DDRB,PinNo);
		break;
	case DIO_PORTC:
		SET_BIT(DDRC,PinNo);
		break;
	case DIO_PORTD:
		SET_BIT(DDRD,PinNo);
		break;
	}
}
else if(Direction == DIO_INPUT){
	switch(PortNo)
	{
	case DIO_PORTA:
		CLR_BIT(DDRA,PinNo);
	break;
	case DIO_PORTB:
		CLR_BIT(DDRB,PinNo);
		break;
	case DIO_PORTC:
		CLR_BIT(DDRC,PinNo);
		break;
	case DIO_PORTD:
		CLR_BIT(DDRD,PinNo);
		break;
	}
}
}
// Get Pin Value whether High (1) or Low (0)
u8 DIO_GetPinValue(u8 PortNo,u8 PinNo){
	u8 pin_value=0;
	switch (PortNo)
	{
	case DIO_PORTA:
	pin_value=GET_BIT(PINA,PinNo) ;
	break;
	case DIO_PORTB:
		pin_value=GET_BIT(PINB,PinNo) ;
		break;
	case DIO_PORTC:
		pin_value= 	GET_BIT(PINC,PinNo) ;
		break;
	case DIO_PORTD:
		pin_value= 	GET_BIT(PIND,PinNo) ;
		break;
	}
	return pin_value;
}
void DIO_SetPortValue(u8 PortNo,u8 Value)
    {
	switch (PortNo)
	{
	case DIO_PORTA:
		PORTA=Value;
		break;
	case DIO_PORTB :
		PORTB=Value;
		break;
	case DIO_PORTC:
		PORTC=Value;
		break;
	case DIO_PORTD :
		PORTD=Value;
		break;

   }
   }

// Set Port Value to High (1) or Clear Port Value (0)
void DIO_SetAllPort(u8 PortNo,u8 Value){

if(Value==DIO_LOW){
switch (PortNo)
{
case DIO_PORTA:
	PORTA=0x00;
	break;
case DIO_PORTB :
	PORTB=0x00;
	break;
case DIO_PORTC:
	PORTC=0x00;
	break;
case DIO_PORTD :
	PORTD=0x00;
	break;
}

}
else if (Value==DIO_HIGH){
	switch (PortNo)
	{
	case DIO_PORTA:
		PORTA=0xff;
		break;
	case DIO_PORTB :
		PORTB=0xff;
		break;
	case DIO_PORTC:
		PORTC=0xff;
		break;
	case DIO_PORTD :
		PORTD=0xff;
		break;
	}
}
}
void DIO_SetAllDirection(u8 PortNo, u8 Direction){
	if(Direction==DIO_INPUT)
	{
	switch (PortNo)
	{
	case DIO_PORTA:
	DDRA=0x00;
	break;
	case DIO_PORTB:
	DDRB=0x00;
     break;
	case DIO_PORTC:
		DDRC=0x00;
	break;
	case DIO_PORTD:
		DDRD=0x00;
	break;
	}
	}
	else if(Direction==DIO_OUTPUT)
	{
	switch (PortNo)
	{
	case DIO_PORTA:
	DDRA=0xff;
	break;
	case DIO_PORTB:
	DDRB=0xff;
     break;
	case DIO_PORTC:
		DDRC=0xff;
	break;
	case DIO_PORTD:
		DDRD=0xff;
	break;
	}
	}
}
// choose which direction whether Input or Output
void DIO_SetPortDirection(u8 PortNo, u8 Direction){
	switch (PortNo)
	{
	case DIO_PORTA:
	DDRA=Direction;
	break;
	case DIO_PORTB:
	DDRB=Direction;
     break;
	case DIO_PORTC:
		DDRC=Direction;
	break;
	case DIO_PORTD:
		DDRD=Direction;
	break;
}
}
// Get Port Value whether High (1) or  Low (0)
u8 DIO_GetPortValue (u8 PortNo)
{
u8 port_value=0;
switch (PortNo)
{
case DIO_PORTA:
port_value=	PINA ;
break;
case DIO_PORTB:
port_value=	PINB ;
break;
case DIO_PORTC:
port_value=	PINC ;
break;
case DIO_PORTD:
port_value=	PIND ;
break;
}
return port_value;
}
// Toggle Pin (Set High (1) then Clear (0) )
void DIO_TogglePinValue(u8 PortNo, u8 PinNo)
{
switch(PortNo)
{
case DIO_PORTA :
	TOG_BIT(PORTA,PinNo);
	break;
case DIO_PORTB :
	TOG_BIT(PORTB,PinNo);
	break;
case DIO_PORTC :
	TOG_BIT(PORTC,PinNo);
	break;
case DIO_PORTD :
	TOG_BIT(PORTD,PinNo);
	break;
}
}

