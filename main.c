#include "render/render.h"
#include "draw/draw.h"
#include "scene/shapes.h"
#include "math/math.h"
#include "light/light.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>

static double ambient_light_intensity = 0.5;
static DirectionLight* direction_lights;
static int direction_lights_amount;
static PointLight* point_lights;
static int point_lights_amount;
static Sphere* spheres;
static int spheres_amount;
static Point camera;
static ViewWindow view_window;

void init_scene();

int map_x(long x);

int map_y(long y);

Color count_light(Point position, Point normal, Color color);

int main() 
{
    open_window();
    init_scene();
    for (int j = -1 * (HEIGHT / 2); j < (HEIGHT / 2); j++)
    {
        for (int i = -1 * (WIDTH / 2); i < (WIDTH / 2); i++)
        {
            Color foundColor;
            foundColor.blue = 0;
            foundColor.green = 0;
            foundColor.red = 0;
            double min_distance = DBL_MAX;
            Sphere* found_sphere = NULL;
            Point vector_to_point_on_window = find_point_on_view_window(i, j, WIDTH, HEIGHT, view_window);
            for (int s = 0; s < spheres_amount; s++)
            {
                Sphere sphere = spheres[s];
                double distance = find_distance_with_sphere(vector_to_point_on_window, spheres+s);
                if (distance != -1 && distance < min_distance)
                {
                    foundColor = (spheres+s)->color; 
                    min_distance = distance;
                    found_sphere = spheres + s;
                }
            }
            if (found_sphere != NULL)
            {
                Point position = vector_multiply(vector_to_point_on_window, min_distance);
                Point normal = subtract(position, found_sphere->center);
                foundColor = count_light(position, normal, foundColor);
            }
            draw_point(map_x(i), map_y(j), foundColor.red, foundColor.green, foundColor.blue);
        }
    }
    sleep(1000);
    close_window();
    return 0;
}

Color count_light(Point position, Point normal, Color color)
{
    return compute_color(color, normal, position, ambient_light_intensity,
        point_lights, point_lights_amount, direction_lights, direction_lights_amount);
}

void init_scene()
{
    Sphere* ss = calloc(3, sizeof(Sphere)); 
    spheres_amount = 3;
    Sphere* sphere0 = malloc(sizeof(Sphere));
    Point center0;
    Color color0;
    center0.x = 1;
    center0.y = -1;
    center0.z = 3;
    color0.red = 60;
    color0.green = 0;
    color0.blue = 0;
    sphere0->color = color0;
    sphere0->center = center0;
    sphere0->radius = 1;
    sphere0->specular = -1;
    ss[0] = *sphere0;

    sphere0 = malloc(sizeof(Sphere));
    center0.x = 0;
    center0.y = 1;
    center0.z = 10;
    color0.red = 0;
    color0.green = 50;
    color0.blue = 0;
    sphere0->color = color0;
    sphere0->center = center0;
    sphere0->radius = 4;
    sphere0->specular = -1;
    ss[1] = *sphere0;

    sphere0 = malloc(sizeof(Sphere));
    center0.x = 0;
    center0.y = -1000000 - 1;
    center0.z = 10;
    color0.red = 0;
    color0.green = 0;
    color0.blue = 50;
    sphere0->color = color0;
    sphere0->center = center0;
    sphere0->radius = 1000000;
    sphere0->specular = 100;
    ss[2] = *sphere0;

    spheres = ss;

    camera.x = 0;
    camera.y = 0;
    camera.z = 0;
    Point view_window_center;
    view_window_center.x = 0;
    view_window_center.y = 0;
    view_window_center.z = 1;
    view_window.center = view_window_center; 
    view_window.height = 4;
    view_window.width = 4;

    direction_lights = calloc(1, sizeof(DirectionLight));
    DirectionLight direction_light0;
    direction_light0.intensity = 2;
    direction_light0.vector.x = 1;
    direction_light0.vector.y = 0;
    direction_light0.vector.z = 0.5;
    direction_lights[0] = direction_light0;
    direction_lights_amount = 1;

    point_lights = calloc(1, sizeof(PointLight));
    PointLight point_light0;
    point_light0.intensity = 3;
    point_light0.position.x = 0;
    point_light0.position.y = 3;
    point_light0.position.z = 2;
    point_lights[0] = point_light0;
    point_lights_amount = 1;

}

int map_x(long x)
{
    return WIDTH / 2 + x;
}

int map_y(long y)
{
    return HEIGHT / 2 - y;
}

