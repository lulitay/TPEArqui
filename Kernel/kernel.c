#include <stdint.h>
#include <string.h>
#include <lib.h>
#include <keyboard_driver.h>
#include <moduleLoader.h>
#include <naiveConsole.h>
#include <systemcalls.h>
#include <interrupts.h>
#include <systemcalls.h>


extern byte text;
extern byte rodata;
extern byte data;
extern byte bss;
extern byte endOfKernelBinary;
extern byte endOfKernel;

static const qword PageSize = 0x1000;
extern unsigned int read();

static void * const shell = (void*)0x400000;



typedef int (*EntryPoint)();

void clearBSS(void * bssAddress, qword bssSize) {
	memset(bssAddress, 0, bssSize);
}

void * getStackBase() {
	return (void*)(
		(qword)&endOfKernel
		+ PageSize * 8				//The size of the stack itself, 32KiB
		- sizeof(qword)			//Begin at the top of the stack
	);
}

void * initializeKernelBinary() {
	

	void * moduleAddresses[] = {
		shell
	};

	loadModules(&endOfKernelBinary, moduleAddresses);
	
	clearBSS(&bss, &endOfKernel - &bss);

	return getStackBase();
}


int main()
{	
	_cli();
	load_idt();
	load_systemcalls();
	_sti();
	
	
	ncClear();
	menu();
	char opcion;
	while(1){
		//ncClear();
		//menu();
		int i = 0;
		
		while((opcion = getBuffer()) == EOF || i<1) {
			i++;
		}
		
		switch(opcion) {
			case '1':
				ncPrint("hola");
				//((EntryPoint)shell)();
				break;
	
		}
	}

	

	return 0;
}
	
void menu(){
	ncPrint("1: Shell");
}
