/*
 * hardware.c
 *
 * Created: 03.03.2023 17:11:42
 *  Author: danie
 */ 

#include "include/hardware.h"

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
		| (SPI_ENABLE_bm)
		& (~SPI_MASTER_bm);
		
		SPI_PORT.DIR &= ~SPI_MOSI_PIN_bm;
		SPI_PORT.DIR |= SPI_MISO_PIN_bm;
		SPI_PORT.DIR &= ~SPI_SCK_PIN_bm;
		SPI_PORT.DIR &= ~SPI_SS_PIN_bm;
		
		SPI0.INTCTRL = SPI_IE_bm;
	}
	return;
}




void init_leds() {
	LED_COLOR0_PORT.DIRSET = ALL_COLOR0_LEDS_bm;
	LED_COLOR1_PORT.DIRSET = ALL_COLOR1_LEDS_bm;
	return;
}
