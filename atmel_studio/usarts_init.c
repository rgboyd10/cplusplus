/*******************************************************
USARTs initialization created by the
CodeWizardAVR V3.32 Automatic Program Generator
© Copyright 1998-2017 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
*******************************************************/

// I/O Registers definitions
#include <xmega128b1.h>

// USARTs initialization functions
#include "usarts_init.h"

// USARTC0 initialization
void usartc0_init(void)
{
// Note: The correct PORTC direction for the RxD, TxD and XCK signals
// is configured in the ports_init function.

// Transmitter is enabled
// Set TxD=1
PORTC.OUTSET=0x08;

// Communication mode: Asynchronous USART
// Data bits: 8
// Stop bits: 1
// Parity: Disabled
USARTC0.CTRLC=USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_CHSIZE_8BIT_gc;

// Receive complete interrupt: Disabled
// Transmit complete interrupt: Disabled
// Data register empty interrupt: Disabled
USARTC0.CTRLA=(USARTC0.CTRLA & (~(USART_RXCINTLVL_gm | USART_TXCINTLVL_gm | USART_DREINTLVL_gm))) |
	USART_RXCINTLVL_OFF_gc | USART_TXCINTLVL_OFF_gc | USART_DREINTLVL_OFF_gc;

// Required Baud rate: 600
// Real Baud Rate: 600.1 (x1 Mode), Error: 0.0 %
USARTC0.BAUDCTRLA=0xF5;
USARTC0.BAUDCTRLB=((0x0C << USART_BSCALE_gp) & USART_BSCALE_gm) | 0x0C;

// Receiver: Off
// Transmitter: On
// Double transmission speed mode: Off
// Multi-processor communication mode: Off
USARTC0.CTRLB=(USARTC0.CTRLB & (~(USART_RXEN_bm | USART_TXEN_bm | USART_CLK2X_bm | USART_MPCM_bm | USART_TXB8_bm))) |
	USART_TXEN_bm;
}

// Write a character to the USARTC0 Transmitter
#pragma used+
void putchar_usartc0(char c)
{
while ((USARTC0.STATUS & USART_DREIF_bm) == 0);
USARTC0.DATA=c;
}
#pragma used-

