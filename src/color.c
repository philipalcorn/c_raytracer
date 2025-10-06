#include "color.h"

// Make sure that the frame buffer length is 3 * width * height 
// as each pixel will need 3 values per pixel
void write_color(unsigned char* framebuffer, int index, vec3 color)  
{
	framebuffer[index+0] = (unsigned char) 255.99 * color.x;
	framebuffer[index+1] = (unsigned char) 255.99 * color.y;
	framebuffer[index+2] = (unsigned char) 255.99 * color.z;
}
