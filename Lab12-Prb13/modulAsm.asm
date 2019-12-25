bits 32
global _afisare_sufix
extern _printf
segment data public data use32
	format db 'Cel mai lung sufix comun intre %s si %s este: %s.',13,10
segment code public code use32
_afisare_sufix
	push ebp
	mov ebp, esp
	mov eax,[ebp+16] ; suf
	push eax 
	mov eax,[ebp+12] ; suf
	push eax 
	mov eax,[ebp+8] ; suf
	push eax 
	push dword format
	call _printf 
	add esp, 12
	mov esp, ebp
	pop ebp
    ret