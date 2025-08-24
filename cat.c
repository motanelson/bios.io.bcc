#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define bufsize 2048

void msgbox();
char linec[bufsize];
char *c=linec;
int f1;
int f2;
int t;
int n;

int main(argc,argv)

int argc; char *argv[];
{
		cls3(0x6020);
		if(argc<2)exit(0);
		
		f2=1;
		
		
		

			f1=open(argv[1],  O_RDONLY);
		
		
				do{
					t=read(f1,c,bufsize);
					write(f2,c,t);
			
			
				}while(t==bufsize);
				close(f1);
		
		close(f2);
		
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
