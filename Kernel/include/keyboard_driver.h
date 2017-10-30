#ifndef KEYBOARD_DRIVER_H
#define KEYBOARD_DRIVER_H
#include "types.h"


void keyboard_handler();
byte getBuffer();
void readAllBuffer(char* buff, int size);
void addToBuffer(char * buffercopy);

#endif
