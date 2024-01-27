#pragma once

typedef struct {
    double e[2];
} Vec2;

Vec2    Vec2_New       (double x, double y);
void    Vec2_Print     (Vec2 v);
Vec2    Vec2_Add       (Vec2 v1, Vec2 v2);
Vec2    Vec2_Subtract  (Vec2 v1, Vec2 v2);
Vec2    Vec2_Scale     (Vec2 v, double scaleFactor);
double  Vec2_Dot       (Vec2 v1, Vec2 v2);