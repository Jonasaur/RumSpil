#include "menu.h"

void menu_init() {
    //setting up the opening screen; game title and selections bars
    clrscr();
    gotoxy(4, 3); printf("            __  .___  ___. .______   .______       _______   _______   _______ .__   __.      ___   .___________.  ______   .______          ___    __   _____    ___           ");
    gotoxy(4, 4); printf("           |  | |   \\/   | |   _  \\  |   _  \\     |   ____| /  _____| /  _____||  \\ |  |     /   \\  |           | /  __  \\  |   _  \\        |__ \\  /_ | | ____|  / _ \\          ");
    gotoxy(4, 5); printf(" ______    |  | |  \\  /  | |  |_)  | |  |_)  |    |  |__   |  |  __  |  |  __  |   \\|  |    /  ^  \\ `---|  |----`|  |  |  | |  |_)  |          ) |  | | | |__   | | | |  ______ ");
    gotoxy(4, 6); printf("|______|   |  | |  |\\/|  | |   ___/  |      /     |   __|  |  | |_ | |  | |_ | |  . `  |   /  /_\\  \\    |  |     |  |  |  | |      /          / /   | | |___ \\  | | | | |______|");
    gotoxy(4, 7); printf("           |  | |  |  |  | |  |      |  |\\  \\----.|  |____ |  |__| | |  |__| | |  |\\   |  /  _____  \\   |  |     |  `--'  | |  |\\  \\----.    / /_   | |  ___) | | |_| |         ");
    gotoxy(4, 8); printf("           |__| |__|  |__| | _|      | _| `._____||_______| \\______|  \\______| |__| \\__| /__/     \\__\\  |__|      \\______/  | _| `._____|   |____|  |_| |____/   \\___/          ");

    gotoxy(TEXT_X + 30, TEXT_Y);
    printf("How to play");
    gotoxy(TEXT_X + 60, TEXT_Y);
    printf("Settings");
    gotoxy(TEXT_X + 90, TEXT_Y);
    printf("Play");
    gotoxy(TEXT_X + 120, TEXT_Y);
    printf("High Scores");

    //--------------------------------------------------------//

    gotoxy(80 + ARROW_X, 3 + ARROW_Y); printf("     .---.    ");
    gotoxy(80 + ARROW_X, 4 + ARROW_Y); printf("    /     \\   ");
    gotoxy(80 + ARROW_X, 5 + ARROW_Y); printf("   /  / \\  \\  ");
    gotoxy(80 + ARROW_X, 6 + ARROW_Y); printf("  /__/| |\\__\\ ");
    gotoxy(80 + ARROW_X, 7 + ARROW_Y); printf("      | |     ");
    gotoxy(80 + ARROW_X, 8 + ARROW_Y); printf("      |_|     ");

    gotoxy(80 + ARROW_X, 2 + 11 + ARROW_Y); printf("       _    ");
    gotoxy(80 + ARROW_X, 3 + 11 + ARROW_Y); printf("      | |     ");
    gotoxy(80 + ARROW_X, 4 + 11 + ARROW_Y); printf("   __ | | __  ");
    gotoxy(80 + ARROW_X, 5 + 11 + ARROW_Y); printf("  \\  \\| |/  / ");
    gotoxy(80 + ARROW_X, 6 + 11 + ARROW_Y); printf("   \\  \\ /  /  ");
    gotoxy(80 + ARROW_X, 7 + 11 + ARROW_Y); printf("    \\     /   ");
    gotoxy(80 + ARROW_X, 8 + 11 + ARROW_Y); printf("     \\___/    ");

    gotoxy(95 + ARROW_X, 3 + 5 + ARROW_Y); printf("      ___      ");
    gotoxy(95 + ARROW_X, 4 + 5 + ARROW_Y); printf("      \\  \\     ");
    gotoxy(95 + ARROW_X, 5 + 5 + ARROW_Y); printf(" ______\\  \\    ");
    gotoxy(95 + ARROW_X, 6 + 5 + ARROW_Y); printf("|_______   >   ");
    gotoxy(95 + ARROW_X, 7 + 5 + ARROW_Y); printf("       /  /    ");
    gotoxy(95 + ARROW_X, 8 + 5 + ARROW_Y); printf("      /__/     ");

    gotoxy(69 + ARROW_X, 3 + 5 + ARROW_Y); printf("   ___        ");
    gotoxy(69 + ARROW_X, 4 + 5 + ARROW_Y); printf("  /  /        ");
    gotoxy(69 + ARROW_X, 5 + 5 + ARROW_Y); printf(" /  /______  ");
    gotoxy(69 + ARROW_X, 6 + 5 + ARROW_Y); printf("<   _______| ");
    gotoxy(69 + ARROW_X, 7 + 5 + ARROW_Y); printf(" \\  \\         ");
    gotoxy(69 + ARROW_X, 8 + 5 + ARROW_Y); printf("  \\__\\        ");


    //--------------------------------------------------------//


    gotoxy(4, INSTRUCTIONS_Y); printf(" __        .______     ______   .___  ___. .______");
    gotoxy(4, 1 + INSTRUCTIONS_Y); printf("/_ |  _    |   _  \\   /  __  \\  |   \\/   | |   _  \\\\");
    gotoxy(4, 2 + INSTRUCTIONS_Y); printf(" | | (_)   |  |_)  | |  |  |  | |  \\  /  | |  |_)  |");
    gotoxy(4, 3 + INSTRUCTIONS_Y); printf(" | |       |   _  <  |  |  |  | |  |\\/|  | |   _  < ");
    gotoxy(4, 4 + INSTRUCTIONS_Y); printf(" | |  _    |  |_)  | |  `--'  | |  |  |  | |  |_)  |");
    gotoxy(4, 5 + INSTRUCTIONS_Y); printf(" |_| (_)   |______/   \\______/  |__|  |__| |______/");

    gotoxy(4, 10 + INSTRUCTIONS_Y); printf(" ___         .______        ______     ______  __  ___  _______ .___________.");
    gotoxy(4, 11 + INSTRUCTIONS_Y); printf("|__ \\   _    |   _  \\      /  __  \\   /      ||  |/  / |   ____||           |");
    gotoxy(4, 12 + INSTRUCTIONS_Y); printf("   ) | (_)   |  |_)  |    |  |  |  | |  ,----'|  '  /  |  |__   `---|  |----`");
    gotoxy(4, 13 + INSTRUCTIONS_Y); printf("  / /        |      /     |  |  |  | |  |     |    <   |   __|      |  |");
    gotoxy(4, 14 + INSTRUCTIONS_Y); printf(" / /_   _    |  |\\  \\----.|  `--'  | |  `----.|  .  \\  |  |____     |  |");
    gotoxy(4, 15 + INSTRUCTIONS_Y); printf("|____| (_)   | _| `._____| \\______/   \\______||__|\\__\\ |_______|    |__|");

    gotoxy(4, 20 + INSTRUCTIONS_Y); printf(" ____         .______      ___      __    __       _______. _______");
    gotoxy(4, 21 + INSTRUCTIONS_Y); printf("|___ \\   _    |   _  \\    /   \\    |  |  |  |     /       ||   ____|");
    gotoxy(4, 22 + INSTRUCTIONS_Y); printf("  __) | (_)   |  |_)  |  /  ^  \\   |  |  |  |    |   (----`|  |");
    gotoxy(4, 23 + INSTRUCTIONS_Y); printf(" |__ <        |   ___/  /  /_\\  \\  |  |  |  |     \\   \\    |   __|");
    gotoxy(4, 24 + INSTRUCTIONS_Y); printf(" ___) |  _    |  |     /  _____  \\ |  `--'  | .----)   |   |  |");
    gotoxy(4, 25 + INSTRUCTIONS_Y); printf("|____/  (_)   | _|    /__/     \\__\\ \\______/  |_______/    |_______|");
}

