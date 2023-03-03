/*
 * hardware_.h
 *
 * Created: 03.03.2023 17:11:25
 *  Author: danie
 */ 


#ifndef HARDWARE_H_
#define HARDWARE_H_

#include <avr/io.h>

#define F_CPU					3333333UL	// 20MHz with default 6 prescaler

#define COM_BUS_PORT			PORTA
#define DATA_READY_PIN_bm		PIN6_bm
#define DATA_PARALLEL_bm		(PIN3_bm | PIN4_bm | PIN5_bm)


#define LED_PORT				PORTF
#define LED1_bm					PIN5_bm
#define LED2_bm					PIN4_bm
#define LED3_bm					PIN3_bm
#define LED4_bm					PIN2_bm
#define ALL_LEDS_bm				(LED1_bm | LED2_bm | LED3_bm | LED4_bm)


int init_slave();
int init_master();
int init_leds();

#endif /* HARDWARE_H_ */