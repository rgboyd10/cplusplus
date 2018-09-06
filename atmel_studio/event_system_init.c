/*******************************************************
Event System initialization created by the
CodeWizardAVR V3.32 Automatic Program Generator
© Copyright 1998-2017 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
*******************************************************/

// I/O Registers definitions
#include <xmega128b1.h>

// Event System initialization
void event_system_init(void)
{
// Event System Channel 0 source: Port A, Pin0
EVSYS.CH0MUX=EVSYS_CHMUX_PORTA_PIN0_gc;
// Event System Channel 1 source: None
EVSYS.CH1MUX=EVSYS_CHMUX_OFF_gc;
// Event System Channel 2 source: None
EVSYS.CH2MUX=EVSYS_CHMUX_OFF_gc;
// Event System Channel 3 source: None
EVSYS.CH3MUX=EVSYS_CHMUX_OFF_gc;
// Event System Channel 0 Digital Filter Coefficient: 8 Samples
// Quadrature Decoder: Off
EVSYS.CH0CTRL=(EVSYS.CH0CTRL & (~(EVSYS_QDIRM_gm | EVSYS_QDIEN_bm | EVSYS_QDEN_bm | EVSYS_DIGFILT_gm))) |
	EVSYS_DIGFILT_8SAMPLES_gc;
// Event System Channel 1 Digital Filter Coefficient: 1 Sample
EVSYS.CH1CTRL=EVSYS_DIGFILT_1SAMPLE_gc;
// Event System Channel 2 Digital Filter Coefficient: 1 Sample
// Quadrature Decoder: Off
EVSYS.CH2CTRL=(EVSYS.CH2CTRL & (~(EVSYS_QDIRM_gm | EVSYS_QDIEN_bm | EVSYS_QDEN_bm | EVSYS_DIGFILT_gm))) |
	EVSYS_DIGFILT_1SAMPLE_gc;
// Event System Channel 3 Digital Filter Coefficient: 1 Sample
EVSYS.CH3CTRL=EVSYS_DIGFILT_1SAMPLE_gc;

// Event System Channel output: Disabled
PORTCFG.CLKEVOUT&= ~PORTCFG_EVOUT_gm;
PORTCFG.EVOUTSEL&= ~PORTCFG_EVOUTSEL_gm;
}

