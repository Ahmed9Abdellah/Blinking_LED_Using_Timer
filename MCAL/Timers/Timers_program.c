/*
 * Timers_program.
 *
 *  Created on: Jun 30, 2022
 *      Author: Ahmed Abdallah
 */

#include "Timers_interface.h"
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

static void (*Timer0OverFlowCallBack) (void);
static void (*Timer0CompareMatchCallBack)(void );
static void (*Timer2OverFlowCallBack)(void);
static void (*Timer2CompareMatchCallBack)(void );
static void (*Timer1OverFlowCallBack)(void);
static void (*Timer1CompareMatchCallBack)(void );

void Timer_Init (int TimerNo)
{
// 1- Select Timer
switch(TimerNo)
{
case timer0:
#if (Timer0_MODE==overflow)

// 2- Select Mode
	// Normal Mode
CLR_BIT(TCCR0,WGM01);
CLR_BIT(TCCR0,WGM00);

// 3- Enable Interrupt of this mode
// Enable Timer0 overflow Interrupt
SET_BIT(TIMSK,0);
#elif (Timer0_MODE== CTC)
// CTC MODE
CLR_BIT(TCCR0,6);
SET_BIT(TCCR0,3);
// Enable Timer0 CTC Interrupt
SET_BIT(TIMSK,1);
#elif (Timer0_MODE==FAST_PWM )
// FAST PWM
SET_BIT(TCCR0,6);
SET_BIT(TCCR0,3);
// select non inverting mode
CLR_BIT(TCCR0,4);
SET_BIT(TCCR0,5);
#endif
break;
case timer2:
#if (Timer2_MODE==overflow)
	// Normal Mode
	CLR_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);
	// Enable timer2 Normal interrupt
		SET_BIT(TIMSK,6);
#elif(Timer2_MODE==CTC)
	// CTC MODE
	CLR_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);
		// Enable timer2 CTC interrupt
		SET_BIT(TIMSK,7);


#elif(Timer2_MODE==FAST_PWM)
		// choose FAST PWM MODE
		SET_BIT(TCCR2,6);
		SET_BIT(TCCR2,3);
        //Clear OC2 on compare match, set OC2 at TOP (Non Inverting MODE)
		CLR_BIT(TCCR2,4);
		SET_BIT(TCCR2,5);
	#endif
	break;

case timer1:
#if (Timer1_MODE==overflow)
// Notrmal Mode
CLR_BIT(TCCR1A,0);
CLR_BIT(TCCR1A,1);
CLR_BIT(TCCR1B,3);
CLR_BIT(TCCR1B,4);
// enable timer 1 overflow interrupt
SET_BIT(TIMSK,2);
#elif (Timer1_MODE==CTC)
// CTC Mode
CLR_BIT(TCCR1A,0);
CLR_BIT(TCCR1A,1);
SET_BIT(TCCR1B,3);
CLR_BIT(TCCR1B,4);

// enable timer 1 CTC interrupt
SET_BIT(TIMSK,4);
#elif (Timer1_MODE==FAST_PWM)
//  FAST_PWM MODE
CLR_BIT(TCCR1A,0);
SET_BIT(TCCR1A,1);
SET_BIT(TCCR1B,3);
SET_BIT(TCCR1B,4);
// Non Inverting Mode
CLR_BIT(TCCR1A,4);
CLR_BIT(TCCR1A,6);
SET_BIT(TCCR1A,5);
SET_BIT(TCCR1A,7);
#endif
}

}

