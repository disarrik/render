#include "../scene/scene.h"
#include "../scene/shapes.h"

#ifndef __RENDER__
#define __RENDER__

Point find_point_on_view_window(int pixelX, int pixelY, int maxX, int maxY, ViewWindow ViewWindow);

long find_distance_with_sphere(Point camera, Point vector, Sphere sphere);

long scalar(Point a, Point b);

#endif