void how_to_screen() {
    // Currently only the header is written - will include some text on where the controls are and such
    // Another idea could be to include this on the first page. We can show here what controls do what.
    clrscr();
    gotoxy(35, 5); printf(" __    __    ______   ____    __    ____   .___________.  ______     .______    __          ___   ____    ____ ");
    gotoxy(35, 6); printf("|  |  |  |  /  __  \\  \\   \\  /  \\  /   /   |           | /  __  \\    |   _  \\  |  |        /   \\  \\   \\  /   / ");
    gotoxy(35, 7); printf("|  |__|  | |  |  |  |  \\   \\/    \\/   /    `---|  |----`|  |  |  |   |  |_)  | |  |       /  ^  \\  \\   \\/   /  ");
    gotoxy(35, 8); printf("|   __   | |  |  |  |   \\            /         |  |     |  |  |  |   |   ___/  |  |      /  /_\\  \\  \\_    _/   ");
    gotoxy(35, 9); printf("|  |  |  | |  `--'  |    \\    /\\    /          |  |     |  `--'  |   |  |      |  `----./  _____  \\   |  |     ");
   gotoxy(35, 10); printf("|__|  |__|  \\______/      \\__/  \\__/           |__|      \\______/    | _|      |_______/__/     \\__\\  |__|     ");
}

