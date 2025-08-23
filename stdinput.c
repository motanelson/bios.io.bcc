
#include <string.h>
 #include <unistd.h>
int pfread(s,i,f1)
char *s;int i;int f1;
{
    
    return (int)read(f1,s,i);
}
void pfgets(s,i,f1)
char *s;int i;int f1;
{
    s[pfread(s,i-1,f1)-1]=0;
}
char pfgetc(f1)
int f1;
{
    char cc[4096];
    cc[0]=0;
    pfread(cc,4095,f1);
    return (char)cc[0];
}
void pgets(s,i)
char *s;int i;
{
    pfgets(s,i-1,0);
}
char pgetc(f1)
int f1;
{
    char cc[4096];
    cc[0]=0;
    pfread(cc,4095,0);
    return (char)cc[0];
}

int main(){
    char ss[4096];
    char *s="\nget me a string\n";
    int i=strlen(s);
    cls3(0x6020);
    write(1,s,i);
    pgets(ss,4095);
    i=strlen(ss);
    write(1,ss,i);
    //pgetc(0);
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

#endasm