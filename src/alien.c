#include "alien.h"

void init_alien(struct alien_t * al, int32_t x, int32_t y, int32_t vx, int32_t vy)
{
    (*al).x = x << 14;
    (*al).y = y << 14;
    (*al).tempx = x << 14;
    (*al).tempy = y << 14;
    (*al).vx = vx << 14;
    (*al).vy = vy << 14;
    (*al).active = 3;
    (*al).tempf = 0;
    (*al).m = 0;
    (*al).G = 25;
}

void draw_alien(struct alien_t *al) {
    switch ((*al).active) {
        case 3:
            if (get_anim() == 1)
            {
                gotoxy((*al).x>>14,(*al).y>>14);
                printf("   %c",(0x5F));
                gotoxy((*al).x>>14,((*al).y>>14)+1);
                printf(" %c%c%c%c%c",0x3C,0x2F,0x5E,0x5C,0x3E);
                gotoxy((*al).x>>14,((*al).y>>14)+2);
                printf("%c%c%c%c%c%c%c",0x3C,0x2F,0xCF,0x2D,0xCF,0x5C,0x3E);
                gotoxy((*al).x>>14,((*al).y>>14)+3);
                printf(" %c%c%c%c%c", 0xC9,0xBC,0xBA,0xC8,0xBB);
            }
            else
            {
                gotoxy((*al).x>>14,(*al).y>>14);
                printf("   %c",(0x5F));
                gotoxy((*al).x>>14,((*al).y>>14) + 1);
                printf(" %c%c%c%c%c",0x3C,0x2F,0x5E,0x5C,0x3E);
                gotoxy((*al).x>>14,((*al).y>>14) + 2);
                printf("%c%c%c%c%c%c%c",0x3C,0x2F,0xCF,0x4F,0xCF,0x5C,0x3E);
                gotoxy((*al).x>>14,((*al).y>>14) + 3);
                printf(" %c%c%c%c%c", 0xCD,0xBC,0xBA,0xC8,0xCD);
            }
            break;
        case 2:
            gotoxy((*al).x>>14,(*al).y>>14);
            printf("   %c",(0x5F));
            gotoxy((*al).x>>14,((*al).y>>14)+1);

            printf("%c%c%c%c",0x2F,0x5E,0x5C,0x3E);
            gotoxy((*al).x>>14,((*al).y>>14)+2);
            printf("%c%c%c%c%c%c",0x2F,0xCF,0x2D,0xCF,0x5C,0x3E);

            gotoxy((*al).x>>14,((*al).y>>14)+3);
            printf(" %c%c%c", 0xC9,0xBC,0xBA);
            break;
        case 1:
            gotoxy((*al).x>>14,(*al).y>>14);
            printf("   %c",(0x5F));
            gotoxy((*al).x>>14,((*al).y>>14)+1);
            printf("%c%c",0x5C,0x3E);
            gotoxy((*al).x>>14,((*al).y>>14)+2);
            printf("%c%c%c%c",0x2D,0xCF,0x5C,0x3E);
            gotoxy(((*al).x>>14) + 1,((*al).y>>14)+3);
            printf("%c%c%c", 0xC9, 0xBC, 0xBA);
            break;
        case 0: {
            break;
        }
    }
}

void delete_alien (struct alien_t * al)
{
    gotoxy(((*al).x >> 14) + 3,(*al).y>>14 - 2);
    printf("      ");
    gotoxy(((*al).x >> 14) + 4,(*al).y>>14 - 1);
    printf("      ");
    gotoxy(((*al).x >> 14) + 3,(*al).y>>14);
    printf("      ");
    gotoxy(((*al).x >> 14) + 1,((*al).y>>14) + 1);
    printf("       ");
    gotoxy((*al).x >> 14, ((*al).y >> 14) + 2);
    printf("         ");
    gotoxy(((*al).x >> 14) + 1, ((*al).y >> 14) + 3);
    printf("       ");
    gotoxy(((*al).x >> 14) + 1, ((*al).y >> 14) + 4);
    printf("       ");
}

void move_alien(struct alien_t * al, int32_t vx, int32_t vy) {
    (*al).i++;
    if (al->active > 0) {
        (*al).x -= (*al).vx/4;
        (*al).y -= (*al).vy/8;
        if (((*al).tempx != (*al).x >> 14) || ((*al).tempy != (*al).y >> 14)){
            delete_alien(al);
            if ((*al).i >= 20)
            {
                (*al).i = 0;
                switch((*al).m)
                {
                    case 0:
                        (*al).vx = 1 * vx << 14;
                        (*al).vy = 0 * vy << 14;
                        (*al).m += 1;
                        break;
                    case 1:
                        (*al).vx = 0 * vx << 14;
                        (*al).vy = -1 * vy << 14;
                        (*al).m += 1;
                        break;
                    case 2:
                        (*al).vx = 1 * vx << 14;
                        (*al).vy = 0 * vy << 14;
                        (*al).m += 1;
                        break;
                    case 3:
                        (*al).vx = 0 * vx << 14;
                        (*al).vy = 1 * vy << 14;
                        (*al).m = 0;
                        break;
                }
            }
            draw_alien(al);
            //(*al).tempx = (*al).x >> 14;
            //(*al).tempy = (*al).y >> 14;
        }
    }
    if (al->active <= 0 && al-> active != -10){
      delete_alien(al);
      (*al).active = -10;
    }
}

void initLaser(struct laser_t * l, int x, int y, int vx, int vy)
{
    for (uint32_t i = 0 ; i < N_LASERS; i++)
    {
        l[i].active = 0;
        l[i].x = x << 14;
        l[i].y = y << 14;
        l[i].tempx = x << 14;
        l[i].vx = vx << 14;
        l[i].vy = vy << 14;
        l[i].tempf = 0;
    }
}


void drawLaser (struct laser_t * l, struct alien_t *al)
{
    for (uint32_t i = 0 ; i < N_LASERS; i++)
    {
        if (l[i].active == 1){
            gotoxy(((l[i].x>>14)),(l[i].y>>14)+1);
            printf("%c",95);
        }
    }
}

void deleteLaser(struct laser_t *l)
{
    for (uint32_t i = 0 ; i < N_LASERS; i++)
    {
        gotoxy((((l[i]).x>>14)),((l[i]).y>>14)+1);
        printf(" ");
    }
}

void updateLaserPos(struct laser_t *l, struct alien_t *al)
{
    for (uint32_t i = 0 ; i < N_LASERS; i++)
    {
        if (l[i].active == 1){
            l[i].tempx = l[i].x;
            l[i].tempy = l[i].y;
            l[i].x += l[i].vx;
            l[i].y += l[i].vy;
        }
    }
}


void shootLaser(struct laser_t *l, struct alien_t *al , int32_t vx, int32_t vy) {
    if (get_flag() > al->tempf + 10){
        al->tempf = get_flag();
        for (uint32_t i = 0 ; i < N_LASERS; i++)
        {
            if (l[i].active == 0)
            {
                l[i].active = 1;
                l[i].x = (*al).x - (1 << 14);
                l[i].y = (*al).y - (0 << 14);
                l[i].vx = vx << 14;
                l[i].vy = vy << 14;
                return;
            }
        }
    }
}

void moveLaser(struct laser_t *l, struct alien_t *al)
{
    deleteLaser(l);
    if  ((*al).active >=1) {
        updateLaserPos(l,al);
        drawLaser(l,al);
    }
}
