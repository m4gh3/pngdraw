#ifndef __PNG_BUFFER__
#define __PNG_BUFFER__

#include <string.h>
#include <stdint.h>
#include <png.h>

typedef struct
{
	png_structp png_ptr;
	png_infop info_ptr;
	png_byte **row_pointers;
	int pixel_size, width, height, depth;
} png_buffer_ut;

int png_buffer_init(png_buffer_ut *png_buf );
int write_png_buf(char *filename, png_buffer_ut *png_buf );

#endif
