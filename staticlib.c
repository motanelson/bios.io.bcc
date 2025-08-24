//bcc -c -Md -o static.o staticlib.c
int adds(a,b);
int subs(a,b);
int mults(a,b);
int divs(a,b);
int adds(a,b)
int a;int b;
{
	return a+b;
}
int subs(a,b)
int a;int b;
{
	return a-b;
}
int mults(a,b)
int a;int b;
{
	return a*b;
}
int divs(a,b)
int a;int b;
{
	return a/b;
}