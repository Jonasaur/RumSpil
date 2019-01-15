#include "menu.h"

void menu_init() {
    //setup name and selections bars
    clrscr();
    gotoxy(25, 10);
    //------------------------------------------//
    printf("Title"); //Write ASCII title here
    //------------------------------------------//
    gotoxy(5, 20);
    printf("How to play");
    gotoxy(21, 20);
    printf("Settings");
    gotoxy(30, 20);
    printf("Play");
    gotoxy(35, 20);
    printf("High Scores");
}

void how_to_screen() {
    clrscr();
    gotoxy(5, 5); printf(" __    __    ______   ____    __    ____   .___________.  ______     .______    __          ___   ____    ____ ");
    gotoxy(5, 6); printf("|  |  |  |  /  __  \\  \\   \\  /  \\  /   /   |           | /  __  \\    |   _  \\  |  |        /   \\  \\   \\  /   / ");
    gotoxy(5, 7); printf("|  |__|  | |  |  |  |  \\   \\/    \\/   /    `---|  |----`|  |  |  |   |  |_)  | |  |       /  ^  \\  \\   \\/   /  ");
    gotoxy(5, 8); printf("|   __   | |  |  |  |   \\            /         |  |     |  |  |  |   |   ___/  |  |      /  /_\\  \\  \\_    _/   ");
    gotoxy(5, 9); printf("|  |  |  | |  `--'  |    \\    /\\    /          |  |     |  `--'  |   |  |      |  `----./  _____  \\   |  |     ");
   gotoxy(5, 10); printf("|__|  |__|  \\______/      \\__/  \\__/           |__|      \\______/    | _|      |_______/__/     \\__\\  |__|     ");
}

void settings_screen() {
    clrscr();
    //gotoxy();

}

void play_screen() {
    clrscr();
    //gotoxy();

}

void high_score() {
    clrscr();
    //gotoxy();

}

void menu_selection(char * uart_char, int8_t * c_count) {
    menu_init();
    int8_t selection;
    int8_t select;
    int8_t in_menu = 1;
    int8_t print_flag;
    do {
        switch(keyboard_read(uart_char, &c_count)) {
            case 3: { //what to do if "Up" is pushed
                (*c_count) = 0;
                if (select == 2) {
                    print_flag = 1;
                }
                break;
            }
            case 4: { //what to do if "Down" is pushed
                select = 1;
                (*c_count) = 0;
                print_flag = 1;
                break;
            }
            case 5: { //what to do if "Right" is pushed
                if (selection < 3)
                {
                    selection++;
                }
                else selection = 0;
                (*c_count) = 0;
                print_flag = 1;
                break;
            }
            case 6: { //what to do if "Left" is pushed
                if (selection > 0)
                {
                    selection--;
                }
                else selection = 3;
                (*c_count) = 0;
                print_flag = 1;
                break;
            }
        }
        if (print_flag == 1) {
            switch(selection) {
                case 0: { //How to
                    menu_init();
                    inverse();
                    gotoxy(5, 20);
                    printf("How to play");
                    no_inverse();
                    if (select == 1) {
                        how_to_screen();
                        select = 2;
                    }
                    break;
                }
                case 1: { //Settings
                    menu_init();
                    inverse();
                    gotoxy(21, 20);
                    printf("Settings");
                    no_inverse();
                    if (select == 1) {
                        settings_screen();
                        select = 2;
                    }
                    break;
                }
                case 2: { //Play
                    menu_init();
                    inverse();
                    gotoxy(30, 20);
                    printf("Play");
                    no_inverse();
                    if (select == 1) {
                        play_screen();
                        select = 2;
                    }
                    break;
                }
                case 3: { //High score
                    menu_init();
                    inverse();
                    gotoxy(35, 20);
                    printf("High Scores");
                    no_inverse();
                    if (select == 1) {
                        high_score();
                        select = 2;
                    }
                    break;
                }
            }
        print_flag = 0;
        }
    } while(in_menu == 1);
}
