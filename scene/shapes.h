#ifndef __SHAPES__
#define __SHAPES__

typedef struct Point 
{
    double x;
    double y;
    double z;
} Point;

typedef struct Color
{
    unsigned short red, green, blue;
} Color;

typedef struct Sphere
{
    Point center;
    double radius;
    Color color;
    double specular;
} Sphere;


#endif