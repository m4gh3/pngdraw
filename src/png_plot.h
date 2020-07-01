#ifndef __PNG_PLOT__
#define __PNG_PLOT__

#include "png_buffer.h"

void plot(png_buffer_ut *png_buf, float x0, float x1, float y0, float y1, int w0, int w1, int h0, int h1, float (*f)(float), uint32_t color );

#endif
