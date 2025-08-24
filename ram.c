#include<string.h>
#include<stdio.h>
#define l 512
int i[l+2];
int ram(a,writes,value)
int a;int writes;int value;
{ 
  int ii=0;
  if(a>0 && a<l+1){
	  if(writes!=0)i[a-1]=value;
	  ii=(int)i[a-1];
  }else{if(a==0){
			ii=(int)l;
		}else{ii=0;}
		}
	
	
  return ii;
}

int main(){
	int d=0;
	int v=0;
	int sizes=ram(0,0,0);
	cls3(0x6020);
	for(d=0;d<sizes;d++)ram(d+1,1,d);
	for(d=0;d<16;d++){
		v=ram(d+1,0,0);
		if(v!=d)puts("error--------------");
		printf("%d=%d\n",d,v);
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
