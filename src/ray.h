#ifndef RAY_H
#define RAY_H

#include "vec3.h"


typedef struct 
{
	vec3 origin;
	vec3 direction;
} ray;

ray ray_initialize (vec3 o, vec3 d);
vec3 ray_at_t(ray r, float t);

#endif
