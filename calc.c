#include <stdio.h>
#include <stdlib.h>
int main(){
    
    long n=0;
    long nn=0;
    int t=1;
    char nm[1024]; 
    nm[0]=0;
    cls3(0x6020);
    printf("\n0\n",n);
    while(t){
        
        fgets(nm,79,stdin);
        if(nm[0]!='\n'){
            nn=atoi(nm);
            n=n+nn;
        }else{
            t=0;
        }
            printf("\033[43;30m%ld\n",n);
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
