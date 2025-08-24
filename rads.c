
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//bcc -o rands rads.c
int i[]={511,255};
int rad(iii)
int iii;
{
	int ii=0;
	srand(time(NULL));
	ii=iii & 1;
	ii=i[ii];
	ii=rand() & ii;
	return ii;
	
}

int main(argc,argv)
int argc;char *argv[];
{
	cls3(0x6020);
	if(argc>1)printf("%d\n",rad(atoi(argv[1])));
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
