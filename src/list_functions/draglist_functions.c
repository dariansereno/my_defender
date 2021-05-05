/*
** EPITECH PROJECT, 2021
** node drag fonctions
** File description:
** draglist_functions
*/

#include "game.h"

void drag_pushback(draglist_t **list, int value)
{
    draglist_t *node = malloc(sizeof(*node));
    draglist_t *lastnode = *list;

    node->value = value;
    node->next = NULL;
    if (*list == NULL)
        *list = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}

void drag_print(draglist_t *node)
{
    write(1, "->", 2);
    while (node != NULL) {
        my_put_nbr(node->value);
        write(1, " ", 1);
        node = node->next;
    }
    write(1, "\n", 1);
}

int drag_exists(draglist_t *list, int value)
{
    draglist_t *node = list;
    int result = 0;

    while (node != NULL) {
        if (node->value == value) {
            result = 1;
            break;
        }
    }
    return (result);
}