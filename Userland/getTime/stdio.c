#include <types.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

extern void int80(qword rdi, qword rsi, qword rdx, qword rcx, qword r8, qword r9);

/* Esto esta mal, printf recibe formato pero no se q hacer :(  PREGUNTARRR */
void printf(const char * str,...){
	char num[12];
	va_list arguments;
	va_start ( arguments,str);
	int length = strlen(str);
	int state=0;
	for(int x=0;x<length;x++){
		if(state==0){
			if(str[x]!= '%')
				putchar(str[x]);
			else
				state=1;
		}else{
			switch(str[x]){
				case 'd':
					intToString(va_arg ( arguments, int),num);
					int index=0;
					while(num[index]!=0)
						putchar(num[index++]);
					state=0;
					break;
				case 'c':
					putchar((char)(va_arg(arguments,int)));
					state=0;
					break;
				case 's':
					printf(va_arg(arguments, char*));
					state = 0;
					break;
				default:	
					putchar('%');
					putchar(str[x]);
					state=0;
					break;
			}
		}

	}	
	va_end(arguments);


}

void putchar(unsigned char c) {
	int80(1, c, 1, 0, 0, 0);
}

void clear_screen(){
	int80(2, 1, 0, 0, 0, 0);
}



