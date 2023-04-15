; Josiah Larimer
; COSC 2425
; programming set 2
;
; used https://learn.microsoft.com/en-us/cpp/assembler/masm/microsoft-macro-assembler-reference?view=msvc-170 as a reference
; used https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/ as a reference
; used https://stackoverflow.com/questions/8971627/masm-using-registers-as-expressions-between-mod-operator to figure out how to take the modulus
;
;"Write a MASM program that finds the greatest common divisor (GCD) between two numbers. The
;user will enter two integers from the keyboard and output to the screen the GCD of the two numbers.
;Assume proper input. Output should be user friendly."
;


.386
.model flat, stdcall, c
.stack 4096


.data
toExit byte 'Enter -1 to exit the program', 10, 0
prompt1 byte 'Enter the first integer: ', 0
prompt2 byte 'Enter the second integer: ', 0
result  byte 'GCD = %d', 10, 10, 0
whitespace byte '     ', 0
userNumber1 dd ?
userNumber2 dd ?
format  BYTE    "%5s", 0


.code
includelib libucrt.lib
includelib libvcruntime.lib
includelib libcmt.lib
includelib legacy_stdio_definitions.lib

extrn scanf:near
extrn printf:near
extrn exit:near
extrn gets:near
extrn atoi:near

public main
main proc


    ; telling the user how to exit the program
    push offset toExit
    call printf

    
    top:

    ; prompt user for first number
    push offset prompt1
    call printf
    push offset userNumber1
    call gets    
    call atoi
    mov userNumber1, eax

    ; prompt user for second number
    push offset prompt2
    call printf
    push offset userNumber2   
    call gets
    call atoi
    mov userNumber2, eax

    ; getting everything in the right place
    mov ebx, userNumber1
    mov ecx, userNumber2

    ; checking if the user wants to exit the program
    .if ebx == -1 || ecx == -1
        jmp superDone
    .endif

    findGCD:

        .if ebx == 0
            mov eax, ecx
            jmp done
        .endif

        ; ecx mod ebx    
        xor edx, edx	; modulus algorithm
	    mov eax, ecx
	    div ebx			; the quotient is in eax, and the remainder in edx

        ; ecx mod ebx is stored in ebx, and ebx is stored in ecx
        mov ecx, ebx    
        mov ebx, edx
        jmp findGCD     ; keep repeating the process



    done:
    ; Display result
    push eax
    push offset result
    call printf
    jmp top


    superDone:

    ; exit program
    push 0
    call exit
main endp
end 
