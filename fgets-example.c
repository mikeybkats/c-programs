#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
  char plaintext[20];
  char *k = argv[1];
  printf("%s\n", k);

  printf("enter plaintext: ");
  fgets(plaintext, 20, stdin);

  printf("You entered: %s", plaintext);
}
