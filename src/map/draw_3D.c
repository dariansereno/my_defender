/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** draw_3D
*/

#include "game.h"

int compute_index_printing(list_3D li, list_elem_char *character)
{
    int i = 0;
    list_3D size = malloc(sizeof(size));
    size = li;
    sfVector2f pos = sfSprite_getPosition(character->object->sprite);

    while (li != NULL && ((pos.y + 82 >= li->rlm[0].y && pos.x + 42 \
    <= li->rlm[2].x - 140) || (pos.y + 82 >= li->rlm[1].y && pos.x + \
    42 >= li->rlm[2].x - 140)) ) {
        i++;
        li = li->next;
    }
    return (i);
}

void create_all_printing_index(list_3D li_3D, list_char li_char)
{
    while (li_char != NULL) {
        li_char->variable.index = compute_index_printing(li_3D, li_char);
        li_char = li_char->next;
    }
}

void print_list_3D(list_3D li, sfRenderWindow *window, st_map *map, \
st_global *global)
{
    list_char li_c = malloc(sizeof(li));
    li_c = global->character_list;
    int index = 0;
    int size = size_list_3D(li);

    if (li == NULL) {
        while (li_c != NULL) {
            sfSprite_setScale(li_c->object->sprite, (sfVector2f){0.5, 0.5});
            sfSprite_setPosition(li_c->object->sprite, li_c->object->position);
            sfSprite_setTextureRect(li_c->object->sprite, \
            li_c->object->animation);
            sfRenderWindow_drawSprite(window, li_c->object->sprite, NULL);
            li_c = li_c->next;
        }
    }
    create_all_printing_index(li, li_c);
    while (li != NULL) {
        while (li_c != NULL) {
            if (index == li_c->variable.index) {
                    sfSprite_setScale(li_c->object->sprite, \
                    (sfVector2f){0.5, 0.5});
                    sfSprite_setPosition(li_c->object->sprite, \
                    li_c->object->position);
                    sfSprite_setTextureRect(li_c->object->sprite, \
                    li_c->object->animation);
                    sfRenderWindow_drawSprite(window, li_c->object->sprite, \
                    NULL);
            }
            li_c = li_c->next;
        }
        for (int i = 0; i < 3; i++) {
            sfRenderWindow_drawVertexArray(window, li->array[i],
            rendering(map->props\
            [find_index(map->props, li->c, map)].textures[i]));
        }
        li_c = global->character_list;
        index++;
        li = li->next;
    }
    while (li_c != NULL) {
        if (index == li_c->variable.index) {
                sfSprite_setScale(li_c->object->sprite, \
                (sfVector2f){0.5, 0.5});
                sfSprite_setPosition(li_c->object->sprite, \
                li_c->object->position);
                sfSprite_setTextureRect(li_c->object->sprite, \
                li_c->object->animation);
                sfRenderWindow_drawSprite(window, li_c->object->sprite, NULL);
        }
        li_c = li_c->next;
    }
}