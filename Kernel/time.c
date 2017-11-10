#include <time.h>
#include <interrupts.h>

static unsigned long ticks = 0;

void timer_handler() {
	ticks++;
}

int ticks_elapsed() {
	return ticks;
}

int seconds_elapsed() {
	return ticks / 18;
}


void sleep(unsigned long t){
	
	_cli();
    unsigned long sleep_ticks = 0;
	while(sleep_ticks < t){
    		sleep_ticks++;
	}
	_sti();

}
