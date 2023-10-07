#include "../scene/scene.h"

#ifndef __MATH__
#define __MATH__

double scalar(Point a, Point b);

double vector_len(Point vector);

Point subtract(Point a, Point b);

Point vector_multiply(Point p, double c);

#endif