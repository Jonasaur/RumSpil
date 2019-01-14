#include "stm32f30x_conf.h"
#include <stdio.h>
#include <string.h>
#include "ansi.h"

#ifndef _TIMER_H_
#define _TIMER_H_

struct time
{
    uint32_t hs, s, m, h, f;
};

int8_t get_flag();

void timer_setup();

void start_timer();

void stop_timer();

void TIM2_IRQHandler(void);

void time_print(int8_t x, int8_t y);

#endif
