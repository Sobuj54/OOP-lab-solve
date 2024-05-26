.model small
.stack 100h
.data
    array db 7,6,5,9,3
    largest db ?
.code
main proc
    mov ax, @data
    mov ds, ax

    mov al, 0       ; Initialize al with 0
    mov cx, 5       ; Count up to 5

    mov si, offset array
up: 
    cmp al, [si]
    jg next       ; Jump if al >= [si]
    mov al, [si]   ; Otherwise assign al with [si] value
next:
    inc si
    
    loop up         ; loop to 'up' if cx is not zero
         
    mov largest, al ; Store the largest value

    ; Display the largest value as a decimal number
    ; Convert the number in 'al' to its ASCII representation
    add al, 30h     ; Convert to ASCII
    mov dl, al
    mov ah, 2
    int 21h

    exit:
    mov ah, 4Ch
    int 21h

main endp
end main
