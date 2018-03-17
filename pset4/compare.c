#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// get two strings
	string s = get_string("s: ");
	string t = get_string("t: ");

	// compare strings' addresses
	if (s == t)
	{
		printf("same\n");
	}
	// the function will never print the strings as different
	// because to the computer they are just strings. one string is == to another string

	else
	{
		printf("different\n");
	}
}
