/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** list_action_ground
*/

#include "game.h"

list_ground push_back_ground(list_ground li, sfVertexArray *vertex, char c, \
sfVector2i pos)
{
    list_elem_ground *elem;

    elem = malloc(sizeof(*elem));
    elem->array = sfVertexArray_create();
    elem->array = vertex;
    elem->pos = pos;
    elem->c = c;
    elem->next = NULL;
    if (li == NULL)
        return elem;
    list_elem_ground *temp;
    temp = li;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = elem;
    return (li);
}

int size_list_ground(list_ground li)
{
    int i = 0;

    while (li != NULL) {
        i++;
        li = li->next;
    }
    return (i);
}

sfBool is_in_ground_list(sfVertexArray *vertex, list_ground li)
{
    while (li != NULL) {
        if (vertex == li->array)
            return (sfTrue);
        li = li->next;
    }
    return (sfFalse);
}

void print_list_ground(list_ground li, sfRenderWindow *window, st_map *map)
{
    while (li != NULL) {
        sfRenderWindow_drawVertexArray(window, li->array, \
        rendering(map->props[find_index(map->props, li->c, map)].textures[0]));
        li = li->next;
    }
}

list_ground pop_back_ground(list_ground list)
{
    list_elem_ground *temp = NULL;
    list_elem_ground *buf = NULL;

    if (list == NULL)
        return (NULL);
    if (list->next == NULL) {
        free(list);
        list = NULL;
        return (NULL);
    }
    temp = list;
    buf = list;
    while (temp->next != NULL) {
        buf = temp;
        temp = temp->next;
    }
    buf->next = NULL;
    free(temp);
    temp = NULL;
    return (list);
}