#include <stdio.h>
#include <stdlib.h>

// the first three bytes of a jpg 0xff 0xd8 0xff
// the fourth byte of the jpg are: 
// 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, of 0xef. Put another way, the fourth byte’s first four bits are 1110
//
// any slack space will be filled with 0s
//  you should ultimately find that the image contains 50 JPEGs

int main(int argc, char *argv[])
{
  // ensure proper usage
  if (argc != 2)
  {
    fprintf(stderr, "Usage: ./recover cardfilename\n");
    return 1;
  }

  char *infile = argv[1];

  // open memory card file
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
  int j;
  while (fread(buffer, sizeof(buffer), 1, inptr) == 1)
  {
    if (buffer[0] == 0xff && 
        buffer[1] == 0xd8 && 
        buffer[2] == 0xff &&
        (buffer[3] & 0xf0) == 0xe0)
    { 
      j = 0;
      jpegFound = 1;
      char filename[8];
      sprintf(filename, "%03i.jpg", i++);
      /*puts(filename);*/
      FILE *img = fopen(filename, "w");
      
      j++;

      int location = ftell(inptr);
      while(jpegFound && !feof(inptr))
      {
        fwrite(buffer, sizeof(buffer), 1, img);
        fread(buffer, sizeof(buffer),1, inptr);
        j++;
        if (buffer[0] == 0xff && 
            buffer[1] == 0xd8 && 
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
          /*printf("%s: %lu\n", filename, (j*sizeof(buffer))/1000);*/
          printf("number of blocks in %s: %i\n", filename, j);
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
    // some other error interrupted the read
    free(buffer);
    fclose(inptr);
    return 1;
  }
}
