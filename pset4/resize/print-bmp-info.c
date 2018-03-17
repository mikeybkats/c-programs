#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    (void)(argc);
    // remember filenames
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
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
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    printf("\nBitmap BF header info: \n");
    printf("bfType: %d\n", bf.bfType );
    printf("bfSize: %i\n", bf.bfSize );
    printf("bfReserved1: %i\n", bf.bfReserved1 );
    printf("bfReserved2: %i\n", bf.bfReserved2 );
    printf("bfOffBits: %i\n\n", bf.bfOffBits );

    printf("Bitmap BI header info: \n");
    printf("biSize: %i\n", bi.biSize );
    printf("biWidth: %i\n", bi.biWidth );
    printf("biHeight: %i\n", bi.biHeight );
    printf("biPlanes: %i\n", bi.biPlanes );
    printf("biBitCount: %i\n", bi.biBitCount );
    printf("biCompression: %i\n", bi.biCompression );
    printf("biSizeImage: %i\n", bi.biSizeImage );
    printf("biXPelsPerMeter: %i\n", bi.biXPelsPerMeter );
    printf("biYPelsPerMeter: %i\n", bi.biYPelsPerMeter );
    printf("biClrUsed: %i\n", bi.biClrUsed );
    printf("biClrImportant: %i\n", bi.biClrImportant );

    RGBTRIPLE triple;
    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
    printf("Size of triple: %lu\n\n", sizeof(RGBTRIPLE));
    /*for(int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++){*/
      /*for (int j = 0; j < bi.biWidth; j++){*/
        /*RGBTRIPLE triple;*/
        /*fread(&triple, sizeof(RGBTRIPLE), 1, inptr);*/
        /*printf("row: %i pixel: %i ", i, j);*/
        /*printf("red: %i ", triple.rgbtRed);*/
        /*printf("green: %i ", triple.rgbtGreen);*/
        /*printf("blue: %i\n", triple.rgbtBlue);*/
      /*}*/
      /*printf("\n");*/
    /*}*/
    // close infile
    fclose(inptr);

    return 0;
}
