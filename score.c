#include <stdio.h>
int sscore=0;
int scores(a)
int a;
{ 
  sscore=sscore+a;
  return sscore;
}
int main(){
	int x=0;
	int xx=16;
	int xxx=0;
	int readss=0;
	cls3(0x6020);
	for(x=0;x<xx;x++){
		xxx=scores(200);
		printf("%d\n",scores(readss));
	}
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
