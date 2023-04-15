; Josiah Larimer
; COSC 2425
; programming set 2
;
; this resource helped a lot when it came to understanding how to work with the registers and memory addresses and whatnot
    ; https://www.cs.virginia.edu/~evans/cs216/guides/x86.html

.386
.model flat, c
.stack 4096

.data
    prompt  byte    "Enter five positive single digit integers with no spaces between them, in the style of 54321: ", 0
    promptOutput  byte    "The outputted string is " 
    num byte '9', '9', '9', '9', '9', 10, 0
    w dword 0
    x dword 0
    y dword 0
    z dword 0
    count dword -1
    
    
    
.code
    includelib libucrt.lib                      ;Lets us use c functions
    includelib legacy_stdio_definitions.lib     ;Lets us use scanf
    includelib libcmt.lib
	includelib libvcruntime.lib

	extern printf: proc
	extern gets: near
	extern exit: proc
	extern atoi: near

    main PROC

        ; getting input
        push offset prompt      ;Prompt the user for input
        call printf
        
        push offset num
        call gets
       ; call atoi

        ; bubble sort   

        mov esi, offset num
    	mov eax, [esi]
        mov ebx, [esi+2]
        mov edx, [esi+4]
        xor ecx, ecx

	.Repeat   

		.if al>ah
           xchg al, ah
           mov num[0], al
           mov num[1], ah
		.endif
        .if bl<ah
           xchg bl, ah                      
           mov num[1], ah
           mov num[2], bl
		.endif
        .if bl > bh
           xchg bl, bh
           mov num[2], bl
           mov num[3], bh
		.endif
        .if bh > dl
           xchg bh, dl
           mov num[3], bh
           mov num[4], dl
		.endif
		inc ecx

    .Until ecx>=5
	
           xchg al, ah
           mov num[1], al
           mov num[0], ah

           xchg bl, bh
           mov num[3], bl
           mov num[2], bh

       done:
       call printf

        endl:
        push 0
        call exit
    main ENDP
END