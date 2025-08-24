#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    long start=time();
    int n=0;
    int nn=0;
    int t=1;
    char nm[1024];
    nm[0]=0; 
    srand((int)(start*18));
    n=rand()/300;
    cls3(0x6020);
    //printf("%d\n",n);
    if (n>100)n=100;
    printf("\ngess number\n",n);
    while(t){
        printf("\033[43;30m\ngess a number for 1 to 100 ");
        fgets(nm,79,stdin);
        nn=atoi(nm);
        if(nn>n)printf("\033[43;30myou  number is to big \n");
        if(nn<n)printf("\033[43;30myou  number is to low \n");
        if(nn==n){
            printf("\033[43;30myou guess the number \n");
            t=0;
        }
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
