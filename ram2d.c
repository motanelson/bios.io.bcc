#include<string.h>
#include<stdio.h>
  #define xx 2
  #define yy 2
  int i[xx*yy+2];
int ram2d(x,y,writes,value)
int x;int y;int writes;int value;
{ 
  int ii=0;
  int l=xx*yy;
  int indexs=0;
  indexs=x+(y*xx);
  if(indexs>1 && indexs<l+2){
	  if(writes!=0)i[indexs-2]=value;

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
	int errs=0;
	x=ram2d(0,0,0,0);
	y=ram2d(0+1,0,0,0);
	cls3(0x6020);
		for(dy=0;dy<y;dy++){
			for(dx=0;dx<x;dx++){
				ram2d(dx+2,dy,1,dx+(dy*xx));
			}
		}

		for(dy=0;dy<y;dy++){
			for(dx=0;dx<x;dx++){
				errs=ram2d(dx+2,dy,0,0);
				if(errs!=dx+(dy*xx))puts("---error");
				printf("x %d,y %d = %d\n",dx,dy,errs);
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
