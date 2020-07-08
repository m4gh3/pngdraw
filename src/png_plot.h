#ifndef __PNG_PLOT__
#define __PNG_PLOT__

#include "png_buffer.h"

#ifdef __cplusplus
extern "C" {
#endif

void plot(png_buffer_ut *png_buf, float x0, float x1, float y0, float y1, int w0, int w1, int h0, int h1, float (*f)(float, void * ), void *data, uint32_t color );

#ifdef __cplusplus
}
#endif

#endif