void StartTimer (int TimerNo)
{
// choose timer
switch(TimerNo)
{

case timer0 :
#if (Timer0_MODE==overflow)
// choose prescaler (8 prescaler)
TCCR0|=0b010;
// start timer on preload
TCNT0=88;
#elif (Timer0_MODE==CTC)
// choose prescaler (8 prescaler)
TCCR0|=0b010;
TCNT0=0;
OCR0=200;
#elif(Timer0_MODE==FAST_PWM)
// choose prescaler (8 prescaler)
TCCR0|=(0b010);
// set inital value to 0
TCNT0=0;
#endif
break;
case timer2 :
#if (Timer2_MODE==overflow)
// choose prescaler (8 prescaler)
TCCR2|=0b010;
// start timer on preload
TCNT2=192;
#elif (Timer2_MODE==CTC)
// choose prescaler (8 prescaler)
TCCR2|=0b010;
TCNT2=0;
OCR2=200;
#elif(Timer2_MODE==FAST_PWM)
// choose prescaler (8 prescaler)
TCCR2|=(0b010);
// set inital value to 0
TCNT2=0;
#endif
break;
case timer1:
#if(Timer1_MODE==overflow)
//choose prescaler (8 prescaler)
TCCR1B|=0b010;
// set inital value to 15536 to get (500ms Delay)
TCNT1=15536;
#elif (Timer1_MODE==CTC)
// choose prescaler (8 prescaler)
TCCR1B|=0b010;
TCNT1=0;
OCR1A=200;
#elif (Timer1_MODE==FAST_PWM)
TCCR1B|=0b010;
TCNT1=0;
#endif

break;
}

}
void StopTimer (int TimerNo)
{
// stop timer
switch(TimerNo)
{
case timer0 :
#if (Timer0_MODE==overflow)
TCCR0&=~(0b111);
#elif (Timer0_MODE==CTC)
TCCR0 &=~(0b111);
#elif (Timer0_MODE==FAST_PWM)
TCCR0&=~(0b111);
#endif
break;

case timer1 :
#if (Timer1_MODE==overflow)
TCCR1B&=~(0b111);
#elif (Timer1_MODE==CTC)
TCCR1B &=~(0b111);
#elif (Timer1_MODE==FAST_PWM)
TCCR1B&=~(0b111);
#endif
break;

case timer2 :
#if (Timer2_MODE==overflow)
TCCR2&=~(0b111);
#elif (Timer2_MODE==CTC)
TCCR2 &=~(0b111);
#elif (Timer2_MODE==FAST_PWM)
TCCR2&=~(0b111);
#endif
break;

}
}

void Timer1_SetCallBack(void (*Fptr)(void))
{
if (Fptr!=NULL)
{
#if Timer1_MODE==overflow
	Timer1OverFlowCallBack=Fptr;
#elif Timer1_MODE==CTC
	Timer1CompareMatchCallBack=Fptr;
#endif

}
}



void Timer2_SetCallBack(void (*Fptr)(void))
{
if (Fptr!=NULL)
{
#if Timer2_MODE==overflow
	Timer2OverFlowCallBack=Fptr;
#elif Timer2_MODE==CTC
	Timer2CompareMatchCallBack=Fptr;
#endif

}
}

void Timer0_SetCallBack (void (*Fptr)(void))
{
	if(Fptr !=NULL)
	{
#if Timer0_MODE==overflow
	Timer0OverFlowCallBack=Fptr;
#elif Timer0_MODE==CTC
	Timer0CompareMatchCallBack=Fptr;
#endif

	}
}
void Timer_write_OCRvalue(int OCR_VALUE,int TimerNo)
{
switch(TimerNo)
{
case timer0:

OCR0=OCR_VALUE;

break;
case timer2 :

OCR2=OCR_VALUE;
break;
case timer1 :
	OCR1A=OCR_VALUE;
	break;
}

}
// Timer0 overflow ISR

void __vector_11 (void)  __attribute__((signal));

void __vector_11 (void)
{
	if(Timer0OverFlowCallBack!=NULL)
	{
	Timer0OverFlowCallBack();
	}
	SET_BIT(TIFR,0);
}
// Timer0 Compare match ISR
void __vector_10 (void)  __attribute__((signal));

void __vector_10 (void)
{
	if(Timer0CompareMatchCallBack != NULL)
	{
	Timer0CompareMatchCallBack();

	}
	SET_BIT(TIFR,1);
}
// timer 2 overflow ISR
void __vector_5 (void)  __attribute__((signal));

void __vector_5 (void)
{
	if(Timer2OverFlowCallBack!=NULL)
	{
	Timer2OverFlowCallBack();
	}
	SET_BIT(TIFR,6);
}
// Timer2 Compare match ISR
void __vector_4 (void)  __attribute__((signal));

void __vector_4 (void)
{
	if(Timer2CompareMatchCallBack != NULL)
	{
	Timer2CompareMatchCallBack();

	}
	SET_BIT(TIFR,7);
}

// Timer1 overflow ISR
void __vector_9 (void)  __attribute__((signal));

void __vector_9 (void)
{
	if(Timer1OverFlowCallBack!=NULL)
	{
	Timer1OverFlowCallBack();
	}
	SET_BIT(TIFR,2);
}
// Timer1 Compare match A  ISR
void __vector_7 (void)  __attribute__((signal));

void __vector_7 (void)
{
	if(Timer1CompareMatchCallBack != NULL)
	{
	Timer1CompareMatchCallBack();
	}
	SET_BIT(TIFR,4);
}
