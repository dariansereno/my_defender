/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** list_action_astar
*/

#include "game.h"

void pop_pos_astar(list_astar *list, sfVector2i pos)
{
    list_elem_astar *temp = *list;
    list_elem_astar *next = NULL;

    if (*list == NULL)
        return ;
    if (temp->node->pos.x == pos.x && temp->node->pos.y == pos.y) {
        *list = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->node->pos.x != pos.x && \
    temp->node->pos.y != pos.y)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return ;
    next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int size_list_astar(list_astar li)
{
    int i = 0;

    while (li != NULL) {
        i++;
        li = li->next;
    }
    return (i);
}

path_node *first_astar(list_astar li)
{
    path_node *node = malloc(sizeof(path_node *));

    node = li->node;
    return (node);
}

void pop_all_list_astar(list_astar li)
{
    while (li != NULL)
        li = pop_back_astar(li);
}

path_node *last_elem_astar(list_astar li)
{
    while (li->next != NULL)
        li = li->next;
    return (li->node);
}