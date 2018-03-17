#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	// get a string
		char *s = get_string("string: ");
	if (!s)
	{
		return 1;
	}

	// print string, one character per line
	for (int i = 0, n = strlen(s); i < n; i++)
	{
		printf("%c\n", s[i]);
		// alternately this could be 
		// printf("%c\n", *(s + i));
		/* Here, at each index i, we are adding that number to s, to create an address with a higher value than s, so we can get to each character in the string directly with those values. And we have to use the * notation around that address to get the value stored at that address.*/
		
	}
	return 0;
}
