#include "alien.h"

void init_alien(struct alien_t * al, int8_t x, int8_t y, int8_t vx, int8_t vy)
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

            gotoxy((*al).x>>14,((*al).y>>14)+3);
            printf(" %c%c%c", 0xC9,0xBC,0xBA);
            break;
        case 0: {
            break;
        }
    }
}

/*
void draw_alien(struct alien_t * al)
{
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
}
*/

void delete_alien (struct alien_t * al)
{
        gotoxy(((*al).x>>14) + 3,(*al).y>>14);
        printf(" ");
        gotoxy((*al).x>>14,((*al).y>>14) + 1);
        printf("      ");
        gotoxy((*al).x>>14,((*al).y>>14) + 2);
        printf("       ");
        gotoxy((*al).x>>14,((*al).y>>14) + 3);
        printf("       ");
}

void move_alien(struct alien_t * al, int8_t vx, int8_t vy)
{
    (*al).i++;
    if (al->active > 0)
    {
        delete_alien(al);
        if ((*al).i >= 9)
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
        (*al).tempx = (*al).x;
        (*al).x -= (*al).vx;
        (*al).tempy = (*al).y;
        (*al).y -= (*al).vy;
        draw_alien(al);
    }
    if (al->active == 0)
    {
        delete_alien(al);
        al->active = -1;
    }

}
