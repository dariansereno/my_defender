/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** vertex_damage
*/

#include "game.h"

void generation_vertex(st_vertex *vertex)
{
    vertex->a.x = 0;
    vertex->a.y = 0;
    vertex->b.x = 0;
    vertex->b.y = 0;
    vertex->c.x = 0;
    vertex->c.y = 0;
    vertex->d.x = 0;
    vertex->d.y = 0;
    vertex->ab = 0;
    vertex->bc = 0;
    vertex->cd = 0;
    vertex->da = 0;
    vertex->ap = 0;
    vertex->bp = 0;
    vertex->cp = 0;
    vertex->dp = 0;
}

bool is_intersection_character(st_vertex *vertex, sfVector2f p)
{
    vertex->ab = sqrt(pow(vertex->b.x - vertex->a.x, 2) \
    + pow(vertex->b.y - vertex->a.y, 2));
    vertex->bc = sqrt(pow(vertex->c.x - vertex->b.x, 2) \
    + pow(vertex->c.y - vertex->b.y, 2));
    vertex->cd = sqrt(pow(vertex->d.x - vertex->c.x, 2) \
    + pow(vertex->d.y - vertex->c.y, 2));
    vertex->da = sqrt(pow(vertex->a.x - vertex->d.x, 2) \
    + pow(vertex->a.y - vertex->d.y, 2));
    vertex->ap = sqrt(pow(p.x - vertex->a.x, 2) \
    + pow(p.y - vertex->a.y, 2));
    vertex->bp = sqrt(pow(p.x - vertex->b.x, 2) \
    + pow(p.y - vertex->b.y, 2));
    vertex->cp = sqrt(pow(p.x - vertex->c.x, 2) \
    + pow(p.y - vertex->c.y, 2));
    vertex->dp = sqrt(pow(p.x - vertex->d.x, 2) \
    + pow(p.y - vertex->d.y, 2));
    return (conditions_intersection_character(vertex));
}

bool conditions_intersection_character(st_vertex *vertex)
{
    double aire_l = vertex->ab * vertex->bc;
    double aire_t = 0;

    aire_t += aire_triangle(vertex->ab, vertex->ap, vertex->bp);
    aire_t += aire_triangle(vertex->bc, vertex->bp, vertex->cp);
    aire_t += aire_triangle(vertex->cd, vertex->cp, vertex->dp);
    aire_t += aire_triangle(vertex->da, vertex->dp, vertex->ap);
    if (round(aire_t) == 4719.0)
        return (true);
    else
        return false;
}

int conditions_1_bloc_around(list_3D node_3d, list_ground \
node_ground, list_char node_char, st_global *global)
{
    if ((node_3d->pos.x - 1 == node_ground->pos.x && node_3d->pos.y == \
    node_ground->pos.y) || (node_3d->pos.x - 1 == node_ground->pos.x && \
    node_3d->pos.y - 1 == node_ground->pos.y) || (node_3d->pos.x == \
    node_ground->pos.x && node_3d->pos.y - 1 == node_ground->pos.y) || \
    (node_3d->pos.x + 1 == node_ground->pos.x && node_3d->pos.y - 1 == \
    node_ground->pos.y) || (node_3d->pos.x + 1 == node_ground->pos.x && \
    node_3d->pos.y == node_ground->pos.y) || (node_3d->pos.x + 1 == \
    node_ground->pos.x && node_3d->pos.y + 1 == node_ground->pos.y) || \
    (node_3d->pos.x == node_ground->pos.x && node_3d->pos.y + 1 == \
    node_ground->pos.y) || (node_3d->pos.x - 1 == node_ground->pos.x && \
    node_3d->pos.y + 1 == node_ground->pos.y)) {
        hit_tower(node_3d, global, node_char);
        node_char->variable.hit = true;
        return (0);
    }
    else {
        not_hit_tower(node_3d, global);
        node_char->variable.hit = false;
        return (1);
    }
}

void is_attack_or_defense(st_global *global, list_3D node_3d, list_char \
node_char)
{
    list_tower *node_tower = global->tower_list;
    int index = 0;

    while (node_tower != NULL) {
        index = node_3d->pos.y * 7 + (node_3d->pos.x + 1);
        if (node_tower->variable.position == index)
            if (node_tower->variable.mode == 2)
                node_char->variable.mode = 1;
        node_tower = node_tower->next;
    }
}