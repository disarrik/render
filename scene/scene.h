#include "shapes.h"

#ifndef __SCENE__
#define __SCENE__

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

static double ambient_light_intensity = 0.5;
static DirectionLight* direction_lights;
static int direction_lights_amount;
static PointLight* point_lights;
static int point_lights_amount;
static Point camera;
static ViewWindow view_window;
static Sphere* spheres;
static int spheres_amount;

#endif