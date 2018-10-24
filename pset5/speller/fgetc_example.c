#include <stdio.h>

// an example of how int argc and char *argv work

int main (int argc, char *argv[])
{
  // usage fgetc_example word
  (void) argc;
  
  if (argc != 2) {
    printf("usage: ftgetc_example filepath\n");
  }

  printf("argv 1: %s\n", argv[1]);

  char *filePath = argv[1];

  // fopen(const char name, const char mode r/w/a)

  FILE *file = fopen(filePath, "r");

  if(file == NULL) {
    perror("Error in opening file");
    return(-1);
  }   

  int index = 0;

  for (int c = fgetc(file); c != EOF; c = fgetc(file))
  {
    printf("character %i: %c\n", index, c);
    /*printf("index: %i\n", index);*/
    index++;
  }

  fclose(file);
  return 0;
}
