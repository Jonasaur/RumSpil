#include "ansi.h"
#include "stm32f30x_conf.h"
#include <stdio.h>
#include <string.h>
#include "serial_com.h"

#ifndef _MENU_H_
#define _MENU_H_

struct high_scores {
    int8_t
};

void menu_init();
void how_to_screen();
void settings_screen();
void play_screen();
void high_score();
void menu_selection();
void play_game();

#endif
