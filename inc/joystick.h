#include "stm32f30x_conf.h"
#include <stdio.h>
#include <string.h>

#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

void joystick_setup();
int16_t readJoystick();

#endif

