#define varn 0x0080
//bcc -Md -o stdout.com stdout.c
void pputs(s)
char *s;
{
    int n=0;
    char *ss=s;
    while(s[n]!=0){
        ss=s+n;
        sputc(ss);
        n++;
    }

}
void pgets(s)
char *s;
{
    int n=0;
    char *ss=s;
    while(s[n]!=13){
        ss=s+n;
        sgetc(ss);
        if(s[n]==13)break;
        n++;
    }
    s[n]=0;
}

int main(){
    char cc[1024];
    int nn;
    int n;
    n=1;
    nn=0xe020;
    cls3(nn);
    pputs("get string......\n\n");
    pgets(cc);
    pputs(cc);	
    return 0;
}
#asm
.globl _cls3
.globl _sputc 
.globl _sgetc
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
_sputc:
    mov si,sp
    add si,*0x2
    mov bx,*01
    mov cx,*01
    mov dx,[si]
    mov ah,*0x40
    int *0x21
    ret
_sgetc:
    mov si,sp
    add si,*0x2
    mov bx,*01
    mov cx,*01
    mov dx,[si]
    mov ah,*0x3f
    int *0x21
    ret

#endasm