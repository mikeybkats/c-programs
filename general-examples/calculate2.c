#include <stdio.h>
#include <string.h>

int main(void){
	float a;
	int b;
	char c;

	printf("enter a: ");
	scanf("%f",&a);

	printf("enter b: ");
	scanf("%i",&b);

	printf("enter c: ");
	scanf("%s",&c);

	printf("Float a %f divided by 3 equals %f\n", a, a/3);
	printf("Int b %i divided by 3 equals %i\n", b, b/3);
	printf("Char c %c divided by 3 cast as an integer equals %c\n", c, c/3);
}

	
