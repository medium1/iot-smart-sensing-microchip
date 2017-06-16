/* Created by plibgen $Revision: 1.31 $ */

#ifndef _ADCHS_P32MZ2048EFM064_H
#define _ADCHS_P32MZ2048EFM064_H

/* Section 1 - Enumerate instances, define constants, VREGs */

#include <xc.h>
#include <stdbool.h>

#include "peripheral/peripheral_common_32bit.h"

/* Default definition used for all API dispatch functions */
#ifndef PLIB_INLINE_API
    #define PLIB_INLINE_API extern inline
#endif

/* Default definition used for all other functions */
#ifndef PLIB_INLINE
    #define PLIB_INLINE extern inline
#endif

typedef enum {

    ADCHS_ID_0 = 0,
    ADCHS_NUMBER_OF_MODULES

} ADCHS_MODULE_ID;

typedef enum {

    ADCHS_AN0 = 0,
    ADCHS_AN1 = 1,
    ADCHS_AN2 = 2,
    ADCHS_AN3 = 3,
    ADCHS_AN4 = 4,
    ADCHS_AN5 = 5,
    ADCHS_AN6 = 6,
    ADCHS_AN7 = 7,
    ADCHS_AN8 = 8,
    ADCHS_AN9 = 9,
    ADCHS_AN10 = 10,
    ADCHS_AN11 = 11,
    ADCHS_AN12 = 12,
    ADCHS_AN13 = 13,
    ADCHS_AN14 = 14,
    ADCHS_AN15 = 15,
    ADCHS_AN16 = 16,
    ADCHS_AN17 = 17,
    ADCHS_AN18 = 18,
    ADCHS_AN43 = 43,
    ADCHS_AN44 = 44

} ADCHS_AN_INPUT_ID;

typedef enum {

    ADCHS_CLASS12_AN0 = 0,
    ADCHS_CLASS12_AN1 = 1,
    ADCHS_CLASS12_AN2 = 2,
    ADCHS_CLASS12_AN3 = 3,
    ADCHS_CLASS12_AN4 = 4,
    ADCHS_CLASS12_AN5 = 5,
    ADCHS_CLASS12_AN6 = 6,
    ADCHS_CLASS12_AN7 = 7,
    ADCHS_CLASS12_AN8 = 8,
    ADCHS_CLASS12_AN9 = 9,
    ADCHS_CLASS12_AN10 = 10,
    ADCHS_CLASS12_AN11 = 11

} ADCHS_CLASS12_AN_INPUT_ID;

typedef enum {

    ADCHS_CLASS2_AN5 = 5,
    ADCHS_CLASS2_AN6 = 6,
    ADCHS_CLASS2_AN7 = 7,
    ADCHS_CLASS2_AN8 = 8,
    ADCHS_CLASS2_AN9 = 9,
    ADCHS_CLASS2_AN10 = 10,
    ADCHS_CLASS2_AN11 = 11

} ADCHS_CLASS2_AN_INPUT_ID;

typedef enum {

    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_0_BITS = 0,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_1_BITS = 1,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_2_BITS = 2,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_3_BITS = 3,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_4_BITS = 4,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_5_BITS = 5,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_6_BITS = 6,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_7_BITS = 7

} ADCHS_INTERRUPT_BIT_SHIFT_LEFT;

typedef enum {

    ADCHS_DATA_RESOLUTION_6BIT = 0,
    ADCHS_DATA_RESOLUTION_8BIT = 1,
    ADCHS_DATA_RESOLUTION_10BIT = 2,
    ADCHS_DATA_RESOLUTION_12BIT = 3

} ADCHS_DATA_RESOLUTION;

typedef enum {

    ADCHS_SCAN_TRIGGER_SOURCE_NONE = 0,
    ADCHS_SCAN_TRIGGER_SOURCE_GLOBAL_SOFTWARE_EDGE = 1,
    ADCHS_SCAN_TRIGGER_SOURCE_SOFTWARE_LEVEL = 2,
    ADCHS_SCAN_TRIGGER_SOURCE_INT0 = 4,
    ADCHS_SCAN_TRIGGER_SOURCE_TMR1_MATCH = 5,
    ADCHS_SCAN_TRIGGER_SOURCE_TMR3_MATCH = 6,
    ADCHS_SCAN_TRIGGER_SOURCE_TMR5_MATCH = 7,
    ADCHS_SCAN_TRIGGER_SOURCE_OC1 = 8,
    ADCHS_SCAN_TRIGGER_SOURCE_OC3 = 9,
    ADCHS_SCAN_TRIGGER_SOURCE_OC5 = 10,
    ADCHS_SCAN_TRIGGER_SOURCE_COUT1 = 11,
    ADCHS_SCAN_TRIGGER_SOURCE_COUT2 = 12

} ADCHS_SCAN_TRIGGER_SOURCE;

typedef enum {

    ADCHS_CHARGEPUMP_DISABLE = 0,
    ADCHS_CHARGEPUMP_ENABLE = 1

} ADCHS_CHARGEPUMP_MODE;

typedef enum {

    ADCHS_FAST_SYNC_SYSTEM_CLOCK_DISABLE = 0,
    ADCHS_FAST_SYNC_SYSTEM_CLOCK_ENABLE = 1

} ADCHS_FAST_SYNC_SYSTEM_CLOCK;

typedef enum {

    ADCHS_FAST_SYNC_PERIPHERAL_CLOCK_DISABLE = 0,
    ADCHS_FAST_SYNC_PERIPHERAL_CLOCK_ENABLE = 1

} ADCHS_FAST_SYNC_PERIPHERAL_CLOCK;

typedef enum {

    ADCHS_OUTPUT_DATA_FORMAT_INTEGER = 0,
    ADCHS_OUTPUT_DATA_FORMAT_FRACTIONAL = 1

} ADCHS_OUTPUT_DATA_FORMAT;

typedef enum {

    ADCHS_DMA_BUFFER_LENGTH_NONE

} ADCHS_DMA_BUFFER_LENGTH;

typedef enum {

    ADCHS_DMA_COUNT_NONE

} ADCHS_DMA_COUNT;

typedef enum {

    ADCHS_CVD_CAPACITOR_0PF = 0,
    ADCHS_CVD_CAPACITOR_2_5PF = 1,
    ADCHS_CVD_CAPACITOR_5PF = 2,
    ADCHS_CVD_CAPACITOR_7_5PF = 3,
    ADCHS_CVD_CAPACITOR_10PF = 4,
    ADCHS_CVD_CAPACITOR_12_5PF = 5,
    ADCHS_CVD_CAPACITOR_15PF = 6,
    ADCHS_CVD_CAPACITOR_17_5PF = 7

} ADCHS_CVD_CAPACITOR;

typedef enum {

    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_1 = 0,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_2 = 1,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_3 = 2,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_4 = 3,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_5 = 4,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_6 = 5,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_7 = 6,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_8 = 7

} ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK;

typedef enum {

    ADCHS_CLOCK_SOURCE_PBCLK = 0,
    ADCHS_CLOCK_SOURCE_FRC = 1,
    ADCHS_CLOCK_SOURCE_RFCLK3 = 2,
    ADCHS_CLOCK_SOURCE_SYSCLK = 3

} ADCHS_CLOCK_SOURCE;

typedef enum {

    ADCHS_VREF_AVDD_AVSS = 0,
    ADCHS_VREF_EXTVREFP_AVSS = 1,
    ADCHS_VREF_AVDD_EXTVREFN = 2,
    ADCHS_VREF_EXTVREFP_EXTVREFN = 3,
    ADCHS_VREF_INTVREFP_INTVREFN = 4,
    ADCHS_VREF_INTVREFP_EXTVREFN = 5,
    ADCHS_VREF_INTVREFP_AVSS = 6,
    ADCHS_VREF_AVDD_INTVREFN = 7

} ADCHS_VREF_SOURCE;

typedef enum {

    ADCHS_CHANNEL_0 = 0,
    ADCHS_CHANNEL_1 = 1,
    ADCHS_CHANNEL_2 = 2,
    ADCHS_CHANNEL_3 = 3,
    ADCHS_CHANNEL_4 = 4,
    ADCHS_CHANNEL_7 = 7

} ADCHS_CHANNEL_ID;

typedef enum {

    ADCHS_CHANNEL_0_DEFAULT_INP_AN0 = 0,
    ADCHS_CHANNEL_1_DEFAULT_INP_AN1 = 4,
    ADCHS_CHANNEL_2_DEFAULT_INP_AN2 = 8,
    ADCHS_CHANNEL_3_DEFAULT_INP_AN3 = 12,
    ADCHS_CHANNEL_4_DEFAULT_INP_AN4 = 16,
    ADCHS_CHANNEL_0_ALTERNATE_INP_AN45 = 1,
    ADCHS_CHANNEL_1_ALTERNATE_INP_AN46 = 5,
    ADCHS_CHANNEL_2_ALTERNATE_INP_AN47 = 9,
    ADCHS_CHANNEL_3_ALTERNATE_INP_AN48 = 13,
    ADCHS_CHANNEL_4_ALTERNATE_INP_AN49 = 17

} ADCHS_CHANNEL_INP_SEL;

typedef enum {

    ADCHS_DEFAULT_CLASS1_AN0 = 0,
    ADCHS_ALTERNATE_CLASS1_AN45 = 1

} ADCHS_CHANNEL_0_INP_SEL;

