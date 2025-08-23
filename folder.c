#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <bios.h>
//bcc -o folder folder.c -lm
int main(){
    char c[4096];
    char *cc=NULL;
    char *ccc=NULL;
    char *cccc=NULL;
    char *a[4096];
    
    int i=0;
    int n=0;
    int nn=0;
    c[0]=0;
    cls3(0x6020);
    printf("\ngive folders separete by space ?\n");
    fgets(c,4095,stdin);
    c[strlen(c)-1]=0;
    i=0;
    cc=c;
    ccc=c;
    cccc=c;
    n=0;
    while(c[i]!='\0'){
        if(c[i]=='\n')c[i]='\0';
        if(c[i]=='\r')c[i]='\0';
        if(c[i]==' '){
            ccc=c+i+1;
            c[i]='\0';
            a[n]=cc;
            cc=ccc;
            n++;
         }
         i++;
                
     }
     a[n]=cc;
     n++;
     for(nn=0;nn<n;nn++)mkdirs (a[nn]);

    return 0;
}
#asm
.globl _cls3

_cls3:
    mov ax,*3
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
_mkdirs:
    mov si,sp
    add si,*0x2
    mov dx,[si]
    mov ah,*0x39
    int *0x21
#endasm