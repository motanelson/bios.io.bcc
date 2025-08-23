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
void locate(xx,yy)
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
    buffers[2001]=0;
    printf("\033c\033[43;30m\n");
    for(n=0;n<h-1;n++){
         memcpy(line,buffers,79);
         line[w]=0;
         printf("%s\n",line);
         buffers=buffers+w;
    }
    buffers[2001]=0;
}
int main(){
   clear();
   locate (4,4);
   print("hello world");
   refresh();
   return 0;
}
