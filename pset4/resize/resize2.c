#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
  // ensure proper usage
  if (argc != 4)
  {
    fprintf(stderr, "Usage: ./resize resizefactor infile outfile\n");
    return 1;
  }

  // remember filenames
  int n = atoi(argv[1]);
  char *infile = argv[2];
  char *outfile = argv[3];

  // open input file
  FILE *inptr = fopen(infile, "r");
  if (inptr == NULL)
  {
    fprintf(stderr, "Could not open %s.\n", infile);
    return 2;
  }

  // open output file
  FILE *outptr = fopen(outfile, "w");
  if (outptr == NULL)
  {
    fclose(inptr);
    fprintf(stderr, "Could not create %s.\n", outfile);
    return 3;
  }

  // read infile's BITMAPFILEHEADER
  BITMAPFILEHEADER bf;
  fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

  // read infile's BITMAPINFOHEADER
  BITMAPINFOHEADER bi;
  fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

  // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
  if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
      bi.biBitCount != 24 || bi.biCompression != 0)
  {
    fclose(outptr);
    fclose(inptr);
    fprintf(stderr, "Unsupported file format.\n");
    return 4;
  }

  printf("biWidth: %i\n", bi.biWidth);
  int originalPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
  int originalWidth = bi.biWidth;
  printf("originalPadding: %i\n", originalPadding);

  // set the resize value in the header file
  bi.biWidth = bi.biWidth * n;
  bi.biHeight = bi.biHeight * n;

  // determine padding for scanlines
  int newPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
  printf("newPadding: %i\n", newPadding);


  bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + newPadding) * abs(bi.biHeight); 
  bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

  // write outfile's BITMAPFILEHEADER
  fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

  // write outfile's BITMAPINFOHEADER
  fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

  /*printf("new height: %i\n", abs(bi.biHeight));*/
  /*printf("new width: %i\n", bi.biWidth);*/

  // iterate over infile's scanlines
  /*int counter = n;*/
  RGBTRIPLE triple;
  for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
  {
    int location = ftell(inptr);
    // loop n number of times for new height
    for (int v = 0; v < n; v++)
    {
      fseek(inptr, location, SEEK_SET);
      /*printf("rgb triple size: %lu\n", sizeof(RGBTRIPLE));*/
      // iterate over pixels in scanline
      for (int j = 0; j < originalWidth; j++)
      {
        fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
        for (int k = 0; k < n; k++)
        {
          // write the new pixels to the outptr
          fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }
      }
      /*int offset = ftell(inptr);*/
      /*printf("offset: %i\n", offset);*/

      // if padding exists then add it to the end of the line
      for (int m = 0; m < newPadding; m++)
      {
        fputc(0x00, outptr);
        // remember 3 characters == the size of an RGBTRIPLE
      }

      // skip over padding, if any in the original file
      fseek(inptr, originalPadding, SEEK_CUR);

      /*if(counter != 0){*/
        /*fseek(inptr, -originalPadding, SEEK_CUR);*/
        // fseek backward to the beginning of the line 
        // according to the biWidth 
        /*for (int l = 0; l < originalWidth; l++)*/
        /*{*/
          /*fseek(inptr, -sizeof(RGBTRIPLE), SEEK_CUR);*/
        /*}*/
        /*int offset2 = ftell(inptr);*/
        /*printf("offset 2: %i\n", offset2);*/
      /*}*/

      /*counter--;*/
      /*if(counter == 0)*/
      /*{*/
        /*counter = n;*/
      /*}*/
    }
  }

  // close infile
  fclose(inptr);

  // close outfile
  fclose(outptr);

  // success
  return 0;
}
