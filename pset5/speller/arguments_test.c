#include <stdio.h>

// an example of how int argc and char *argv work

int main (int argc, char *argv[])
{
   printf("number of args: %i\n", argc);
   
   printf("the arguments: %s\n", argv[1]);
   
   int args = argc;
   
   if (args > 2)
   {
       for ( int i = 2; i < args; i++) {
          printf("%s\n", argv[i]);
       }
   }
   
   return 0;
}
