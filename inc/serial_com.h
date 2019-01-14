#include "stm32f30x_conf.h"
#include <stdio.h>
#include <string.h>

#ifndef _SERIAL_COM_H_
#define _SERIAL_COM_H_

char keyboard_read(char * uart_char, int8_t * c_count);
int8_t keyboard_controls(char button_pressed);

#endif
