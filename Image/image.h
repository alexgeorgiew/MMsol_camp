#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Pixel_Data{
    unsigned char red,green,blue;
}Pixel_Data;


typedef struct PPM_Image_Buffer{
      Pixel_Data* data;
      int rown,coln;
}PPM_Image_Buffer;

int max(int a,int b);

int read_ppm_color_bitmap(char* filename, PPM_Image_Buffer* buf);

int write_ppm_color_bitmap(char* filename, PPM_Image_Buffer *buf);

void filter_color_component(PPM_Image_Buffer* buf,unsigned int rgb_mask);

void convert_to_grayscale(PPM_Image_Buffer* buf);

void printfBuffer(PPM_Image_Buffer* input);

int write_to_binaryppm(PPM_Image_Buffer* image,char* filename);
int read_from_binaryppm(PPM_Image_Buffer* image,char* filename);

