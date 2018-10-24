#include <stdio.h>

int main (int argc, char *argv[])
{
  (void) argc;

  char *filePath = argv[1];
  
  FILE *file = fopen(filePath, "r");

  if (file == NULL) {
    printf("The file or path is invalid");

    return -1;
  }

  char buf[45];

  for (int word = fscanf(file, "%s", buf); word != EOF; word = fscanf(file, "%s", buf))
    {
      printf("%s ", buf);  
    }

  fclose(file);

  return 0;
}
