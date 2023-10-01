#include "render.h"
#include <math.h>

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

long find_distance_with_sphere(Point camera, Vector vector, Sphere sphere)
{
    // вектор от камеры до центра сферы
    Vector co;
    co.a = camera.position;
    co.b = sphere.center;
    long a = scalar(vector, vector);
    long b = 2 * scalar(co, vector);
    long c = scalar(co, co) - (sphere.radius * sphere.radius);

    long discr = sqrt(b*b - 4*a*c) / (2*a);
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

Point change_coordinates(Point p, Vector v)
{
    Point newP;
    newP.x = p.x + (v.b.x - v.a.x);
    newP.y = p.y + (v.b.y - v.a.y);
    newP.z = p.z + (v.b.z - v.a.z);
    return newP;
}

long scalar(Vector a, Vector b)
{
    Point a_normalized = change_coordinates(a.b, a);
    Point b_normalized = change_coordinates(b.b, b);
    return a_normalized.x*b_normalized.x  + a_normalized.y*b_normalized.y + a_normalized.z*b_normalized.z;
}