#include <stdbool.h>
#include "../scene/shapes.h"

#ifndef __SHADOW__
#define __SHADOW__

bool have_object_infront(Point point, Point direction, double max_distance, Sphere *spheres, int spheres_amount);

#endif