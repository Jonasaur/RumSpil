/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_conf.h"
#include "alien.h"
#include "asteroid.h"
#include "PowerUps.h"
#include "config.h"
#include "fpsqrt.h"
#include "LCD.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#ifndef _GAMEFUNCTIONS_H_
#define _GAMEFUNCTIONS_H_

struct counter_t
{
    int32_t lives, ammo, bombs;
};

struct spaceship_t
{
    int32_t x, y, tempx, tempy, tempf, active;
};

struct Rocket_t
{
    int32_t x, y, vx, vy, tempx, tempy, tempf, active;
};

struct Bomb_t
{
    int32_t x, y, vx, vy, tempx, tempy, tempf, active;
};

void initSpaceship(struct spaceship_t * s, int x, int y);
void drawSpaceship (struct spaceship_t * s);
void deleteSpaceship (struct spaceship_t * s);
void updateShippositionRight(struct spaceship_t * s);
void updateShippositionLeft(struct spaceship_t * s);
void updateShippositionDown(struct spaceship_t * s);
void updateShippositionUp(struct spaceship_t * s);

void initRocket(struct Rocket_t * r, int x, int y, int vx, int vy);
void drawRocket(struct Rocket_t * r);
void deleteRocket(struct Rocket_t * r);
void shootRocket(struct Rocket_t * r, struct spaceship_t * s , struct counter_t * c, uint8_t * buffer, int8_t vx, int8_t vy);
void updateRocketPos(struct Rocket_t * r);
void moveRocket(struct Rocket_t * r);
void hitDetection (struct Rocket_t * r, struct Bomb_t * b, struct alien_t * al, struct asteroid_t * as, struct spaceship_t * s, struct powerup_t * p, struct counter_t * c, uint8_t * buffer);

void initBomb(struct Bomb_t * b, int x, int y, int vx, int vy);
void drawBomb (struct Bomb_t * b);
void deleteBomb(struct Bomb_t * b);
void shootBomb(struct Bomb_t * b, struct spaceship_t * s, struct counter_t * c, uint8_t * buffer, int8_t vx, int8_t vy);
void updateBombPos (struct Bomb_t * b);
void moveBomb(struct Bomb_t * b);

void respawn (struct spaceship_t *s, struct counter_t *c, uint8_t *buffer);
void controlPowerups(struct powerup_t * p);
void background(int x, int y);
void gravity(struct Rocket_t * r, struct alien_t * al);

#endif


