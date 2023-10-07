#include "render/render.h"
#include "draw/draw.h"
#include "scene/shapes.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>

static Sphere* spheres;
static int spheres_amount;
static Point camera;
static ViewWindow view_window;

void init_scene();

int map_x(long x);

int map_y(long y);

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
            for (int s = 0; s < spheres_amount; s++)
            {
                Sphere sphere = spheres[s];
                Point vector_to_point_on_window = find_point_on_view_window(i, j, WIDTH, HEIGHT, view_window);
                double distance = find_distance_with_sphere(vector_to_point_on_window, spheres+s);
                if (distance != -1 && distance < min_distance)
                {
                    foundColor = (spheres+s)->color; 
                    min_distance = distance;
                }
            }
            draw_point(map_x(i), map_y(j), foundColor.red, foundColor.green, foundColor.blue);
        }
    }
    sleep(10);
    close_window();
    return 0;
}

void init_scene()
{
    Sphere* ss = calloc(2, sizeof(Sphere)); 
    spheres_amount = 2;
    Sphere* sphere0 = malloc(sizeof(Sphere));
    Point center0;
    Color color0;
    center0.x = 0;
    center0.y = 0;
    center0.z = 3;
    color0.red = 255;
    color0.green = 0;
    color0.blue = 0;
    sphere0->color = color0;
    sphere0->center = center0;
    sphere0->radius = 1;
    ss[0] = *sphere0;

    sphere0 = malloc(sizeof(Sphere));
    center0.x = 0;
    center0.y = 1;
    center0.z = 10;
    color0.red = 0;
    color0.green = 255;
    color0.blue = 0;
    sphere0->color = color0;
    sphere0->center = center0;
    sphere0->radius = 4;
    ss[1] = *sphere0;

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
}

int map_x(long x)
{
    return WIDTH / 2 + x;
}

int map_y(long y)
{
    return HEIGHT / 2 - y;
}

