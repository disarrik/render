#include "shadow.h"
#include <stdio.h>
#include "../scene/scene.h"
#include "../render/render.h"

bool have_object_infront(Point point, Point direction, double light_distance, Sphere *spheres, int spheres_amount)
{
    for (int i = 0; i < spheres_amount; i++)
    {
        double distance = find_distance_with_sphere(point, direction, spheres+i);
        if (distance > 0 && distance < light_distance)
        {
            return true;
        }
    }
    return false;
}