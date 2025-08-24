#include<stdio.h>
long *i;
long ii=0;
long count=0;
long rad(a)
long a;
{
	long t=0;
	if(a==0){
		ii=0;
		i=(long*)rad;
	}
	if (count>80){
		count=0;
		i=(long*)rad;
	}
	count++;
	i=i+1;
	t=*i & 255;
	if(a==1)t=t*2;
	return t;
}


long main(){
	long aa=0;
	aa=rad(0);
	cls3(0x6020);
	for(aa=0;aa<80;aa++)printf(" %ld , ",rad(1));
	return 0;
}#asm
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
