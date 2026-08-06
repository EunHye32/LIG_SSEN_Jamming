/*
 * 2026-08-03
 * STM32 HAL NRF24 LIBRARY
 */

#ifndef _NRF_24_CONF_H_
#define _NRF_24_CONF_H_

#define hspiX hspi4
#define spi_w_timeout 100
#define spi_r_timeout 100
#define spi_rw_timeout 100

// TX
#define csn_gpio_port GPIOB
#define csn_gpio_pin GPIO_PIN_3

// RX
#define ce_gpio_port GPIOB
#define ce_gpio_pin GPIO_PIN_4

#define htimX htim1

#endif
