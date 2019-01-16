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

void initRocket(struct Rocket_t *r, int x, int y, int vx)
{
    for (uint8_t i = 0 ; i < 10 ; i++){
        r[i].active = 0;
        r[i].x = x << 14;
        r[i].y = y << 14;
        r[i].tempx = x << 14;
        r[i].vx = vx << 14;
        r[i].tempf = 0;
    }
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

void drawRocket (struct Rocket_t *r)
{
    for (uint8_t i = 0 ; i < 10 ; i++)
    {
        if (r[i].active == 1)
        {
            gotoxy(((r[i].x>>14)+1),(r[i].y>>14));
            printf("%c",95);
        }
    }
}

void deleteRocket(struct Rocket_t *r)
{
    for (uint8_t i = 0 ; i < 10 ; i++)
    {
       // if (r[i].active == 1 || r[i].active == 0)
        {
            gotoxy((((r[i]).x>>14)+1),((r[i]).y>>14));
            printf(" ");
        }
    }
}

void shootRocket (struct Rocket_t *r, struct spaceship_t *s )
{


    for (uint8_t i = 0 ; i < 10 ; i++)
    {
        if (r[i].active == 0)
        {
            r[i].active = 1;
            r[i].x = (*s).x+(1<<14);
            r[i].y = (*s).y-(2<<14);
            return;
        }
    }
}

void hitDetection (struct Rocket_t *r){

 for (uint8_t i = 0 ; i < 10 ; i++)
    {
      if (r[i].x == 180 << 14) {

       r[i].active = 0;

      }


    }
}

void Controls(struct spaceship_t *s, struct Rocket_t *r)
{
    char uart_char[255];
    static int8_t c_count;

    switch (keyboard_read(uart_char, &c_count))
    {

    case 3:   /// up
    {
        if ((*s).y > 3 << 14)
        {
            deleteSpaceship(s);
            updateShippositionUp(s);
            drawSpaceship(s);
            c_count = 0;
        }
        break;
    }
    case 5:   /// right
    {
        if ( (*s).x < 176 << 14 ){
        deleteSpaceship(s);
        updateShippositionRight(s);
        drawSpaceship(s);
        c_count = 0;
        }
        break;

    }
    case 6:   /// left
    {
        if ( (*s).x > 3 << 14 )
        {
            deleteSpaceship(s);
            updateShippositionLeft(s);
            drawSpaceship(s);
            c_count = 0;
        }
        break;

    }
    case 4:    /// down
    {
        if ( (*s).y < 47 << 14)
        {
            deleteSpaceship(s);
            updateShippositionDown(s);
            drawSpaceship(s);
            c_count = 0;
        }
        break;
    }
    case 7 : // space-bar
    {
        shootRocket(r,s);
        break;
    }

    }

}

void updateRocketPos (struct Rocket_t *r)
{

    for (uint8_t i = 0 ; i < 10 ; i++)
    {
        if (r[i].active == 1)
        {
            r[i].tempx = (*r).x;
            r[i].x += (*r).vx;
            // (*b).tempf = timer.f;
        }
    }
}

void moveRocket (struct Rocket_t *b)
{
    //if ((*b).active == 1){
        deleteRocket(b);
        updateRocketPos(b);
        drawRocket(b);
    //}
}

void updateShippositionRight ( struct spaceship_t *s)
{
    // if (timer.f != (*s).tempf)
    {
        (*s).tempx = (*s).x;
        (*s).x+= 2 << 14;
        //(*s).tempf = timer.f;


    }
}

void updateShippositionLeft ( struct spaceship_t *s)
{
    // if (timer.f != (*s).tempf)
    {

        (*s).tempx = (*s).x;
        (*s).x-= 2 << 14;
        // (*s).tempf = timer.f;

    }
}


void updateShippositionDown ( struct spaceship_t *s)
{
    //if (timer.f != (*s).tempf)
    {
        (*s).tempy = (*s).y;
        (*s).y+= 2 << 14;
        // (*s).tempf = timer.f;

    }
}


void updateShippositionUp ( struct spaceship_t *s)
{

    {
        (*s).tempy = (*s).y;
        (*s).y-= 2 << 14;
        // (*s).tempf = timer.f;

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