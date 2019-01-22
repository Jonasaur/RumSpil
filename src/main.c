/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "ansi.h"
#include "serial_com.h"
#include "timer.h"
#include "LED_control.h"
#include "joystick.h"
#include "menu.h"
#include "asteroid.h"
#include "alien.h"
#include "gamefunctions.h"
#include "LCD.h"
#include "powerUps.h"

#include "config.h"

#include <stdlib.h>
#include <time.h>
//#include "calc_sin.h" //needs to be implemented

void setup()
{
    uart_init(UART_BAUDRATE);
    uart_clear();
    clrscr();

    timer_setup();
    joystick_setup();
    LED_setup();
    lcd_init();

    srand(time(0));

    background(41,8);
}

int main(void)
{
    //uint16_t input, oldinput;
    char uart_char[CHAR_ARRAY_LEN];
    int8_t c_count = 0;
    int8_t i_time = 0;
    setup();

    struct Rocket_t theRockets[N_ROCKETS];
    initRocket(theRockets, 15, 15, 2, 0);

    struct Bomb_t theBombs[N_BOMBS];
    initBomb(theBombs, 2, 1, 1, 0);

    struct alien_t the_alien;
    init_alien(&the_alien, 60, 30, 0, 0);

    struct spaceship_t theShip;
    initSpaceship(&theShip, 20, 30);

    struct asteroid_t theAsteroid;
    init_asteroid(&theAsteroid, 140, 20, 0, 0);

    struct counter_t theCounts;
    initCounter(&theCounts, 3, N_ROCKETS, N_BOMBS);

    struct powerup_t thePowerup;
    init_powerup(&thePowerup, 30, 15);

    uint8_t buffer [512];
    int16_t i = 0;

    //struct high_scores high_score[5];
    set_lvl(100);
    menu_selection(uart_char, &c_count, 1);

    memset(buffer,0x00,512);
    lcd_draw_hearts(theCounts.lives,buffer, 1, 2);
    lcd_write_string("Holy Recourses",buffer, 1, 0);
    lcd_draw_rockets(theCounts.ammo, buffer, 1, 3);
    lcd_draw_bombs(theCounts.bombs, buffer, 1, 4);
    lcd_push_buffer(buffer);

    while(1)
    {
        game_controls(&i_time, &theShip, theRockets, theBombs, &theCounts, buffer);
        if (get_flag() != (theShip).tempf && i_time == 0)
        {
            gravity(theRockets, &the_alien);
            moveRocket(theRockets);
            moveBomb(theBombs);
            move_alien(&the_alien);
            move_asteroid(&theAsteroid);
            hitDetection(theRockets,theBombs, &the_alien, &theAsteroid, &theShip ,&thePowerup, & theCounts , buffer );
            respawn(&theShip, &theCounts,buffer);
            theShip.tempf = get_flag();
            controlPowerups(&thePowerup);
        }


/*
        if (lost == true)
        {
            update_high_score(high_score);
            go to high score screen
        }
*/
    }

}
