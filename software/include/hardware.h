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
#define DATA_ADDRESS_START_bp	PIN3_bp
#define DATA_PARALLEL_bm		(PIN3_bm | PIN4_bm | PIN5_bm)


#define LED_COLOR0_PORT			PORTF
#define LED_COLOR1_PORT			PORTB

// COLOR0
#define LED0_COLOR0_bm			PIN5_bm
#define LED1_COLOR0_bm			PIN4_bm
#define LED2_COLOR0_bm			PIN3_bm
#define LED3_COLOR0_bm			PIN2_bm
#define ALL_COLOR0_LEDS_bm		(LED0_COLOR0_bm | LED1_COLOR0_bm | LED2_COLOR0_bm | LED3_COLOR0_bm)

// COLOR1
#define LED0_COLOR1_bm			PIN5_bm
#define LED1_COLOR1_bm			PIN4_bm
#define ALL_COLOR1_LEDS_bm		(LED0_COLOR1_bm | LED1_COLOR1_bm)


int init_slave();
int init_master();
int init_leds();

#endif /* HARDWARE_H_ */