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
static void * const shell = (void*)0x400000;
extern unsigned int read();
static void * entry = (void *) 0x3008; //usamos la segunda entrada de la tabla de pagina PDP


//mapeamos el modulo en la direccion fisica
//hacemos que la entrada de la tabla PDP apunte a la direccion fisica
void map(void * fisica, void * module){
	memcpy(fisica,module,10000);
	*((uint64_t *)entry) = fisica;
}


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
	char opcion = '0';
	ncPrint("Seleccionar modulo:");ncNewline();
;
	ncPrint("1: Hello World");ncNewline();
	ncPrint("2: Shell");ncNewline();
	ncPrint("3: Display time");ncNewline();
	ncPrint("4: Graph");ncNewline();
	ncPrint("5: Verify exceptions");ncNewline();
	while(1){
		//ncClear();
		//menu();
		int i = 0;
		
		while((opcion = getBuffer()) == EOF || i<1) {
			i++;
		}


		
		switch(opcion) {
			case '1':
				ncPrint("Hello World ");
				ncNewline();
				//((EntryPoint)shell)();
				break;
			case '2':
				ncClear();
				ncNewline();
				ncNewline();
				ncNewline();
				map(0x1000000,shell);	
				((EntryPoint)*((uint64_t *)entry))();;
				ncPrint("Shell");
				ncNewline();
				ncPrint("--------");
				break;
			case '3':
				//nueva ventana (?
				ncPrint("La hora actual es ");
				ncPrintTime();
				ncNewline();
				break;
			case '4':
				//nueva ventana
				ncPrint("Seleccione tipo de funcion a graficar ");ncNewline();
				ncPrint("1: f(x) = ax + b ");ncNewline();
				ncPrint("2: f(x) = ax^2 + bx + c ");ncNewline();
				//despues habria q tomar los valores para a b y c
				ncNewline();
				break;
			case '5':
				ncPrint("Mostrando informacion de excepciones ");ncNewline();
				ncNewline();
				break;

	
		}
	}

	

	return 0;
}
	
void menu(){
	ncPrint(" ");
}
