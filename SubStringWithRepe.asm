org 100h

jmp start

str db "world hello world world hello world$"
sizeStr equ ($-str)
dummy1 dw 10 dup($)
subS db "world$"
sizeSub equ ($-subS)
dummy2 dw 10 dup($)
msg db "The Number of subString is : $"

start:
    cld
    call subStringFind
    
    jmp EXT
    
    
    subStringFind proc near
        pushf
        push ax
        push bx
        push cx
        push dx
        
        lea si,str
        lea di,subS
        mov sp,00h
        mov bl,00h
        mov bp,sizeStr
        
    FLAG:
        mov cx,sizeSub
        repe cmpsb
        
        cmp cx,00h
        jz EQUAL
        
        jmp NOT_EQUAL
        
    EQUAL:
         dec si
         inc sp
         dec bp
         jz RETURN
         lea di,subS
         jmp FLAG
    NOT_EQUAL: 
        dec bp
        jz EXT
        lea di,subS
        jmp FLAG
        
        pop ax
        pop bx
        pop cx
        pop dx
        popf

        
    RETURN:
        ret


EXT:
    mov dx, offset msg
    mov ah, 9
    int 21h
    
    mov ax,sp
    add ax,30h
    mov ah, 0eh
    int 10h

end


