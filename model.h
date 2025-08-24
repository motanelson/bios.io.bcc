#include <stdio.h>

void (*adds1)();
void (*adds2)();
void module_init(adds)
void (*adds);
{
	adds1=adds;
}
void module_exit(adds)
void (*adds);
{
	adds2=adds;
}
void pr_debug(s)
char *s;
{
	puts(s);
}

int main(){
	start();
	(*adds1)();
	(*adds2)();
	return 0;
}
