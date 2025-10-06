#include "vec3.h"
#include <math.h>


vec3 vec3_add(vec3 a, vec3 b) 
{
	return (vec3) { a.x+b.x, a.y+b.y, a.z+b.z };
}

vec3 vec3_sub(vec3 a, vec3 b) 
{
	return (vec3) { a.x-b.x, a.y-b.y, a.z-b.z };
} 

vec3 vec3_multiple(vec3 a, double b) 
{
	return (vec3) { a.x*b, a.y*b, a.z*b };
} 

vec3 vec3_divide(vec3 a, double b) 
{
	return (vec3) { a.x/b, a.y/b, a.z/b };
} 

vec3 vec3_negate(vec3 a) 
{
	return (vec3) {-a.x, -a.y, -a.z};
}

double vec3_dot(vec3 a, vec3 b) 
{
	return (double)( a.x*b.x + a.y*b.y + a.z*b.z );
}

vec3 vec3_cross(vec3 a, vec3 b) 
{
	return (vec3)
	{
		a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.y*b.z - a.y*b.x
	};
}

double  vec3_length (vec3 a) 
{
	return (double) sqrt(vec3_dot(a, a));
}

double  vec3_length_squared (vec3 a) 
{
	return  a.x*a.x + a.y*a.y + a.z*a.z ;
}

vec3 vec3_normalize(vec3 a) 
{
	return vec3_divide(a, vec3_length(a));
}
