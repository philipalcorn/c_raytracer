#include "vec3.h"
#include <math.h>


vec3 vec3_add(vec3 a, vec3 b) 
{
	return (vec3) { a.x+b.x, a.y+b.y, a.z+b.z };
}

vec3 vec3_subtract(vec3 a, vec3 b) 
{
	return (vec3) { a.x-b.x, a.y-b.y, a.z-b.z };
} 

vec3 vec3_multiply(vec3 a, float b) 
{
	return (vec3) { a.x*b, a.y*b, a.z*b };
} 

vec3 vec3_divide(vec3 a, float b) 
{
	return (vec3) { a.x/b, a.y/b, a.z/b };
} 

vec3 vec3_negate(vec3 a) 
{
	return (vec3) {-a.x, -a.y, -a.z};
}

float vec3_dot(vec3 a, vec3 b) 
{
	return (float)( a.x*b.x + a.y*b.y + a.z*b.z );
}

vec3 vec3_cross(vec3 a, vec3 b) 
{
	return (vec3)
	{
		a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.x*b.y - a.y*b.x
	};
}

float  vec3_length (vec3 a) 
{
	return (float) sqrt(vec3_dot(a, a));
}

float  vec3_length_squared (vec3 a) 
{
	return  a.x*a.x + a.y*a.y + a.z*a.z ;
}

vec3 vec3_normalize(vec3 a) 
{
	return vec3_divide(a, vec3_length(a));
}
