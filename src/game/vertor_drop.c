/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** vector_drop
*/

#include "game.h"

double aire_triangle(double a, double b, double c)
{
    double p = a + b + c;
    double s = 0;

    p /= 2;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    return (s);
}

bool is_intersection(st_global *global, sfVector2f p)
{
    global->drag->ab = sqrt(pow(global->drag->b.x - global->drag->a.x, 2) \
    + pow(global->drag->b.y - global->drag->a.y, 2));
    global->drag->bc = sqrt(pow(global->drag->c.x - global->drag->b.x, 2) \
    + pow(global->drag->c.y - global->drag->b.y, 2));
    global->drag->cd = sqrt(pow(global->drag->d.x - global->drag->c.x, 2) \
    + pow(global->drag->d.y - global->drag->c.y, 2));
    global->drag->da = sqrt(pow(global->drag->a.x - global->drag->d.x, 2) \
    + pow(global->drag->a.y - global->drag->d.y, 2));
    global->drag->ap = sqrt(pow(p.x - global->drag->a.x, 2) \
    + pow(p.y - global->drag->a.y, 2));
    global->drag->bp = sqrt(pow(p.x - global->drag->b.x, 2) \
    + pow(p.y - global->drag->b.y, 2));
    global->drag->cp = sqrt(pow(p.x - global->drag->c.x, 2) \
    + pow(p.y - global->drag->c.y, 2));
    global->drag->dp = sqrt(pow(p.x - global->drag->d.x, 2) \
    + pow(p.y - global->drag->d.y, 2));
    return (conditions_intersection(global));
}

bool conditions_intersection(st_global *global)
{
    double aire_l = global->drag->ab * global->drag->bc;
    double aire_t = 0;

    aire_t += aire_triangle(global->drag->ab, global->drag->ap, \
    global->drag->bp);
    aire_t += aire_triangle(global->drag->bc, global->drag->bp, \
    global->drag->cp);
    aire_t += aire_triangle(global->drag->cd, global->drag->cp, \
    global->drag->dp);
    aire_t += aire_triangle(global->drag->da, global->drag->dp, \
    global->drag->ap);
    if (round(aire_t) == 4719.0)
        return (true);
    else
        return false;
}