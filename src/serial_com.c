#include "serial_com.h"

char keyboard_read(char * uart_char, int8_t * c_count) {
    if (uart_get_count() > 0) {
        uart_char[*c_count] = uart_get_char();
        if (uart_char[(*c_count) - 2] == (0x1B) && uart_char[(*c_count) - 1] == (0x5B))
        {
            switch(uart_char[(*c_count)]) {
                case 65: { //up
                    (*c_count) -= 1;
                    uart_char[(*c_count) - 1] = 0;
                return 3;
                break;
                }
                case 66: { //down
                    (*c_count) -= 1;
                    uart_char[(*c_count) - 1] = 0;
                return 4;
                break;
                }
                case 67: { //right
                    (*c_count) -= 1;
                    uart_char[(*c_count) - 1] = 0;
                return 5;
                break;
                }
                case 68: { //left
                    (*c_count) -= 1;
                    uart_char[(*c_count) - 1] = 0;
                return 6;
                break;
                }
            }
            (*c_count) -= 2;
        }
        if (uart_char[(*c_count)] == (0x7F))
        {
            //uart_char[(*c_count)] = 0;
            //(*c_count)--;
            //clreol();
            //printf("%s",uart_char);
            return 2;
        }
        if (uart_char[(*c_count)] == (0x0D))
        {
            uart_char[(*c_count)] = 0;
            (*c_count) = 0;
            return 1;
        }
        (*c_count)++;
    }
    return 0;
}

int8_t keyboard_controls(char button_pressed) {
    switch(button_pressed) {
        case 72: { //up 0x48
            printf("%i", button_pressed);
        break;
        }
        case 80: { //down 0x50
            printf("%i", button_pressed);
        break;
        }
        case 75: { //left 0x4B
            printf("%i", button_pressed);
        break;
        }
        case 77: { //right 0x4D
            printf("%i", button_pressed);
        break;
        }
    }
}
