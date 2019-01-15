#include "gamefunctions.h"
#define ESC 0x1B

void initSpaceship(struct spaceship_t *s, int x, int y)
{
    (*s).x = x << 14;
    (*s).y = y << 14;
    (*s).tempx = x << 14;
    (*s).tempy = y << 14;
    (*s).tempf = 0;
}

void initRocket(struct Rocket_t *b, int x, int y, int vx)
{
    (*b).x = x << 14;
    (*b).y = y << 14;
    (*b).tempx = x << 14;
    (*b).vx = vx << 14;
    (*b).tempf = 0;
}

void drawSpaceship (struct spaceship_t *s)
{
    gotoxy((*s).x>>14,(*s).y>>14);
    printf("%c",206);
    gotoxy(((*s).x>>14)+1,(*s).y>>14);
    printf("%c",205);
    gotoxy(((*s).x>>14)+2,(*s).y>>14);
    printf("%c",205);
    gotoxy(((*s).x>>14)+3,(*s).y>>14);
    printf("%c",205);
    gotoxy(((*s).x>>14)+4,(*s).y>>14);
    printf("%c",231);
    gotoxy(((*s).x>>14)-1,(*s).y>>14);
    printf("%c",204);

    /// Thrusters, only to appear when moving
    gotoxy(((*s).x>>14)-2,(*s).y>>14);
    printf("%c",41);
    // gotoxy(((*s).x>>14)-3,(*s).y>>14);
    //printf("%c",41);

    /// Wings
    gotoxy((*s).x>>14,((*s).y>>14)+1);
    printf("%c",202);
    //gotoxy(x,y+2);
    //printf("%c",202);
    gotoxy((*s).x+1>>14,((*s).y>>14)-1);
    printf("%c",203);
}

void deleteSpaceship (struct spaceship_t *s)
{
    gotoxy((*s).x>>14,(*s).y>>14);
    printf(" ");
    gotoxy(((*s).x>>14)+1,(*s).y>>14);
    printf(" ");
    gotoxy(((*s).x>>14)+2,(*s).y>>14);
    printf(" ");
    gotoxy(((*s).x>>14)+3,(*s).y>>14);
    printf(" ");
    gotoxy(((*s).x>>14)+4,(*s).y>>14);
    printf(" ");
    gotoxy(((*s).x>>14)-1,(*s).y>>14);
    printf(" ");

    /// Thrusters, only to appear when moving
    gotoxy(((*s).x>>14)-2,(*s).y>>14);
    printf(" ");
    // gotoxy(((*s).x>>14)-3,(*s).y>>14);
    // printf(" ");

    /// Wings
    gotoxy((*s).x>>14,((*s).y>>14)+1);
    printf(" ");
    //gotoxy(x,y+2);
    //printf("%c",202);
    gotoxy((*s).x+1>>14,((*s).y>>14)-1);
    printf(" ");
}

void drawRocket (struct Rocket_t *b)
{
    gotoxy((((*b).x>>14)+1),((*b).y>>14)+1);
    printf("%c",95);
}

void deleteRocket(struct Rocket_t *b)
{
    gotoxy((((*b).x>>14)+1),((*b).y>>14)+1);
    printf(" ");
}

void shootRocket (struct Rocket_t *b, struct spaceship_t *s ) {
    (*b).active = 1;
    (*b).x = (*s).x+(1<<14);
    (*b).y = (*s).y-(2<<14);
}

void Controls(struct spaceship_t *s, struct Rocket_t *b, char * uart_char, int8_t * c_count)
{
    switch (keyboard_read(uart_char, &c_count))
    {
    case 3:   /// up
    {
        deleteSpaceship(s);
        updateShippositionUp(s);
        drawSpaceship(s);
        c_count = 0;
        break;
    }
    case 5:   /// right
    {
        deleteSpaceship(s);
        updateShippositionRight(s);
        drawSpaceship(s);
        c_count = 0;
        break;
    }
    case 6:   /// left
    {
        deleteSpaceship(s);
        updateShippositionLeft(s);
        drawSpaceship(s);
        c_count = 0;
        break;
    }
    case 4:    /// down
    {
        deleteSpaceship(s);
        updateShippositionDown(s);
        drawSpaceship(s);
        c_count = 0;
        break;
    }
    case 7 : // space-bar
        shootRocket(b,s);
    }
}

void moveRocket (struct Rocket_t *b)
{
    if ((*b).active == 1){
        deleteRocket(b);
        updateRocketPos(b);
        drawRocket(b);
    }
}

void updateRocketPos(struct Rocket_t *b)
{
    (*b).tempx = (*b).x;
    (*b).x += (*b).vx;
    (*b).tempf = get_flag() ;
}

void updateShippositionRight(struct spaceship_t *s)
{
    if (get_flag() != (*s).tempf)
    {
        (*s).tempx = (*s).x;
        (*s).x+= 1 << 14;
        (*s).tempf = get_flag();
    }
}

void updateShippositionLeft(struct spaceship_t *s)
{
    if (get_flag() != (*s).tempf)
    {
        (*s).tempx = (*s).x;
        (*s).x-= 1 << 14;
        (*s).tempf = get_flag();
    }
}

void updateShippositionDown(struct spaceship_t *s)
{
    if (get_flag() != (*s).tempf)
    {
        (*s).tempy = (*s).y;
        (*s).y+= 1 << 14;
        (*s).tempf = get_flag();
    }
}

void updateShippositionUp(struct spaceship_t *s)
{
    if (get_flag() != (*s).tempf)
    {
        (*s).tempy = (*s).y;
        (*s).y-= 1 << 14;
        (*s).tempf = get_flag();
    }
}

/*void collisionDetect(struct ball_t *b)
{
    if(((*b).y >> 14) >= (20) && ((*b).vy >> 14) > (0)){
    (*b).vy = -(*b).vy;
    }
    else if(((*b).y >> 14) <= 1 && ((*b).vy >> 14) < 0){
    (*b).vy = -(*b).vy;
    }
    else if(((*b).x >> 14) >= 80 && ((*b).vx >> 14) > 0){
    (*b).vx = -(*b).vx;
    }
    else if(((*b).x >> 14) <= 1 && ((*b).vx >> 14) < 0){
    (*b).vx = -(*b).vx;
    }
}*/
