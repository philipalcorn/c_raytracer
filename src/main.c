#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vec3.h"
#include "color.h"
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
			int index = 3 * (j*width + i);
			// colors the red and green based on x and y position.
			vec3 color = {	(float)(i)/(float)(width) ,
							(float)(j)/(float)(height),
							sqrt(i*i + j*j)/sqrt(width*width+height*height) };
			write_color(framebuffer, index, color);
		}
	}
	printf("Writing file...\n");
	// Writing the framebuffer to a file
	if (!write_ppm("output.ppm", framebuffer, width, height)) 
	{
		perror("Error: Failed to write to image!");
		exit(1);
	}
	printf("Done.\n");
	free(framebuffer);

	return 0;

}
