/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** tower_functions
*/

#include "game.h"

void push_back_tower(list_tower **li, st_tower_variables variable)
{
    list_tower *node = malloc(sizeof(*node));
    list_tower *lastnode = *li;

    node->variable = variable;
    node->variable.level = variable.level;
    node->next = NULL;
    if (*li == NULL)
        *li = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}

void pop_position_tower(list_tower **list, int index)
{
    list_tower *temp = *list;
    list_tower *next = NULL;

    if (*list == NULL)
        return;
    if (index == 67) {
        *list = temp->next;
        free(temp);
        return;
    }
    for (; temp != NULL && temp->next->variable.position != index;)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int size_list_tower(st_global *global)
{
    list_tower *node = global->tower_list;
    int i = 0;

    for (; node != NULL; i++)
        node = node->next;
    return (i);
}

void print_tower_list(st_global *global)
{
    list_tower *node = global->tower_list;

    while (node != NULL)
        node = node->next;
}