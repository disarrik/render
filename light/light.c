#include "light.h"
#include <stdio.h>
#include "../math/math.h"

double get_intensity(Point light, double max_intensity_of_light, Point normal);

Color compute_color(
    Color begin_color, 
    Point normal, 
    Point position,
    double ambient_intensity, 
    PointLight *point_lights, 
    int point_lights_amount,
    DirectionLight *direction_lights,
    int direction_lights_amount)
{
    double result_intensity = ambient_intensity;
    for (int i = 0; i < direction_lights_amount; i++)
    {
        result_intensity += get_intensity(direction_lights[i].vector, direction_lights[i].intensity, normal);
    }
    for (int i = 0; i < point_lights_amount; i++)
    {
        Point vector = subtract(point_lights[i].position, position);
        result_intensity += get_intensity(vector, point_lights[i].intensity, normal);
    }
    Color result;
    result.red = begin_color.red * result_intensity;
    result.green = begin_color.green * result_intensity;
    result.blue = begin_color.blue * result_intensity;
    return result;
}

double get_intensity(Point light, double max_intensity_of_light, Point normal)
{
    double intensity = scalar(light, normal) / (vector_len(light), vector_len(normal));
    if (intensity < 0)
        return 0;
    return intensity;
}