typedef enum {

    ADCHS_DEFAULT_CLASS1_AN1 = 4,
    ADCHS_ALTERNATE_CLASS1_AN46 = 5

} ADCHS_CHANNEL_1_INP_SEL;

typedef enum {

    ADCHS_DEFAULT_CLASS1_AN2 = 8,
    ADCHS_ALTERNATE_CLASS1_AN47 = 9

} ADCHS_CHANNEL_2_INP_SEL;

typedef enum {

    ADCHS_DEFAULT_CLASS1_AN3 = 12,
    ADCHS_ALTERNATE_CLASS1_AN48 = 13

} ADCHS_CHANNEL_3_INP_SEL;

typedef enum {

    ADCHS_DEFAULT_CLASS1_AN4 = 16,
    ADCHS_ALTERNATE_CLASS1_AN49 = 17

} ADCHS_CHANNEL_4_INP_SEL;

typedef enum {

    ADCHS_CHANNEL_UNSYNC_TRIGGER_UNSYNC_SAMPLING = 0,
    ADCHS_CHANNEL_SYNC_SAMPLING = 1,
    ADCHS_CHANNEL_SYNC_TRIGGER_UNSYNC_SAMPLING = 2

} ADCHS_CHANNEL_TRIGGER_SAMPLING_SEL;

typedef enum {

    ADCHS_INPUT_MODE_SINGLE_ENDED_UNIPOLAR = 0,
    ADCHS_INPUT_MODE_SINGLE_ENDED_TWOS_COMP = 1,
    ADCHS_INPUT_MODE_DIFFERENTIAL_UNIPOLAR = 2,
    ADCHS_INPUT_MODE_DIFFERENTIAL_TWOS_COMP = 3

} ADCHS_INPUT_MODE;

typedef enum {

    ADCHS_DIGITAL_COMPARATOR_1 = 0,
    ADCHS_DIGITAL_COMPARATOR_2 = 1,
    ADCHS_DIGITAL_COMPARATOR_3 = 2,
    ADCHS_DIGITAL_COMPARATOR_4 = 3,
    ADCHS_DIGITAL_COMPARATOR_5 = 4,
    ADCHS_DIGITAL_COMPARATOR_6 = 5

} ADCHS_DIGITAL_COMPARATOR_ID;

typedef enum {

    ADCHS_DIGITAL_FILTER_1 = 0,
    ADCHS_DIGITAL_FILTER_2 = 1,
    ADCHS_DIGITAL_FILTER_3 = 2,
    ADCHS_DIGITAL_FILTER_4 = 3,
    ADCHS_DIGITAL_FILTER_5 = 4,
    ADCHS_DIGITAL_FILTER_6 = 5

} ADCHS_DIGITAL_FILTER_ID;

typedef enum {

    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_2X = 4,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_4X = 0,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_8X = 5,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_16X = 1,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_32X = 6,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_64X = 2,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_128X = 7,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_256X = 3

} ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO;

typedef enum {

    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_2 = 0,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_4 = 1,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_8 = 2,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_16 = 3,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_32 = 4,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_64 = 5,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_128 = 6,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_256 = 7

} ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT;

typedef enum {

    ADCHS_DIGITAL_FILTER_SIGNIFICANT_FIRST_12BITS = 0,
    ADCHS_DIGITAL_FILTER_SIGNIFICANT_ALL_16BITS = 1

} ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS;

typedef enum {

    ADCHS_SCAN_TRIGGER_SENSITIVE_EDGE = 0,
    ADCHS_SCAN_TRIGGER_SENSITIVE_LEVEL = 1

} ADCHS_SCAN_TRIGGER_SENSITIVE;

typedef enum {

    ADCHS_WARMUP_CLOCK_16 = 0,
    ADCHS_WARMUP_CLOCK_32 = 5,
    ADCHS_WARMUP_CLOCK_64 = 6,
    ADCHS_WARMUP_CLOCK_128 = 7,
    ADCHS_WARMUP_CLOCK_256 = 8,
    ADCHS_WARMUP_CLOCK_512 = 9,
    ADCHS_WARMUP_CLOCK_1024 = 10,
    ADCHS_WARMUP_CLOCK_2048 = 11,
    ADCHS_WARMUP_CLOCK_4096 = 12,
    ADCHS_WARMUP_CLOCK_8192 = 13,
    ADCHS_WARMUP_CLOCK_16384 = 14,
    ADCHS_WARMUP_CLOCK_32768 = 15

} ADCHS_WARMUP_CLOCK;

typedef enum {

    ADCHS_TRIGGER_SOURCE_NONE = 0,
    ADCHS_TRIGGER_SOURCE_GLOBAL_SOFTWARE_EDGE = 1,
    ADCHS_TRIGGER_SOURCE_SOFTWARE_LEVEL = 2,
    ADCHS_TRIGGER_SOURCE_SCAN = 3,
    ADCHS_TRIGGER_SOURCE_INT0 = 4,
    ADCHS_TRIGGER_SOURCE_TMR1_MATCH = 5,
    ADCHS_TRIGGER_SOURCE_TMR3_MATCH = 6,
    ADCHS_TRIGGER_SOURCE_TMR5_MATCH = 7,
    ADCHS_TRIGGER_SOURCE_OC1 = 8,
    ADCHS_TRIGGER_SOURCE_OC3 = 9,
    ADCHS_TRIGGER_SOURCE_OC5 = 10,
    ADCHS_TRIGGER_SOURCE_COUT1 = 11,
    ADCHS_TRIGGER_SOURCE_COUT2 = 12

} ADCHS_TRIGGER_SOURCE;

