/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** list_neighbours
*/

#include "game.h"

list_n push_back_list_n(list_n li, path_node *node, path_node *parent)
{
    list_elem_n *elem;
    list_elem_n *temp;
    list_n list = malloc(sizeof(list));
    elem = malloc(sizeof(*elem));

    elem->node = malloc(sizeof(*elem->node));
    elem->node->bObstacle = node->bObstacle;
    elem->node->bVisited = node->bVisited;
    elem->node->f_cost = node->f_cost;
    elem->node->pos = node->pos;
    elem->node->g_cost = heuristic_by_pos(elem->node->pos, parent->start);
    elem->node->h_cost = node->h_cost;
    elem->node->neighbours = NULL;
    elem->node->parent = malloc(sizeof(path_node *));
    elem->node->parent = parent;
    elem->next = NULL;
    if (li == NULL)
        return (elem);
    temp = li;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = elem;
    return (li);
}

void print_list_n(list_n li)
{
}

int size_list_n(list_n li)
{
    int i = 0;

    while (li != NULL) {
        i++;
        li = li->next;
    }
    return (i);
}

list_n pop_back_n(list_n li)
{
    list_elem_n *temp = NULL;
    list_elem_n *buffer = NULL;

    if (li == NULL)
        return (li);
    if (li->next == NULL) {
        free(li);
        li = NULL;
        return (NULL);
    }
    temp = li;
    buffer = li;
    while (temp->next != NULL) {
        buffer = temp;
        temp = temp->next;
    }
    buffer->next = NULL;
    free(temp);
    temp = NULL;
    return (li);
}

void pop_all_list_n(list_n li)
{
    while (li != NULL)
        li = pop_back_n(li);
}