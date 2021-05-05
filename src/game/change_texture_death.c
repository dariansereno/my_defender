/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** change_texture_death
*/

#include "game.h"

void change_texture_death(st_global *global)
{
    list_tower *node_tower = global->tower_list;
    list_char node_char = global->character_list;
    int i = 1;

    while (node_tower != NULL) {
        if (node_tower->variable.dead == 1) {
            remove_texture(global, node_tower->variable.position);
            pop_position_tower(&global->tower_list, \
            node_tower->variable.position);
            break;
        }
        node_tower = node_tower->next;
    }
    while (node_char != NULL) {
        if (node_char->variable.dead == 1) {
            pop_position_char(global->character_list, i);
            break;
        }
        i++;
        node_char = node_char->next;
    }
}

void remove_texture(st_global *global, int index)
{
    list_3D node_3d = global->map->li_3D;

    while (node_3d != NULL) {
        if (index == (node_3d->pos.y * 7 + (node_3d->pos.x + 1))) {
            global->map->map[node_3d->pos.y][node_3d->pos.x] = '0';
            global->map->map_int[node_3d->pos.y * 2][node_3d->pos.x * 2] = \
            global->map->props\
            [find_index(global->map->props, '0', global->map)].height;
            global->map->map_int[node_3d->pos.y * 2 + 1][node_3d->pos.x * 2] =\
            global->map->props\
            [find_index(global->map->props, '0', global->map)].height;
            global->map->map_int[node_3d->pos.y * 2 + 1]\
            [node_3d->pos.x * 2 + 1] = global->map->props\
            [find_index(global->map->props, '0', global->map)].height;
            global->map->map_int[node_3d->pos.y * 2][node_3d->pos.x * 2 + 1] =\
            global->map->props\
            [find_index(global->map->props, '0', global->map)].height;
        }
        node_3d = node_3d->next;
    }
}

void vertex_ground_by_vertex(list_ground node_ground, st_vertex *vertex)
{
    vertex->a = \
    sfVertexArray_getVertex(node_ground->array, 0)->position;
    vertex->b = \
    sfVertexArray_getVertex(node_ground->array, 1)->position;
    vertex->c = \
    sfVertexArray_getVertex(node_ground->array, 2)->position;
    vertex->d = \
    sfVertexArray_getVertex(node_ground->array, 3)->position;
}