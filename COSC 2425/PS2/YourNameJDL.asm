; Josiah Larimer
; COSC 2425
; programming set 2
;
; "Write a MASM program that outputs your first and last name to the screen. Output should be user friendly."
; learned from a video you linked in the MASM information tab, https://www.youtube.com/watch?v=bpZv5bOi5dE&t=2s

.386
.model flat, stdcall, c
.stack 4096

.data
msg BYTE 'Josiah Larimer', 0

.code
includelib libucrt.lib
includelib legacy_stdio_definitions.lib
includelib libcmt.lib
includelib libvcruntime.lib

extrn printf:near
extrn exit:near

public main
main proc
	push	offset msg
	call	printf
	push	0
	call	exit

main endp
end