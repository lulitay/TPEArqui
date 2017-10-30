#include <types.h>
#include <terminal.h>
#include <keyboard_driver.h>

static char buffer[2001];


void copyToBuffer(){
	ncCopyscreen(buffer);
}

void printCopy(){
	addToBuffer(buffer);
	buffer[0]=0;
}