PLIB_INLINE SFR_TYPE* _ADCHS_TURBO_MODE_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_TURBO_MODE_ERROR_CHECK_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_TURBO_MODE_MASTER_CHANNEL_SELECT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_TURBO_MODE_SLAVE_CHANNEL_SELECT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_FRACTIONAL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_7_RESOLUTION_SELECTION_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_SCAN_TRIGGER_SOURCE_SELECT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_IDLE_MODE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHARGE_PUMP_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CVD_MODE_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_FAST_SYNC_SYS_CLK_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_FAST_SYNC_PERIPH_CLK_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_VECTOR_SHIFT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_SCAN_TRG_LEVEL_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CONTROL_REG_1_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_VREF_READY_CHECK_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_VREF_FAULT_CHECK_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_SCAN_COMPLETE_CHECK_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CVD_CAP_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_7_SAMPLE_TIME_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_VREF_READY_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_VREF_FAULT_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_SCAN_COMPLETE_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_EARLY_INT_OVERRIDE_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_7_EARLY_INTERRUPT_SELECTION_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_7_CLOCK_DIVISOR_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CONTROL_REG_2_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CLOCK_SOURCE_SELECT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CONTROL_CLK_DIVISOR_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_7_DIGITAL_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_4_DIGITAL_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_3_DIGITAL_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_2_DIGITAL_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_1_DIGITAL_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_0_DIGITAL_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_VREF_SOURCE_SELECTION_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_TRIGGER_SUSPEND_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_UPDATE_READY_INTRRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_UPDATE_READY_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_SAMPLE_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_REQUEST_TO_CONVERT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_GLOBAL_LEVEL_SOFT_TRIGGER_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_GLOBAL_SOFT_TRIGGER_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_MANUAL_ANALOG_INPUT_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CONTROL_REG_3_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_4_ALT_INPUT_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_3_ALT_INPUT_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_2_ALT_INPUT_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_1_ALT_INPUT_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_0_ALT_INPUT_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_4_PRESYNC_TRG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_3_PRESYNC_TRG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_2_PRESYNC_TRG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_1_PRESYNC_TRG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_0_PRESYNC_TRG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_4_SYNC_SAMP_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_3_SYNC_SAMP_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_2_SYNC_SAMP_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_1_SYNC_SAMP_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_0_SYNC_SAMP_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_TRIGGER_MODE_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGMODE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_INPUT_MODE_CON_REG_1_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCIMCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_INPUT_MODE_CON_REG_2_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCIMCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_GLOBAL_INT_EN_REG_1_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCGIRQEN1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_GLOBAL_INT_EN_REG_2_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCGIRQEN2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_SCAN_SELECT_REG_1_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCSS1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_SCAN_SELECT_REG_2_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCSS2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DATA_RDY_STATUS_1_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDSTAT1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DATA_RDY_STATUS_2_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDSTAT2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_AN_INPUT_REG_1_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPEN1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_AN_INPUT_REG_2_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPEN2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_AN_INPUT_REG_3_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPEN3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_AN_INPUT_REG_4_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPEN4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_AN_INPUT_REG_5_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPEN5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_AN_INPUT_REG_6_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPEN6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_LIMIT_REG_1_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMP1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_LIMIT_REG_2_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMP2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_LIMIT_REG_3_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMP3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_LIMIT_REG_4_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMP4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_LIMIT_REG_5_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMP5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_LIMIT_REG_6_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMP6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_1_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_1_SIGNIFICANT_BIT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_1_MODE_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_1_DATA_READY_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_1_ANALOG_INPUT_ID_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_1_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_REG_1_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_2_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_2_SIGNIFICANT_BIT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_2_MODE_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_2_RATIO_SELECT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_2_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_2_DATA_READY_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_2_ANALOG_INPUT_ID_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_2_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_REG_2_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_3_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_3_SIGNIFICANT_BIT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_3_MODE_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_3_RATIO_SELECT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_3_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_3_DATA_READY_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_3_ANALOG_INPUT_ID_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_3_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_REG_3_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_4_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_4_SIGNIFICANT_BIT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_4_MODE_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_4_RATIO_SELECT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_4_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_4_DATA_READY_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_4_ANALOG_INPUT_ID_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_4_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_REG_4_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_5_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_5_SIGNIFICANT_BIT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_5_MODE_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_5_RATIO_SELECT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_5_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_5_DATA_READY_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_5_ANALOG_INPUT_ID_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_5_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_REG_5_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_6_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_6_SIGNIFICANT_BIT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_6_MODE_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_6_RATIO_SELECT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_6_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_6_DATA_READY_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_6_ANALOG_INPUT_ID_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_6_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_DIGITAL_FILTER_REG_6_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFLTR6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_3_TRIGGER_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRG1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_2_TRIGGER_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRG1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_1_TRIGGER_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRG1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_0_TRIGGER_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRG1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_TRIGGER_CONTROL_BASE_ADDRESS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRG1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_7_TRIGGER_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRG2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_6_TRIGGER_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRG2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_5_TRIGGER_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRG2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_4_TRIGGER_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRG2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_11_TRIGGER_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRG3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_10_TRIGGER_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRG3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_9_TRIGGER_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRG3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_8_TRIGGER_SEL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRG3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CVD_RESULT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_1_ANALOG_INPUT_ID_GET_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_1_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_1_EVENT_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_CONTROL_REG_1_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_2_ANALOG_INPUT_ID_GET_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_2_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_2_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_2_EVENT_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_CONTROL_REG_2_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_3_ANALOG_INPUT_ID_GET_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_3_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_3_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_3_EVENT_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_CONTROL_REG_3_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_4_ANALOG_INPUT_ID_GET_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_4_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_4_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_4_EVENT_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_CONTROL_REG_4_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_5_ANALOG_INPUT_ID_GET_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_5_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_5_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_5_EVENT_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_CONTROL_REG_5_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_6_ANALOG_INPUT_ID_GET_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_6_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_6_INTERRUPT_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_6_EVENT_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_COMPARATOR_CONTROL_REG_6_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCCMPCON6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_FIFO_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFSTAT;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ADC4_FIFO_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFSTAT;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ADC3_FIFO_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFSTAT;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ADC2_FIFO_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFSTAT;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ADC1_FIFO_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFSTAT;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ADC0_FIFO_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFSTAT;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_FIFO_INTERRUPT_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFSTAT;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_FIFO_DATA_READY_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFSTAT;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_FIFO_OVERWRT_ERROR_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFSTAT;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_FIFO_COUNT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFSTAT;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_FIFO_SIGN_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFSTAT;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ADC_CHANNEL_ID_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFSTAT;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_FIFO_STAT_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFSTAT;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_FIFO_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCFIFO;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ADCBASE_BASE_ADDR_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCBASE;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_0_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CONVERSION_RESULT_BASE_ADDRESS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_1_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_2_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_3_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA3;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_4_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA4;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_5_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA5;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_6_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA6;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_7_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA7;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_8_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA8;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_9_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA9;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_10_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA10;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_11_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA11;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_12_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA12;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_13_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA13;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_14_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA14;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_15_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA15;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_16_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA16;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_17_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA17;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_18_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA18;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_43_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA43;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_INPUT_44_CONVERTED_DATA_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCDATA44;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_TRIG_SENSITIVE_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCTRGSNS;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_0_EARLY_INTERRUPT_SELECTION_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC0TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_0_RESOLUTION_SELECTION_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC0TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_0_CLOCK_DIVISOR_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC0TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_0_SAMPLE_TIME_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC0TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ADC_0_TIME_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC0TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_1_EARLY_INTERRUPT_SELECTION_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC1TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_1_RESOLUTION_SELECTION_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC1TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_1_CLOCK_DIVISOR_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC1TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_1_SAMPLE_TIME_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC1TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ADC_1_TIME_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC1TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_2_EARLY_INTERRUPT_SELECTION_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC2TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_2_RESOLUTION_SELECTION_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC2TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_2_CLOCK_DIVISOR_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC2TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_2_SAMPLE_TIME_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC2TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ADC_2_TIME_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC2TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_3_EARLY_INTERRUPT_SELECTION_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC3TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_3_RESOLUTION_SELECTION_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC3TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_3_CLOCK_DIVISOR_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC3TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_3_SAMPLE_TIME_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC3TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ADC_3_TIME_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC3TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_4_EARLY_INTERRUPT_SELECTION_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC4TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_4_RESOLUTION_SELECTION_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC4TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_4_CLOCK_DIVISOR_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC4TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_4_SAMPLE_TIME_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC4TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ADC_4_TIME_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC4TIME;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_EARLY_INTERRUPT_REG_1_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCEIEN1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_EARLY_INTERRUPT_REG_2_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCEIEN2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_EARLY_INTERRUPT_STATUS_REG_1_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCEISTAT1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_EARLY_INTERRUPT_STATUS_REG_2_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCEISTAT2;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_WARM_UP_COUNT_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_7_WARM_UP_INTERRUPT_ENABLE_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_4_WARM_UP_INTERRUPT_ENABLE_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_3_WARM_UP_INTERRUPT_ENABLE_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_2_WARM_UP_INTERRUPT_ENABLE_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_1_WARM_UP_INTERRUPT_ENABLE_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_0_WARM_UP_INTERRUPT_ENABLE_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_7_WARMP_UP_READY_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_4_WARMP_UP_READY_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_3_WARMP_UP_READY_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_2_WARMP_UP_READY_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_1_WARMP_UP_READY_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_0_WARMP_UP_READY_STATUS_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_7_ANALOG_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_4_ANALOG_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_3_ANALOG_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_2_ANALOG_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_1_ANALOG_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_0_ANALOG_ENABLE_CONTROL_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_ANALOG_CONTROL_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCANCON;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_0_CONFIG_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC0CFG;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_1_CONFIG_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC1CFG;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_2_CONFIG_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC2CFG;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_3_CONFIG_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC3CFG;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_4_CONFIG_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC4CFG;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_CHANNEL_7_CONFIG_REG_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADC7CFG;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_INPUT_CHECK_REG_0_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCSYSCFG0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _ADCHS_INPUT_CHECK_REG_1_VREG(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return &ADCSYSCFG1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TURBO_MODE_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_TRBEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TURBO_MODE_ERROR_CHECK_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_TRBERR_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TURBO_MODE_MASTER_CHANNEL_SELECT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_TRBMST_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TURBO_MODE_SLAVE_CHANNEL_SELECT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_TRBSLV_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FRACTIONAL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_FRACT_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_RESOLUTION_SELECTION_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_SELRES_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_TRIGGER_SOURCE_SELECT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_STRGSRC_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_ON_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_IDLE_MODE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_SIDL_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHARGE_PUMP_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_AICPMPEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CVD_MODE_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_CVDEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FAST_SYNC_SYS_CLK_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_FSSCLKEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FAST_SYNC_PERIPH_CLK_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_FSPBCLKEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VECTOR_SHIFT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_IRQVS_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_TRG_LEVEL_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_STRGLVL_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONTROL_REG_1_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_READY_CHECK_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_BGVRRDY_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_FAULT_CHECK_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_REFFLT_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_COMPLETE_CHECK_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_EOSRDY_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CVD_CAP_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_CVDCPL_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_SAMPLE_TIME_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_SAMC_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_READY_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_BGVRIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_FAULT_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_REFFLTIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_COMPLETE_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_EOSIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INT_OVERRIDE_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_ADCEIOVR_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_EARLY_INTERRUPT_SELECTION_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_ADCEIS_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_CLOCK_DIVISOR_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_ADCDIV_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONTROL_REG_2_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CLOCK_SOURCE_SELECT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_ADCSEL_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONTROL_CLK_DIVISOR_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_CONCLKDIV_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_DIGITAL_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN7_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_DIGITAL_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN4_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_DIGITAL_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN3_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_DIGITAL_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN2_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_DIGITAL_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN1_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_DIGITAL_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN0_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_SOURCE_SELECTION_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_VREFSEL_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TRIGGER_SUSPEND_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_TRGSUSP_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_UPDATE_READY_INTRRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_UPDIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_UPDATE_READY_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_UPDRDY_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SAMPLE_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_SAMP_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_REQUEST_TO_CONVERT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_RQCNVRT_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_GLOBAL_LEVEL_SOFT_TRIGGER_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_GLSWTRG_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_GLOBAL_SOFT_TRIGGER_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_GSWTRG_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_MANUAL_ANALOG_INPUT_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_ADINSEL_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONTROL_REG_3_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_ALT_INPUT_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH4ALT_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_ALT_INPUT_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH3ALT_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_ALT_INPUT_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH2ALT_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_ALT_INPUT_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH1ALT_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_ALT_INPUT_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH0ALT_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_PRESYNC_TRG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN4_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_PRESYNC_TRG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN3_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_PRESYNC_TRG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN2_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_PRESYNC_TRG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN1_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_PRESYNC_TRG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN0_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_SYNC_SAMP_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN4_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_SYNC_SAMP_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN3_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_SYNC_SAMP_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN2_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_SYNC_SAMP_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN1_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_SYNC_SAMP_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN0_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TRIGGER_MODE_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_INPUT_MODE_CON_REG_1_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_INPUT_MODE_CON_REG_2_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_GLOBAL_INT_EN_REG_1_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_GLOBAL_INT_EN_REG_2_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_SELECT_REG_1_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_SELECT_REG_2_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DATA_RDY_STATUS_1_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DATA_RDY_STATUS_2_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_1_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_2_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_3_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_4_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_5_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_6_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_1_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_2_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_3_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_4_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_5_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_6_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_AFEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_SIGNIFICANT_BIT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_DATA16EN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_MODE_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_DFMODE_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_OVRSAM_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_AFGIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_DATA_READY_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_AFRDY_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_ANALOG_INPUT_ID_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_CHNLID_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_FLTRDATA_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_1_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_AFEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_SIGNIFICANT_BIT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_DATA16EN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_MODE_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_DFMODE_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_RATIO_SELECT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_OVRSAM_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_AFGIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_DATA_READY_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_AFRDY_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_ANALOG_INPUT_ID_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_CHNLID_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_FLTRDATA_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_2_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_AFEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_SIGNIFICANT_BIT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_DATA16EN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_MODE_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_DFMODE_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_RATIO_SELECT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_OVRSAM_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_AFGIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_DATA_READY_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_AFRDY_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_ANALOG_INPUT_ID_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_CHNLID_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_FLTRDATA_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_3_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_AFEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_SIGNIFICANT_BIT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_DATA16EN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_MODE_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_DFMODE_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_RATIO_SELECT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_OVRSAM_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_AFGIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_DATA_READY_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_AFRDY_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_ANALOG_INPUT_ID_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_CHNLID_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_FLTRDATA_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_4_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_AFEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_SIGNIFICANT_BIT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_DATA16EN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_MODE_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_DFMODE_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_RATIO_SELECT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_OVRSAM_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_AFGIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_DATA_READY_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_AFRDY_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_ANALOG_INPUT_ID_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_CHNLID_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_FLTRDATA_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_5_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_AFEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_SIGNIFICANT_BIT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_DATA16EN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_MODE_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_DFMODE_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_RATIO_SELECT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_OVRSAM_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_AFGIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_DATA_READY_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_AFRDY_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_ANALOG_INPUT_ID_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_CHNLID_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_FLTRDATA_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_6_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_3_TRIGGER_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG1_TRGSRC3_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_2_TRIGGER_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG1_TRGSRC2_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_1_TRIGGER_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG1_TRGSRC1_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_0_TRIGGER_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG1_TRGSRC0_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TRIGGER_CONTROL_BASE_ADDRESS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_7_TRIGGER_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG2_TRGSRC7_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_6_TRIGGER_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG2_TRGSRC6_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_5_TRIGGER_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG2_TRGSRC5_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_4_TRIGGER_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG2_TRGSRC4_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_11_TRIGGER_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG3_TRGSRC11_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_10_TRIGGER_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG3_TRGSRC10_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_9_TRIGGER_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG3_TRGSRC9_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_8_TRIGGER_SEL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG3_TRGSRC8_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CVD_RESULT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_CVDDATA_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_1_ANALOG_INPUT_ID_GET_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_AINID_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_1_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_ENDCMP_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_DCMPGIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_1_EVENT_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_DCMPED_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_1_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_2_ANALOG_INPUT_ID_GET_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON2_AINID_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_2_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON2_ENDCMP_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_2_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON2_DCMPGIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_2_EVENT_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON2_DCMPED_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_2_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_3_ANALOG_INPUT_ID_GET_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON3_AINID_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_3_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON3_ENDCMP_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_3_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON3_DCMPGIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_3_EVENT_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON3_DCMPED_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_3_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_4_ANALOG_INPUT_ID_GET_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON4_AINID_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_4_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON4_ENDCMP_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_4_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON4_DCMPGIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_4_EVENT_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON4_DCMPED_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_4_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_5_ANALOG_INPUT_ID_GET_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON5_AINID_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_5_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON5_ENDCMP_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_5_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON5_DCMPGIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_5_EVENT_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON5_DCMPED_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_5_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_6_ANALOG_INPUT_ID_GET_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON6_AINID_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_6_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON6_ENDCMP_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_6_INTERRUPT_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON6_DCMPGIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_6_EVENT_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON6_DCMPED_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_6_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC4_FIFO_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC4EN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC3_FIFO_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC3EN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC2_FIFO_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC2EN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC1_FIFO_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC1EN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC0_FIFO_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC0EN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_INTERRUPT_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FIEN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_DATA_READY_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FRDY_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_OVERWRT_ERROR_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FWROVERR_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_COUNT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FCNT_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_SIGN_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FSIGN_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_CHANNEL_ID_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADCID_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_STAT_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADCBASE_BASE_ADDR_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_0_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONVERSION_RESULT_BASE_ADDRESS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_1_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_2_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_3_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_4_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_5_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_6_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_7_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_8_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_9_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_10_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_11_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_12_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_13_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_14_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_15_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_16_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_17_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_18_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_43_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_44_CONVERTED_DATA_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TRIG_SENSITIVE_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_EARLY_INTERRUPT_SELECTION_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC0TIME_ADCEIS_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_RESOLUTION_SELECTION_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC0TIME_SELRES_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_CLOCK_DIVISOR_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC0TIME_ADCDIV_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_SAMPLE_TIME_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC0TIME_SAMC_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_0_TIME_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_EARLY_INTERRUPT_SELECTION_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC1TIME_ADCEIS_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_RESOLUTION_SELECTION_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC1TIME_SELRES_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_CLOCK_DIVISOR_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC1TIME_ADCDIV_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_SAMPLE_TIME_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC1TIME_SAMC_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_1_TIME_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_EARLY_INTERRUPT_SELECTION_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC2TIME_ADCEIS_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_RESOLUTION_SELECTION_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC2TIME_SELRES_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_CLOCK_DIVISOR_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC2TIME_ADCDIV_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_SAMPLE_TIME_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC2TIME_SAMC_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_2_TIME_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_EARLY_INTERRUPT_SELECTION_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC3TIME_ADCEIS_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_RESOLUTION_SELECTION_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC3TIME_SELRES_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_CLOCK_DIVISOR_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC3TIME_ADCDIV_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_SAMPLE_TIME_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC3TIME_SAMC_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_3_TIME_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_EARLY_INTERRUPT_SELECTION_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC4TIME_ADCEIS_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_RESOLUTION_SELECTION_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC4TIME_SELRES_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_CLOCK_DIVISOR_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC4TIME_ADCDIV_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_SAMPLE_TIME_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC4TIME_SAMC_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_4_TIME_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INTERRUPT_REG_1_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INTERRUPT_REG_2_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INTERRUPT_STATUS_REG_1_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INTERRUPT_STATUS_REG_2_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_WARM_UP_COUNT_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKUPCLKCNT_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_WARM_UP_INTERRUPT_ENABLE_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN7_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_WARM_UP_INTERRUPT_ENABLE_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN4_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_WARM_UP_INTERRUPT_ENABLE_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN3_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_WARM_UP_INTERRUPT_ENABLE_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN2_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_WARM_UP_INTERRUPT_ENABLE_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN1_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_WARM_UP_INTERRUPT_ENABLE_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN0_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_WARMP_UP_READY_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY7_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_WARMP_UP_READY_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY4_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_WARMP_UP_READY_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY3_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_WARMP_UP_READY_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY2_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_WARMP_UP_READY_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY1_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_WARMP_UP_READY_STATUS_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY0_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_ANALOG_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN7_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_ANALOG_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN4_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_ANALOG_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN3_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_ANALOG_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN2_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_ANALOG_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN1_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_ANALOG_ENABLE_CONTROL_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN0_MASK;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_CONTROL_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_CONFIG_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_CONFIG_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_CONFIG_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_CONFIG_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_CONFIG_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_CONFIG_REG_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_INPUT_CHECK_REG_0_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_INPUT_CHECK_REG_1_MASK(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)-1;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TURBO_MODE_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_TRBEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TURBO_MODE_ERROR_CHECK_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_TRBERR_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TURBO_MODE_MASTER_CHANNEL_SELECT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_TRBMST_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TURBO_MODE_SLAVE_CHANNEL_SELECT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_TRBSLV_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FRACTIONAL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_FRACT_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_RESOLUTION_SELECTION_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_SELRES_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_TRIGGER_SOURCE_SELECT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_STRGSRC_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_ON_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_IDLE_MODE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_SIDL_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHARGE_PUMP_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_AICPMPEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CVD_MODE_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_CVDEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FAST_SYNC_SYS_CLK_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_FSSCLKEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FAST_SYNC_PERIPH_CLK_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_FSPBCLKEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VECTOR_SHIFT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_IRQVS_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_TRG_LEVEL_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_STRGLVL_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONTROL_REG_1_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_READY_CHECK_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_BGVRRDY_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_FAULT_CHECK_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_REFFLT_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_COMPLETE_CHECK_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_EOSRDY_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CVD_CAP_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_CVDCPL_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_SAMPLE_TIME_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_SAMC_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_READY_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_BGVRIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_FAULT_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_REFFLTIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_COMPLETE_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_EOSIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INT_OVERRIDE_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_ADCEIOVR_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_EARLY_INTERRUPT_SELECTION_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_ADCEIS_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_CLOCK_DIVISOR_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_ADCDIV_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONTROL_REG_2_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CLOCK_SOURCE_SELECT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_ADCSEL_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONTROL_CLK_DIVISOR_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_CONCLKDIV_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_DIGITAL_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN7_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_DIGITAL_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN4_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_DIGITAL_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN3_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_DIGITAL_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN2_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_DIGITAL_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN1_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_DIGITAL_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN0_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_SOURCE_SELECTION_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_VREFSEL_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TRIGGER_SUSPEND_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_TRGSUSP_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_UPDATE_READY_INTRRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_UPDIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_UPDATE_READY_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_UPDRDY_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SAMPLE_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_SAMP_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_REQUEST_TO_CONVERT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_RQCNVRT_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_GLOBAL_LEVEL_SOFT_TRIGGER_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_GLSWTRG_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_GLOBAL_SOFT_TRIGGER_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_GSWTRG_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_MANUAL_ANALOG_INPUT_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_ADINSEL_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONTROL_REG_3_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_ALT_INPUT_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH4ALT_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_ALT_INPUT_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH3ALT_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_ALT_INPUT_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH2ALT_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_ALT_INPUT_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH1ALT_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_ALT_INPUT_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH0ALT_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_PRESYNC_TRG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN4_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_PRESYNC_TRG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN3_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_PRESYNC_TRG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN2_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_PRESYNC_TRG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN1_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_PRESYNC_TRG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN0_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_SYNC_SAMP_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN4_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_SYNC_SAMP_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN3_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_SYNC_SAMP_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN2_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_SYNC_SAMP_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN1_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_SYNC_SAMP_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN0_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TRIGGER_MODE_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_INPUT_MODE_CON_REG_1_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_INPUT_MODE_CON_REG_2_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_GLOBAL_INT_EN_REG_1_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_GLOBAL_INT_EN_REG_2_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_SELECT_REG_1_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_SELECT_REG_2_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DATA_RDY_STATUS_1_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DATA_RDY_STATUS_2_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_1_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_2_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_3_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_4_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_5_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_6_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_1_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_2_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_3_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_4_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_5_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_6_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_AFEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_SIGNIFICANT_BIT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_DATA16EN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_MODE_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_DFMODE_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_OVRSAM_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_AFGIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_DATA_READY_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_AFRDY_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_ANALOG_INPUT_ID_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_CHNLID_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_FLTRDATA_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_1_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_AFEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_SIGNIFICANT_BIT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_DATA16EN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_MODE_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_DFMODE_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_RATIO_SELECT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_OVRSAM_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_AFGIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_DATA_READY_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_AFRDY_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_ANALOG_INPUT_ID_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_CHNLID_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_FLTRDATA_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_2_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_AFEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_SIGNIFICANT_BIT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_DATA16EN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_MODE_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_DFMODE_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_RATIO_SELECT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_OVRSAM_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_AFGIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_DATA_READY_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_AFRDY_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_ANALOG_INPUT_ID_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_CHNLID_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_FLTRDATA_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_3_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_AFEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_SIGNIFICANT_BIT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_DATA16EN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_MODE_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_DFMODE_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_RATIO_SELECT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_OVRSAM_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_AFGIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_DATA_READY_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_AFRDY_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_ANALOG_INPUT_ID_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_CHNLID_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_FLTRDATA_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_4_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_AFEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_SIGNIFICANT_BIT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_DATA16EN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_MODE_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_DFMODE_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_RATIO_SELECT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_OVRSAM_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_AFGIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_DATA_READY_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_AFRDY_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_ANALOG_INPUT_ID_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_CHNLID_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_FLTRDATA_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_5_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_AFEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_SIGNIFICANT_BIT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_DATA16EN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_MODE_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_DFMODE_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_RATIO_SELECT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_OVRSAM_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_AFGIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_DATA_READY_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_AFRDY_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_ANALOG_INPUT_ID_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_CHNLID_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_FLTRDATA_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_6_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_3_TRIGGER_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG1_TRGSRC3_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_2_TRIGGER_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG1_TRGSRC2_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_1_TRIGGER_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG1_TRGSRC1_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_0_TRIGGER_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG1_TRGSRC0_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TRIGGER_CONTROL_BASE_ADDRESS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_7_TRIGGER_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG2_TRGSRC7_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_6_TRIGGER_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG2_TRGSRC6_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_5_TRIGGER_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG2_TRGSRC5_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_4_TRIGGER_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG2_TRGSRC4_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_11_TRIGGER_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG3_TRGSRC11_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_10_TRIGGER_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG3_TRGSRC10_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_9_TRIGGER_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG3_TRGSRC9_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_8_TRIGGER_SEL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG3_TRGSRC8_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CVD_RESULT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_CVDDATA_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_1_ANALOG_INPUT_ID_GET_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_AINID_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_1_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_ENDCMP_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_DCMPGIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_1_EVENT_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_DCMPED_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_1_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_2_ANALOG_INPUT_ID_GET_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON2_AINID_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_2_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON2_ENDCMP_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_2_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON2_DCMPGIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_2_EVENT_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON2_DCMPED_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_2_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_3_ANALOG_INPUT_ID_GET_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON3_AINID_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_3_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON3_ENDCMP_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_3_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON3_DCMPGIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_3_EVENT_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON3_DCMPED_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_3_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_4_ANALOG_INPUT_ID_GET_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON4_AINID_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_4_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON4_ENDCMP_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_4_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON4_DCMPGIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_4_EVENT_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON4_DCMPED_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_4_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_5_ANALOG_INPUT_ID_GET_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON5_AINID_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_5_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON5_ENDCMP_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_5_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON5_DCMPGIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_5_EVENT_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON5_DCMPED_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_5_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_6_ANALOG_INPUT_ID_GET_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON6_AINID_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_6_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON6_ENDCMP_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_6_INTERRUPT_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON6_DCMPGIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_6_EVENT_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON6_DCMPED_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_6_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC4_FIFO_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC4EN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC3_FIFO_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC3EN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC2_FIFO_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC2EN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC1_FIFO_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC1EN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC0_FIFO_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC0EN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_INTERRUPT_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FIEN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_DATA_READY_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FRDY_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_OVERWRT_ERROR_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FWROVERR_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_COUNT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FCNT_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_SIGN_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FSIGN_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_CHANNEL_ID_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADCID_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_STAT_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADCBASE_BASE_ADDR_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_0_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONVERSION_RESULT_BASE_ADDRESS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_1_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_2_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_3_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_4_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_5_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_6_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_7_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_8_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_9_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_10_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_11_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_12_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_13_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_14_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_15_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_16_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_17_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_18_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_43_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_44_CONVERTED_DATA_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TRIG_SENSITIVE_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_EARLY_INTERRUPT_SELECTION_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC0TIME_ADCEIS_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_RESOLUTION_SELECTION_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC0TIME_SELRES_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_CLOCK_DIVISOR_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC0TIME_ADCDIV_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_SAMPLE_TIME_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC0TIME_SAMC_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_0_TIME_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_EARLY_INTERRUPT_SELECTION_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC1TIME_ADCEIS_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_RESOLUTION_SELECTION_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC1TIME_SELRES_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_CLOCK_DIVISOR_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC1TIME_ADCDIV_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_SAMPLE_TIME_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC1TIME_SAMC_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_1_TIME_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_EARLY_INTERRUPT_SELECTION_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC2TIME_ADCEIS_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_RESOLUTION_SELECTION_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC2TIME_SELRES_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_CLOCK_DIVISOR_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC2TIME_ADCDIV_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_SAMPLE_TIME_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC2TIME_SAMC_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_2_TIME_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_EARLY_INTERRUPT_SELECTION_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC3TIME_ADCEIS_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_RESOLUTION_SELECTION_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC3TIME_SELRES_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_CLOCK_DIVISOR_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC3TIME_ADCDIV_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_SAMPLE_TIME_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC3TIME_SAMC_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_3_TIME_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_EARLY_INTERRUPT_SELECTION_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC4TIME_ADCEIS_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_RESOLUTION_SELECTION_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC4TIME_SELRES_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_CLOCK_DIVISOR_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC4TIME_ADCDIV_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_SAMPLE_TIME_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC4TIME_SAMC_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_4_TIME_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INTERRUPT_REG_1_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INTERRUPT_REG_2_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INTERRUPT_STATUS_REG_1_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INTERRUPT_STATUS_REG_2_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_WARM_UP_COUNT_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKUPCLKCNT_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_WARM_UP_INTERRUPT_ENABLE_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN7_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_WARM_UP_INTERRUPT_ENABLE_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN4_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_WARM_UP_INTERRUPT_ENABLE_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN3_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_WARM_UP_INTERRUPT_ENABLE_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN2_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_WARM_UP_INTERRUPT_ENABLE_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN1_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_WARM_UP_INTERRUPT_ENABLE_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN0_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_WARMP_UP_READY_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY7_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_WARMP_UP_READY_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY4_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_WARMP_UP_READY_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY3_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_WARMP_UP_READY_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY2_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_WARMP_UP_READY_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY1_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_WARMP_UP_READY_STATUS_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY0_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_ANALOG_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN7_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_ANALOG_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN4_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_ANALOG_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN3_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_ANALOG_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN2_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_ANALOG_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN1_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_ANALOG_ENABLE_CONTROL_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN0_POSITION;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_CONTROL_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_CONFIG_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_CONFIG_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_CONFIG_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_CONFIG_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_CONFIG_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_CONFIG_REG_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_INPUT_CHECK_REG_0_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_INPUT_CHECK_REG_1_POS(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)0;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TURBO_MODE_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_TRBEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TURBO_MODE_ERROR_CHECK_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_TRBERR_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TURBO_MODE_MASTER_CHANNEL_SELECT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_TRBMST_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TURBO_MODE_SLAVE_CHANNEL_SELECT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_TRBSLV_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FRACTIONAL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_FRACT_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_RESOLUTION_SELECTION_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_SELRES_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_TRIGGER_SOURCE_SELECT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_STRGSRC_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_ON_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_IDLE_MODE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_SIDL_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHARGE_PUMP_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_AICPMPEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CVD_MODE_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_CVDEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FAST_SYNC_SYS_CLK_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_FSSCLKEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FAST_SYNC_PERIPH_CLK_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_FSPBCLKEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VECTOR_SHIFT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_IRQVS_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_TRG_LEVEL_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON1_STRGLVL_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONTROL_REG_1_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_READY_CHECK_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_BGVRRDY_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_FAULT_CHECK_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_REFFLT_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_COMPLETE_CHECK_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_EOSRDY_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CVD_CAP_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_CVDCPL_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_SAMPLE_TIME_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_SAMC_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_READY_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_BGVRIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_FAULT_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_REFFLTIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_COMPLETE_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_EOSIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INT_OVERRIDE_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_ADCEIOVR_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_EARLY_INTERRUPT_SELECTION_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_ADCEIS_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_CLOCK_DIVISOR_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON2_ADCDIV_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONTROL_REG_2_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CLOCK_SOURCE_SELECT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_ADCSEL_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONTROL_CLK_DIVISOR_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_CONCLKDIV_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_DIGITAL_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN7_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_DIGITAL_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN4_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_DIGITAL_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN3_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_DIGITAL_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN2_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_DIGITAL_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN1_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_DIGITAL_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_DIGEN0_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_VREF_SOURCE_SELECTION_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_VREFSEL_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TRIGGER_SUSPEND_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_TRGSUSP_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_UPDATE_READY_INTRRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_UPDIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_UPDATE_READY_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_UPDRDY_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SAMPLE_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_SAMP_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_REQUEST_TO_CONVERT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_RQCNVRT_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_GLOBAL_LEVEL_SOFT_TRIGGER_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_GLSWTRG_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_GLOBAL_SOFT_TRIGGER_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_GSWTRG_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_MANUAL_ANALOG_INPUT_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCON3_ADINSEL_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONTROL_REG_3_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_ALT_INPUT_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH4ALT_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_ALT_INPUT_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH3ALT_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_ALT_INPUT_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH2ALT_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_ALT_INPUT_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH1ALT_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_ALT_INPUT_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SH0ALT_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_PRESYNC_TRG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN4_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_PRESYNC_TRG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN3_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_PRESYNC_TRG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN2_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_PRESYNC_TRG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN1_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_PRESYNC_TRG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_STRGEN0_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_SYNC_SAMP_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN4_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_SYNC_SAMP_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN3_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_SYNC_SAMP_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN2_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_SYNC_SAMP_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN1_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_SYNC_SAMP_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRGMODE_SSAMPEN0_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TRIGGER_MODE_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_INPUT_MODE_CON_REG_1_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_INPUT_MODE_CON_REG_2_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_GLOBAL_INT_EN_REG_1_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_GLOBAL_INT_EN_REG_2_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_SELECT_REG_1_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_SCAN_SELECT_REG_2_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DATA_RDY_STATUS_1_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DATA_RDY_STATUS_2_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_1_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_2_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_3_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_4_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_5_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_AN_INPUT_REG_6_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_1_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_2_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_3_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_4_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_5_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_LIMIT_REG_6_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_AFEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_SIGNIFICANT_BIT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_DATA16EN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_MODE_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_DFMODE_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_OVRSAM_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_AFGIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_DATA_READY_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_AFRDY_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_ANALOG_INPUT_ID_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_CHNLID_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_1_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR1_FLTRDATA_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_1_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_AFEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_SIGNIFICANT_BIT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_DATA16EN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_MODE_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_DFMODE_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_RATIO_SELECT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_OVRSAM_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_AFGIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_DATA_READY_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_AFRDY_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_ANALOG_INPUT_ID_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_CHNLID_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_2_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR2_FLTRDATA_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_2_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_AFEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_SIGNIFICANT_BIT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_DATA16EN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_MODE_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_DFMODE_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_RATIO_SELECT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_OVRSAM_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_AFGIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_DATA_READY_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_AFRDY_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_ANALOG_INPUT_ID_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_CHNLID_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_3_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR3_FLTRDATA_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_3_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_AFEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_SIGNIFICANT_BIT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_DATA16EN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_MODE_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_DFMODE_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_RATIO_SELECT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_OVRSAM_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_AFGIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_DATA_READY_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_AFRDY_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_ANALOG_INPUT_ID_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_CHNLID_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_4_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR4_FLTRDATA_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_4_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_AFEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_SIGNIFICANT_BIT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_DATA16EN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_MODE_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_DFMODE_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_RATIO_SELECT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_OVRSAM_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_AFGIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_DATA_READY_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_AFRDY_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_ANALOG_INPUT_ID_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_CHNLID_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_5_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR5_FLTRDATA_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_5_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_AFEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_SIGNIFICANT_BIT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_DATA16EN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_MODE_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_DFMODE_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_RATIO_SELECT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_OVRSAM_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_AFGIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_DATA_READY_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_AFRDY_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_ANALOG_INPUT_ID_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_CHNLID_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_6_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFLTR6_FLTRDATA_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_DIGITAL_FILTER_REG_6_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_3_TRIGGER_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG1_TRGSRC3_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_2_TRIGGER_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG1_TRGSRC2_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_1_TRIGGER_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG1_TRGSRC1_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_0_TRIGGER_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG1_TRGSRC0_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TRIGGER_CONTROL_BASE_ADDRESS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_7_TRIGGER_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG2_TRGSRC7_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_6_TRIGGER_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG2_TRGSRC6_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_5_TRIGGER_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG2_TRGSRC5_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_4_TRIGGER_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG2_TRGSRC4_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_11_TRIGGER_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG3_TRGSRC11_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_10_TRIGGER_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG3_TRGSRC10_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_9_TRIGGER_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG3_TRGSRC9_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_8_TRIGGER_SEL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCTRG3_TRGSRC8_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CVD_RESULT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_CVDDATA_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_1_ANALOG_INPUT_ID_GET_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_AINID_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_1_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_ENDCMP_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_DCMPGIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_1_EVENT_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON1_DCMPED_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_1_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_2_ANALOG_INPUT_ID_GET_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON2_AINID_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_2_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON2_ENDCMP_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_2_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON2_DCMPGIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_2_EVENT_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON2_DCMPED_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_2_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_3_ANALOG_INPUT_ID_GET_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON3_AINID_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_3_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON3_ENDCMP_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_3_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON3_DCMPGIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_3_EVENT_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON3_DCMPED_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_3_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_4_ANALOG_INPUT_ID_GET_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON4_AINID_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_4_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON4_ENDCMP_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_4_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON4_DCMPGIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_4_EVENT_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON4_DCMPED_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_4_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_5_ANALOG_INPUT_ID_GET_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON5_AINID_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_5_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON5_ENDCMP_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_5_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON5_DCMPGIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_5_EVENT_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON5_DCMPED_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_5_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_6_ANALOG_INPUT_ID_GET_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON6_AINID_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_6_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON6_ENDCMP_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_6_INTERRUPT_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON6_DCMPGIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_6_EVENT_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCCMPCON6_DCMPED_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_COMPARATOR_CONTROL_REG_6_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC4_FIFO_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC4EN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC3_FIFO_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC3EN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC2_FIFO_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC2EN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC1_FIFO_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC1EN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC0_FIFO_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADC0EN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_INTERRUPT_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FIEN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_DATA_READY_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FRDY_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_OVERWRT_ERROR_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FWROVERR_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_COUNT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FCNT_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_SIGN_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_FSIGN_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_CHANNEL_ID_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCFSTAT_ADCID_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_STAT_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_FIFO_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADCBASE_BASE_ADDR_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_0_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CONVERSION_RESULT_BASE_ADDRESS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_1_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_2_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_3_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_4_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_5_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_6_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_7_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_8_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_9_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_10_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_11_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_12_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_13_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_14_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_15_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_16_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_17_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_18_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_43_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_INPUT_44_CONVERTED_DATA_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_TRIG_SENSITIVE_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_EARLY_INTERRUPT_SELECTION_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC0TIME_ADCEIS_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_RESOLUTION_SELECTION_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC0TIME_SELRES_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_CLOCK_DIVISOR_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC0TIME_ADCDIV_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_SAMPLE_TIME_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC0TIME_SAMC_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_0_TIME_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_EARLY_INTERRUPT_SELECTION_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC1TIME_ADCEIS_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_RESOLUTION_SELECTION_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC1TIME_SELRES_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_CLOCK_DIVISOR_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC1TIME_ADCDIV_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_SAMPLE_TIME_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC1TIME_SAMC_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_1_TIME_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_EARLY_INTERRUPT_SELECTION_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC2TIME_ADCEIS_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_RESOLUTION_SELECTION_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC2TIME_SELRES_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_CLOCK_DIVISOR_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC2TIME_ADCDIV_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_SAMPLE_TIME_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC2TIME_SAMC_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_2_TIME_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_EARLY_INTERRUPT_SELECTION_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC3TIME_ADCEIS_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_RESOLUTION_SELECTION_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC3TIME_SELRES_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_CLOCK_DIVISOR_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC3TIME_ADCDIV_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_SAMPLE_TIME_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC3TIME_SAMC_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_3_TIME_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_EARLY_INTERRUPT_SELECTION_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC4TIME_ADCEIS_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_RESOLUTION_SELECTION_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC4TIME_SELRES_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_CLOCK_DIVISOR_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC4TIME_ADCDIV_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_SAMPLE_TIME_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADC4TIME_SAMC_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ADC_4_TIME_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INTERRUPT_REG_1_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INTERRUPT_REG_2_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INTERRUPT_STATUS_REG_1_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_EARLY_INTERRUPT_STATUS_REG_2_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_WARM_UP_COUNT_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKUPCLKCNT_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_WARM_UP_INTERRUPT_ENABLE_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN7_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_WARM_UP_INTERRUPT_ENABLE_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN4_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_WARM_UP_INTERRUPT_ENABLE_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN3_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_WARM_UP_INTERRUPT_ENABLE_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN2_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_WARM_UP_INTERRUPT_ENABLE_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN1_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_WARM_UP_INTERRUPT_ENABLE_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKIEN0_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_WARMP_UP_READY_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY7_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_WARMP_UP_READY_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY4_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_WARMP_UP_READY_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY3_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_WARMP_UP_READY_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY2_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_WARMP_UP_READY_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY1_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_WARMP_UP_READY_STATUS_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_WKRDY0_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_ANALOG_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN7_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_ANALOG_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN4_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_ANALOG_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN3_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_ANALOG_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN2_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_ANALOG_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN1_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_ANALOG_ENABLE_CONTROL_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return _ADCANCON_ANEN0_LENGTH;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_ANALOG_CONTROL_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_0_CONFIG_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_1_CONFIG_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_2_CONFIG_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_3_CONFIG_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_4_CONFIG_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_CHANNEL_7_CONFIG_REG_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_INPUT_CHECK_REG_0_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _ADCHS_INPUT_CHECK_REG_1_LEN(ADCHS_MODULE_ID i)
{
    switch (i) {
        case ADCHS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/adchs_EnableControl_Default.h"
#include "../templates/adchs_TurboMode_Default.h"
#include "../templates/adchs_DigitalComparator_Default.h"
#include "../templates/adchs_DigitalFilter_Default.h"
#include "../templates/adchs_FIFO_Default.h"
#include "../templates/adchs_DMA_Unsupported.h"
#include "../templates/adchs_CVD_Default.h"
#include "../templates/adchs_VREFControl_Default.h"
#include "../templates/adchs_AnalogInputScan_Default.h"
#include "../templates/adchs_AnalogFeatureControl_Default.h"
#include "../templates/adchs_DigitalFeatureControl_Default.h"
#include "../templates/adchs_AnalogInputModeControl_Default.h"
#include "../templates/adchs_TriggerControl_Default.h"
#include "../templates/adchs_ChannelTriggerSampleControl_Default.h"
#include "../templates/adchs_EarlyInterruptControl_Default.h"
#include "../templates/adchs_ManualControl_Default.h"
#include "../templates/adchs_UpdateReadyControl_Default.h"
#include "../templates/adchs_InputControl_Default.h"
#include "../templates/adchs_ExternalConversionRequest_Unsupported.h"
#include "../templates/adchs_Setup_Default.h"
#include "../templates/adchs_AnalogInputCheck_Default.h"
#include "../templates/adchs_ChannelConfiguration_Default.h"
#include "../templates/adchs_ConversionResult_Default.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void PLIB_ADCHS_Enable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_Enable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_Disable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_Disable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsEnableControl(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsEnableControl_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_TurboModeEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_TurboModeEnable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_TurboModeDisable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_TurboModeDisable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_TurboModeErrorHasOccurred(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_TurboModeErrorHasOccurred_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_TurboModeChannelSelect(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID masterChannelID, ADCHS_CHANNEL_ID slaveChannelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_TurboModeChannelSelect_Default(index, masterChannelID, slaveChannelID);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsTurboMode(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsTurboMode_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorAnalogInputSelect(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator, ADCHS_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalComparatorAnalogInputSelect_Default(index, digComparator, analogInput);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API ADCHS_AN_INPUT_ID PLIB_ADCHS_DigitalComparatorAnalogInputGet(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_DigitalComparatorAnalogInputGet_Default(index, digComparator);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (ADCHS_AN_INPUT_ID)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorEnable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalComparatorEnable_Default(index, digComparator);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorDisable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalComparatorDisable_Default(index, digComparator);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorInterruptEnable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalComparatorInterruptEnable_Default(index, digComparator);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorInterruptDisable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalComparatorInterruptDisable_Default(index, digComparator);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorSetup(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID id, bool intEnable, bool inBetweenOrEqual, bool greaterEqualHi, bool lessThanHi, bool greaterEqualLo, bool lessThanLo, ADCHS_AN_INPUT_ID analogInput, int16_t hiLimit, int16_t loLimit)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalComparatorSetup_Default(index, id, intEnable, inBetweenOrEqual, greaterEqualHi, lessThanHi, greaterEqualLo, lessThanLo, analogInput, hiLimit, loLimit);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_DigitalComparatorEventHasOccurred(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID id)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_DigitalComparatorEventHasOccurred_Default(index, id);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorLimitSet(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID id, int16_t hiLimit, int16_t loLimit)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalComparatorLimitSet_Default(index, id, hiLimit, loLimit);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsDigitalComparator(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsDigitalComparator_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterEnable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalFilterEnable_Default(index, id);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterDisable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalFilterDisable_Default(index, id);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterOversamplingModeSetup(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id, ADCHS_AN_INPUT_ID analogInput, ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length, ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio, bool intEnable)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalFilterOversamplingModeSetup_Default(index, id, analogInput, length, ratio, intEnable);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterAveragingModeSetup(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id, ADCHS_AN_INPUT_ID analogInput, ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length, ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count, bool intEnable)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalFilterAveragingModeSetup_Default(index, id, analogInput, length, count, intEnable);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id, ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalFilterOversamplingModeRatioSelect_Default(index, id, ratio);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id, ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalFilterAveragingModeSampleCountSelect_Default(index, id, count);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_DigitalFilterDataIsReady(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_DigitalFilterDataIsReady_Default(index, id);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API int16_t PLIB_ADCHS_DigitalFilterDataGet(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID dfltrID)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_DigitalFilterDataGet_Default(index, dfltrID);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (int16_t)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID digFilter)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalFilterDataReadyInterruptEnable_Default(index, digFilter);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID digFilter)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DigitalFilterDataReadyInterruptDisable_Default(index, digFilter);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsDigitalFilter(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsDigitalFilter_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API int32_t PLIB_ADCHS_FIFORead(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_FIFORead_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (int32_t)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_FIFODataIsAvailable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_FIFODataIsAvailable_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_FIFODataReadyInterruptEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_FIFODataReadyInterruptEnable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_FIFODataReadyInterruptDisable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_FIFODataReadyInterruptDisable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_FIFOEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_FIFOEnable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_FIFODisable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_FIFODisable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_FIFOSourceSelect(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_FIFOSourceSelect_Default(index, channelID);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint8_t PLIB_ADCHS_FIFODataCountGet(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_FIFODataCountGet_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API ADCHS_CHANNEL_ID PLIB_ADCHS_FIFOSourceGet(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_FIFOSourceGet_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (ADCHS_CHANNEL_ID)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_FIFOErrorHasOccurred(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_FIFOErrorHasOccurred_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_FIFODataIsNegative(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_FIFODataIsNegative_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsFIFO(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsFIFO_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DMAEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DMAEnable_Unsupported(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DMADisable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DMADisable_Unsupported(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DMASetup(ADCHS_MODULE_ID index, ADCHS_DMA_BUFFER_LENGTH bufferLengthBytes, uint32_t baseAddress, ADCHS_DMA_COUNT countMode, uint32_t countBaseAddress)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_DMASetup_Unsupported(index, bufferLengthBytes, baseAddress, countMode, countBaseAddress);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMASourceSelect(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_DMASourceSelect_Unsupported(index, channelID);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMASourceRemove(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_DMASourceRemove_Unsupported(index, channelID);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_A_InterruptEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_DMABuffer_A_InterruptEnable_Unsupported(index, channelID);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_A_InterruptDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_DMABuffer_A_InterruptDisable_Unsupported(index, channelID);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_B_InterruptEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_DMABuffer_B_InterruptEnable_Unsupported(index, channelID);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_B_InterruptDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_DMABuffer_B_InterruptDisable_Unsupported(index, channelID);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API int8_t _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_A_IsFull(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_DMABuffer_A_IsFull_Unsupported(index, channelID);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (int8_t)0;
    }
}

PLIB_INLINE_API int8_t _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_B_IsFull(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_DMABuffer_B_IsFull_Unsupported(index, channelID);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (int8_t)0;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMAOverflowErrorHasOccurred(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_DMAOverflowErrorHasOccurred_Unsupported(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsDMA(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsDMA_Unsupported(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_CVDEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_CVDEnable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_CVDDisable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_CVDDisable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_CVDSetup(ADCHS_MODULE_ID index, ADCHS_CVD_CAPACITOR capSel, bool inBetweenOrEqual, bool greaterEqualHi, bool lessThanHi, bool greaterEqualLo, bool lessThanLo, ADCHS_AN_INPUT_ID inputEnable, int16_t hiLimit, int16_t loLimit)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_CVDSetup_Default(index, capSel, inBetweenOrEqual, greaterEqualHi, lessThanHi, greaterEqualLo, lessThanLo, inputEnable, hiLimit, loLimit);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API int16_t PLIB_ADCHS_CVDResultGet(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_CVDResultGet_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (int16_t)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsCVD(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsCVD_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_VREFIsReady(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_VREFIsReady_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_VREFFaultHasOccurred(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_VREFFaultHasOccurred_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_VREFReadyInterruptEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_VREFReadyInterruptEnable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_VREFReadyInterruptDisable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_VREFReadyInterruptDisable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_VREFFaultInterruptEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_VREFFaultInterruptEnable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_VREFFaultInterruptDisable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_VREFFaultInterruptDisable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsVREFControl(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsVREFControl_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_AnalogInputScanIsComplete(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_AnalogInputScanIsComplete_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputScanSelect(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_AnalogInputScanSelect_Default(index, analogInput);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputScanRemove(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_AnalogInputScanRemove_Default(index, analogInput);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_AnalogInputScanIsSelected(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_AnalogInputScanIsSelected_Default(index, analogInput);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputScanSetup(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput, ADCHS_SCAN_TRIGGER_SENSITIVE trgSensitive, ADCHS_SCAN_TRIGGER_SOURCE triggerSource)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_AnalogInputScanSetup_Default(index, analogInput, trgSensitive, triggerSource);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_ScanCompleteInterruptEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ScanCompleteInterruptEnable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_ScanCompleteInterruptDisable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ScanCompleteInterruptDisable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsAnalogInputScan(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsAnalogInputScan_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelAnalogFeatureEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ChannelAnalogFeatureEnable_Default(index, channelID);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelAnalogFeatureDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ChannelAnalogFeatureDisable_Default(index, channelID);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ChannelIsReady(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ChannelIsReady_Default(index, channelID);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelIsReadyInterruptEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ChannelIsReadyInterruptEnable_Default(index, channelID);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelIsReadyInterruptDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ChannelIsReadyInterruptDisable_Default(index, channelID);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsChannelAnalogControl(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsChannelAnalogControl_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelDigitalFeatureEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ChannelDigitalFeatureEnable_Default(index, channelID);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelDigitalFeatureDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ChannelDigitalFeatureDisable_Default(index, channelID);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsChannelDigitalControl(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsChannelDigitalControl_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputModeSelect(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput, ADCHS_INPUT_MODE mode)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_AnalogInputModeSelect_Default(index, analogInput, mode);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API ADCHS_INPUT_MODE PLIB_ADCHS_AnalogInputModeGet(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_AnalogInputModeGet_Default(index, analogInput);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (ADCHS_INPUT_MODE)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsAnalogInputModeControl(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsAnalogInputModeControl_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputLevelTriggerSet(ADCHS_MODULE_ID index, ADCHS_CLASS12_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_AnalogInputLevelTriggerSet_Default(index, analogInput);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputEdgeTriggerSet(ADCHS_MODULE_ID index, ADCHS_CLASS12_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_AnalogInputEdgeTriggerSet_Default(index, analogInput);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputTriggerSourceSelect(ADCHS_MODULE_ID index, ADCHS_CLASS12_AN_INPUT_ID inputId, ADCHS_TRIGGER_SOURCE triggerSource)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_AnalogInputTriggerSourceSelect_Default(index, inputId, triggerSource);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_GlobalSoftwareTriggerEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_GlobalSoftwareTriggerEnable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_GlobalLevelSoftwareTriggerEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_GlobalLevelSoftwareTriggerEnable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_GlobalLevelSoftwareTriggerDisable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_GlobalLevelSoftwareTriggerDisable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_TriggerSuspendEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_TriggerSuspendEnable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_TriggerSuspendDisable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_TriggerSuspendDisable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsTriggerControl(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsTriggerControl_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ChannelTriggerSampleSelect(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID, ADCHS_CHANNEL_TRIGGER_SAMPLING_SEL sampSel)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ChannelTriggerSampleSelect_Default(index, channelID, sampSel);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsTriggerSampleControl(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsTriggerSampleControl_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_EarlyInterruptEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_EarlyInterruptEnable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_EarlyInterruptDisable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_EarlyInterruptDisable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputEarlyInterruptEnable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_AnalogInputEarlyInterruptEnable_Default(index, analogInput);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputEarlyInterruptDisable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_AnalogInputEarlyInterruptDisable_Default(index, analogInput);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_AnalogInputEarlyInterruptIsReady(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_AnalogInputEarlyInterruptIsReady_Default(index, analogInput);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsEarlyInterruptControl(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsEarlyInterruptControl_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_SoftwareSamplingStart(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_SoftwareSamplingStart_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_SoftwareSamplingStop(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_SoftwareSamplingStop_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_SoftwareConversionStart(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_SoftwareConversionStart_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_SoftwareConversionInputSelect(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID anInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_SoftwareConversionInputSelect_Default(index, anInput);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsManualControl(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsManualControl_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ControlRegistersCanBeUpdatedInterruptEnable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptDisable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ControlRegistersCanBeUpdatedInterruptDisable_Default(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ControlRegistersCanBeUpdated(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ControlRegistersCanBeUpdated_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsUpdateReadyControl(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsUpdateReadyControl_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ChannelInputSelect(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID, ADCHS_CHANNEL_INP_SEL sel)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ChannelInputSelect_Default(index, channelID, sel);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsChannelInputSelectControl(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsChannelInputSelectControl_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ExternalConversionRequestEnable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ExternalConversionRequestEnable_Unsupported(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ExternalConversionRequestDisable(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ExternalConversionRequestDisable_Unsupported(index);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsExternalConversionRequestControl(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsExternalConversionRequestControl_Unsupported(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_Setup(ADCHS_MODULE_ID index, ADCHS_VREF_SOURCE voltageRefSelect, ADCHS_CHARGEPUMP_MODE chargePump, ADCHS_OUTPUT_DATA_FORMAT outputFormat, bool stopInIdle, ADCHS_FAST_SYNC_SYSTEM_CLOCK sysClk, ADCHS_FAST_SYNC_PERIPHERAL_CLOCK periClk, ADCHS_INTERRUPT_BIT_SHIFT_LEFT intVectorShift, uint16_t intVectorBase, ADCHS_CLOCK_SOURCE adcClockSource, int8_t adcClockDivider, ADCHS_WARMUP_CLOCK warmUpClock)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_Setup_Default(index, voltageRefSelect, chargePump, outputFormat, stopInIdle, sysClk, periClk, intVectorShift, intVectorBase, adcClockSource, adcClockDivider, warmUpClock);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelSetup(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID, ADCHS_DATA_RESOLUTION res, uint8_t channelClockDivider, uint16_t sampleTimeCount, ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK earlyInterruptClk)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ChannelSetup_Default(index, channelID, res, channelClockDivider, sampleTimeCount, earlyInterruptClk);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsConfiguration(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsConfiguration_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_AnalogInputIsAvailable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_AnalogInputIsAvailable_Default(index, analogInput);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsAnalogInputCheck(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsAnalogInputCheck_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint32_t PLIB_ADCHS_ChannelConfigurationGet(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ChannelConfigurationGet_Default(index, channelID);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (uint32_t)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelConfigurationSet(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID, uint32_t config)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_ChannelConfigurationSet_Default(index, channelID, config);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsChannelConfiguration(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsChannelConfiguration_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputDataReadyInterruptEnable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_AnalogInputDataReadyInterruptEnable_Default(index, analogInput);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputDataReadyInterruptDisable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            ADCHS_AnalogInputDataReadyInterruptDisable_Default(index, analogInput);
            break;
        case ADCHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_AnalogInputDataIsReady(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_AnalogInputDataIsReady_Default(index, analogInput);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint32_t PLIB_ADCHS_AnalogInputResultGet(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_AnalogInputResultGet_Default(index, analogInput);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (uint32_t)0;
    }
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsConversionResults(ADCHS_MODULE_ID index)
{
    switch (index) {
        case ADCHS_ID_0 :
            return ADCHS_ExistsConversionResults_Default(index);
        case ADCHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

#endif
