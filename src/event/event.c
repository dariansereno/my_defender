/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** event
*/

#include "game.h"

void events_close(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
}

void menu_button_event(sfEvent event, sfRenderWindow *window, \
st_global *global)
{
    if (event.type == sfEvtKeyPressed && event.key.code == \
    sfKeyEnter && global->menu[1]->animation.left == 0)
        global->variable->menu = 1;
    else if (event.type == sfEvtKeyPressed && event.key.code == \
    sfKeyEnter && global->menu[1]->animation.left == 527)
        global->variable->menu = 2;
    else if (event.type == sfEvtKeyPressed && event.key.code == \
    sfKeyEnter && global->menu[1]->animation.left == 1054)
        global->variable->menu = 3;
}

void events_menu(sfEvent event, sfRenderWindow *window, st_global *global)
{
    events_close(event, window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
        if (global->menu[1]->animation.left < 1054)
        global->menu[1]->animation.left += 527;
        sfSprite_setTextureRect(global->menu[1]->sprite, \
        global->menu[1]->animation);
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
        if (global->menu[1]->animation.left > 0)
            global->menu[1]->animation.left -= 527;
        sfSprite_setTextureRect(global->menu[1]->sprite, \
        global->menu[1]->animation);
    }
    menu_button_event(event, window, global);
}

void events_game_normal(sfEvent event, sfRenderWindow *window, \
st_global *global)
{
    events_close(event, window);
    event_pause(event, window, global);
    drag(window, event, global);
}

void change_list_facing(int change, list_char listo)
{
    list_char li = malloc(sizeof(li));
    li = listo;

    while (li != NULL) {
        li->variable.facing += change;
        if (li ->variable.facing > 7)
            li->variable.facing = 0;
        if (li->variable.facing < 0)
            li->variable.facing = 7;
        li = li->next;
    }
}