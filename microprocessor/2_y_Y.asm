.model small
.stack 100h
.data
    a db "Enter a character: $"
    print db 10,13," $"
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
    
    cmp bh,"y"
    je show   
    
    cmp bh,"Y"
    je show
    jmp exit
    
    show: 
        lea dx,print
        mov ah,9
        int 21h
        
        mov ah,2
        mov dl,bh
        int 21h

    exit:
    mov ah, 4Ch
    int 21h

main endp
end main
