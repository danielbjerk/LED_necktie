/*
 * bus_communication.c
 *
 * Created: 03.03.2023 22:04:30
 *  Author: danie
 */ 

#include "include/bus_communication.h"

uint8_t bus_writer(uint8_t frame) {
	SPI_PORT.OUT &= ~SPI_SS_PIN_bm;
	SPI0.DATA = frame;
	while (!(SPI0.INTFLAGS & SPI_IF_bm)) /* waits until data is exchanged*/
	{
		;
	}
	SPI_PORT.OUT |= SPI_SS_PIN_bm;
	return SPI0.DATA;
}
