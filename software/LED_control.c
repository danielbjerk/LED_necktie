/*
 * LED_control.c
 *
 * Created: 03.03.2023 20:25:19
 *  Author: danie
 */ 

#include "include/LED_control.h"

int turn_all_on_color(int color) {
	switch (color) {
		case 0:
			LED_COLOR0_PORT.OUTSET = ALL_COLOR0_LEDS_bm;
			break;
		case 1:
			LED_COLOR1_PORT.OUTSET = ALL_COLOR1_LEDS_bm;
			break;
	}
	return 0;
}

int turn_all_off_color(int color) {
	switch (color) {
		case 0:
			LED_COLOR0_PORT.OUTCLR = ALL_COLOR0_LEDS_bm;
			break;
		case 1:
			LED_COLOR1_PORT.OUTCLR = ALL_COLOR1_LEDS_bm;
			break;
	}
	return 0;
}

int turn_all_on() {
	turn_all_on_color(0);
	turn_all_on_color(1);
	return 0;
}

int turn_all_off() {
	turn_all_off_color(0);
	turn_all_off_color(1);
	return 0;
}

int turn_on_single(int color, int LED_num) {
	if (color == 0) {
		switch (LED_num) {
			case 0:
				LED_COLOR0_PORT.OUTSET = LED0_COLOR0_bm;
				break;
			case 1:
				LED_COLOR0_PORT.OUTSET = LED1_COLOR0_bm;
				break;
			case 2:
				LED_COLOR0_PORT.OUTSET = LED2_COLOR0_bm;
				break;
			case 3:
				LED_COLOR0_PORT.OUTSET = LED3_COLOR0_bm;
				break;
		}
	} else if (color == 1) {
		switch (LED_num) {
			case 0:
				LED_COLOR1_PORT.OUTSET = LED0_COLOR1_bm;
				break;
			case 1:
				LED_COLOR1_PORT.OUTSET = LED1_COLOR1_bm;
				break;
		}
	}
	return 0;
}