//GAMEFUNCTIONS FORLOOPS
#define N_ALIENS 10
#define N_ROCKETS 10
#define N_BOMBS 5
#define N_LASERS 10

#define ESC 0x1B

//COMMUNICATION WITH PUTTY
#define UART_BAUDRATE 256000
#define CHAR_ARRAY_LEN 255

//
#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / b )

//ALIEN SPAWN Y_COORDINATE INTERVAL
#define MAX_RAND 40
#define MIN_RAND 10

//MENU
#define TEXT_X  8
#define TEXT_Y 38
#define ARROW_X 40
#define ARROW_Y 20
#define INSTRUCTIONS_Y 20
