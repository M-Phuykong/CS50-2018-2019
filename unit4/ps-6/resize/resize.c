// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    //Make sure to accept 4 command line arguments
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize size infile outfile\n");
        return 1;
    }
    //Check to see if n is in the range of (1-100)
    else if (atoi(argv[1]) < 0 || atoi(argv[1]) > 100)
    {
        fprintf(stderr, "Make sure resize size is between 0-100\n");
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
    //Create two new bf bitmapfileheader
    BITMAPFILEHEADER bf, new_bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    //Copy bf info into new_bf
    new_bf = bf;

    // read infile's BITMAPINFOHEADER
    //Make another bitmapinfoheader
    BITMAPINFOHEADER bi, new_bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    //Copy bi information into new_bi
    new_bi = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    //New width and height for output file
    new_bi.biHeight = bi.biHeight * n;
    new_bi.biWidth = bi.biWidth * n;


    int new_padding = (4 - (new_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // determine new padding for out file
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //Calculate new image size for the outfile so that the dimension would increase
    new_bi.biSizeImage = (sizeof(RGBTRIPLE) * new_bi.biWidth + new_padding) * abs(new_bi.biHeight);
    new_bf.bfSize = new_bi.biSizeImage + sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER);


    // write  new header to outfile's BITMAPFILEHEADER
    fwrite(&new_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write new header to outfile's BITMAPINFOHEADER
    fwrite(&new_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Iterate over infile's scanlines
    // Using old width and height since we are reading from infile
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //Declare triple as an RGBTRIPLE struct
        RGBTRIPLE triple;

        //For sizing vertically (n - 1) times so that we can write the last line manually
        for (int j = 0; j < n - 1; j++)
        {
            //Iterate through each pixel
            for (int v = 0; v < bi.biWidth; v++)
            {

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                //Write the recently read RBG value and write it n times to outfile
                for (int k = 0; k < n ; k++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

            }

            //Add padding if any
            for (int k = 0; k < new_padding; k++)
            {
                fputc(0x00, outptr);
            }

            //Make a variable to caculate the width in bits
            int seeknum = (sizeof(RGBTRIPLE) * bi.biWidth);

            //Bring the cursor of the infile back to the start, "-" moves backward instead of forward
            fseek(inptr, -seeknum, SEEK_CUR);
        }

        //Write the last line of the image
        for (int v = 0; v < bi.biWidth; v++)
        {

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for (int k = 0; k < n ; k++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }

        //Adding final padding
        for (int k = 0; k < new_padding; k++)
        {
            fputc(0x00, outptr);
        }
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);


    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;

}
