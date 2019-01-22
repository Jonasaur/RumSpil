#include "stm32f30x_conf.h"
#include <stdio.h>
#include <string.h>

#ifndef _TIMER_H_
#define _TIMER_H_

struct time
{
    uint32_t hs, s, m, h, f, al, n, anim; //n is the level - a speed multiplier - it changes a flag controlling how fast asteroids and aliens update
};

//void update_high_score(struct high_scores * hs);

void timer_setup();

void start_timer();

void stop_timer();

void TIM2_IRQHandler(void);

int8_t get_flag();

int8_t get_level_flag();

void set_lvl(int8_t lvl_input);

int8_t get_anim_flag();

#endif
