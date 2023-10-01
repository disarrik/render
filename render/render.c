#include "render.h"
#include <math.h>
#include <stdio.h>

Point find_point_on_view_window(int pixelX, int pixelY, int maxX, int maxY, ViewWindow viewWindow)
{
    // todo алгоритм не учитывает что экран может быть повернут
    // надо сделать его более универсальным
    Point point;
    point.x = (viewWindow.width / maxX) + pixelX;
    point.y = (viewWindow.height / maxY) + pixelY;
    point.z = viewWindow.center.z;
    return point;
}

long find_distance_with_sphere(Point camera, Point vector, Sphere sphere)
{
    // todo как-будто камера всегда в центре коодинат
    Point co;
    co = sphere.center;
    long a = scalar(vector, vector);
    long b = 2 * scalar(co, vector);
    long c = scalar(co, co) - (sphere.radius * sphere.radius);
    long discr = b*b - 4*a*c;
    printf("%d %d %d %d \n", a, b, c, discr);
    if (discr < 0) 
        return -1;
    else if (discr == 0) {
        long result = (-1 * b) / (2*a);
        if (result < 0) return -1; 
        return (-1 * b) / (2*a);
    }

    long t1 = (-1 * b + sqrt(discr)) / (2*a);
    long t2 = (-1 * b - sqrt(discr)) / (2*a);
    if (t1 < 0 && t2 < 0) return -1;
    if (t1 < 0) return t2;
    if (t2 < 0) return t1;
    if (t1 < t2) {
        return t1;
    }
    return t2;
}

long scalar(Point a, Point b)
{
    return a.x*b.x  + a.y*b.y + a.z*b.z;
}