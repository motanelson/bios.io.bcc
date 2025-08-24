#include<string.h>
#include<stdio.h>
  //      "1     2  1     2
  //      "1  2  1  2  1  2  1  2
  char *i=" \n*\n \n*\n \n*\n \n*\n";

int map3d(x,y,z)
int x;int y;int z;
{ 
  int ii=0;
  int l=0;
  int indexs=0;
  int xx=2;
  int yy=2;
  int zz=2;
  l=strlen(i);
  indexs=x+(y*xx)+(yy*xx)*z;
  if(indexs>2 && indexs<l+3){
	  ii=(int)i[indexs-3];
  }else{if(indexs==0){
			ii=xx;
		}else{
			if(indexs==1){
			ii=yy;
				
			}else{if(indexs==2){
				ii=zz;
			}
		}}}
	
	
  return ii;
}


int main(){
	int x=0;
	int y=0;
	int z=0;
	int dx=0;
	int dy=0;
	int dz=0;
	x=map3d(0,0,0);
	y=map3d(0+1,0,0);
	z=map3d(0+2,0,0);
	cls3(0x6020);
	for(dz=0;dz<z;dz++){
		for(dy=0;dy<y;dy++){
			for(dx=0;dx<x;dx++){
				putc(map3d(dx+3,dy,dz),stdout);
			}
		}
		putc('\n',stdout);
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
