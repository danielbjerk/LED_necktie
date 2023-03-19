/*
 * bus_communication.c
 *
 * Created: 03.03.2023 22:04:30
 *  Author: danie
 */ 

#include "include/bus_communication.h"


int receiveData = -1;

ISR(SPI0_INT_vect)
{
	receiveData = SPI0.DATA;
	SPI0.INTFLAGS = SPI_IF_bm; /* Clear the Interrupt flag by writing 1 */
}
void init_communication(int is_master) {
	// TODO: Endre med ønskelige parametre
	if (is_master)
	{
		SPI_PORT.DIR |= SPI_MOSI_PIN_bm;
		SPI_PORT.DIR &= ~SPI_MISO_PIN_bm; // unused, till future
		SPI_PORT.DIR |= SPI_SCK_PIN_bm;
		SPI_PORT.DIR |= SPI_SS_PIN_bm;
		
		SPI_PORT.OUTSET = SPI_SS_PIN_bm;
		
		SPI0.CTRLA = SPI_CLK2X_bm
		| SPI_DORD_bm
		| SPI_ENABLE_bm
		| SPI_MASTER_bm
		| SPI_PRESC_DIV16_gc;
		
		SPI0.CTRLB |= SPI_SSD_bm;
	} else {
		SPI0.CTRLA = SPI_DORD_bm
		| SPI_ENABLE_bm
		& (~SPI_MASTER_bm);
		
		SPI_PORT.DIR &= ~SPI_MOSI_PIN_bm;
		SPI_PORT.DIR |= SPI_MISO_PIN_bm;
		SPI_PORT.DIR &= ~SPI_SCK_PIN_bm;
		SPI_PORT.DIR &= ~SPI_SS_PIN_bm;
		
		SPI0.INTCTRL = SPI_IE_bm;
	}
	return;
}



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
