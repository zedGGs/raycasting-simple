#include <stdio.h>
#include "Vec2.h"

Vec2 Vec2_New(double x, double y) {
    Vec2 v;
        v.e[0] = x;
        v.e[1] = y;
    return v;
}

void Vec2_Print(Vec2 v) {
    printf("[%.3lf, %.3lf\n]", v.e[0], v.e[1]);
}

Vec2 Vec2_Add(Vec2 v1, Vec2 v2) {
    Vec2 result;
        result.e[0] = v1.e[0] + v2.e[0];
        result.e[1] = v1.e[1] + v2.e[1];
    return result;
}

Vec2 Vec2_Subtract(Vec2 v1, Vec2 v2) {
    Vec2 result;
         result.e[0] = v1.e[0] - v2.e[0];
         result.e[1] = v1.e[1] - v2.e[1];
    return result;
}

Vec2 Vec2_Scale(Vec2 v, double scaleFactor) {
    Vec2 result;
        result.e[0] = scaleFactor*v.e[0];
        result.e[1] = scaleFactor*v.e[1];
    return result;
}

double Vec2_Dot(Vec2 v1, Vec2 v2) {
    return v1.e[0]*v2.e[0] + v1.e[1]*v2.e[1];
}