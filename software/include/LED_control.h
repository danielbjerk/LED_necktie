/*
 * LED_control.h
 *
 * Created: 03.03.2023 09:08:39
 *  Author: danie
 */ 


#ifndef LED_CONTROL_H_
#define LED_CONTROL_H_

#include "hardware.h"

int turn_all_on();
int turn_all_off();
int LED_num_to_LED_bm(int num);
int turn_on_single(int LED_num);

#endif /* LED_CONTROL_H_ */