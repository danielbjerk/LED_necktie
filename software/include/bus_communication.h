/*
 * bus_communication.h
 *
 * Created: 03.03.2023 09:25:12
 *  Author: danie
 */ 


#ifndef BUS_COMMUNICATION_H_
#define BUS_COMMUNICATION_H_

#include "hardware_pins.h"
#include <avr/interrupt.h>

uint8_t bus_writer(uint8_t data);

// checks if data_ready is high (not active low, since module failure implies always low), reads from data-lines when ready
// updates own animation_num with new number
// this probably should interrupt the currently playing animation and turn off all LEDs for synchronization-reasons


#endif /* BUS_COMMUNICATION_H_ */