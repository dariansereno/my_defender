/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** list_action_char
*/

#include "game.h"

list_char push_back_char(list_char li, st_object *object, \
st_char_variables variable)
{
    list_elem_char *elem;
    list_elem_char *temp;

    elem = malloc(sizeof(*elem));
    elem->variable = variable;
    elem->object = object;
    elem->next = NULL;
    if (li == NULL)
        return elem;
    temp = li;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = elem;
    return (li);
}

void pop_position_char(list_char list, int position)
{
    list_char temp = list;
    list_char next = NULL;

    if (list == NULL)
        return;
    if (position == 1) {
        list = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int size_list_char(list_char li)
{
    int i = 0;

    while (li != NULL) {
        i++;
        li = li->next;
    }
    return (i);
}

void print_char_list(list_char li, sfRenderWindow *window)
{
    while (li != NULL) {
        sfSprite_setScale(li->object->sprite, (sfVector2f){0.5, 0.5});
        sfSprite_setPosition(li->object->sprite, li->object->position);
        sfSprite_setTextureRect(li->object->sprite, li->object->animation);
        sfRenderWindow_drawSprite(window, li->object->sprite, NULL);
        li = li->next;
    }
}