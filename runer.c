#include <stdio.h>
#include <stdlib.h>

int main(argc,argv)
int argc; char *argv[];
{
    char c[4096];
    char *cc=NULL;
    char *ccc=NULL;
    char *cccc=NULL;
    char *a[4096];
    int i=0;
    int n=0;
    int nn=0;
    FILE *f1;

    c[0]=0;
    cls3(0x6020);
    if (argc<2)return 1;
    printf("%s\n--------------------------------\n",argv[1]);
    f1=fopen(argv[1],"r");
    i=0;
    if (f1==NULL) return 1;
    while(!feof(f1)){
        
        if(fgets(c,4095,f1)!=NULL){
            i=0;
            cc=c;
            ccc=c;
            cccc=c;
            n=0;
            while(c[i]!='\0'){
                if(c[i]==','){
                   ccc=c+i+1;
                   c[i]='\0';
                   a[n]=cc;
                   cc=ccc;
                   n++;
                 }
                i++;
                
            }
            a[n]=cc;
            n++;
            for(nn=0;nn<n;nn++)printf ("%s\n",a[nn]);
        }
        
    }
    fclose(f1);
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
