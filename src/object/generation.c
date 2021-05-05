/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** generation
*/

#include "game.h"
#include <stdio.h>

st_object *generate_tiles(char *path, int x, int y, sfVector2i shift)
{
    st_object *object = malloc(sizeof(*object));

    object->texture = sfTexture_createFromFile(path, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object->animation = (sfIntRect){shift.x, shift.y, x, y};
    sfSprite_setTextureRect(object->sprite, object->animation);
    object->position = (sfVector2f){0, 0};
    object->hitbox = sfSprite_getGlobalBounds(object->sprite);
    return (object);
}

st_object *generate_object(char *path, sfVector2f pos, sfIntRect animation)
{
    st_object *object = malloc(sizeof(*object));

    object->texture = sfTexture_createFromFile(path, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object->animation = animation;
    sfSprite_setTextureRect(object->sprite, object->animation);
    object->position = pos;
    sfSprite_setPosition(object->sprite, object->position);
    object->hitbox = sfSprite_getGlobalBounds(object->sprite);
    object->timer = malloc(sizeof(*object->timer));
    object->timer->clock = sfClock_create();
    object->timer->time = sfClock_getElapsedTime(object->timer->clock);
    object->timer->seconds = 0;
    object->timer->seconds = object->timer->time.microseconds / 1000;
    generate_object_2(object);
    return (object);
}

st_menu *generate_menu(char *path, sfVector2f pos, sfIntRect rect)
{
    st_menu *menu = malloc(sizeof(*menu));

    menu->sprite = sfSprite_create();
    menu->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    menu->animation = rect;
    sfSprite_setTextureRect(menu->sprite, menu->animation);
    menu->position = pos;
    sfSprite_setPosition(menu->sprite, menu->position);
    return (menu);
}

st_character *generate_character(char *path, int x, int y, sfVector2i shift)
{
    st_character *object = malloc(sizeof(*object));

    object->texture = sfTexture_createFromFile(path, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object->animation = (sfIntRect){shift.x, shift.y, x, y};
    sfSprite_setTextureRect(object->sprite, object->animation);
    object->position = (sfVector2f){0, 0};
    object->hitbox = sfSprite_getGlobalBounds(object->sprite);
    return (object);
}

st_global *generate_global(void)
{
    st_global *global = malloc(sizeof(*global));

    global->character_list = NULL;
    global->tower_list = NULL;
    global->map = read_file("map2.txt");
    global->variable = malloc(sizeof(*global->variable));
    global->variable->menu = 0;
    global->variable->interface = 0;
    global->variable->frame_index = 0;
    global->variable->price_upgrade = 300;
    global->variable->money_time = 0;
    global->drag = malloc(sizeof(*global->drag));
    global->drag->mousePos = (sfVector2f){0, 0};
    global->drag->moving = false;
    global->menu = malloc(sizeof(*global->menu));
    global->menu = generate_menu_tab();
    global->ui = malloc(sizeof(*global->ui));
    global->ui = generate_interface(global);
    generate_global_2(global);
    return (global);
}