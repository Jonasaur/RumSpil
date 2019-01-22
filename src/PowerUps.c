#include "powerUps.h"

void init_powerup(struct powerup_t  * p, int8_t x, int8_t y)
{
    (*p).x = x << 14;
    (*p).y = y << 14;
    (*p).active = 1;
}

void drawPowerup(struct powerup_t * p) {
    gotoxy(((*p).x >> 14)-1,(*p).y >> 14);
    printf("%c%c%c", 204, 206, 185);
    gotoxy(((*p).x >> 14),((*p).y >> 14) - 1);
    printf("%c",(203));
    gotoxy((*p).x >> 14,((*p).y >> 14) + 1);
    printf("%c",(202));

}

void deletePowerup(struct powerup_t * p) {
    gotoxy(((*p).x >> 14)-1,(*p).y >> 14);
    printf("   ");
    gotoxy(((*p).x >> 14),((*p).y >> 14)-1);
    printf(" ");
    gotoxy(((*p).x >> 14),((*p).y >> 14) + 1);
    printf(" ");
}

