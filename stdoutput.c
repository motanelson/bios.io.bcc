#include <string.h>
#include <unistd.h>
void pfwrite(s,i,f1)
char *s;int i;int f1;
{
    write(f1,s,i);
}
void pfputs(s,f1)
char *s;int f1;
{
    int i=strlen(s);
    pfwrite(s,i,f1);
}
void pputs(s)
char *s;
{
    pfputs(s,1);
}

void pfputc(c,f1)
char c;int f1;
{
    char s[1024];
    s[1]=0;
    s[0]=(char)c;
    pfwrite(s,1,f1);
}

void pputc(c)
char c;
{
    pfputc(c,1);
}
void pfprintf(s,f1)
char *s;int f1;
{
    int c=0;
    char *integers=" integer \0";
    while (s[c]!=0){
        if (s[c]!='%'){
            pfputc(s[c],f1);
        }else{
            pfputs(integers,f1);
        }
        
        c++;
    }

}
void pprintf(s)
char *s;
{
    pfprintf(s,1);
}
void pperror(s)
char *s;
{
    pfputs(s,2);
}
int main(){
    char *s="\nhello world...\n";
    cls3(0x6020);
    pputs(s);
    pprintf("xx%xxxx%xx\n");
    pperror("err:>simulate a error\n");  
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