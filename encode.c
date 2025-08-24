#include<stdio.h>
long i[]={5,7,9,3,71,10,10,12,4,12,2,1,2,3,15,16};
long encodeX(a)

long a;
{ 
  long size=16;
  long ii=-1;
  
  if(a>-1 && a<size){
	  ii=i[a];
  }else{ii=-1;}
  return ii;
}

long main(){
	long d=0;
	long e=0;
	cls3(0x6020);
	e=16;
	for(d=0;d<e;d++)printf("%ld=%ld\n",d,encodeX(d));
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
