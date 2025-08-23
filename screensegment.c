#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define w 80
#define h 25
int x=0;
int y=0;
char buffer[2048];
char line[1000];
int print(c)
char *c;
{
    char *ptrs;
    char *ptrr=buffer;
    int n=strlen(c);
    int v=y*w+x;
    if(v>2000) return 0;
    if(v+n>2000)n=2000-v;
    ptrs=ptrr+v;
    memcpy(ptrs,c,n);
    buffer[2001]=0;
    return 0;
}
void locates(xx,yy)
int xx;int yy;
{
    x=xx;
    y=yy;
    buffer[2001]=0;
}
void clear(){
    int n=0;
    for(n=0;n<2000;n++)buffer[n]=32;
    buffer[2001]=0;

}
void refresh(){
    int n=0;
    char *buffers=buffer;
    refreshs(buffer);
}
int main(){
   int nn=0;
   nn=0xe020;
   cls3(nn);

   clear();
   for(nn=4;nn<10;nn++)
   {
       locates(4,nn);
       print("hello world");
   }
   refresh();
   return 0;
}
#asm
.globl _cls3
.globl _refreshs 
_cls3:
    mov ax,*03
    int 0x10
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
_refreshs:
    mov si,sp
    add si,*0x2
    mov dx,[si]
    mov si,dx
    mov ax,*0xb800
    push es
    mov es,ax
    
    mov dx,ax
    mov cx,*2000
    mov di,*0x0   
refreshs1:
    
    mov al,[si]
    push ds
    mov ds,dx
    mov [di],al
    pop ds   
    inc di
    inc di
    inc si
    dec cx
    cmp cx,*0x0
    jnz refreshs1
    pop es
    ret


#endasm