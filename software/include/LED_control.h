/*
 * LED_control.h
 *
 * Created: 03.03.2023 09:08:39
 *  Author: danie
 */ 


#ifndef LED_CONTROL_H_
#define LED_CONTROL_H_

#include "hardware.h"

int turn_all_on_color(int color);
int turn_all_off_color(int color);

int turn_all_on();
int turn_all_off();
int turn_on_single(int color, int LED_num);

#endif /* LED_CONTROL_H_ */