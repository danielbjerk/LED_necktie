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

int LED_num_to_LED_bm(int num) {
	int LED_bm = -1;
	switch (num) {
		case 0:
			LED_bm = LED0_bm;
			break;
		case 1:
			LED_bm = LED1_bm;
			break;
		case 2:
			LED_bm = LED2_bm;
			break;
		case 3:
			LED_bm = LED3_bm;
			break;
		default:
			LED_bm = -1;
			break;
	}
	
	return LED_bm;
}

int turn_on_single(int LED_num) {
	LED_PORT.OUTSET = LED_num_to_LED_bm(LED_num);
	return 0;
}