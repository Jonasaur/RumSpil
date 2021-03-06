#include "joystick.h"

void joystick_setup()
{
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

//USED TO BE IN MAIN()

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
