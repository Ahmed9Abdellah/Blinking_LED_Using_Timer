#include"APP.h"

void APP_Init(void)
{
	Timer_Init (timer0);
	LED_init(LED_PORT,LED_PIN,DIO_OUTPUT);
}

// Delay 50 ms using prescaler 8 , with Timer0 and FCPU 16 MHz
void TimerDelay (void )
{

static u8 counter=0;
counter++;
if(counter==1)
{
counter=0;
TCNT0=88;

LED_toggle(LED_PORT,LED_PIN);
}
}




