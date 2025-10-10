#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vec3.h"
#include "ray.h"
#include "color.h"
#include "write_ppm.h"
#include <stdbool.h>
/* 
 * Here I define the viewing direction as follows:
 * The camera center will be at 0,0,0. This will be where all rays originate.
 * The y-axis will point up.
 * The x-axis will point to the right.
 * The positive z-axis will point out from the camera, into the viewing direction.
 *
 * */


float hit_sphere(vec3 center, float radius, ray r) 
{
	vec3 origin_to_center = vec3_subtract(r.origin,center);
	float a = vec3_dot(r.direction, r.direction);
	float b = 2.0f * vec3_dot(r.direction, origin_to_center);
	float c = vec3_dot(origin_to_center, origin_to_center) - radius * radius;
	float discriminant = b*b - 4*a*c;

	if(discriminant < 0) 
	{
		return -1.0;
	} else
	{
		// Return the closer t
		return (-b - sqrt(discriminant)) / (2*a);
	}


}

// Here we use the formula for linearly scaling 0 < a < 1.
// blended_value = (1-a)*start_value + a * end_value
vec3 ray_color(const ray r) 
{
	// check if we hit a sphere at (0,0,1), right in front of the camera; 
	float t = hit_sphere( (vec3){0,0,1}, 0.5, r);

	if(t>0) 
	{
		vec3 N = vec3_normalize(vec3_subtract(ray_at_t(r, t), (vec3) {0,0,1}));
		return vec3_multiply((vec3) {N.x+1, N.y+1, N.z+1}, 0.5);
	}
	
	vec3 unit_direction = vec3_normalize(r.direction);
	float a = 0.5*(unit_direction.y +1.0);
	return vec3_add(vec3_multiply( (vec3){1.0, 1.0, 1.0}, 1-a ),
					vec3_multiply( (vec3){0.5, 0.7, 1.0}, a ));
}

int main () 
{
	printf("Hello, World\n");

	float aspect_ratio = 16.0/9.0; // Ratio of W/H 
	int image_width = 500;

	int image_height = (int)(image_width / aspect_ratio);

	// Make sure the image height is at least 1 and not rounded to 0.
	image_height = (image_height<1) ? 1 : image_height; 

	// Camera
	
	float focal_length = 1.0;
	float viewport_height = 2.0;

	// Can't use aspect ratio here because the true aspect ratio will be based on
	// the division between the pixels of w and h, which will be integer valued
	// and so might have a slightly different aspect ratio than the "ideal" 
	// aspect ratio
	float viewport_width = viewport_height * (float)(image_width)/(float)(image_height);
	vec3 camera_center = {0,0,0};
	
	// Calculating the horozontal and vertical vectors across the entire 
	// viewport. These will be used to calculate the delta x and delta y vectors
	// to get the separation between pixels.
	vec3 viewport_total_x = {viewport_width, 0,0};	
	vec3 viewport_total_y = {0, -viewport_height,0};	

	vec3 pixel_delta_x = vec3_divide(viewport_total_x, (float)image_width);
	vec3 pixel_delta_y = vec3_divide(viewport_total_y, (float)image_height);

	// Top left of the viewport:
	// Find the z distance from the camera.
	vec3 viewport_top_left = vec3_add(camera_center, (vec3) {0,0,focal_length});
	// Camera is the center of the x and y coordinates of the viewport.
	// So subtract half the viewport_total_x and half the viewport_total_y
	// (remember that viewport_total_y faces down)
	viewport_top_left = vec3_subtract(viewport_top_left, vec3_divide(viewport_total_x,2));
	viewport_top_left = vec3_subtract(viewport_top_left, vec3_divide(viewport_total_y,2));

	// Set the top left pixel location.
	vec3 pixel_edge_offset = vec3_multiply(vec3_add(pixel_delta_x, pixel_delta_y), 0.5);
	vec3 pixel_top_left = vec3_add(viewport_top_left, pixel_edge_offset);


	// times three for three color values per pixel
	unsigned char* framebuffer = malloc(image_width * image_height * 3);
	if (!framebuffer) 
	{
		perror("Error: Failed to allocate framebuffer memory");
		exit(1);
	}

	// Filling the framebuffer with data
	for (int j = 0; j < image_height; j++ ) 
	{
		for (int i=0; i< image_width; i++) 
		{
			// Getting the center of the current pixel	
			vec3 pixel_x = vec3_multiply(pixel_delta_x, i);
			vec3 pixel_y = vec3_multiply(pixel_delta_y, j);
			vec3 pixel_center = vec3_add(pixel_top_left, pixel_x);
			pixel_center = vec3_add(pixel_center, pixel_y);
			
			vec3 ray_direction = vec3_subtract(pixel_center, camera_center);

			// Generate a ray from the camera to the pixel center
			ray r = {camera_center, ray_direction};

			// Rendering
			vec3 pixel_color = ray_color(r);

			int index = 3 * (j*image_width + i);
			// colors the red and green based on x and y position.
			write_color(framebuffer, index, pixel_color);
		}
	}
	printf("Writing file...\n");
	// Writing the framebuffer to a file
	if (!write_ppm("output.ppm", framebuffer, image_width, image_height)) 
	{
		perror("Error: Failed to write to image!");
		exit(1);
	}
	printf("Done.\n");
	free(framebuffer);

	return 0;

}
