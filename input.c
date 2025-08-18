#define varn 0x0080
//bcc -Md -o input.com input.c
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
int pgetc(){
    return cgetchar();
}
void pgets(s,i)
char *s;
int i;
{
    int n=0;
    char c=0;
    for (n=0;n<i-1;n++){
        c=pgetc();
        s[n]=c;
        s[n+1]=0;
        pputc(c);
        if(c==13)break;
    }

}
int main(){
    char s[4096];
    int nn;
    int n;
    n=1;
    nn=0xe020;
    cls3(nn);
    pputs("get a string......\n\n");	
    pgets(s,4096);
    pputs(s);
    return 0;
}
#asm
.globl _cls3
.globl _sputc 
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
_sputc:
    mov si,sp
    add si,*0x2
    mov bl,*0x0e
    mov bh,*0x00
    mov al,[si]
    mov ah,*0x0e
    int *0x10
    ret
_cgetchar:
    mov ax,0
    int 0x16
    ret
#endasm