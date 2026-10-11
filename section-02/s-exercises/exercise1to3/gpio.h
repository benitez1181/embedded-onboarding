#ifndef MYGPIO_H
#define MYGPIO_H

#include <stdio.h>>
#include <stdint.h>

typedef enum{
    INPUT,
    OUTPUT
}GPIO_MODE;

typedef struct{
    volatile uint32_t gpio_crl;
    volatile uint32_t gpio_crh;
    volatile uint32_t gpio_idr;
    volatile uint32_t gpio_odr;
    volatile uint32_t gpio_bsrr;
    volatile uint32_t gpio_brr;
    volatile uint32_t gpio_lckr;
}PORT;

void my_gpio_init(uint32_t port, uint32_t pin, GPIO_MODE mode);
void my_gpio_toggle(uint32_t port, uint32_t pin);
void my_gpio_write(uint32_t port, uint32_t pin, bool value);
void my_hal_delay(uint32_t delay);

#endif