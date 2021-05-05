/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** list_astar
*/

#include "game.h"

list_astar push_back_list_astar(list_astar li, path_node *node, \
path_node *parent)
{
    list_elem_astar *elem;
    list_n li_n = malloc(sizeof(*li_n));
    li_n = node->neighbours;
    elem = malloc(sizeof(*elem));

    elem->node = malloc(sizeof(*elem->node));
    elem->node->bObstacle = node->bObstacle;
    elem->node->bVisited = node->bVisited;
    elem->node->f_cost = node->f_cost;
    elem->node->g_cost = node->g_cost;
    elem->node->h_cost = node->h_cost;
    elem->node->neighbours = NULL;
    while (li_n != NULL) {
        elem->node->neighbours = push_back_list_n(elem->node->neighbours, \
        li_n->node, node);
        li_n = li_n->next;
    }
    elem->node->parent = malloc(sizeof(path_node *));
    elem->node->parent = parent;
    elem->node->pos = node->pos;
    elem->next = NULL;
    if (li == NULL)
        return (elem);

    list_elem_astar *temp;
    temp = li;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = elem;

    return (li);
}

list_astar push_front_list_astar(list_astar li, path_node *node, \
path_node *parent)
{
    list_elem_astar *elem;
    elem = malloc(sizeof(*elem));

    list_n li_n = malloc(sizeof(*li_n));
    li_n = node->neighbours;

    elem->node = malloc(sizeof(*elem->node));
    elem->node->bObstacle = node->bObstacle;
    elem->node->bVisited = node->bVisited;
    elem->node->f_cost = node->f_cost;
    elem->node->g_cost = node->g_cost;
    elem->node->h_cost = node->h_cost;
    elem->node->neighbours = NULL;
    while (li_n != NULL) {
        elem->node->neighbours = push_back_list_n(elem->node->neighbours, \
        li_n->node, node);
        li_n = li_n->next;
    }
    elem->node->parent = malloc(sizeof(path_node *));
    elem->node->parent = parent;
    elem->node->pos = node->pos;
    elem->next = NULL;

    if (li == NULL)
        elem->next = NULL;
    else
        elem->next = li;

    return (elem);
}

list_astar pop_back_astar(list_astar li)
{
    list_elem_astar *temp = NULL;
    list_elem_astar *buffer = NULL;

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

list_astar pop_front_astar(list_astar li)
{
    list_elem_astar *elem;

    if (li == NULL)
        return (li);
    elem = malloc(sizeof(*elem));
    elem = li->next;
    free(li);
    li = NULL;

    return (elem);
}

int is_in_list_astar(list_astar li, sfVector2i pos)
{
    list_elem_astar *searcher;

    if (li == NULL)
        return (0);
    searcher = malloc(sizeof(*searcher));
    searcher = li;
    while (searcher != NULL) {
        if (searcher->node->pos.x == pos.x && searcher->node->pos.y == pos.y)
            return (1);
        searcher = searcher->next;
    }
    return (0);
}