#include "png_plot.h"

void plot(png_buffer_ut *png_buf, float x0, float x1, float y0, float y1, int w0, int w1, int h0, int h1, float(*f)(float), uint32_t color )
{
	for(int i=0; i < w1-w0+1; i++ )
	{
		float x = (x1-x0)*(((float)i)/(w0-w1)) + x0;
		float y = (h1-h0)*(f(x)-y0)/(y1-y0) + h0;
		png_buf->row_pointers[(int)y][(i+w0)*3]   |= color&0xff;
		png_buf->row_pointers[(int)y][(i+w0)*3+1] |= (color>>8)&0xff;
		png_buf->row_pointers[(int)y][(i+w0)*3+2] |= (color>>16)&0xff;
	}
}
