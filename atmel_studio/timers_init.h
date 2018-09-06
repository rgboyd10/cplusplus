/*******************************************************
Timers/Counters initialization created by the
CodeWizardAVR V3.32 Automatic Program Generator
© Copyright 1998-2017 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
*******************************************************/

#ifndef _TIMERS_INIT_INCLUDED_
#define _TIMERS_INIT_INCLUDED_

// Disable a Timer/Counter type TC0
void tc0_disable(TC0_t *ptc);
// Disable a Timer/Counter type TC1
void tc1_disable(TC1_t *ptc);
// Timer/Counter TCC0 initialization
void tcc0_init(void);
// Timer/Counter TCC1 initialization
void tcc1_init(void);

#endif
