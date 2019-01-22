#include "LCD.h"

void lcd_write_string(char * str, uint8_t * buffer, int x, int y) {
    int i, j;
    int n = strlen(str);
    for (i = 0; i < n; i++) {
        for(j = 0; j < 5; j++) {
            buffer[((i * 5 + j + x) & 127) + (y * 128)] = character_data[str[i] - 0x20][j];
        }
    }
}

void lcd_update(int16_t* i, uint8_t * buffer) {
        (*i)--;
        memset(buffer, 0x00, 512);
        lcd_write_string("Extra lives", buffer, *i, 0);
        lcd_push_buffer(buffer);
    }

void lcd_draw_hearts(int amount, uint8_t * buffer, int pos, int row) {
    memset(buffer + pos + (row - 1) * 128, 0x00, 24);
    int i = 0;
    for (i = 0; i < amount; i++) {
        int offset;
        offset = pos + i * 8 + (row - 1) * 128;

        memset(buffer + offset, 0b00001100, 1);
        memset(buffer + offset + 1,0b00011110, 1);
        memset(buffer + offset + 2,0b00111110, 1);
        memset(buffer + offset + 3,0b01111100, 1);
        memset(buffer + offset + 4,0b00111110, 1);
        memset(buffer + offset + 5,0b00011110, 1);
        memset(buffer + offset + 6,0b00001100, 1);
    }
}

void lcd_draw_rockets(int amount, uint8_t * buffer, int pos, int row)
{
    memset(buffer + pos + (row - 1) * 128, 0x00, 70);
    int i = 0;
    for (i = 0; i < amount; i++)
    {
        int offset;
        offset = pos + i * 7 + (row - 1) * 128;
        memset(buffer + offset, 0b00001100, 1);
        memset(buffer + offset + 1, 0b00001100, 1);
        memset(buffer + offset + 2, 0b11111111, 1);
        memset(buffer + offset + 3, 0b11111111, 1);
        memset(buffer + offset + 4, 0b00001100, 1);
        memset(buffer + offset + 5, 0b00001100, 1);
    }
}


void lcd_draw_bombs(int amount, uint8_t * buffer, int pos, int row) {
    memset(buffer + pos + (row - 1) * 128, 0x00, 30);
    int i = 0;
    for (i = 0; i < amount; i++) {
        int offset;
        offset = pos + i * 6 + (row - 1) * 128;

        memset(buffer + offset, 0b000100, 1);
        memset(buffer + offset + 1, 0b001110, 1);
        memset(buffer + offset + 2, 0b011111, 1);
        memset(buffer + offset + 3, 0b001110, 1);
        memset(buffer + offset + 4, 0b000100, 1);
    }
}



