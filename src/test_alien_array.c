/*void initRocket(struct Rocket_t *r, int x, int y, int vx)
{
    for (uint8_t i = 0 ; i < 10 ; i++)
    {
        r[i].active = 0;
        r[i].x = x << 14;
        r[i].y = y << 14;
        r[i].tempx = x << 14;
        r[i].vx = vx << 14;
        r[i].tempf = 0;
    }
}

void drawRocket (struct Rocket_t *r)
{
    for (uint8_t i = 0 ; i < 10 ; i++)
    {
        if (r[i].active == 1)
        {
            gotoxy(((r[i].x >> 14) + 1),(r[i].y >> 14));
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

void shootRocket (struct Rocket_t *r, struct spaceship_t *s)
{
    for (uint8_t i = 0 ; i < 10 ; i++)
    {
        if (r[i].active == 0)
        {
            r[i].active = 1;
            r[i].x = (*s).x + (1 << 14);
            r[i].y = (*s).y - (2 << 14);
            return;
        }
    }
}

void hitDetection(struct Rocket_t *r, struct Bomb_t *b, struct alien_t *al)
{

    for (uint8_t i = 0 ; i < 10 ; i++)
    {
        if (r[i].x == 180 << 14)
        {

            r[i].active = 0;

        }
        if (b[i].x == 180 << 14)
        {

            b[i].active = 0;

        }
        if ((r[i].x >= (*al).x && ((r[i].y <= (*al).y + (3<<14)) && (r[i].y >= (*al).y - (0<<14) ))) && (*al).active > 0 && r[i].active > 0)
        {
            r[i].active = 0;
            (*al).active -= 1;
        }
        if ((b[i].x >= (*al).x && ((r[i].y <= (*al).y + (3<<14)) && (b[i].y >= (*al).y - (0<<14) ))) && (*al).active > 0 && b[i].active > 0)
        {
            b[i].active = 0;
            (*al).active = 0;

        }
    }

}

void Controls(struct spaceship_t *s, struct Rocket_t *r, struct Bomb_t *b)
{
    char uart_char[255];
    static int8_t c_count;

    switch (keyboard_read(uart_char, &c_count))
    {
        case 3:   /// up
            if ((*s).y > 14 << 14)
            {
                deleteSpaceship(s);
                updateShippositionUp(s);
                drawSpaceship(s);
                c_count = 0;
            }
            break;
        case 5:   /// right
            if ( (*s).x < 176 << 14 )
            {
                deleteSpaceship(s);
                updateShippositionRight(s);
                drawSpaceship(s);
                c_count = 0;
            }
            break;
        case 6:   /// left
            if ( (*s).x > 5 << 14 )
            {
                deleteSpaceship(s);
                updateShippositionLeft(s);
                drawSpaceship(s);
                c_count = 0;
            }
            break;
        case 4:    /// down
            if ( (*s).y < 47 << 14)
            {
                deleteSpaceship(s);
                updateShippositionDown(s);
                drawSpaceship(s);
                c_count = 0;
            }
            break;
        case 7 : // 1
            shootRocket(r,s);
            break;
        case 2: // b-button
            shootBomb(b,s);
            break;
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
        }
    }
}

void moveRocket (struct Rocket_t *r)
{
    //if ((*b).active == 1){
    deleteRocket(r);
    updateRocketPos(r);
    drawRocket(r);
    //}
}
*/
