#include<string.h>
#include<stdio.h>
int eeppromX(a)
int a;
{ 
  int ii=0;
  int l=0;
  char i[1024];
  strcpy(i,"hello world...\n");
  l=strlen(i);
  if(a>0 && a<l+1){
	  ii=(int)i[a-1];
  }else{if(a==0){
			ii=(int)l;
		}else{ii=0;}
		}
	
	
  return ii;
}



int main(){
	int d=0;
	int e=0;
	cls3(0x6020);
	e=eeppromX(0);
	for(d=0;d<e;d++)putc(eeppromX(d+1),stdout);
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
