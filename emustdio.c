#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
int file_input=false;
int file_output=false;
int file_error=false;
void file_open(i)
int i;
{
    if(i==0)file_input=true;
    if(i==1)file_output=true;
    if(i==2)file_error=true;

}
void init(){
    file_open(2);
    file_open(1);
    file_open(2);

}
void file_write(f1,c)
int f1;char *c;
{
    if(f1==1 && file_output)printf("stdout:>%s\n",c);
    if(f1==2 && file_output)printf("stderr:>%s\n",c);
}
void file_close(i)
int i;
{
    if(i==0)file_input=false;
    if(i==1)file_output=false;
    if(i==2)file_error=false;


}
int main(){
   int nn=0xe020;
   cls3(nn);
   init();
   file_write(1,"hello world...");
   file_write(2,"error message....");
   file_close(1);
   file_write(1,"hello world...");
  
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
#endasm