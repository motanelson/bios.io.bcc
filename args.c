#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(argc,argv)
int argc;char *argv[];
{
	int i;
	int ii;
	int iii;
	int n;
	char *cc;
        cls3(0x6020);
	if(argc>2){
		ii=0;
		i=argc;
		ii=atoi(argv[1]);
		ii=ii+2;
		if(ii<i){
			printf("%s",argv[ii]);
		}else{
			return 1;
		}
	}else{
		return 1;
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
