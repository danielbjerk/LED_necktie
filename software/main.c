/*
 * main.c
 *
 * Created: 3/3/2023 8:59:55 AM
 *  Author: danie
 */ 

#include <xc.h>
#include "include/hardware.h"
#include "include/LED_control.h"
#include "include/bus_communication.h"

// Included to do delays
#include <util/delay.h>

#define IS_MASTER 0

int main(void)
{
	// Pseudocode:
	
	// init_hardware(self_is_master_or_slave, self_num); (setter cur-animation-num til -1 slik at animate ikke viser noe
	
	init_leds();	// led med små bokstaver :)
	if (IS_MASTER) {
		init_master();
	} else {
		init_slave();
	}
	
	// if (self_is_master) {
		// start animation_sequencer_interrupt();
		// function which changes CUR_ANIMATION_NUM, and makes bus_writer write this new state to the common bus
		// bus_writer should lower (raise?) the data_ready-line, change the data on the parallell bus,
		// and then invert the data_ready-line, as well as update own cur_animation_num when this is done
		
		// question: should the master also read from the bus to update it's own animation?
		// No, because this is slow and the master is already slower than the slaves and also this entails
		// needing to use seperate pins for both input and output from the bus, if design is to be modular.
    while(1)
    {
		// Temporary, to move to own thread or as part of animate.
		if (IS_MASTER) {
			bus_writer(2);
			turn_all_off();
			turn_all_on();
			_delay_ms(1000);
			
			bus_writer(3);
			turn_all_off();
			turn_on_single(0, 1);
			_delay_ms(1000);
			
			bus_writer(3);
			turn_all_off();
			turn_on_single(1, 0);
			_delay_ms(1000);
		} else {
			turn_all_on();
			_delay_ms(1000);
			turn_all_off();
			_delay_ms(1000);
		}
		
        // animate(CUR_ANIMATION_NUM);
		
		// animate ser ish sånn ut:
		// switch ANIMATION_NUM{
		// case 1 { fade(); } case 2 { swirl(); } etc
		
    }
}