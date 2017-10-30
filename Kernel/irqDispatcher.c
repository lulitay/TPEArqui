#include <time.h>
#include <keyboard_driver.h>
#include <stdint.h>

static void int_20();
static void int_21();

void irqDispatcher(uint64_t irq) {
	
	irq = 1; //para q ande, sino no me toma el teclado
	switch (irq) {
		case 0:
			int_20();
			break;
		case 1:
			int_21();
			break;
	}
	return;
}

void int_20() {
	timer_handler();
}

void int_21(){
	keyboard_handler();
}

//Puse la nro 21 pero puede ser cualquiera porque en la idt desde la 20 son reservados
//Para las excepciones pedidas hay q fijarse en internet q numero de la idt usar