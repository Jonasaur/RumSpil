#include "stm32f30x_conf.h"
#include <stdio.h>

#ifndef _ASTEROID_H_
#define _ASTEROID_H_

struct asteroid_t {
    int8_t x, y, vx, vy, tempx, tempy, tempf, active, G;
};

void init_asteroid(struct asteroid_t * as, int8_t x, int8_t y, int8_t vx, int8_t vy);
void draw_asteroid(struct asteroid_t * as);
void delete_asteroid(struct asteroid_t * as);
void move_asteroid(struct asteroid_t * as);

#endif
