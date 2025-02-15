#include "asciigen.h"

void print_usage()
{
    printf(
            "\nASCII art generator application \n"
    "=============================== \n\n"
    "asciiartgen <path-to-source-bmp> <options>... \n\n"
    "Available <options>: \n"
    "-size               prints out the size of the BMP file in bytes \n"
    "-w                  prints out the width of the BMP file \n"
    "-h                  prints out the height of the BMP file \n"
    "-depth              prints out the color depth of the BMP file \n"
    "-o <path-to-txt>    specify where to put the resulting txt file \n"
    "-mono               convert the BMP picture as monochromatic txt, "
    "non-white pixels will be represented with x characters \n"
    "-mono <character>   convert the BMP picture as monochromatic txt, "
    "<character> will be used to represent non-white pixels \n"
    "-regular            convert the BMP picture as multiple colored txt\n");
}

void print_size(FILE* fptr)
{
    unsigned char buffer[6];
    fread(buffer, sizeof(unsigned char),6, fptr);
    int* size_int_ptr = (int *) &buffer[2];
    printf("Size: %d\n", *(size_int_ptr));
    rewind(fptr);
}

void print_width(FILE* fptr)
{
    unsigned char buffer[30];
    fread(buffer, sizeof(unsigned char),30, fptr);
    int* width_int_ptr = (int *) &buffer[18];
    printf("Width: %d pixels\n", *(width_int_ptr));
    rewind(fptr);
}

void print_height(FILE* fptr)
{
    unsigned char buffer[50];
    fread(buffer, sizeof(unsigned char),50, fptr);
    int* height_int_ptr = (int *) &buffer[22];
    printf("Height: %d pixels\n", *(height_int_ptr));
    rewind(fptr);
}

void print_depth(FILE* fptr)
{
    unsigned char buffer[50];
    fread(buffer, sizeof(unsigned char),50, fptr);
    int* depth_int_ptr = (int *) &buffer[0x1C];
    printf("Depth: %d bits\n", *(depth_int_ptr));
    rewind(fptr);
}

/*
    for (int i = 0; i < 50; ++i) {
        printf("%d: %d\n", i, buffer[i]);
    }
 */