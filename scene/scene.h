#ifndef __SCENE__
#define __SCENE__

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

typedef struct ColoredPoint
{
    Point point;
    Color color;
} ColoredPoint;

typedef struct ViewWindow 
{
    Point center;
    double height;
    double width;
} ViewWindow;

typedef struct PointLight
{
    Point position;
    double intensity;
} PointLight;

typedef struct DirectionLight
{
    Point vector;
    double intensity;
} DirectionLight;

#endif