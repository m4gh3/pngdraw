CFLAGS=-g

example_drawcircle: build/png_buffer.o build/png_plot.o
	$(CC) $(CFLAGS) build/png_buffer.o build/png_plot.o examples/drawcircle.c -lm -lpng -o drawcircle

clean:
	rm build/*.o

clean_examples:
	rm drawcircle

build/libpngdraw.so: build/png_buffer.o build/png_plot.o
	$(CC) $(CFLAGS) build/png_buffer.o build/png_plot.o -lm -lpng -shared -o build/libpngdraw.so

build/png_plot.o: build/png_buffer.o src/png_plot.c
	$(CC) $(CFLAGS) src/png_plot.c -c -o build/png_plot.o

build/png_buffer.o: src/png_buffer.c
	$(CC) $(CFLAGS) src/png_buffer.c -c -o build/png_buffer.o
