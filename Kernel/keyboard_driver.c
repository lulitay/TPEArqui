#include <asciicode.h>
#include <keyboard_driver.h>
#include <types.h>
#define BUFFER_SIZE 2000

static byte buffer[BUFFER_SIZE];
static int index=0;
static int bufferindex=0;

extern int read();

void keyboard_handler() {
	byte key = read();
	key = ASCII_VALUE[key];
	buffer[bufferindex] = key;
	bufferindex = (bufferindex+1)%BUFFER_SIZE;
}

byte getBuffer(){
	
	if(index != bufferindex){
		byte aux = buffer[index];
		index = (index+1)%BUFFER_SIZE;
		return aux;
	}

	return EOF;
}

void readAllBuffer(char* buff, int size){
    int i = 0;
    char c;

    while (i < size - 1 && (c = getBuffer()) != EOF) {
        buff[i] = (char) c;
        i++;
    }

    buff[i] = 0;
    
}

void addToBuffer(char *buffercopy){
	for(int x=0; buffercopy[x]!=0; x++){
		buffer[bufferindex] = buffercopy[x];
		bufferindex = (bufferindex+1)%BUFFER_SIZE;
	}
}
