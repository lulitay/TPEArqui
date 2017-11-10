section .text
; A mejorar lo de imprimir registros, es solo para prueba
GLOBAL get_rax
GLOBAL get_rbx
GLOBAL get_rcx
GLOBAL get_rdx
GLOBAL get_rbp
GLOBAL get_rdi
GLOBAL get_r8
GLOBAL get_r9
GLOBAL get_r10
GLOBAL get_r11
GLOBAL get_r12
GLOBAL get_r13
GLOBAL get_r14
GLOBAL get_r15


get_rax: ret

get_rbx: mov rax, [rbx]
		 ret

get_rcx: mov rax, [rcx]
		 ret

get_rdx: mov rax, [rdx]
		 ret

get_rbp: mov rax, [rbp]
		 ret

get_rdi: mov rax, [rdi]
		 ret

get_r8: mov rax, [r8]
		 ret

get_r9: mov rax, [r9]
		 ret

get_r10: mov rax, [r10]
		 ret

get_r11: mov rax, [r11]
		 ret

get_r12: mov rax, [r12]
		 ret

get_r13: mov rax, [r13]
		 ret

get_r14: mov rax, [r14]
		 ret

get_r15: mov rax, [r15]
		 ret


