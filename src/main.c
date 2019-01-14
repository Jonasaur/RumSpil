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
//#include "timer.h"
//#include "ball.h"
//#include "calc_sin.h" //needs to be implemented

#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / b )



void setup()
{
    uart_init(9600);
    uart_clear();
    clrscr();
    // Enable clock for GPIO Port
    RCC->AHBENR  |= RCC_AHBPeriph_GPIOA;
    RCC->AHBENR  |= RCC_AHBPeriph_GPIOB;
    RCC->AHBENR  |= RCC_AHBPeriph_GPIOC;

    //Right PC0
    GPIOC->MODER &= ~(0x00000003 << (0 * 2));
    GPIOC->MODER |=  (0x00000000 << (0 * 2));
    //Up PA4
    GPIOA->MODER &= ~(0x00000003 << (4 * 2));
    GPIOA->MODER |=  (0x00000000 << (4 * 2));
    //Center PB5
    GPIOB->MODER &= ~(0x00000003 << (5 * 2));
    GPIOB->MODER |=  (0x00000000 << (5 * 2));
    //Left PC1
    GPIOC->MODER &= ~(0x00000003 << (1 * 2));
    GPIOC->MODER |=  (0x00000000 << (1 * 2));
    //Down PB0
    GPIOB->MODER &= ~(0x00000003 << (0 * 2));
    GPIOB->MODER |=  (0x00000000 << (0 * 2));

    //LED-Setup
    //RED
    GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2)); // Clear speed register
    GPIOB->OSPEEDR |= (0x00000002 << (4 * 2)); // set speed register (0x01 - 10
    GPIOB->OTYPER &= ~(0x0001 << (4)); // Clear output type register
    GPIOB->OTYPER |= (0x0000 << (4)); // Set output type register (0x00 -
    GPIOB->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
    GPIOB->MODER |= (0x00000001 << (4 * 2)); // Set mode register (0x00 –

    //GREEN
    GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2)); // Clear speed register
    GPIOC->OSPEEDR |= (0x00000002 << (7 * 2)); // set speed register (0x01 - 10
    GPIOC->OTYPER &= ~(0x0001 << (7)); // Clear output type register
    GPIOC->OTYPER |= (0x0000 << (7)); // Set output type register (0x00 -
    GPIOC->MODER &= ~(0x00000003 << (7 * 2)); // Clear mode register
    GPIOC->MODER |= (0x00000001 << (7 * 2)); // Set mode register (0x00 –

    //BLUE
    GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2)); // Clear speed register
    GPIOA->OSPEEDR |= (0x00000002 << (9 * 2)); // set speed register (0x01 - 10
    GPIOA->OTYPER &= ~(0x0001 << (9)); // Clear output type register
    GPIOA->OTYPER |= (0x0000 << (9)); // Set output type register (0x00 -
    GPIOA->MODER &= ~(0x00000003 << (9 * 2)); // Clear mode register
    GPIOA->MODER |= (0x00000001 << (9 * 2)); // Set mode register (0x00 –

    GPIOA->ODR |= (0x0001 << 9); //Set pin PA1 to high
    GPIOB->ODR |= (0x0001 << 4); //Set pin PA1 to high
    GPIOC->ODR |= (0x0001 << 7); //Set pin PA1 to high
}

struct time
{
    uint32_t hs, s, m, h, f;
};

volatile struct time timer; //Global variable
volatile struct time timer_s1;
volatile struct time timer_s2;

int setLED (int in)
{
    switch(in)
    {
        //NO INPUT
    case 0:
    {
        GPIOA->ODR |= (0x0001 << 9); //Blue
        GPIOB->ODR |= (0x0001 << 4); //Red
        GPIOC->ODR |= (0x0001 << 7); //Green
    }
    break;

    case 1: //UP
    {
        GPIOA->ODR &= ~(0x0001 << 9); //Blue
        GPIOB->ODR |= (0x0001 << 4); //Red
        GPIOC->ODR |= (0x0001 << 7); //Green
    }
    break;
    case 2: //DOWN
    {
        GPIOA->ODR |= (0x0001 << 9); //Blue
        GPIOB->ODR &= ~(0x0001 << 4); //Red
        GPIOC->ODR |= (0x0001 << 7); //Green
    }
    break;
    case 4: //LEFT
    {
        GPIOA->ODR |= (0x0001 << 9); //Blue
        GPIOB->ODR |= (0x0001 << 4); //Red
        GPIOC->ODR &= ~(0x0001 << 7); //Green
    }
    break;
    case 8: //RIGHT
    {
        GPIOA->ODR &= ~(0x0001 << 9); //Blue
        GPIOB->ODR &= ~(0x0001 << 4); //Red
        GPIOC->ODR |= (0x0001 << 7); //Green
    }
    break;
    case 16: //CENTER
    {
        GPIOA->ODR &= ~(0x0001 << 9); //Blue
        GPIOB->ODR &= ~(0x0001 << 4); //Red
        GPIOC->ODR &= ~(0x0001 << 7); //Green
    }
    break;
    default: //NO INPUT
    {
        GPIOA->ODR |= (0x0001 << 9); //Blue
        GPIOB->ODR |= (0x0001 << 4); //Red
        GPIOC->ODR |= (0x0001 << 7); //Green
    }
    break;
    }
}

int16_t readJoystick()
{
    uint16_t val_r, val_u, val_c, val_l, val_d, val_dir;
    //Register button presses
    val_r = (GPIOC->IDR & (0x0001 << 0)) << 3; //Right PC0
    val_u = (GPIOA->IDR & (0x0001 << 4)) >> 4; //Up PA4
    val_c = (GPIOB->IDR & (0x0001 << 5)) >> 1; //Center PB5
    val_l = (GPIOC->IDR & (0x0001 << 1)) << 1; //Left PC1
    val_d = (GPIOB->IDR & (0x0001 << 0)) << 1; //Down PB0
    val_dir = val_r + val_u + val_c + val_l + val_d;
    return val_dir;
}

int main(void)
{
    uint16_t input, oldinput;
    char uart_char[255];
    int8_t c_count;

    setup();
    timer_setup();

    /*fgcolor(15);
    struct ball_t theBall;
    initBall(&theBall,10,10,1,0);

    int * pt;
    pt = &theBall.y;
    */

    while(1)
    {
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

        //input = readJoystick();
        //setLED(input);
        //time_print(10, 20);

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
