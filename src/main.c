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
#include "ball.h"
#include "LED_control.h"
#include "joystick.h"
#include "menu.h"
//#include "calc_sin.h" //needs to be implemented

#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / b )



void setup()
{
    uart_init(921600);
    uart_clear();
    clrscr();

    timer_setup();
    joystick_setup();
    LED_setup();
}

volatile struct time timer; //Global variable
volatile struct time timer_s1;
volatile struct time timer_s2;

int main(void)
{
    //uint16_t input, oldinput;
    char uart_char[255];
    int8_t c_count;

    setup();

    while(1)
    {
        menu_selection(uart_char, &c_count);
        /*deleteBall(&theBall);
        updateBallPos(&theBall);
        printBall(&theBall);
        if (theBall.y >= 20)
        {
            theBall.vy = -theBall.vy;
        }
        */
    }
}
