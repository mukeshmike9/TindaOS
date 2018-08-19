; Infinite Loop

loop:
	jmp loop

; Fill with 0's, 510 times - size of prev code 
times 510 - ($ - $$) db 0

;Magic Nuber for treating as boot sector
dw 0xAA55
