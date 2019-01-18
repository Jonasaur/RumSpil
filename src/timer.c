#include "timer.h"

volatile struct time timer; //Global variable

void timer_setup()
{
    RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;

    TIM2->CR1 = (0x0000); //Settings of the Control Register 1 (CR1)
    TIM2->PSC = (0x28); //Prescaler
    TIM2->ARR = (0x3CF8); //Reload value - How often the interrupt is triggered
    TIM2->DIER |= 0x0001; // Enable timer 2 interrupts //DMA/Interrupt Enable

    NVIC_SetPriority(TIM2_IRQn, 0); // Set interrupt priority
    NVIC_EnableIRQ(TIM2_IRQn); // Enable interrupt

    timer.hs = 0;
    timer.s = 0;
    timer.m = 0;
    timer.h = 0;
    timer.f = 0;
    timer.al = 0;
    timer.n = 0;
    timer.anim = 0;

    start_timer();
}

void start_timer()
{
    TIM2->CR1 |= (0x01);
}

void stop_timer()
{

    TIM2->CR1 &= ~(0x01);
}

void TIM2_IRQHandler(void)
{
    //Whenever it is interrupted, do this
    timer.hs++;
    if (timer.hs >= 100)
    {
        timer.s++;
        timer.hs = 0;
    }
    if (timer.s >= 60)
    {
        timer.m++;
        timer.s = 0;
    }
    if (timer.m >= 60)
    {
        timer.h++;
        timer.m = 0;
    }
    if (timer.h >= 24)
    {
        timer.h = 0;
    }
    if ((timer.hs & 1) == 0) {
        timer.f++;
    }
    if ((timer.hs & timer.n) == 0) {
        timer.al++;
    }
    if ((timer.hs & timer.n) == 0) {
        timer.anim = 1;
    }
    TIM2->SR &= ~0x0001; //reset the interrupt
}

int8_t get_flag()
{
    return timer.f;
}

int8_t get_anim()
{
    if (timer.anim == 1){
        timer.anim = 0;
        return 1;
    } else return 0;
}

void set_lvl(int8_t lvl_input) {
    timer.n = lvl_input;
}

int8_t get_level_flag() {
    return timer.al;
}



