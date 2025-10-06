#include <stdio.h>
#include <stdlib.h>
#include "write_ppm.h"

// Writes a framebuffer as a binary ppm image. 
// framebuffer is an array of unsigned chars, size = width* height * 3.
// The idea is that the main loop simply generates the frame buffer, and then
// it all gets written at once here. 
// Each pixel has RGB in [0, 255].
int write_ppm(const char* filename, const unsigned char* framebuffer, int width, int height) 
{
	FILE* f = fopen(filename, "wb");

	// Error handling
	if (!f) 
	{
		perror("Failed to open output file.");
		exit(1);
	}

	// P6 header: binary RGB image
	// https://paulbourke.net/dataformats/ppm/
	fprintf(f, "P6\n%d %d\n255\n", width, height);

	fwrite(framebuffer, 3, width*height, f);
	fclose(f);

	return 1;
}


