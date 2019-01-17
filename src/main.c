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
#include <stdlib.h>
//#include "calc_sin.h" //needs to be implemented

//#define RAND_MAX 40
//#define RAND_MIN 10
#define UART_BAUDRATE 256000
#define CHAR_ARRAY_LEN 255

#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / b )



void setup()
{
    uart_init(UART_BAUDRATE);
    uart_clear();
    clrscr();

    timer_setup();
    joystick_setup();
    LED_setup();
}

//volatile struct time timer; //Global variable

int main(void)
{
    //uint16_t input, oldinput;
    char uart_char[CHAR_ARRAY_LEN];
    int8_t c_count;
    setup();
    //printf("%i",rand());

    struct spaceship_t theShip;
    initSpaceship(&theShip, 15, 15);

    struct Rocket_t theRockets[10];
    initRocket(theRockets, 15, 15, 2);

    struct Bomb_t theBombs[10];
    initBomb(theBombs, 2, 1, 1);

    struct alien_t the_alien;
    init_alien(&the_alien, 160, rand() % 50 , 1);

    set_lvl(100);

    menu_selection(uart_char, &c_count, 1);

    while(1)
    {
        Controls(&theShip, theRockets, theBombs);
        if (get_flag() != (theShip).tempf)
        {
            moveRocket(theRockets);
            moveBomb(theBombs);
            hitDetection(theRockets,theBombs, &the_alien);
            move_alien(&the_alien);

            theShip.tempf = get_flag();
        }
    }

}
