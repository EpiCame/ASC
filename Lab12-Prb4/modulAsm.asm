bits 32
global _print_number
extern _printf
segment data public data use32
	rez db 'Numarul in baza 16: %x ; in baza 2: %d.',13,10
	;format db '',0
segment code public code use32
_print_number:
	push ebp 
	mov ebp,esp
	pushad
	mov eax, [ebp+8]
	mov ebx, [ebp+12]
	push dword ebx
	push dword eax 
	push dword rez
	call _printf 
	add esp,4*3
	;----------------------
;	push dword format 
;	call _printf 
;	add esp,4
	popad
	mov esp,ebp
	pop ebp
    ret