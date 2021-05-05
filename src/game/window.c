/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** main
*/

#include "game.h"

sfRenderWindow *window_create(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    window = sfRenderWindow_create(mode, "my_defender", sfResize | sfClose, \
    NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    return (window);
}

int main(void)
{
    sfRenderWindow *window = window_create();
    st_global *global = generate_global();

    if (window != NULL)
        menuloop(window, global);
    sfMusic_destroy(global->music);
    sfRenderWindow_destroy(window);
}