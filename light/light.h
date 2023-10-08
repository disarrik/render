#include "../scene/scene.h"

#ifndef __LIGHT__
#define __LIGHT__

Color compute_color(
    Color begin_color, 
    Point normal, 
    Point position,
    double specular,
    double ambient_intensity, 
    PointLight *point_lights, 
    int point_lights_amount,
    DirectionLight *direction_lights,
    int direction_lights_amount,
    Sphere* spheres,
    int spehres_amount);

#endif