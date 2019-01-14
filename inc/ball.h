#include "stm32f30x_conf.h"
#include <stdio.h>
#include <string.h>
#include "ansi.h"
#include "timer.h"

#ifndef _BALL_H_
#define _BALL_H_

struct ball_t
{
    int32_t x, y, vx,vy, tempx,tempy,tempf;
};

void printBall(struct ball_t * b);
void deleteBall(struct ball_t * b);
void rotateBall (struct ball_t * b, int angle);
void updateBallPos(struct ball_t * b);
void initBall(struct ball_t * b, int x, int y, int vx, int vy);


#endif
