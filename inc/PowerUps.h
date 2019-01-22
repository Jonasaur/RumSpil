/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_conf.h"

#ifndef _POWERUPS_H_
#define _POWERUPS_H_

struct powerup_t {
    int32_t x, y, active;
};

void init_powerup(struct powerup_t  * p, int8_t x, int8_t y);
void drawPowerup(struct powerup_t * p);
void deletePowerup(struct powerup_t * p);

#endif
