/*
 * Timers_interface.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Ahmed Abdallah
 */

#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

#include"Timers_config.h"
#include "Timers_private.h"

// Timer No
#define timer0   0
#define timer1   1
#define timer2   2

// MODE
#define overflow          10
#define CTC               20
#define FAST_PWM          30
#define PHASE_CORRECT_PWM 40

// Clock Select for Timer 0

#define Timer0_NO_CLOCK_SOURCE  0b000
#define Timer0_NO_PRESCALER     0b001
#define Timer0_PRESCALER_8      0b010
#define Timer0_PRESCALER_32     0b011
#define Timer0_PRESCALER_64     0b100
#define Timer0_PRESCALER_128    0b101
#define Timer0_PRESCALER_256    0b110
#define Timer0_PRESCALER_1024   0b111

// Clock Select for Timer 2

#define Timer2_NO_CLOCK_SOURCE  0b000
#define Timer2_NO_PRESCALER     0b001
#define Timer2_PRESCALER_8      0b010
#define Timer2_PRESCALER_32     0b011
#define Timer2_PRESCALER_64     0b100
#define Timer2_PRESCALER_128    0b101
#define Timer2_PRESCALER_256    0b110
#define Timer2_PRESCALER_1024   0b111

// Clock Select for Timer 1

#define Timer1_NO_CLOCK_SOURCE             0b000
#define Timer1_NO_PRESCALER                0b001
#define Timer1_PRESCALER_8                 0b010
#define Timer1_PRESCALER_64                0b011
#define Timer1_PRESCALER_256   			   0b100
#define Timer1_PRESCALER_1024              0b101
#define Timer1_EXTERNAL_CLK_FALLING_EDGE   0b110
#define Timer1_EXTERNAL_CLK_RISING_EDGE    0b111


 // TCCR0 PINS
#define FOC0           7
#define WGM01          3
#define WGM00          6
#define COM00          4
#define COM01          5
#define CS02           2
#define CS01           1
#define CS00           0


 // TCCR2 PINS
#define FOC2           7
#define WGM20          6
#define WGM21          3
#define COM21          5
#define COM20          4
#define CS22           2
#define CS21           1
#define CS20           0


// TCCR1A PINS

#define COM1A1         7
#define COM1A0         6
#define COM1B1         5
#define COM1B0         4
#define FOC1A          3
#define FOC1AB         2
#define WGM11          1
#define WGM10          0


// TCCR1A PINS

#define ICNC1          7
#define ICES1          6
#define WGM13          4
#define WGM12          3
#define CS12           2
#define CS11           1
#define CS10           0


 // TIMSK for Timer 0 PINS

#define TOIE0 0
#define OCIE0 1

// TIMSK for Timer1 PINS

#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2




// TIFR for Timer 0 PINS

#define TOV0 0
#define OCF0 1

// TIFR for Timer 1 PINS

#define TOV1  2
#define OCF1A 4
#define OCF1B 3
#define ICF1  5


// SFIOR PINS for Timer 0 , Timer 1

#define PSR10 0

// SFIOR PINS for Timer 2

#define PSR2 1

//ASSR PINS for timer 2

#define AS2    3
#define TCN2UB 2
#define OCR2UB 1
#define TCR2UB 0




void Timer_Init(int  TimerNo);
void StartTimer(int TimerNo);
void StopTimer(int TimerNo);
void Timer_write_OCRvalue(int OCR_VALUE,int TimerNo);
void Timer0_SetCallBack (void (*Fptr)(void));
void Timer1_SetCallBack (void (*Fptr)(void));
void Timer2_SetCallBack (void (*Fptr)(void));
#endif /* TIMERS_INTERFACE_H_ */
