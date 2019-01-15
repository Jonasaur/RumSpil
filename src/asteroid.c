
void initAsteroid(struct asteroid_t * a, int x, int y)
{
    (*a).x = x << 14;
    (*a).y = y << 14;
    (*a).tempx = x << 14;
    (*a).tempy = y << 14;
    (*a).tempf = 0;
}

void draw_asteroid(struct asteroid_t * a)
{
    //---------------------------------------------------\\

    //                Draw ASCII asteroid here

    //---------------------------------------------------\\
    gotoxy((*a).x>>14,(*a).y>>14);
    printf("   _");
    gotoxy(((*a).x>>14)+1,(*a).y>>14);
    printf(" </^\\>");
    gotoxy(((*a).x>>14)+2,(*a).y>>14)
    printf("</¤^¤\\>");
    gotoxy(((*a).x>>14)+3,(*a).y>>14);
    print("  ╔╝║╚╗");

    /*
    gotoxy((*a).x>>14,(*a).y>>14);
    printf("   _");
    gotoxy(((*a).x>>14)+1,(*a).y>>14);
    printf(" </^\>");
    gotoxy(((*a).x>>14)+2,(*a).y>>14)
    printf("</¤⌂¤\>");
    gotoxy(((*a).x>>14)+3,(*a).y>>14);
    print("  ╔╝║╚╗");
    */
}
