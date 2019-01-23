#include "gamefunctions.h"

void initCounter(struct counter_t * c, int x) {
    (*c).lives = x;
    (*c).ammo = N_ROCKETS;
    (*c).bombs  = N_BOMBS;
}

void initSpaceship(struct spaceship_t * s, int x, int y) {
    (*s).x = x << 14;
    (*s).y = y << 14;
    (*s).tempx = x << 14;
    (*s).tempy = y << 14;
    (*s).tempf = 0;
}

/// All the structures with arrays, loops over the initialization
void initRocket(struct Rocket_t * r, int x, int y, int vx, int vy)
{
    for (uint8_t i = 0 ; i < N_ROCKETS; i++)
    {
        r[i].active = 0;
        r[i].x = x << 14;
        r[i].y = y << 14;
        r[i].tempx = x << 14;
        r[i].vx = vx << 14;
        r[i].vy = vy << 14;
        r[i].tempf = 0;
    }
}

void initBomb(struct Bomb_t * b, int x, int y, int vx, int vy)
{
    for (uint8_t i = 0 ; i < N_BOMBS; i++)
    {
        b[i].active = 0;
        b[i].x = x << 14;
        b[i].y = y << 14;
        b[i].tempx = x << 14;
        b[i].vx = vx << 14;;
        b[i].vy = vy << 14;
        b[i].tempf = 0;
    }

}

/// draws the spaceship, with goto and asci codes
void drawSpaceship (struct spaceship_t * s)
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

/// goes to the previous spaceship locations and prints spaces.
void deleteSpaceship (struct spaceship_t * s)
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

/// draws the array of rockets
void drawRocket (struct Rocket_t * r)
{
    for (uint8_t i = 0 ; i < N_ROCKETS; i++)
    {
        if (r[i].active == 1)
        {
            gotoxy(((r[i].x>>14)),(r[i].y>>14)+1);
            printf("%c%c",197, 196);
        }
    }
}

void drawBomb (struct Bomb_t * b)
{
    for (uint8_t i = 0 ; i < N_BOMBS; i++)
    {
        if (b[i].active == 1)
        {
            gotoxy(((b[i].x>>14)),(b[i].y>>14)+3);
            printf("%c",111);
        }
    }
}

void deleteRocket(struct Rocket_t * r)
{
    for (uint8_t i = 0 ; i < N_ROCKETS; i++)
    {
        {
            gotoxy((((r[i]).x>>14)),((r[i]).y>>14)+1);
            printf("  ");
        }
    }
}

void deleteBomb(struct Bomb_t * b)
{
    for (uint8_t i = 0 ; i < N_BOMBS; i++)
    {
        {
            gotoxy((((b[i]).x>>14)),((b[i]).y>>14)+3);
            printf("  ");
        }
    }
}

/// shoots rockets when player wants to
void shootRocket(struct Rocket_t *r, struct spaceship_t *s , struct counter_t *c, uint8_t * buffer, int8_t vx, int8_t vy) {
    /// only shoots if ammo > 0
    if ((*c).ammo > 0)
    {
        /// depletes ammo, and displays amount on LCD
        (*c).ammo -= 1;
        lcd_draw_rockets((*c).ammo, buffer, 1,3);
        lcd_push_buffer(buffer);
        /// when rocket is fired sets to active, and sets position at the spaceships position.
        for (uint8_t i = 0 ; i < N_ROCKETS; i++)
        {
            if (r[i].active == 0)
            {
                r[i].active = 1;
                r[i].x = (*s).x + (1 << 14);
                r[i].y = (*s).y - (2 << 14);
                r[i].vx = vx << 14;
                r[i].vy = vy << 14;
                return;
            }
        }
    }
}

/// works the same as shoot rockets
void shootBomb (struct Bomb_t *b, struct spaceship_t *s, struct counter_t *c, uint8_t * buffer, int8_t vx, int8_t vy) {
    if ((*c).bombs > 0)
    {
        (*c).bombs -= 1;
        lcd_draw_bombs((*c).bombs, buffer, 1,4);
        lcd_push_buffer(buffer);
        for (uint8_t i = 0 ; i < N_BOMBS ; i++)
        {
            if (b[i].active == 0)
            {
                b[i].active = 1;
                b[i].x = (*s).x + (1 << 14);
                b[i].y = (*s).y - (2 << 14);
                b[i].vx = vx << 14;
                b[i].vy = vy << 14;
                return;
            }
        }
    }
}

