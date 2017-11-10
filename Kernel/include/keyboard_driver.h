#ifndef KEYBOARD_DRIVER_H
#define KEYBOARD_DRIVER_H
#include "types.h"


void keyboard_handler();
void update_buffer(unsigned char key);
char get_buffer();
void read_buffer(char* buff, int size);
void add_buffer(char * buffercopy);


#endif