void settings_screen() {
    // Perhaps a place to enable/disable sounds - increase difficulty - perhaps change keybindings (It's definitely possible)
    clrscr();
    gotoxy(50, 5); printf("     _______. _______ .___________.___________. __  .__   __.   _______      _______.");
    gotoxy(50, 6); printf("    /       ||   ____||           |           ||  | |  \\ |  |  /  _____|    /       |");
    gotoxy(50, 7); printf("   |   (----`|  |__   `---|  |----`---|  |----`|  | |   \\|  | |  |  __     |   (----`");
    gotoxy(50, 8); printf("    \\   \\    |   __|      |  |        |  |     |  | |  . `  | |  | |_ |     \\   \\    ");
    gotoxy(50, 9); printf(".----)   |   |  |____     |  |        |  |     |  | |  |\\   | |  |__| | .----)   |   ");
   gotoxy(50, 10); printf("|_______/    |_______|    |__|        |__|     |__| |__| \\__|  \\______| |_______/    ");
}

void high_score() {
    // We still need to construct yet another struct where we can write the high scores to
    // THe high score list should have a sorting feature, where we look for the highest to lowest numbers
    // In here we should utilize the currently not in use write feature

    clrscr();
    gotoxy(45, 5); printf(" __    __   __    _______  __    __         _______.  ______   ______   .______       _______ ");
    gotoxy(45, 6); printf("|  |  |  | |  |  /  _____||  |  |  |       /       | /      | /  __  \\  |   _  \\     |   ____|");
    gotoxy(45, 7); printf("|  |__|  | |  | |  |  __  |  |__|  |      |   (----`|  ,----'|  |  |  | |  |_)  |    |  |__   ");
    gotoxy(45, 8); printf("|   __   | |  | |  | |_ | |   __   |       \\   \\    |  |     |  |  |  | |      /     |   __|  ");
    gotoxy(45, 9); printf("|  |  |  | |  | |  |__| | |  |  |  |        \\   \\   |  |     |  |  |  | |     /      |  |____");
   gotoxy(45, 10); printf("|__|  |__| |__|  \\______| |__|  |__|    |_______/    \\______| \\______/  | _| `._____||_______|");
}

void stop_game() {

}

