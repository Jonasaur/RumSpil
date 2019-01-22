#include "stm32f30x_conf.h"
#include <stdio.h>
#include <string.h>
#include "timer.h"
#include "30010_io.h"
#include "gamefunctions.h"

#ifndef _SERIAL_COM_H_
#define _SERIAL_COM_H_

char keyboard_read(char * uart_char, int8_t * c_count);
void game_controls(int8_t * i_time, struct spaceship_t * s, struct Rocket_t * r, struct Bomb_t * b, struct counter_t * c, uint8_t * buffer);

#endif
