/*
#include "alien.h"

void init_alien(struct alien_t * al, int8_t x, int8_t y, int8_t vx, int8_t vy)
{
    for (uint8_t i = 0 ; i < N_ALIENS ; i++)
    {
        al[i].x = x << 14;
        al[i].y = y << 14;
        al[i].tempx = x << 14;
        al[i].tempy = y << 14;
        al[i].vx = vx << 14;
        al[i].vy = vy << 14;
        al[i].active = 0;
        al[i].tempf = 0;
        al[i].m = 0;
    }
}

void spawn_alien(struct alien_t * al)
{
    for (uint8_t i = 0 ; i < N_ALIENS ; i++)
    {
        if (al[i].active == 0)
        {
            al[i].active = 3;
            al[i].x = 160;
            al[i].y = 30; //rand() % (MAX_RAND + 1 - MIN_RAND) + MIN_RAND; //random number in range of MIN_RAND to MAX_RAND
            al[i].m = 0; //rand() % 4; // random number from 0 - 3 (the 4 different stages of movement of the alien)
            return;
        }
    }
}

void delete_alien (struct alien_t * al)
{
    for (uint8_t i = 0 ; i < N_ALIENS ; i++)
    {
        gotoxy((al[i].x >> 14) + 3,al[i].y >> 14);
        printf(" ");
        gotoxy(al[i].x >> 14, (al[i].y >> 14) + 1);
        printf("      ");
        gotoxy(al[i].x >> 14,(al[i].y >> 14) + 2);
        printf("       ");
        gotoxy(al[i].x >> 14,(al[i].y >> 14) + 3);
        printf("       ");
    }
}

void draw_alien(struct alien_t * al)
{
    for (uint8_t i = 0 ; i < N_ALIENS ; i++)
    {
        if (al[i].active == 1)
        {
            switch (al[i].active) {
                case 3:
                    if (get_anim() == 1)
                    {
                        gotoxy(al[i].x>>14,al[i].y>>14);
                        printf("   %c",(0x5F));
                        gotoxy(al[i].x>>14,(al[i].y>>14)+1);
                        printf(" %c%c%c%c%c",0x3C,0x2F,0x5E,0x5C,0x3E);
                        gotoxy(al[i].x>>14,(al[i].y>>14)+2);
                        printf("%c%c%c%c%c%c%c",0x3C,0x2F,0xCF,0x2D,0xCF,0x5C,0x3E);
                        gotoxy(al[i].x>>14,(al[i].y>>14)+3);
                        printf(" %c%c%c%c%c", 0xC9,0xBC,0xBA,0xC8,0xBB);
                    }
                    else
                    {
                        gotoxy(al[i].x>>14,al[i].y>>14);
                        printf("   %c",(0x5F));
                        gotoxy(al[i].x>>14,(al[i].y>>14) + 1);
                        printf(" %c%c%c%c%c",0x3C,0x2F,0x5E,0x5C,0x3E);
                        gotoxy(al[i].x>>14,(al[i].y>>14) + 2);
                        printf("%c%c%c%c%c%c%c",0x3C,0x2F,0xCF,0x4F,0xCF,0x5C,0x3E);
                        gotoxy(al[i].x>>14,(al[i].y>>14) + 3);
                        printf(" %c%c%c%c%c", 0xCD,0xBC,0xBA,0xC8,0xCD);
                    }
                    break;
                case 2:
                    gotoxy(al[i].x>>14,al[i].y>>14);
                    printf("   %c",(0x5F));
                    gotoxy(al[i].x>>14,(al[i].y>>14)+1);

                    printf("%c%c%c%c",0x2F,0x5E,0x5C,0x3E);
                    gotoxy(al[i].x>>14,(al[i].y>>14)+2);
                    printf("%c%c%c%c%c%c",0x2F,0xCF,0x2D,0xCF,0x5C,0x3E);

                    gotoxy(al[i].x>>14,(al[i].y>>14)+3);
                    printf(" %c%c%c", 0xC9,0xBC,0xBA);
                    break;
                case 1:
                    gotoxy(al[i].x>>14,al[i].y>>14);
                    printf("   %c",(0x5F));
                    gotoxy(al[i].x>>14,(al[i].y>>14)+1);
                    printf("%c%c",0x5C,0x3E);
                    gotoxy(al[i].x>>14,(al[i].y>>14)+2);
                    printf("%c%c%c%c",0x2D,0xCF,0x5C,0x3E);

                    gotoxy(al[i].x>>14,(al[i].y>>14)+3);
                    printf(" %c%c%c", 0xC9,0xBC,0xBA);
                    break;
                case 0: {
                    break;
                }
            }
        }
    }
}

void move_alien(struct alien_t * al, int8_t vx, int8_t vy)
{
    for (uint8_t i = 0 ; i < N_ALIENS ; i++)
    {
        al[i].i++;
        if (al[i].active > 0)
        {
            delete_alien(al);
            /*if (al[i].i >= 9)
            {
                al[i].i = 0;
                switch(al[i].m)
                {
                    case 0:
                        al[i].vx = 1 * vx << 14;
                        al[i].vy = 0 * vy << 14;
                        al[i].m += 1;
                        break;
                    case 1:
                        al[i].vx = 0 * vx << 14;
                        al[i].vy = -1 * vy << 14;
                        al[i].m += 1;
                        break;
                    case 2:
                        al[i].vx = 1 * vx << 14;
                        al[i].vy = 0 * vy << 14;
                        al[i].m += 1;
                        break;
                    case 3:
                        al[i].vx = 0 * vx << 14;
                        al[i].vy = 1 * vy << 14;
                        al[i].m = 0;
                        break;
                }
            }*/ /*
            al[i].tempx = al[i].x;
            al[i].x -= al[i].vx;
            al[i].tempy = al[i].y;
            al[i].y -= al[i].vy;
            draw_alien(al);
        }
        if (al[i].active == 0)
        {
            delete_alien(al);
            al[i].active = -1;
        }

    }
}*/
