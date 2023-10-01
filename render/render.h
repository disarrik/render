#include "../scene/scene.h"
#include "../scene/shapes.h"

#ifndef __RENDER__
#define __RENDER__

Point find_point_on_view_window(int pixelX, int pixelY, int maxX, int maxY, ViewWindow ViewWindow);

long find_distance_with_sphere(Point camera, Vector vector, Sphere sphere);

Point change_coordinates(Point p, Vector v);

long scalar(Vector a, Vector b);

#endif