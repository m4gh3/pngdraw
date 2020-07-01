#include <stdio.h>
#include <math.h>
#include "../src/png_plot.h"

float circ(float x)
{ return 1-sqrt(1-x*x); }

float circ1(float x)
{ return sqrt(1-x*x); }

int main()
{

	png_buffer_ut png_buf;
	png_buf.depth = 8; png_buf.height = 256; png_buf.width = 256; png_buf.pixel_size = 3;
	png_buffer_init(&png_buf);

	plot(&png_buf, 0, 1, 0, 1, 0, 255, 0, 255, circ, 0x0000ff );
	plot(&png_buf, 0, 1, 0, 1, 0, 255, 0, 255, circ1, 0xff0000 );

	write_png_buf("test.png", &png_buf );
	return 0;

}
