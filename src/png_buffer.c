#include "png_buffer.h"

int png_buffer_init(png_buffer_ut *png_buf )
{

	png_buf->png_ptr = NULL;
	png_buf->info_ptr = NULL;
	png_buf->row_pointers = NULL;

	png_buf->png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL );
	if( png_buf->png_ptr == NULL )
		goto png_create_write_struct_failed;

	png_buf->info_ptr = png_create_info_struct(png_buf->png_ptr);
	if(png_buf->info_ptr == NULL )
		goto png_create_info_struct_failed;

	if( setjmp(png_jmpbuf(png_buf->png_ptr)) )
		goto png_failure;

	png_set_IHDR	(	png_buf->png_ptr,
				png_buf->info_ptr,
				png_buf->width,
				png_buf->height,
				png_buf->depth,
				PNG_COLOR_TYPE_RGB,
				PNG_INTERLACE_NONE,
				PNG_COMPRESSION_TYPE_DEFAULT,
				PNG_FILTER_TYPE_DEFAULT
			);

	png_buf->row_pointers = png_malloc(png_buf->png_ptr, png_buf->height * sizeof(png_byte *) );

	for(int y = 0; y < png_buf->height; y++)
	{
		png_buf->row_pointers[y] =
			png_malloc(png_buf->png_ptr, sizeof(uint8_t) * png_buf->width * png_buf->pixel_size );
		memset(png_buf->row_pointers[y], 0, sizeof(uint8_t) * png_buf->width * png_buf->pixel_size );
	}

	return 1;

	png_failure:
	png_create_info_struct_failed:
		png_destroy_write_struct(&png_buf->png_ptr, &png_buf->info_ptr );
	png_create_write_struct_failed:
		return 0;

}

int write_png_buf(char *filename, png_buffer_ut *png_buf )
{

	FILE *fp;
	fp = fopen("test.png", "wb" );
	if(!fp)
		return 0;
	
	png_init_io(png_buf->png_ptr, fp );
	png_set_rows(png_buf->png_ptr, png_buf->info_ptr, png_buf->row_pointers );
	png_write_png(png_buf->png_ptr, png_buf->info_ptr, PNG_TRANSFORM_IDENTITY, NULL );

	 for(int i=0; i < png_buf->height; i++)
		png_free (png_buf->png_ptr, png_buf->row_pointers[i] );
    
	png_free(png_buf->png_ptr, png_buf->row_pointers );

	fclose(fp);

	return 1;

}

