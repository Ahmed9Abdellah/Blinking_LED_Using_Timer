/*
 * Timers_pivate.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Ahmed Abdallah
 */


#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_

#define TCCR0 	*((volatile u8*)(0x53))
#define TCNT0 	*((volatile u8*)(0x52))
#define OCR0 	*((volatile u8*)(0x5C))

#define TCCR2   *((volatile u8*)(0x45))
#define TCNT2   *((volatile u8*)(0x44))
#define OCR2    *((volatile u8*)(0x43))

#define TCCR1A  *((volatile u8*)(0x4F))
#define TCCR1B  *((volatile u8*)(0x4E))
#define TCNT1   *((volatile u16*)(0x4C))
#define OCR1A   *((volatile u16*)(0x4A))
#define OCR1B   *((volatile u16*)(0x48))
#define ICR1    *((volatile u16*)(0x46))

#define TIMSK 	*((volatile u8*)(0x59))
#define TIFR 	*((volatile u8*)(0x58))





#endif /* TIMERS_PRIVATE_H_ */
