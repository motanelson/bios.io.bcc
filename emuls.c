#include <stdio.h>
int floatEmulator(a,b,matfunc)
int a;int b;int matfunc;
{ 
  int ii=0;
  int precs=1000;
  if(matfunc==0)ii=a+b;
  if(matfunc==1)ii=a-b;
  if(matfunc==2)ii=a*b;
  if(matfunc==3)ii=a/b;
  if(matfunc==4)ii=a*precs;
  if(matfunc==5)ii=a/precs;
  return ii;
}
int main(){
	int getInt=5;
	int setInt=4;
	int divs=3;
	int mult=2;
	int subs=1;
	int adds=0;
	int x=0;
	int xx=16;
	int xxx=0;
	int readss=0;
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
