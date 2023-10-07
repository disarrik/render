#include "math.h"
#include <math.h>

double scalar(Point a, Point b) 
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

double vector_len(Point vector)
{
    return sqrt(scalar(vector, vector));
}

Point subtract(Point a, Point b)
{
    Point p;
    p.x = a.x - b.x;
    p.y = a.y - b.y;
    p.z = a.z - b.z;
    return p;
}

Point vector_multiply(Point p, double c)
{
    Point result;
    result.x = p.x * c;
    result.y = p.y * c;
    result.z = p.z * c;
    return result;
}