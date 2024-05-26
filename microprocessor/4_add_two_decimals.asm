.model small
.stack 100h
.data
    a db "Enter 1st number: $"   
    b db 10,13,"Enter 2nd number: $"
    c db 10,13,"The sum is: $"
.code
main proc
    mov ax, @data
    mov ds, ax
    
    lea dx,a
    mov ah,9
    int 21h
    
    mov ah,1   ;first number
    int 21h
    mov bh,al
    
    lea dx,a
    mov ah,9
    int 21h           
    
    mov ah,1 ;second number
    int 21h
    mov bl,al
    
    add bl,bh ; sum
    sub bl,48
    
    lea dx,c
    mov ah,9
    int 21h
    
    mov dl,bl
    mov ah,2
    int 21h

    exit:
    mov ah, 4Ch
    int 21h

main endp
end main
