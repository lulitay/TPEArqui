#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
Habria q ver de pasar la hora de formato BCD a decimal en vez de
restar manualmente.
*/

int main (void){

	clear_screen();
	char * hh;
	char * mm;
	int h = hour();
	int m = minutes();

	if(h == 1){
		h = 22;
	}
	else if(h == 2)
	{
		h = 23;
	}
	else if(h == 0){
		h = 21;
	}
	else{
		h = h-3;
	}
	
	
	intToString(h,hh);
	intToString(m,mm);


	printf("Local time is ");
	printf(hh);
	printf(":");
	printf(mm);
	
	

	int i=0;
	while(i < 500000000) {
		i++;
	}

	return 0;
}







