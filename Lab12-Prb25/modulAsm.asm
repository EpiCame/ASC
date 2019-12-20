bits 32

global _maxim
segment data public data use32
	max dd -1
	len dd 1
segment code public code use32
_maxim:
	push ebp
	mov ebp, esp
	mov esi,[ebp+8]
	mov eax,[ebp+12]
	mov [len],eax 
	mov ecx, [len]
	repeta:
		lodsd 
		cmp eax, [max] 
		jle final 
		mov [max], eax 
		final:
	loop repeta
	mov eax,[max]
	mov esp, ebp
	pop ebp
    ret