#include <stdio.h>
long floatEmulator(a,b,matfunc)
long a;long b;long matfunc;
{ 
  long ii=0;
  long precs=1000;
  if(matfunc==0)ii=a+b;
  if(matfunc==1)ii=a-b;
  if(matfunc==2)ii=a*b;
  if(matfunc==3)ii=a/b;
  if(matfunc==4)ii=a*precs;
  if(matfunc==5)ii=a/precs;
  return ii;
}
long main(){
	long getInt=5;
	long setInt=4;
	long divs=3;
	long mult=2;
	long subs=1;
	long adds=0;
	long x=0;
	long xx=16;
	long xxx=0;
	long readss=0;
	cls3(0x6020);
	for(x=0;x<xx;x++){
		xxx=floatEmulator(x,0,setInt);
		xxx=floatEmulator(xxx,10,divs);
		printf("0.%d\n",xxx);
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
