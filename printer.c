#define varn 0x0080
//bcc -Md -o output.com output.c
void pputc(c)
char c;
{

    sputc(c);

}
void pputs(s)
char *s;
{
    int n=0;
    while(s[n]!=0){
        pputc(s[n]);
        n++;
    }

}
int main(){
    int nn;
    int n;
    n=1;
    nn=0xe020;
    cls3(nn);
    pputs("hello world......\n\n\f");	
    return 0;
}
#asm
.globl _cls3
.globl _sputc 
_cls3:
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
_sputc:
    mov si,sp
    add si,*0x2
    mov bl,*0x0e
    mov al,*0x00
    mov dx,*0x00
    mov dl,[si]
    mov ah,*0x05
    int *0x21
    ret

#endasm