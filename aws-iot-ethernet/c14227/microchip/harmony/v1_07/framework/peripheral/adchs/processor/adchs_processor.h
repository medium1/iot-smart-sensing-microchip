#ifndef _PLIB_ADCHS_PROCESSOR_H
#define _PLIB_ADCHS_PROCESSOR_H

#if defined(__PIC32MX__)
	#include "adchs_p32xxxx.h"
	
#elif defined(__PIC32MZ__)
	#include "adchs_p32xxxx.h"
	
#elif defined(__PIC32MK__)
	#include "adchs_p32xxxx.h"	
	
#elif defined(__PIC32WK__)
    #include "adchs_p32xxxx.h"

#else
    #error Cant find header

#endif

#endif//_PLIB_ADCHS_PROCESSOR_H