/// hit detection creates "hit boxes" for objects in the game,
void hitDetection (struct Rocket_t * r, struct Bomb_t * b, struct alien_t * al, struct asteroid_t * as, struct spaceship_t * s, struct powerup_t * p, struct counter_t * c, uint8_t * buffer, struct laser_t * l)
{

    for (uint8_t i = 0 ; i < 10 ; i++)
    {
        if ((r[i].x >= 176 << 14) || (r[i].x <= 5 << 14) || (r[i].y <= 14 << 14) || (r[i].y >= 47 << 14))
        {

            r[i].active = 0;

        }
        if ((b[i].x >= 176 << 14) || (b[i].x <= 5 << 14) || (b[i].y <= 14 << 14) || (b[i].y >= 47 << 14))
        {

            b[i].active = 0;

        } /// rocket hits alien
        if ((((r[i].x >= (*al).x) && (r[i].x <= (*al).x + (5 << 14))) && ((r[i].y <= (*al).y + (3<<14)) && (r[i].y >= (*al).y))) && (*al).active > 0 && r[i].active > 0)
        {
            r[i].active = 0;
            (*al).active -= 1;
        } /// bomb hits alien
        if ((((b[i].x >= (*al).x) && (b[i].x <= (*al).x + (5 << 14))) && ((b[i].y <= (*al).y + (3<<14)) && (b[i].y >= (*al).y))) && (*al).active > 0 && b[i].active > 0)
        {
            b[i].active = 0;
            (*al).active -= 3;

        } /// rocket hits asteroid
        if ((r[i].x >= (*as).x +(2<<14) && ((r[i].y <= (*as).y + (2<<14)) && (r[i].y >= (*as).y - (2<<14) ))) && (*as).active > 0 && r[i].active > 0)
        {
            r[i].active = 0;
            (*as).active -= 1;
        } /// bomb hits asteroid
        if ((b[i].x >= (*as).x +(2<<14) && ((b[i].y <= (*as).y + (2<<14)) && (b[i].y >= (*as).y - (2<<14) ))) && (*as).active > 0 && b[i].active > 0)
        {
            b[i].active = 0;
            (*as).active -= 3;
        }
        /// Ship hits alien

        if (((*s).x +(4<<14)) > ((*al).x - (1<<14)) && ((*s).x -(1<<14)) < ((*al).x + (5<<14)) && (*s).y > ((*al).y -(0<<14)) && (*s).y < ((*al).y + (4<<14)) )
        {
            (*s).active = 0;

        } /// ship hits asteroid
        if (((*s).x +(4<<14)) > ((*as).x - (4<<14)) && ((*s).x -(1<<14)) < ((*as).x + (4<<14)) && ((*s).y + (2<<14)) > ((*as).y -(2<<14)) && ((*s).y - (2<<14)) < ((*as).y + (2<<14)) )
        {
            (*s).active = 0;


        } /// ship hits powerup;
        if ( ((*p).x -(*s).x <= (2<<14)) && ( (*p).x -(*s).x >= (-2<<14)) &&  ((*p).y - (*s).y <= (2<<14)) && ((*p).y - (*s).y >= (-2<<14)) && (*p).active > 0)
            //if (((*s).x+ (4<<14)) > ((*p).x) - (1<<14) && (((*s).x) - (1<<14)) < ((*p).x + (1<<14)) && /* ((*s).y) + ((1<<14) > ((*p).y) -(1<<14)) && (((*s).y) -(1<<14)) < ((*p).y)+ (1<<14) */ (*p).y - (*s).y < 2)
        {
            (*p).active -= 1;
            (*c).ammo = 10;
            (*c).bombs = 5;
            lcd_draw_rockets((*c).ammo,buffer,1,3);
            lcd_draw_bombs((*c).bombs, buffer, 1,4);
            lcd_push_buffer(buffer);
            deletePowerup(p);
        }

        /// laser hits wall
        if  ((l[i].x >= 176 << 14) || (l[i].x <= 5 << 14) || (l[i].y <= 14 << 14) || (l[i].y >= 47 << 14))
        {
            l[i].active = 0;
        }

        /// laser hits ship
        if ( ((*s).x - l[i].x <= (1<<14)) && ( (*s).x -l[i].x >= (-1<<14)) &&  ((*s).y - l[i].y <= (1<<14)) && ((*s).y - l[i].y >= (-1<<14)) && l[i].active > 0)
        {
            (*s).active = 0;
            l[i].active = 0;

        }
    }
}


