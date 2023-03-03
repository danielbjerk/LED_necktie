/*
 * LED_control.c
 *
 * Created: 03.03.2023 20:25:19
 *  Author: danie
 */ 

#include "include/LED_control.h"

int turn_all_on() {
	LED_PORT.OUTSET = ALL_LEDS_bm;
	return 0;
}

int turn_all_off() {
	LED_PORT.OUTCLR = ALL_LEDS_bm;
	return 0;
}
