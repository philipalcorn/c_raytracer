#include <stdio.h>
#include <stdlib.h>

#include "vec3.h"
#include "write_ppm.h"

int main () 
{
	printf("Hello, World\n");


	int width = 1000;
	int height = 1000;
	// times three for three color values per pixel
	unsigned char* framebuffer = malloc(width * height * 3);
		
	if (!framebuffer) 
	{
		perror("Error: Failed to allocate framebuffer memory");
		exit(1);
	}

	// Filling the framebuffer with data
	for (int j = 0; j < height; j++ ) 
	{
		for (int i=0; i< width; i++) 
		{
			int index = (j*width + i) * 3;

			framebuffer[index + 0] = (unsigned char) (255.99 * (float)i/width);
			framebuffer[index + 1] = (unsigned char) (255.99 * (float)j/height);
			framebuffer[index + 2] = 128;
		}
	}

	// Writing the framebuffer to a file
	if (!write_ppm("output.ppm", framebuffer, width, height)) 
	{
		perror("Error: Failed to write to image!");
		exit(1);
	}
	free(framebuffer);

	return 0;

}
