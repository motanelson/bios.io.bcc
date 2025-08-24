#include<string.h>
#include<stdio.h>
#define l 512
int i[l+2];
int stackPoint=0;
int stacks(value,pushPopRead)
int value;int pushPopRead;
{ 
  int ii=0;
if(pushPopRead==0){
	if(stackPoint<l){
		i[stackPoint]=value;
		stackPoint++;
		ii=value;
	}else{
		ii=-1;
	}
}else{
	if(pushPopRead==1){
			if(stackPoint>0){
				stackPoint--;
			ii=i[stackPoint];
	}else{
		ii=-1;
	}
}else{
	if(pushPopRead==2){
		ii=i[stackPoint];
	}
}
	
}	
  return ii;

}




int main(){
	int d=0;
	int v=0;
	int pushs=0;
	int pops=1;
	int read=2;
	int sizes=255;
	cls3(0x6020);
	for(d=0;d<sizes;d++)stacks(d,pushs);
	for(d=0;d<16;d++){
		v=stacks(d,pops);
		if(v!=254-d)puts("error--------------");
		printf("%d\n",v);
	}
	
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
