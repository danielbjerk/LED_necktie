/*
 * main.c
 *
 * Created: 3/3/2023 8:59:55 AM
 *  Author: danie
 */ 

#include <xc.h>

#include "include/hardware_pins.h"
#include "include/LED_control.h"
#include "include/bus_communication.h"

// Included to do delays
// only for debugging?
#include <util/delay.h>

#define IS_MASTER 0



int main(void)
{
	// Pseudocode:
	// init_hardware(self_is_master_or_slave, self_num); (setter cur-animation-num til -1 slik at animate ikke viser noe
	sei();
	init_leds();	// led med små bokstaver :)
	init_communication(IS_MASTER);
		
	
	// if (self_is_master) {
		// start animation_sequencer_interrupt();
		// function which changes CUR_ANIMATION_NUM, and makes bus_writer write this new state to the common bus
		// bus_writer should lower (raise?) the data_ready-line, change the data on the parallell bus,
		// and then invert the data_ready-line, as well as update own cur_animation_num when this is done
		
		// question: should the master also read from the bus to update it's own animation?
		// No, because this is slow and the master is already slower than the slaves and also this entails
		// needing to use seperate pins for both input and output from the bus, if design is to be modular.
    uint8_t data_written;
	while(1)
    {
		// Temporary, to move to own thread or as part of animate.
		if (IS_MASTER) {
			turn_all_off();
			data_written = 1;
			bus_writer(data_written);
			turn_on_single(0, data_written);
			_delay_ms(1000);
			
			data_written = 2;
			turn_all_off();
			bus_writer(data_written);
			turn_on_single(0, data_written);
			_delay_ms(1000);
		} else {
			turn_all_off();
			if (!(receiveData < 0)) {
				turn_on_single(0, receiveData);	
			}
		}
		
        // animate(CUR_ANIMATION_NUM);
		
		// animate ser ish sånn ut:
		// switch ANIMATION_NUM{
		// case 1 { fade(); } case 2 { swirl(); } etc
		
    }
}