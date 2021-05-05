/*
** EPITECH PROJECT, 2021
** gameloop
** File description:
** my_defender
*/

#include "game.h"

void redirect_menu(st_global *global, sfRenderWindow *window)
{
    if (global->variable->menu == 0)
        return;
    else if (global->variable->menu == 1)
        game_normal(global, window);
    else if (global->variable->menu == 2)
        how_to_play(global, window);
    else
        exit(0);
}

st_menu **generate_menu_tab(void)
{
    st_menu **tab = malloc(sizeof(st_menu *) * 2);

    tab[0] = generate_menu("contents/img/background.png", (sfVector2f){0, 0}, \
    (sfIntRect){0, 0, 1920, 1080});
    tab[1] = generate_menu("contents/img/buttons.png", (sfVector2f){500, 470}, \
    (sfIntRect){0, 0, 527, 422});
    return (tab);
}

void display_menu(st_global *global, sfRenderWindow *window)
{
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawSprite(window, global->menu[i]->sprite, NULL);
}

void menuloop(sfRenderWindow *window, st_global *global)
{
    sfEvent event;
    global->character_list = generate_random_char_between(1, 10);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        while (sfRenderWindow_pollEvent(window, &event))
            events_menu(event, window, global);
        redirect_menu(global, window);
        display_menu(global, window);
        sfRenderWindow_display(window);
    }
}