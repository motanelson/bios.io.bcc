#include<string.h>
#include<stdio.h>
  //       0        1        2        3        4        5        6         7         
  //      "01234567 01234567 01234567 01234567 01234567 01234567 012345670 01234567
  char *i="   ..  \n  .  . \n  .  . \n  .  . \n  .  . \n  .... \n  .  . \n  .  . \n";

int map2d(x,y)
int x;int y;
{ 
  int ii=0;
  int l=0;
  int indexs=0;
  int xx=8;
  int yy=8;
  l=strlen(i);
  indexs=x+(y*xx);
  if(indexs>1 && indexs<l+2){
	  ii=(int)i[indexs-2];
  }else{if(indexs==0){
			ii=xx;
		}else{
			if(indexs==1){
			ii=yy;
				
			}
		}}
	
	
  return ii;
}


int main(){
	int x=0;
	int y=0;
	int dx=0;
	int dy=0;
	x=map2d(0,0);
	y=map2d(0+1,0);
	cls3(0x6020);
		for(dy=0;dy<y;dy++){
			for(dx=0;dx<x;dx++){
				putc(map2d(dx+2,dy),stdout);
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