void updateRocketPos(struct Rocket_t * r)
{
    for (uint8_t i = 0 ; i < N_ROCKETS; i++)
    {
        if (r[i].active == 1)
        {
            r[i].tempx = r[i].x;
            r[i].tempy = r[i].y;
            r[i].x += r[i].vx;
            r[i].y += r[i].vy;
        }
    }
}

void updateBombPos(struct Bomb_t * b)
{
    for (uint8_t i = 0 ; i < N_BOMBS; i++)
    {
        if (b[i].active == 1)
        {
            b[i].tempx = b[i].x;
            b[i].tempy = b[i].y;
            b[i].x += b[i].vx;
            b[i].y += b[i].vy;
        }
    }
}

void moveRocket(struct Rocket_t * r)
{
    deleteRocket(r);
    updateRocketPos(r);
    drawRocket(r);
}

void moveBomb(struct Bomb_t * b)
{
    deleteBomb(b);
    updateBombPos(b);
    drawBomb(b);
}

void updateShippositionRight(struct spaceship_t * s)
{
    {
        (*s).tempx = (*s).x;
        (*s).x += 2 << 14;
    }
}

void updateShippositionLeft(struct spaceship_t * s)
{
    {
        (*s).tempx = (*s).x;
        (*s).x-= 2 << 14;

    }
}

void updateShippositionDown(struct spaceship_t * s) {
    {
        (*s).tempy = (*s).y;
        (*s).y += 2 << 14;
    }
}

void updateShippositionUp(struct spaceship_t * s) {
    {
        (*s).tempy = (*s).y;
        (*s).y-= 2 << 14;
    }
}

void respawn(struct spaceship_t * s, struct counter_t * c, uint8_t * buffer) {
    lcd_draw_hearts((*c).lives,buffer, 1, 2);
    lcd_write_string("Holy Resources",buffer, 0, 0);
    lcd_push_buffer(buffer);
    if ((*s).active == 0 && (*c).lives >= 1)
    {
        deleteSpaceship(s);
        (*s).active = 1;
        (*c).lives -= (1);
        initSpaceship(s, 15, 15);
        drawSpaceship(s);
    }
}

void controlPowerups(struct powerup_t * p) {
    if ((*p).active == 1) {
        drawPowerup(p);
    }
    if ((*p).active <= 0 && (*p).active != -10){
        deletePowerup(p);
        (*p).active = -10;
    }
}

void background(int x, int y) {
    gotoxy(x,y);
    printf("%c",42);
}

