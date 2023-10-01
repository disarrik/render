#include "render.h"
#include <math.h>
#include <stdio.h>

Point negate(Point p)
{
    Point newP;
    newP.x = -1 * p.x;
    newP.y = -1 * p.y;
    newP.z = -1 * p.z;
    return newP;
}

Point find_point_on_view_window(int pixelX, int pixelY, int maxX, int maxY, ViewWindow viewWindow)
{
    Point point;
    point.x = (viewWindow.width / maxX) * pixelX;
    point.y = (viewWindow.height / maxY) * pixelY;
    point.z = viewWindow.center.z;
    return point;
}

double find_distance_with_sphere(Point vector, Sphere sphere)
{
    Point co;
    co = negate(sphere.center);
    double a = scalar(vector, vector);
    double b = 2 * scalar(co, vector);
    double c = scalar(co, co) - (sphere.radius * sphere.radius);
    double discr = b*b - 4*a*c;
    printf("%d %d %d %d \n", a, b, c, discr);
    if (discr < 0) 
        return -1;
    else if (discr == 0) {
        double result = (-1 * b) / (2*a);
        if (result < 0) return -1; 
        return (-1 * b) / (2*a);
    }

    double t1 = (-1 * b + sqrt(discr)) / (2*a);
    double t2 = (-1 * b - sqrt(discr)) / (2*a);
    if (t1 < 0 && t2 < 0) return -1;
    if (t1 < 0) return t2;
    if (t2 < 0) return t1;
    if (t1 < t2) {
        return t1;
    }
    return t2;
}
// break render/render.c:31 if (vector.x < 0 && vector.x > -0.1 && vector.y < 0 && vector.y > -0.1)

double scalar(Point a, Point b) 
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}
