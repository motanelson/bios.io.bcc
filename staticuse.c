#include <stdlib.h>
#include <stdio.h>
int adds(a,b);
int subs(a,b);
int mults(a,b);
int divs(a,b);
int main(){
        cls3(0x6020);
	printf("add:%d\n",adds(10,10));
	printf("sub:%d\n",subs(10,1));
	printf("mul:%d\n",mults(10,10));
	printf("div:%d\n",divs(10,2));
	return 0;
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
