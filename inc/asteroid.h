#include "stm32f30x_conf.h"
#include <stdio.h>

#ifndef _ASTEROID_H_
#define _ASTEROID_H_

struct asteroid_t {
    int32_t x, y, vx, vy, tempx, tempy, tempf, active, G;
};

void init_asteroid(struct asteroid_t * as, int32_t x, int32_t y, int32_t vx, int32_t vy);
void draw_asteroid(struct asteroid_t * as);
void delete_asteroid(struct asteroid_t * as);
void move_asteroid(struct asteroid_t * as);

#endif
