/*
** EPITECH PROJECT, 2020
** push_swap
** File description:
** list_action
*/

#include "game.h"

list_3D assign_value_push_3D(list_3D elem, d3_handling var,
sfVertexArray **vertex)
{
    for (int i = 0; i < 4; i++)
        elem->array = sfVertexArray_create();
    for (int i = 0; i < 4; i++)
        elem->array[i] = vertex[i];
    elem->rlm = malloc(sizeof(sfVector2f) * 3);
    for (int i = 0; i < 3; i++)
        elem->rlm[i] = var.rlm[i];
    elem->pos = var.pos;
    elem->c = var.c;
    elem->next = NULL;
    return (elem);
}

list_3D push_back_3D(list_3D li, sfVertexArray **vertex, d3_handling var)
{
    list_elem_3D *elem;
    list_elem_3D *temp;

    elem = malloc(sizeof(*elem));
    elem = assign_value_push_3D(elem, var, vertex);
    if (li == NULL)
        return elem;
    temp = li;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = elem;
    return (li);
}

int size_list_3D(list_3D li)
{
    int i = 0;

    while (li != NULL) {
        i++;
        li = li->next;
    }
    return (i);
}

void pop_back_3D(list_3D *list)
{
    list_3D temp = NULL;
    list_3D buf = NULL;

    if (*list == NULL)
        return;
    if ((*list)->next == NULL) {
        for (int i = 0; i < 3; i++)
            sfVertexArray_destroy((*list)->array[i]);
        free(list);
        *list = NULL;
        return;
    }
    temp = *list;
    buf = *list;
    while (temp->next != NULL) {
        buf = temp;
        temp = temp->next;
    }
    buf->next = NULL;
    free(temp);
    temp = NULL;
}