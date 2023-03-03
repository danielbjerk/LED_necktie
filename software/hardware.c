/*
 * hardware.c
 *
 * Created: 03.03.2023 17:11:42
 *  Author: danie
 */ 

#include "include/hardware.h"


int init_slave() {
	COM_BUS_PORT.DIRCLR = DATA_READY_PIN_bm;
	COM_BUS_PORT.DIRCLR = DATA_PARALLEL_bm;
	return 0;
}

int init_master() {
	COM_BUS_PORT.DIRSET = DATA_READY_PIN_bm;
	COM_BUS_PORT.DIRSET = DATA_PARALLEL_bm;
	return 0;
}

int init_leds() {
	LED_PORT.DIRSET = ALL_LEDS_bm;
}
