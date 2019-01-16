#include "asteroid.h"

void init_alien(struct alien_t * al, int x, int y, int vx)
{
    (*al).x = x << 14;
    (*al).y = y << 14;
    (*al).tempx = x << 14;
    (*al).tempy = y << 14;
    (*al).tempf = 0;
}

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

void move_alien(struct alien_t * al)
{
    if (get_level_flag() != (*al).tempf)
    {
        delete_alien(al);
        (*al).tempx = (*al).x;
        (*al).x -= 1 << 14;
        (*al).tempf = get_level_flag();
        draw_alien(al);
    }
}
