#include "asteroid.h"

void init_asteroid(struct asteroid_t * as, int8_t x, int8_t y, int8_t vx, int8_t vy) {
    (*as).x = x << 14;
    (*as).y = y << 14;
    (*as).tempx = x << 14;
    (*as).tempy = y << 14;
    (*as).vx = vx << 14;
    (*as).vy = vy << 14;
    (*as).active = 6;
    (*as).tempf = 0;
    (*as).G = 2500 << 14;
}

void draw_asteroid(struct asteroid_t *as ) {

    if ((*as).active == 6)
    {
        gotoxy(((*as).x>>14)-3,((*as).y>>14)+2);
        printf("%c%c%c%c%c%c", 176, 176, 176, 176, 176, 176);
        gotoxy(((*as).x>>14)-4,((*as).y>>14)+1);
        printf("%c%c%c%c%c%c%c%c", 176, 176, 176, 176, 176, 176, 176, 176);
        gotoxy(((*as).x>>14)-5,((*as).y>>14));
        printf("%c%c%c%c%c%c%c%c%c%c", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176);
        gotoxy(((*as).x>>14)-4,((*as).y>>14)-1);
        printf("%c%c%c%c%c%c%c%c", 176, 176, 176, 176, 176, 176, 176, 176);
        gotoxy(((*as).x>>14)-3,((*as).y>>14)-2);
        printf("%c%c%c%c%c%c", 176, 176, 176, 176, 176, 176);
    }

    if ((*as).active == 5 || (*as).active == 4 )
    {
        gotoxy(((*as).x>>14)-3,((*as).y>>14)+2);
        printf("%c%c%c%c%c%c", 176, 32, 176, 176, 176, 32);
        gotoxy(((*as).x>>14)-4,((*as).y>>14)+1);
        printf("%c%c%c%c%c%c%c%c", 176, 176, 176, 176, 176, 32, 176, 176);
        gotoxy(((*as).x>>14)-5,((*as).y>>14));
        printf("%c%c%c%c%c%c%c%c%c%c", 176, 176, 176, 176, 176, 32, 176, 176, 176, 176);
        gotoxy(((*as).x>>14)-4,((*as).y>>14)-1);
        printf("%c%c%c%c%c%c%c%c", 176, 32, 176, 32, 32, 176, 176, 176);
        gotoxy(((*as).x>>14)-3,((*as).y>>14)-2);
        printf("%c%c%c%c%c%c", 176, 176, 176, 176, 176, 176);
    }

    if ((*as).active == 3 || (*as).active == 2 )
    {
        gotoxy(((*as).x>>14)-3,((*as).y>>14)+2);
        printf("%c%c%c%c%c%c", 176, 32, 32, 176, 176, 32);
        gotoxy(((*as).x>>14)-4,((*as).y>>14)+1);
        printf("%c%c%c%c%c%c%c%c", 176, 176, 176, 176, 176, 32, 176, 176);
        gotoxy(((*as).x>>14)-5,((*as).y>>14));
        printf("%c%c%c%c%c%c%c%c%c%c", 176, 176, 32, 176, 32, 32, 176, 176, 32, 176);
        gotoxy(((*as).x>>14)-4,((*as).y>>14)-1);
        printf("%c%c%c%c%c%c%c%c", 176, 32, 176, 32, 32, 176, 176, 176);
        gotoxy(((*as).x>>14)-3,((*as).y>>14)-2);
        printf("%c%c%c%c%c%c", 176, 176, 176, 32, 176, 176);
    }
    if((*as).active ==  1)
    {
        gotoxy(((*as).x>>14)-3,((*as).y>>14)+2);
        printf("%c%c%c%c%c%c", 32, 32, 32, 176, 176, 32);
        gotoxy(((*as).x>>14)-4,((*as).y>>14)+1);
        printf("%c%c%c%c%c%c%c%c", 176, 176, 176, 176, 176, 32, 176, 176);
        gotoxy(((*as).x>>14)-5,((*as).y>>14));
        printf("%c%c%c%c%c%c%c%c%c%c", 176, 176, 32, 176, 32, 32, 176, 176, 32, 32);
        gotoxy(((*as).x>>14)-4,((*as).y>>14)-1);
        printf("%c%c%c%c%c%c%c%c", 32, 32, 176, 32, 32, 176, 176, 32);
        gotoxy(((*as).x>>14)-3,((*as).y>>14)-2);
        printf("%c%c%c%c%c%c", 176, 176, 176, 32, 32, 176);
    }
}

void delete_asteroid(struct asteroid_t *as) {
        gotoxy(((*as).x>>14)-3,((*as).y>>14)+2);
        printf("%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32);
        gotoxy(((*as).x>>14)-4,((*as).y>>14)+1);
        printf("%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32, 32, 32);
        gotoxy(((*as).x>>14)-5,((*as).y>>14));
        printf("%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32, 32, 32, 32, 32);
        gotoxy(((*as).x>>14)-4,((*as).y>>14)-1);
        printf("%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32, 32, 32);
        gotoxy(((*as).x>>14)-3,((*as).y>>14)-2);
        printf("%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32);
}

void move_asteroid(struct asteroid_t * as) {
    if (as->active > 0)
    {
        (*as).x += (*as).vx;
        if ((*as).tempx != (*as).x >>14)
        {
            delete_asteroid(as);
            draw_asteroid(as);
            (*as).tempx = (*as).x >> 14;
        }
    }
    if (as->active <= 0 && as-> active != -10)
    {
        delete_asteroid(as);
        (*as).active = -10;
    }
}
