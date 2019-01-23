#include "stm32f30x_conf.h"
#include <stdio.h>
#include <string.h>
#include "ansi.h"
#include "config.h"

#ifndef _ALIEN_H_
#define _ALIEN_H_

struct alien_t {
    int32_t x, y, tempx, tempy, tempf, vx, vy, active, m, i, G;
};

struct laser_t {
    int32_t x, y, vx, vy, tempx, tempy, tempf, active;
};

void init_alien(struct alien_t * al, int32_t x, int32_t y, int32_t vx, int32_t vy);
void draw_alien(struct alien_t * al);
void delete_alien (struct alien_t * al);
void move_alien(struct alien_t * al, int32_t vx, int32_t vy);

//-----------------------------------------------------------------

void initLaser(struct laser_t * l, int x, int y, int vx, int vy);
void drawLaser (struct laser_t * l, struct alien_t *al);
void deleteLaser(struct laser_t *l);
void updateLaserPos(struct laser_t *l, struct alien_t *al);
void shootLaser(struct laser_t *l, struct alien_t *al , int32_t vx, int32_t vy);
void moveLaser(struct laser_t *l, struct alien_t *al);

#endif
