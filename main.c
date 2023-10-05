#include "render/render.h"
#include "draw/draw.h"
#include "scene/shapes.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>

Sphere* spheres;
static Point camera;
static ViewWindow viewWindow;

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
            double minDistance = DBL_MAX;
            for (int s = 0; s < 1; s++)
            {
                Sphere sphere = spheres[s]; // тут правильная копия
                printf("%d", spheres[s].radius);
                Point vector_to_point_on_window = find_point_on_view_window(i, j, WIDTH, HEIGHT, viewWindow);
                double distance = find_distance_with_sphere(vector_to_point_on_window, spheres);
                printf("%d \n", distance);
                if (distance != -1 && distance < minDistance)
                {
                    foundColor = spheres->color; 
                    minDistance = distance;
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
    Sphere* sphere0 = malloc(sizeof(Sphere)); // 0x55555555b300
    Point* center0 = malloc(sizeof(Point)); // 0x55555555ba10
    Color* color0 = malloc(sizeof(Color)); // 0x55555555b940
    center0->x = 0;
    center0->y = 0;
    center0->z = 3;
    color0->red = 255;
    color0->green = 0;
    color0->blue = 0;
    sphere0->color = *color0;
    sphere0->center = *center0;
    sphere0->radius = 1;
    spheres = sphere0;
    camera.x = 0;
    camera.y = 0;
    camera.z = 0;
    Point viewWindowCenter;
    viewWindowCenter.x = 0;
    viewWindowCenter.y = 0;
    viewWindowCenter.z = 1;
    viewWindow.center = viewWindowCenter; 
    viewWindow.height = 4;
    viewWindow.width = 4;
}

int map_x(long x)
{
    return WIDTH / 2 + x;
}

int map_y(long y)
{
    return HEIGHT / 2 - y;
}

