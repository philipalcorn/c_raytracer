#ifndef VEC3_H
#define VEC3_H

typedef struct 
{
	float x;
	float y;
	float z;
} vec3;


vec3 vec3_add(vec3 a, vec3 b);
vec3 vec3_subtract(vec3 a, vec3 b);
vec3 vec3_multiply(vec3 a, float b);
vec3 vec3_divide(vec3 a, float b);
vec3 vec3_negate(vec3 a);
float vec3_dot(vec3 a, vec3 b);
vec3 vec3_cross(vec3 a, vec3 b);
float vec3_length(vec3 a);
float vec3_length_squared(vec3 a);
vec3 vec3_normalize(vec3 a);

#endif
