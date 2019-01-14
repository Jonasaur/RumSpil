#include "ansi.h"

#define ESC 0x1B

void fgcolor(uint8_t foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(uint8_t background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(uint8_t foreground, uint8_t background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void clrscr() {
    printf("%c[2J", ESC);
}

void clreol() {
    printf("%c[K", ESC);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
    printf("%c[m", ESC);
}

void gotoxy(uint8_t x, uint8_t y) {
    printf("%c[%u;%uH", ESC, y, x);  //X and y are switched so that they behave normally
}

void underline(uint8_t on) {

}

void inverse()
{
    printf("%c[7m",ESC);
}

void no_inverse()
{

    printf("%c[27m",ESC);
}

void window(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, char title[], uint8_t color, uint8_t type) {
    clrscr();
    resetbgcolor();
    //inverse();
    gotoxy(x1,y1);
    printf("%c",218);
    gotoxy(x2,y1);
    printf("%c",192);
    gotoxy(x2,y2);
    printf("%c",217);
    gotoxy(x1,y2);
    printf("%c",191);
    gotoxy(x1,y1 + 1);
    printf("%c",180);
    gotoxy(x1,y2 - 1);
    printf("%c",195);
    int8_t i;
    inverse();
    gotoxy(x1, y1 + 4);
    printf("%s",title);
    no_inverse();
    //resetbgcolor();
    for (i = y1 +1; i < y2; i++)
    {
        gotoxy(x2,i);
        printf("%c",196);
    }
    for (i = x1 + 1; i < x2; i++)
    {
        gotoxy(i,y1);
        printf("%c",179);
        gotoxy(i,y2);
        printf("%c",179);
    }

    //venstre nedre hjørne - 192
    //venstre øvre hjørne 218
    //højre nedre hjørne 217
    //højre øvre hjørne 191
    //vertikal 179
    //horisontal 196
    //venstre dims 180
    //højre dims 195
}
