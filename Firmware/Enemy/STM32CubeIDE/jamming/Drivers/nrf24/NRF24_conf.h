/*
 * 25-JUL-2024
 * STM32 HAL NRF24 LIBRARY
 */

#ifndef _NRF_24_CONF_H_
#define _NRF_24_CONF_H_

#define hspiX hspi4
#define spi_w_timeout 1000
#define spi_r_timeout 1000
#define spi_rw_timeout 1000

// Modify V3 : RX 보드용
// Modify V1 : TX 보드용
#define csn_gpio_port GPIOB
#define csn_gpio_pin GPIO_PIN_3

#define ce_gpio_port GPIOB
#define ce_gpio_pin GPIO_PIN_4

/* Modify V3 : RX 보드용
// Modify V2 : NRF24.c에서 직접 제어
#define csn_gpio_port GPIOD
#define csn_gpio_pin GPIO_PIN_4

#define ce_gpio_port GPIOD
#define ce_gpio_pin GPIO_PIN_5

// Modify V3 : TX 보드용
#define csn_gpio_port GPIOA
#define csn_gpio_pin GPIO_PIN_3

#define ce_gpio_port GPIOA
#define ce_gpio_pin GPIO_PIN_4
// Modify V3 : Test Tx, Rx function */

#define htimX htim1

#endif

