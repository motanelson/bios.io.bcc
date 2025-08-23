#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <bios.h>
#include <conio.h>
//#define FP_SEG (fp) ((unsigned) ((unsigned long)(fp) >> 16))
#define FP_OFF(fp) ((unsigned)(fp))
void psystem(cmd)
const char *cmd;
{
    union REGS regs;
    struct SREGS sregs;
    regs.h.ah=0x4b;
    regs.h.al=0x0;
    regs.x.dx = FP_OFF(cmd);
    sregs.ds = __get_ds();
    int86x(0x21,&regs,&regs,&sregs);
    printf(">>>>run:%s\n",cmd);

}
int main(){
    char *s="command line cmd...\n";
    int nn=0;
    char sss[4096];
    char *ss=sss;
    nn=0xe020;
    cls3(nn);

    printf("%s",s); 
    while (ss[0]!='\n'){
        ss=fgets(sss,4095,stdin);
        if(ss[0]=='\n'){
            break;
        }else{
            nn=strlen(ss);
            ss[nn-1]=0;
            psystem(ss);
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
#endasm