#include "ball.h"



void printBall(struct ball_t * b)
{
    gotoxy((*b).y>>14,(*b).x>>14);
    printf("%c",111);
}
void deleteBall(struct ball_t * b)
{
    if ((*b).tempf != get_flag())
    {
        gotoxy((*b).y>>14,(*b).x>>14);
        printf(" ");
    }
}

void rotateBall (struct ball_t * b, int angle)
{
    int temp_vx = FIX14_MULT((*b).vx,calc_cosinus(angle)) - FIX14_MULT((*b).vy,calc_sinus(angle));
    int temp_vy = FIX14_MULT((*b).vx,calc_sinus(angle)) + FIX14_MULT((*b).vy,calc_cosinus(angle));

    (*b).vx = temp_vx;
    (*b).vy = temp_vy;
}

void updateBallPos(struct ball_t *b)
{
    if (get_flag() != (*b).tempf)
    {
        (*b).tempx = (*b).x;
        (*b).tempy = (*b).y;
        (*b).x += (*b).vx;
        (*b).y += (*b).vy;
        (*b).tempf = get_flag();
    }
}


void initBall(struct ball_t * b, int x, int y, int vx, int vy)
{
    (*b).x = x << 14;
    (*b).y = y << 14;
    (*b).tempx = x << 14;
    (*b).tempy = y << 14;
    (*b).vx = vx << 14;
    (*b).vy = vy << 14;
    (*b).tempf = 0;
}

/*
void rotateVector (struct vector_t *v, int angle) {

int tempx = FIX14_MULT((*v).x,calc_cosinus(angle)) - FIX14_MULT((*v).y,calc_sinus(angle));

int tempy = FIX14_MULT((*v).x,calc_sinus(angle)) + FIX14_MULT((*v).y,calc_cosinus(angle));

(*v).x = tempx;
(*v).y = tempy;
}

*/
