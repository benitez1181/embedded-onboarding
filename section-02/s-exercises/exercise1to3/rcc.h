#ifndef RCC_H
#define RCC_H

#include <stdint.h>
#define ADDRESS_BASE 0x4002'1000

typedef struct{
    volatile uint32_t rcc_cr;
    volatile uint32_t rcc_cfgr;
    volatile uint32_t rcc_cir;
    volatile uint32_t rcc_apb2rstr;
    volatile uint32_t rcc_apb1rstr;
    volatile uint32_t rcc_ahbenr;
    volatile uint32_t rcc_apb2enr;
    volatile uint32_t rcc_apb1enr;
    volatile uint32_t rcc_bdcr;
    volatile uint32_t rcc_csr;
    volatile uint32_t rcc_ahbrstr;
    volatile uint32_t rcc_cfgr2;
}RCC;

#define rcc ((RCC*)ADDRESS_BASE)

#endif