#include "model.h"
int hello_init(){
	pr_debug("hello\n");
}
int hello_exit(){
	pr_debug("bye\n");
}
int start(){
        cls3(0x6020);
	module_init(hello_init);
	module_exit(hello_exit);
}



#asm
.globl _cls3
_cls3:
    mov ax,*03
    int *0x10
    mov si,sp
    add si,*0x2
    mov dx,[si]
    mov ax,*0xb800
    push ds
    mov ds,ax
    
    mov ax,dx
    mov cx,*0x8a0
    mov si,*0x0
    
cls31:
    
    mov [si],ax   
    inc si
    inc si
    dec cx
    cmp cx,*0x0
    jnz cls31
    pop ds
    ret
    ret

#endasm
