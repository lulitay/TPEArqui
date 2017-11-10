#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <types.h>
#include <stdlib.h>
#define FONT_WIDTH     10
#define FONT_HEIGHT 16
#define MAX_SIZE 2000
#define exit 2
#define WIDTH 1024
#define HEIGHT 768

#include "./include/stdio.h"

/* ESTO VA A GRAFICAR CON EL EJE Y CRECIENTE HACIA ABAJO  EJE X CRECIENTE A LA DERECHA*/
void coordinates();

int abs( int a ){
	if(a < 0){
		return a*(-1);
	}
	else
	{
		return a;
	}
}



int main (void){
	clear_screen();
	int dx, dy, p, end;
	float x1, x2, y1, y2, x, y;
	int a; /*Por ahora funciona con int pero en realidad deberian funcionar con doubles*/
	int b;
	printf("f(x) = ax + b\n");
	printf("Ingresar valor de 'a':\n");
	char buffer[MAX_SIZE];
	char buffer2[MAX_SIZE];
  	int index;
  	char c;
  	int state;
  
  	
	while(state != exit) {

		

		if ((c = getchar()) != EOF) {
    			
    			if(c == '\n'){
	      
	      			buffer[index] = 0;
				state = exit;

				}
		
      			 else {
		      		buffer[index] = c;
		      		index++;
		      		buffer[index] = 0;
		     		putchar(buffer[index-1]);	
	  		}	   	
		}	
	}
	printf("\n");
	sscanf("%d",buffer, &a);
	state = 0;
	int index2;

	printf("Ingresar valor de 'b':\n");
	while(state != exit) {

		

		if ((c = getchar()) != EOF) {
    			
    			if(c == '\n'){
	      
	      			buffer2[index2] = 0;
				state = exit;

				}
		
      			 else {
		      		buffer2[index2] = c;
		      		index2++;
		      		buffer2[index2] = 0;
		     		putchar(buffer2[index2-1]);	
	  		}	   	
		}	
	}

	sscanf("%d",buffer2, &b);
	clear_screen();
	
/*
	x1 = 0; //(WIDTH/2-HEIGHT/2);// 0;
 	x2 = WIDTH; //-(WIDTH/2-HEIGHT/2);
	y1 = a*x1 + b ;
	y2 = a*x2 + b;
*/

	//dx = abs(x1 - x2);
	//dy = abs(y1 - y2);

	coordinates();
	if(x1 > x2)
	{
		x = x2;
		y = y2;
		end = x1;
	}
	else
	{
		x = x1;
		y = y1;
		end = x2;
      }
	if( a == 0){
		for(int i = 0; i < WIDTH; i++){

			draw_pixel(i, HEIGHT-b-HEIGHT/2);
		}	
	}else{

	for(int i = 0; i < WIDTH-(WIDTH/2-HEIGHT/2); i++){
		y = a*i + b;
		draw_pixel(i + (WIDTH/2-HEIGHT/2), HEIGHT-y);
	}

	}


	

	int i=0;

	
	while(i<50000000) {
		i++;
	}

	return 0;
	
}

void coordinates() {

	int x = (WIDTH / 2) - 1;
	int y = (HEIGHT / 2) - 1;

	
	for (int j = 0; j < HEIGHT; j++) {

		draw_pixel(x, j);

	}

	for(int i = 0; i < WIDTH; i++){

		draw_pixel(i, y);
	}
}









