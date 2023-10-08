#include "light.h"
#include <stdio.h>
#include <math.h>
#include "../math/math.h"
#include "../shadow/shadow.h"
#include <float.h>

double get_intensity(Point light, double max_intensity_of_light, Point normal);

double get_intensity_for_specular(Point light, Point position, Point normal, double max_intensity_of_light, double specular);

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
    int spehres_amount)
{
    double result_intensity = ambient_intensity;
    for (int i = 0; i < direction_lights_amount; i++)
    {
        if (have_object_infront(position, negate(direction_lights[i].vector), DBL_MAX, spheres, spehres_amount))
        {
            continue;
        }
        result_intensity += get_intensity(direction_lights[i].vector, direction_lights[i].intensity, normal);
        if (specular != -1)
            result_intensity += get_intensity_for_specular(direction_lights[i].vector, position, normal, direction_lights[i].intensity, specular);
    }
    for (int i = 0; i < point_lights_amount; i++)
    {
        Point vector = subtract(point_lights[i].position, position);
        if (have_object_infront(position, negate(vector), vector_len(subtract(position, point_lights[i].position)), spheres, spehres_amount))
        {
            continue;
        }
        result_intensity += get_intensity(vector, point_lights[i].intensity, normal);
        if (specular != -1)
            result_intensity += get_intensity_for_specular(vector, position, normal, point_lights[i].intensity, specular);
    }
    Color result;
    result.red = begin_color.red * result_intensity;
    result.green = begin_color.green * result_intensity;
    result.blue = begin_color.blue * result_intensity;
    if (result.red > 255)
        result.red = 255;
    if (result.green > 255)
        result.green = 255;
    if (result.blue > 255)
        result.blue = 255;
    return result;
}

double get_intensity(Point light, double max_intensity_of_light, Point normal)
{
    double intensity = max_intensity_of_light * (scalar(light, normal) / (vector_len(light), vector_len(normal)));
    if (intensity < 0)
        return 0;
    return intensity;
}

double get_intensity_for_specular(Point light, Point position, Point normal, double max_intensity_of_light, double specular)
{
    Point vector_to_camera = negate(position);
    Point reflection_direction = subtract(vector_multiply(vector_multiply(normal, scalar(normal, light)), 2), light);
    double result = max_intensity_of_light * 
        pow((scalar(reflection_direction, vector_to_camera)/(vector_len(reflection_direction) * vector_len(vector_to_camera))), specular);
    if (result < 0)
        return 0;
    return result;
}