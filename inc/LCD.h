/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "charset.h"

#ifndef _LCD_H_
#define _LCD_H_

void lcd_update(int16_t* i, uint8_t * buffer);
void lcd_draw_hearts(int amount, uint8_t * buffer, int pos, int row);
void lcd_draw_rockets(int amount, uint8_t * buffer, int pos, int row);
void lcd_draw_bombs(int amount, uint8_t * buffer, int pos, int row);

#define ESC 0x1B
#endif
