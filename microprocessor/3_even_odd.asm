.model small
.stack 100h
.data
    a db "Enter a number: $"   
    b db 10,13,"The number is even: $"
    c db 10,13,"The number is odd: $"
.code
main proc
    mov ax, @data
    mov ds, ax
    
    lea dx,a
    mov ah,9
    int 21h
    
    mov ah,1
    int 21h
    mov bh,al           
    
    and bh,1 ;bitwise and
    jz even
    lea dx,c
    mov ah,9
    int 21h 
    jmp exit
    
    even:
        lea dx,b
        mov ah,9
        int 21h
    

    exit:
    mov ah, 4Ch
    int 21h

main endp
end main
