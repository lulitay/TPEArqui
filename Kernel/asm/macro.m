
; -----------------------------------------------------------------------------
;	This macro preserves the value of all registers
; -----------------------------------------------------------------------------

%macro pushState 0
	push rax
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro

; -----------------------------------------------------------------------------
;	This macro restores the value of all registers
; -----------------------------------------------------------------------------


%macro popState 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro

%macro irqHandlerMaster 1
	pushState

	mov rdi, %1
	call irqDispatcher

	; signal pic EOI (End of Interrupt)
	mov al, 20h
	out 20h, al
	

	popState
	iretq
%endmacro



%macro exceptionHandler 1
	mov rdi, %1 
	call exceptionDispatcher
	
	mov qword [rsp],0x400000
	iretq
%endmacro

