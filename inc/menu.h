#include "ansi.h"
#include "stm32f30x_conf.h"
#include <stdio.h>
#include <string.h>
#include "serial_com.h"
#include "config.h"

#ifndef _MENU_H_
#define _MENU_H_

struct high_scores {
    int8_t hs, s, m, h;
};

void menu_init();
void how_to_screen();
void settings_screen();
void high_score();
void start_game();
void menu_selection(char * uart_char, int8_t * c_count, int8_t in_menu);

#endif


