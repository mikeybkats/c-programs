#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: ./recover cardfilename\n");
    return 1;
  }

  char *infile = argv[1];

  FILE *inptr = fopen(infile, "r");
  if (inptr == NULL)
  {
    fprintf(stderr, "Could not open %s.\n", infile);
    return 2;
  }
  
  int i = 0;
  unsigned char *buffer;
  buffer = (unsigned char *)malloc(sizeof(unsigned char) * 512); 
  int jpegFound = 0;
  while (fread(buffer, sizeof(buffer), 1, inptr) == 1)
  {
    if (buffer[0] == 0xff && 
        buffer[1] == 0xd8 && 
        buffer[2] == 0xff &&
        (buffer[3] & 0xf0) == 0xe0)
    { 
      jpegFound = 1;
      char filename[8];
      sprintf(filename, "%03i.jpg", i++);
      FILE *img = fopen(filename, "w");
      
      int location = ftell(inptr);
      while(jpegFound && !feof(inptr))
      {
        fwrite(buffer, sizeof(buffer), 1, img);
        fread(buffer, sizeof(buffer),1, inptr);
        if (buffer[0] == 0xff && 
            buffer[1] == 0xd8 && 
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
          jpegFound = 0;
          fseek( inptr, location, SEEK_SET); 
        }
      }
      fclose(img);
    }
  }
  if (feof(inptr))
  {
    free(buffer);
    fclose(inptr);
    return 0;
  }
  else
  {
    free(buffer);
    fclose(inptr);
    return 1;
  }
}
