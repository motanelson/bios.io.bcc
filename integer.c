#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long num=1000;
long mults(values)
long values;
{
    return values*num;
}
long divsn(values)
long values;
{
    return values/num;
}
long matsn(min,max,values)
long min; long max;long values;
{
    return (max-min)/values;

}

long main(){
    
    long n=0;
    long nn=0;
    long nnn=0;
    long i=0;
    long divs=9;
    long t=1;
    char nm[1024];
    nm[0]=0;
    cls3(0x6020);
    n=mults(100);
    printf("%d=%ld\n",n,divsn(n));
    nnn=mults(200);
    i=matsn(n,nnn,divs);
    while(t){
        n=n+i;
        if(n<nnn){
            printf("m%ld=%ld\n",n,divsn(n));
        }else{
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
