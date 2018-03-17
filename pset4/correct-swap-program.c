#include <stdio.h>
#include <cs50.h>

void swap(char *a, char *b)
{
	eprintf("a is %s, b is %s\n", a, b);
	char *tmp = a;
	a = b;
	b = tmp;
	eprintf("a is %s, b is %s\n", a, b);
}

int main(int argc, char *argv[]){
	if (argc > 0)
	{
		char *a = argv[1];
		char *b = argv[2];
		swap( a, b);
	}
}
