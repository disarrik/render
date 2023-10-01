#ifndef __SCENE__
#define __SCENE__

typedef struct Point 
{
    long x;
    long y;
    long z;
} Point;

typedef struct Color
{
    unsigned short red, green, blue;
} Color;

typedef struct ColoredPoint
{
    Point point;
    Color color;
} ColoredPoint;

typedef struct Vector 
{
    Point a;
    Point b;    
} Vector;

typedef struct ViewWindow 
{
    Point center;
    unsigned long height;
    unsigned long width;
} ViewWindow;

#endif