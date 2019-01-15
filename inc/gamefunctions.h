/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_conf.h"
#include <stdio.h>
#include <string.h>
#include "serial_com.h"
#include "timer.h"
#include "ansi.h"

#ifndef _GAMEFUNCTIONS_H_
#define _GAMEFUNCTIONS_H_

struct spaceship_t {
    int32_t x, y, tempx, tempy, tempf;
};

void initSpaceship(struct spaceship_t *s, int x, int y);
void drawSpaceship(struct spaceship_t *s);
void deleteSpaceship(struct spaceship_t *s);

struct Rocket_t
{
    int32_t x, y, vx, tempx, tempy, tempf, active;
};

void initRocket(struct Rocket_t *b, int x, int y, int vx);
void drawRocket(struct Rocket_t *b);
void deleteRocket(struct Rocket_t *b);
void shootRocket(struct Rocket_t *b, struct spaceship_t *s );
void moveRocket(struct Rocket_t *b);
void updateRocketPos(struct Rocket_t *b);

void Controls(struct spaceship_t *s, struct Rocket_t *b, char * uart_char, int8_t * c_count);

void updateShippositionRight(struct spaceship_t *s);
void updateShippositionLeft(struct spaceship_t *s);
void updateShippositionDown(struct spaceship_t *s);
void updateShippositionUp(struct spaceship_t *s);

//void collisionDetect(struct ball_t *b);

#endif

