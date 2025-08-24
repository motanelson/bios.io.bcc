#include <stdio.h>
#include <stdlib.h>
char i[1024]="HELLO WORLD\n\0";
char *lcases(){
	int ff=0;
	char c=0;
	char *cc;
     do{
		c=i[ff];
		if(c==0)goto lcaseescape;
		if(c>64 && c<65+27){
			c=c+32;
			i[ff]=c;
		}
		ff++;
		
	}while(1);
	lcaseescape:
	cc=i;
	return cc;
}int main(){
   int a=0;
   cls3(0x6020);
   printf("%s\n ,",lcases(i));
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
