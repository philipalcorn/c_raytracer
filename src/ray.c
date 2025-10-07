#include "ray.h"

ray ray_initialize(vec3 o, vec3 d) 
{
	return (ray){o, d};
}

vec3 ray_at_t(ray r, double t) 
{
	// Returning the point (vec3) at P = A+t*b
	// P = Point
	// A = Ray origin
	// b = Ray direction
	// t is the parameter we pass.
	return (vec3_add(r.origin, vec3_multiply(r.direction, t)));
}
