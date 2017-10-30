#ifndef SYSTEM_CALLS
#define SYSTEM_CALLS

void load_systemcalls();

void irq80Handler(void);

void interruption_set_handler(int, qword);

#endif