void gravityRockets(struct Rocket_t * r, struct asteroid_t * as) {
    //brug 32 for at undgå overflow. Vi har burg for at shifte for at opnå præccision når vi kigger på kredsløb.
    //afstand til asteroide
    static int32_t Dvx[N_ROCKETS];
    static int32_t Dvy[N_ROCKETS];
    int32_t dy[N_ROCKETS];
    int32_t dx[N_ROCKETS];
    int32_t F[N_ROCKETS];
    int32_t Dvx_old[N_ROCKETS];
    int32_t Dvy_old[N_ROCKETS];
    int32_t r2[N_ROCKETS];
    int32_t G = 2500 << 14; //int32_t G = as->G << 14; //25
    int32_t countLimit = (1 << 13) / 3;

    for (int8_t i = 0; i < N_ROCKETS; i++) {
        if ((r[i].active == 1)) {

            dx[i] = (as->x - r[i].x ) >> 14;
            dy[i] = (as->y - r[i].y ) >> 14;

            r2[i] = (sqrtI2I(dx[i] * dx[i] + dy[i] * dy[i]) * sqrtI2I(dx[i] * dx[i] + dy[i] * dy[i])) << 11; //giver radius i anden
            //r2[i] = r2[i] << 11;// Hvad vi gerne vil er at beregne en hastighedsændring som følge af asteroiden.  Dvs: v = v + Delta v
            F[i] = G / r2[i];

            Dvx_old[i] = Dvx[i];
            Dvy_old[i] = Dvy[i];

            if (abs(Dvx_old[i]) > abs(Dvx[i]) ) { // for negativ til positv ændring
                Dvx[i] = 0;
            }
            if (abs(Dvy_old[i]) > abs(Dvy[i]) ) {
                Dvy[i] = 0;
            }
            //Afgører om påvirkningen er positivt eller negativt.
            //Påvirkningen er mindre, jo større r2 er. r2 er det reciprokke af radius i anden.

            Dvx[i] += ((dx[i] / abs(dx[i])) * F[i]);
            Dvy[i] += ((dy[i] / abs(dy[i])) * F[i]);

            if (Dvx[i] >= countLimit || Dvx[i] <= -(countLimit)) {
                r[i].vx += ((Dvx[i] / abs(Dvx[i])) << 14);
                Dvx[i] = 0;
            }
            if (Dvy[i] >= countLimit || Dvy[i] <= -(countLimit)) {
                r[i].vy += ((Dvy[i] / abs(Dvy[i])) << 14);
                Dvy[i] = 0;
            }
        }
        else {
            Dvx[i] = 0;
            Dvy[i] = 0;
        }
    }
}

void gravityBombs(struct Bomb_t * b, struct asteroid_t * as) {
    //brug 32 for at undgå overflow. Vi har burg for at shifte for at opnå præccision når vi kigger på kredsløb.
    //afstand til asteroide
    static int32_t Dvx[N_BOMBS];
    static int32_t Dvy[N_BOMBS];
    int32_t dy[N_BOMBS];
    int32_t dx[N_BOMBS];
    int32_t F[N_BOMBS];
    int32_t Dvx_old[N_BOMBS];
    int32_t Dvy_old[N_BOMBS];
    int32_t r2[N_BOMBS];
    int32_t G = 2500 << 14; //int32_t G = as->G << 14; //25
    int32_t countLimit = (1 << 13) / 3;

    for (int8_t i = 0; i < N_BOMBS; i++) {
        if ((b[i].active == 1)) {

            dx[i] = (as->x - b[i].x ) >> 14;
            dy[i] = (as->y - b[i].y ) >> 14;

            r2[i] = (sqrtI2I(dx[i] * dx[i] + dy[i] * dy[i]) * sqrtI2I(dx[i] * dx[i] + dy[i] * dy[i])) << 11; //giver radius i anden
            //r2[i] = r2[i] << 11;// Hvad vi gerne vil er at beregne en hastighedsændring som følge af asteroiden.  Dvs: v = v + Delta v
            F[i] = G / r2[i];

            Dvx_old[i] = Dvx[i];
            Dvy_old[i] = Dvy[i];

            if (abs(Dvx_old[i]) > abs(Dvx[i]) ) { // for negativ til positv ændring
                Dvx[i] = 0;
            }
            if (abs(Dvy_old[i]) > abs(Dvy[i]) ) {
                Dvy[i] = 0;
            }
            //Afgører om påvirkningen er positivt eller negativt.
            //Påvirkningen er mindre, jo større r2 er. r2 er det reciprokke af radius i anden.

            Dvx[i] += ((dx[i] / abs(dx[i])) * F[i]);
            Dvy[i] += ((dy[i] / abs(dy[i])) * F[i]);

            if (Dvx[i] >= countLimit || Dvx[i] <= -(countLimit)) {
                b[i].vx += ((Dvx[i] / abs(Dvx[i])) << 14);
                Dvx[i] = 0;
            }
            if (Dvy[i] >= countLimit || Dvy[i] <= -(countLimit)) {
                b[i].vy += ((Dvy[i] / abs(Dvy[i])) << 14);
                Dvy[i] = 0;
            }
        }
        else {
            Dvx[i] = 0;
            Dvy[i] = 0;
        }
    }
}
