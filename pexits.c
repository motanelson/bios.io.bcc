#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
void handler(value)
int value;
{
	printf("\n signal:%d\n",value);
	exit(0);
}
void eexits(i,arg)
int i;void *arg;
{
	printf("\n on_exits:%s\n",arg);
}
int main(){
        cls3(0x6020);
	//signal(SIGINT,handler);
	on_exit(eexits,(void *) 0);
	puts("press crt-break");
	while(1){
	};
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
