#include "serial_com.h"

char keyboard_read(char * uart_char, int8_t * c_count)
{
    if (uart_get_count() > 0)
    {
        uart_char[*c_count] = uart_get_char();
        if (uart_char[(*c_count) - 2] == (0x1B) && uart_char[(*c_count) - 1] == (0x5B))
        {
            switch(uart_char[(*c_count)])
            {
                case 65:   //up
                    (*c_count) -= 1;
                    uart_char[(*c_count) - 1] = 0;
                    return 3;
                    break;
                case 66:   //down
                    (*c_count) -= 1;
                    uart_char[(*c_count) - 1] = 0;
                    return 4;
                    break;
                case 67:   //right
                    (*c_count) -= 1;
                    uart_char[(*c_count) - 1] = 0;
                    return 5;
                    break;
                case 68:   //left
                    (*c_count) -= 1;
                    uart_char[(*c_count) - 1] = 0;
                    return 6;
                    break;
            }
            (*c_count) -= 2;
        }
        if (uart_char[(*c_count)] == (0x31))
        {
            return 7;
        }
        if (uart_char[(*c_count)] == (0x32))
        {
            return 2;
        }
        if (uart_char[(*c_count)] == (0x33))
        {
            return 8;
        }
        if (uart_char[(*c_count)] == (0x0D))
        {
            uart_char[(*c_count)] = 0;
            (*c_count) = 0;
            return 1;
        }
        (*c_count)++;
        /*if (uart_char[(*c_count)] != 0)
        {
            uart_char[(*c_count)] = 0;
            (*c_count) = 0;
            return 20;
        }*/
    }
    return 0;
}

void game_controls(int8_t * i_time, struct spaceship_t * s, struct Rocket_t * r, struct Bomb_t * b, struct counter_t * c, uint8_t * buffer) {
    char uart_char[255];
    static int8_t c_count;
    switch(keyboard_read(uart_char, &c_count)) {
        case 3:   // up
            c_count = 0;
            if ((*s).y > 14 << 14 && (*i_time) == 0)
            {
                deleteSpaceship(s);
                updateShippositionUp(s);
                drawSpaceship(s);
            }
            break;
        case 5:   // right
            c_count = 0;
            if ((*s).x < 176 << 14 && (*i_time) == 0)
            {
                deleteSpaceship(s);
                updateShippositionRight(s);
                drawSpaceship(s);
            }
            break;
        case 6:   // left
            c_count = 0;
            if ((*s).x > 5 << 14 && (*i_time) == 0)
            {
                deleteSpaceship(s);
                updateShippositionLeft(s);
                drawSpaceship(s);
            }
            break;
        case 4:    // down
            c_count = 0;
            if ((*s).y < 47 << 14 && (*i_time) == 0)
            {
                deleteSpaceship(s);
                updateShippositionDown(s);
                drawSpaceship(s);
            }
            break;
        case 7 : // 1(*i_time)
            shootRocket(r, s, c, buffer, 2, 0);
            break;
        case 2: // b-button
            shootBomb(b, s, c, buffer, 1, 0);
            break;
        case 8:
            if ((*i_time) == 0)
            {
                stop_timer();
                (*i_time) = 1;
            }
            else
            {
                start_timer();
                (*i_time) = 0;
            }
            break;
    }
}

