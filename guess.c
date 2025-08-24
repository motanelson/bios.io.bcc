#include <stdio.h>
#include <stdlib.h>
int n=50;
int nn=0;
int lessn=1;
int bigs=100;
int yess=1;
char s[1024]="";
void pprists(){
    printf("\nAnswer me with these 3 symbols =+-");
    printf("\n= for This is the number I thought of\n");
    printf("\n+ My number is bigger");
    printf("\n- My number is smaller");
}
int main(){
    cls3(0x6020);
    printf("\ncomputer guess a number");
    printf("\nThink of a number for 1 to 100");
    printf("\nI'll try to guess your number, by trying");
    while (yess){
        pprists();
        n=lessn+((bigs-lessn)/2);
        printf("%d\n",n);
        fgets(s,1023,stdin);
        if (s[0]=='='){
           yess=0;
        }
        if (s[0]=='-'){
           bigs=n;
        }
        if (s[0]=='+'){
           lessn=n;
        }
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
