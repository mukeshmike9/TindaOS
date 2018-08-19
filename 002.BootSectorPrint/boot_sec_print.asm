; 0x0e on ah tells the video interrupt that the actual function we want to run is 'write the contents of al in tty mode'

mov ah, 0x0e ; tty mode
mov al, 'T'
int 0x10 ; interrupt for video
mov al, 'i'
int 0x10
mov al, 'n'
int 0x10
mov al, 'd'
int 0x10
mov al, 'a'
int 0x10
mov al, ' '
int 0x10
mov al, 'O'
int 0x10
mov al, 'S'
int 0x10

loop:
	jmp loop

times 510 - ($ - $$) db 0

dw 0xAA55
