/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_conf.h"
#include <stdio.h>
#include <string.h>
#include "serial_com.h"
#include "timer.h"
#include "ansi.h"
#include "asteroid.h"
#include "alien.h"

#ifndef _GAMEFUNCTIONS_H_
#define _GAMEFUNCTIONS_H_


struct spaceship_t
{
    int32_t x, y, tempx, tempy, tempf;
};

struct Rocket_t
{
    int32_t x, y, vx, tempx, tempy, tempf, active;
};

struct Bomb_t
{
    int32_t x, y, vx, tempx, tempy, tempf, active;
};

void initSpaceship(struct spaceship_t *s, int x, int y);
void drawSpaceship (struct spaceship_t *s);
void deleteSpaceship (struct spaceship_t *s);
void updateShippositionRight ( struct spaceship_t *s);
void updateShippositionLeft ( struct spaceship_t *s);
void updateShippositionDown ( struct spaceship_t *s);
void updateShippositionUp ( struct spaceship_t *s);

void initRocket(struct Rocket_t *r, int x, int y, int vx);
void drawRocket (struct Rocket_t *r);
void deleteRocket(struct Rocket_t *r);
void shootRocket (struct Rocket_t *r, struct spaceship_t *s);
void updateRocketPos (struct Rocket_t *r);
void moveRocket (struct Rocket_t *r);
void hitDetection (struct Rocket_t *r, struct Bomb_t *b, struct alien_t *al);

void initBomb(struct Bomb_t *b, int x, int y, int vx);
void drawBomb (struct Bomb_t *b);
void deleteBomb(struct Bomb_t *b);
void shootBomb (struct Bomb_t *b, struct spaceship_t *s);
void updateBombPos (struct Bomb_t *b);
void moveBomb (struct Bomb_t *b);



void Controls(struct spaceship_t *s, struct Rocket_t *r, struct Bomb_t *b);


#include "gamefunctions.h"
#define ESC 0x1B




//void collisionDetect(struct ball_t *b);

#endif

