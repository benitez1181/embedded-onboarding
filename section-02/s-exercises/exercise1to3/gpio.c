#include "gpio.h"
#include "rcc.h"

#define PORT_BASE 0x4001'0800
#define GPIO_PORT(n) (PORT *)((n*0x3FF) + PORT_BASE)
#define PORT_CLK_MASK(n) (1U << (n+2))
#define PIN_MASK(n) (1U << )

/* Parameters:
    port: A-G => 0-6
    pin: pin number
    mode: pin mode (INPUT, OUTPUT)
*/

void my_gpio_init(uint32_t port, uint32_t pin, GPIO_MODE mode){
    PORT * port_ptr = GPIO_PORT(port);

    rcc->rcc_apb2enr |= PORT_CLK_MASK(port);

    switch(mode){
        case INPUT:
            if(pin < 8)
                port_ptr->gpio_crl |= ((0b00 << pin) | (0b01 << (pin + 2)));   
            else
                port_ptr->gpio_crh |= ((0b00 << (pin - 8)) | (0b01 << (pin - 6)));
            break;
        case OUTPUT:
            if(pin < 8)
                port_ptr->gpio_crl |= ((0b01 << pin) | (0b01 << (pin + 2)));   
            else
                port_ptr->gpio_crh |= ((0b01 << (pin - 8)) | (0b01 << (pin - 6)));
            
            break;
    }
}

void my_gpio_toggle(uint32_t port, uint32_t pin){
    PORT * port_ptr = GPIO_PORT(port);

    if(pin < 8)
        port_ptr->gpio_odr & ~(1U << pin);
    else 
        port_ptr->gpio_odr & ~(1U << (pin - 8));
}

void my_gpio_write(uint32_t port, uint32_t pin, bool value){
    PORT * port_ptr = GPIO_PORT(port);

    if(pin < 8)
        port_ptr->gpio_odr | (value << pin);
    else 
        port_ptr->gpio_odr | (value << (pin - 8));
}
