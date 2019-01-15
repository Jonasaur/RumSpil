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
    uart_init(9600);
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

    /*fgcolor(15);
    struct ball_t theBall;
    initBall(&theBall,10,10,1,0);

    int * pt;
    pt = &theBall.y;
    */

    while(1)
    {
        menu_selection(uart_char, &c_count);
        switch(keyboard_read(uart_char, &c_count)) {
            case 1: {
                printf("%s",uart_char);
                break;
            }
            case 2: {
                printf("%c",0x7F);
                break;
            }
            case 3: { //what to do if "Up" is pushed
                printf("Up!");
                break;
            }
            case 4: { //what to do if "Down" is pushed
                uart_char[c_count - 1] = 0;
                printf("Down!");
                break;
            }
            case 5: { //what to do if "Right" is pushed
                uart_char[c_count - 1] = 0;
                printf("Right!");
                break;
            }
            case 6: { //what to do if "Left" is pushed
                uart_char[c_count - 1] = 0;
                printf("Left!");
                break;
            }
        }

        /*
        input = readJoystick();
        setLED(input);
        time_print(10, 20);

        if(input != oldinput)
        {
            switch(input)
            {
            case 2: //DOWN
            {
                stop_timer();
                timer.hs = 0; timer_s1.hs = 0; timer_s2.hs = 0;
                 timer.s = 0;  timer_s1.s = 0;  timer_s2.s = 0;
                 timer.m = 0;  timer_s1.m = 0;  timer_s2.m = 0;
                 timer.h = 0;  timer_s1.h = 0;  timer_s2.h = 0;
            }
            break;
            case 4: //LEFT
            {
                timer_s1 = timer;
            }
            break;
            case 8: //RIGHT
            {
                timer_s2 = timer;
            }
            break;
            case 16:
            {
                if (TIM2->CR1 & (0x01)) stop_timer();
                else start_timer();
                break;
            }
            }
            //printf("Hey, look at this number: %d\n", input);
        }
        oldinput = input;
*/

/*
        deleteBall(&theBall);
        updateBallPos(&theBall);
        printBall(&theBall);
        if (theBall.y >= 20)
        {
            theBall.vy = -theBall.vy;
        }
        */
    }
}
