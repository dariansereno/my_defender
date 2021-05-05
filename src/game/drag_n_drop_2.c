/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** drag_n_drop
*/

#include "game.h"

void vertex_ground(st_global *global, list_ground node_ground)
{
    global->drag->a = \
    sfVertexArray_getVertex(node_ground->array, 0)->position;
    global->drag->b = \
    sfVertexArray_getVertex(node_ground->array, 1)->position;
    global->drag->c = \
    sfVertexArray_getVertex(node_ground->array, 2)->position;
    global->drag->d = \
    sfVertexArray_getVertex(node_ground->array, 3)->position;
}

void vertex_3_d(st_global *global, list_3D node_3d)
{
    global->drag->a = \
    sfVertexArray_getVertex(node_3d->array[3], 0)->position;
    global->drag->b = \
    sfVertexArray_getVertex(node_3d->array[3], 1)->position;
    global->drag->c = \
    sfVertexArray_getVertex(node_3d->array[3], 2)->position;
    global->drag->d = \
    sfVertexArray_getVertex(node_3d->array[3], 3)->position;
}

bool empty_tiles(list_ground node_ground, st_global *global)
{
    sfVector2f pos;
    list_char node_char = global->character_list;
    st_vertex *vertex = malloc(sizeof(*vertex));

    generation_vertex(vertex);
    vertex_ground_by_vertex(node_ground, vertex);
    while (node_char != NULL) {
        pos = sfSprite_getPosition(node_char->object->sprite);
        pos.y += 82.5;
        if (is_intersection_character(vertex, (sfVector2f){pos.x, pos.y}))
            return (true);
        node_char = node_char->next;
    }
    return (false);
}