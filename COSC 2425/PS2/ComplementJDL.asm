; Josiah Larimer
; COSC 2425
; programming set 2
;
;Write a MASM program that finds the two’s complement of a number (+/-). The user will enter a
;single integer from the keyboard and output to the screen the two’s complement value of the number
;entered. Assume proper input. Output should be user friendly.
;
; What I did was convert from the PS1 Two's complement to here for the basic bitch binary conversion
; figured out modulo via https://stackoverflow.com/questions/8971627/masm-using-registers-as-expressions-between-mod-operator
;
;https://learn.microsoft.com/en-us/cpp/assembler/masm/microsoft-macro-assembler-reference?view=msvc-170
; this reference was absolutely essential
;


.386
.model flat, c
.stack 4096

.data
	prompt byte		"Enter a single integer between 127 and -128: ", 0
	num dword 0
	base dword 2
	binary byte '0', '0', '0', '0', '0', '0', '0', '0', 10, 0 ; i don't really "know" how to properly declare and initialize an array, but this works

.code
	includelib libucrt.lib                      ;Lets us use c functions
    includelib legacy_stdio_definitions.lib     ;Lets us use scanf
    includelib libcmt.lib
	includelib libvcruntime.lib

	extern printf: proc
	extern gets: near
	extern exit: proc
	extern atoi: near


	main proc

		push offset prompt
		call printf

		push offset num
		call gets
		
		mov eax, num
		cmp eax, 0     ; look if number is not negative
        jl endl       ; if less than zero program ends.

		mov eax, num
		call atoi	  ;i don't remember seeing where I could do this	
		

		mov ebx, 0
		positiveBinary:
			; if the entered num is zero, skip the binary logic
			.if eax == 0
				mov binary[ebx],  '0'	
				jmp RevDigits
			.endif	
		
			; the meat of the conversion
			.while	eax != 0 &&  ebx < 12
				xor edx, edx	; modulus algorithm
				push eax
				mov ecx, 2
				div ecx			; the quotient is in eax, and the remainder in edx

				.if edx == 0
					mov binary[ebx], '0'
				.else
					mov binary[ebx], '1'
				.endif

				inc ebx
			.endw	

			jmp RevDigits

		; adapted from the RevDigits file you have in the sample.asm folder from the MASM assembly language information page in canvas
		; is neccessary due to the way I worked with the binary string
		RevDigits:			
		
		mov ecx, 8
        mov esi, 0
        StackIt:        ;Based off the sample code from the video "Setup Visual Studio for Assembly MASM" https://www.youtube.com/watch?v=LqyVybUodXE
	        movzx eax, binary[esi]
	        push eax
	        inc esi
	        loop StackIt
        mov ecx, 8      ;Reset the loop counter
        mov esi, 0
        PopIt:
	        pop eax
	        mov binary[esi], al
	        inc esi
	        loop PopIt

		; truncating the array at eight bits
		mov ebx, 8
		mov binary[ebx], 10
		inc ebx
		mov binary[ebx], 0
        push offset binary[0]
        call printf


				
		endl:
		push 0;		
		call exit
	main ENDP
END