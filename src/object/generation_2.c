/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** generation
*/

#include "game.h"

st_global *generate_global_2(st_global *global)
{
    global->win = generate_object("contents/img/win.png", \
    (sfVector2f){381, 226}, (sfIntRect){0, 0, 1159, 629});
    global->lose = generate_object("contents/img/lose.png", \
    (sfVector2f){381, 226}, (sfIntRect){0, 0, 1159, 629});
    global->map_background = generate_tiles("contents/img/map.jpg", \
    1920, 1080, (sfVector2i){0, 0});
    global->map->resize = 75;
    global->timer = malloc(sizeof(*global->timer));
    global->timer->clock = sfClock_create();
    global->timer->seconds = 0;
    global->time_passed = malloc(sizeof(*global->timer));
    global->time_passed->clock = sfClock_create();
    global->time_passed->seconds = 0;
    global->music = sfMusic_createFromFile("contents/audio/ambience.ogg");
    sfMusic_setLoop(global->music, sfTrue);
    sfMusic_play(global->music);
    generate_global_3(global);
    return (global);
}

st_global *generate_global_3(st_global *global)
{
    global->pause = generate_object("contents/img/pause/pause.png", \
    (sfVector2f){381, 226}, (sfIntRect){0, 0, 1159, 629});
    global->how_to_play = generate_object("contents/img/how_to_play.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    global->variable->win = 0;
    global->trees = generate_object("contents/img/pause/trees.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
}

void generate_object_2(st_object *object)
{
    object->timer2 = malloc(sizeof(*object->timer2));
    object->timer2->clock = sfClock_create();
    object->timer2->time = sfClock_getElapsedTime(object->timer->clock);
    object->timer2->seconds = 0;
    object->timer2->seconds = object->timer->time.microseconds / 1000;
}