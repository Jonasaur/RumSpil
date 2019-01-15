#include "LED_control.h"

void LED_setup() {
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
