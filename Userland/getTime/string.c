#include <types.h>
#include <string.h>

int strlen(const char * str){
	int length = 0;
	while(str[length++] != '\0' );
	return length - 1;
}




