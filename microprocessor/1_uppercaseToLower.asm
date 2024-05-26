.model small
.stack 100h
.data
    a db "Enter lower Case: $"
    b db 10,13,"Enter UpperCase : $"
    print db 10,13,"Converted case: $"
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
    
    lea dx,print
    mov ah,9
    int 21h   
       
    sub bh,32 ; convert lower case to uppercase
    mov dl,bh
    mov ah,2
    int 21h    
    
    lea dx,b
    mov ah,9
    int 21h
    
    mov ah,1
    int 21h
    mov bh,al
    
    lea dx,print
    mov ah,9
    int 21h   
       
    add bh,32 ; convert lower case to uppercase
    mov dl,bh
    mov ah,2
    int 21h 

    exit:
    mov ah, 4Ch
    int 21h

main endp
end main
