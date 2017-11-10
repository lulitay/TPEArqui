#ifndef STDIO_H
#define STDIO_H

#include "../types.h"

/* Prints character */
void putchar(unsigned char c);

/* Gets a character, an unsigned char, from stdin */
//char getchar();

/*Returns string length*/
int strlen(const char* str);

/*Transforms int to string*/
void intostr(int num,char*a);

/* Prints string with format */
void printf(const char* str,...);

/* Clears the screen, displaying an empty screen */
void clear_screen();

/*Draws pixel*/
void draw_pixel(int x, int y);

/* Scans input */
int scanf(const char* format,...);

int sscanf(char format [90],char str[90], ...);

/* Deletes the last character from stdin */
void backspace();
#endif
