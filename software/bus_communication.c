/*
 * bus_communication.c
 *
 * Created: 03.03.2023 22:04:30
 *  Author: danie
 */ 

#include "include/bus_communication.h"

int bus_writer(int data) {
	COM_BUS_PORT.OUTCLR = DATA_READY_PIN_bm;
	COM_BUS_PORT.OUTCLR = DATA_PARALLEL_bm;
	COM_BUS_PORT.OUTSET = (data << DATA_ADDRESS_START_bp) & DATA_PARALLEL_bm;
	COM_BUS_PORT.OUTSET = DATA_READY_PIN_bm;
	return 0;
}

int bus_reader() {
	int data = -1;
	int ready = COM_BUS_PORT.IN & DATA_READY_PIN_bm;
	if (!ready) { return data; }
	
	data = (COM_BUS_PORT.IN & DATA_PARALLEL_bm) >> DATA_ADDRESS_START_bp;
	return data;
}