void start_game() {
    //The Final Frontier - Revenge of Mecha-Jesus
    //Seventh Heaven - Expanse
    //The Second Coming - Blood of the Heathens-
    //Expansive Exorcism
    //Vengeance Cometh
    //The Atonement of Andromeda
    //Atonement of the Infidels
    //Crossroads of the Infidels
    //Space Jesus - Dare you cross him again?

    clrscr();
    gotoxy(4, 3); printf("            __  .___  ___. .______   .______       _______   _______   _______ .__   __.      ___   .___________.  ______   .______          ___    __   _____    ___           ");
    gotoxy(4, 4); printf("           |  | |   \\/   | |   _  \\  |   _  \\     |   ____| /  _____| /  _____||  \\ |  |     /   \\  |           | /  __  \\  |   _  \\        |__ \\  /_ | | ____|  / _ \\          ");
    gotoxy(4, 5); printf(" ______    |  | |  \\  /  | |  |_)  | |  |_)  |    |  |__   |  |  __  |  |  __  |   \\|  |    /  ^  \\ `---|  |----`|  |  |  | |  |_)  |          ) |  | | | |__   | | | |  ______ ");
    gotoxy(4, 6); printf("|______|   |  | |  |\\/|  | |   ___/  |      /     |   __|  |  | |_ | |  | |_ | |  . `  |   /  /_\\  \\    |  |     |  |  |  | |      /          / /   | | |___ \\  | | | | |______|");
    gotoxy(4, 7); printf("           |  | |  |  |  | |  |      |  |\\  \\----.|  |____ |  |__| | |  |__| | |  |\\   |  /  _____  \\   |  |     |  `--'  | |  |\\  \\----.    / /_   | |  ___) | | |_| |         ");
    gotoxy(4, 8); printf("           |__| |__|  |__| | _|      | _| `._____||_______| \\______|  \\______| |__| \\__| /__/     \\__\\  |__|      \\______/  | _| `._____|   |____|  |_| |____/   \\___/          ");
    uint8_t i;
    gotoxy(1, 11);
    printf("%c", 0xC9);
    for (i = 0; i <= 179; i++)
    {
        gotoxy(2+i, 11);
        printf("%c",0xCD);
        gotoxy(2+i, 49);
        printf("%c",0xCD);
    }
    gotoxy(182, 11);
    printf("%c",0xBB);

    for (i = 0; i <= 36; i++)
    {
        gotoxy(1, 12 + i);
        printf("%c",0xBA);
        gotoxy(182, 12 + i);
        printf("%c",0xBA);
    }

    gotoxy(1,49);
    printf("%c",0xC8);
    gotoxy(182,49);
    printf("%c",0xBC);
}

void menu_selection(char * uart_char, int8_t * c_count, int8_t in_menu) {
    menu_init();
    int8_t selection;
    int8_t select;
    int8_t print_flag;
    do {
        switch(keyboard_read(uart_char, &c_count)) {
            case 3: //what to do if "Up" is pushed
                (*c_count) = 0;
                if (select == 2) {
                    print_flag = 1;
                    select = 0;
                }
                break;
            case 4: //what to do if "Down" is pushed
                if (select == 0) { //If you push down as the first thing somethings gonna fuck up
                    select = 1;
                    (*c_count) = 0;
                    print_flag = 1;
                }
                break;
            case 5: //what to do if "Right" is pushed
                if (select == 0) {
                    if (selection < 3)
                    {
                        selection++;
                    }
                    else selection = 0;
                    (*c_count) = 0;
                    print_flag = 1;
                }
                break;
            case 6: //what to do if "Left" is pushed
                if (select == 0)
                {
                    if (selection > 0)
                    {
                        selection--;
                    }
                    else selection = 3;
                    (*c_count) = 0;
                    print_flag = 1;
                }
                break;
        }
        if (print_flag == 1) {
            switch(selection) {
                case 0: { //How to
                    menu_init();
                    inverse();
                    gotoxy(TEXT_X + 30, TEXT_Y);
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
                    gotoxy(TEXT_X + 60, TEXT_Y);
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
                    gotoxy(TEXT_X + 90, TEXT_Y);
                    printf("Play");
                    no_inverse();
                    if (select == 1) {
                        select = 2;
                        in_menu = 0;
                    }
                    break;
                }
                case 3: { //High score
                    menu_init();
                    inverse();
                    gotoxy(TEXT_X + 120, TEXT_Y);
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
    start_game();
}
