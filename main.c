#include "render/render.h"
#include "draw/draw.h"
#include "scene/shapes.h"
#include <unistd.h>
#include <limits.h>

static Sphere sphere;

int main() 
{
    open_window();
    Point camera;
    camera.x = 0;
    camera.y = 0;
    camera.z = 0;
    ViewWindow viewWindow;
    Point viewWindowCenter;
    viewWindowCenter.x = 0;
    viewWindowCenter.y = 0;
    viewWindowCenter.z = 1;
    viewWindow.center = viewWindowCenter; 
    viewWindow.height = 1000;
    viewWindow.width = 1000;
    init_spheres();
    for (int i = -1 * (HEIGHT / 2); i < (HEIGHT / 2); i++)
    {
        for (int j = -1 * (WIDTH / 2); j < (WIDTH / 2); j++)
        {
            Color foundColor;
            foundColor.blue = 0;
            foundColor.green = 0;
            foundColor.red = 0;
            unsigned long  minDistance = ULONG_MAX;
            for (int s = 0; s < 1; s++)
            {
                Point point_on_window = find_point_on_view_window(i, j, WIDTH, HEIGHT, viewWindow);
                Vector vector_to_point_on_window;
                vector_to_point_on_window.a = camera;
                vector_to_point_on_window.b = point_on_window;
                long distance = find_distance_with_sphere(camera, vector_to_point_on_window, sphere);
                if (distance != -1 && distance < minDistance)
                {
                    foundColor = sphere.color;
                    minDistance = distance;
                }
            }
            draw_point(i, j, foundColor.red, foundColor.green, foundColor.blue);
        }
    }
    sleep(3);
    close_window();
    return 0;
}

void init_spheres()
{
    Sphere sphere0;
    Point center0;
    Color color0;
    center0.x = 0;
    center0.y = -1;
    center0.z = 3;
    color0.red = 255;
    color0.green = 0;
    color0.blue = 0;
    sphere0.color = color0;
    sphere0.center = center0;
    sphere = sphere0;
}
