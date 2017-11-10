#include <vsa_driver.h>
#include <registers.h>
#include <naiveConsole.h>

#define ZERO_EXCEPTION_ID 0
//#define OVERFLOW_EXCEPTION 4
//#define INVALID_OPCODE 6


static void zero_division();
//static void overflow();
//static void invalid_opcode();


void showRegisters();

void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division();
	
}

static void zero_division() {
	clear_screen();
	print_string("EXCEPTION 00: DIVIDE ERROR");
	nextLine();	
	showRegisters();
}

/*static void overflow() {
	clear_screen();
	print_string("EXCEPTION: OVERFLOW");
	nextLine();	
	showRegisters();

}

static void invalid_opcode() {
	clear_screen();
	print_string("EXCEPTION: INVALID OPCODE");
	nextLine();	
	showRegisters();

}*/


void showRegisters(){
	print_string("RAX: ");
	ncPrintHex(get_rax());
	nextLine();
	print_string("RBX: ");
	ncPrintHex(get_rbx());
	nextLine();
	print_string("RCX: ");
	ncPrintHex(get_rcx());
	nextLine();
	print_string("RDX: ");
	ncPrintHex(get_rdx());
	nextLine();
	print_string("RBP: ");
	ncPrintHex(get_rbp());
	nextLine();
	print_string("RDI: ");
	ncPrintHex(get_rdi());
	nextLine();
	print_string("R8: ");
	ncPrintHex(get_r8());
	nextLine();
	print_string("R9: ");
	ncPrintHex(get_r9());
	nextLine();
	print_string("R10: ");
	ncPrintHex(get_r10());
	nextLine();
	print_string("R11: ");
	ncPrintHex(get_r11());
	nextLine();
	print_string("R12: ");
	ncPrintHex(get_r12());
	nextLine();
	print_string("R13: ");
	ncPrintHex(get_r13());
	nextLine();
	print_string("R14: ");
	ncPrintHex(get_r14());
	nextLine();
	print_string("R15: ");
	ncPrintHex(get_r15());
	nextLine();
	
	print_string("Returning to shell...");
	int i = 0;
	while(i < 500000000)
		i++;

	
}
