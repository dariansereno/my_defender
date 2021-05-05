/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** damage_handling
*/

#include "game.h"

void character_damage(st_global *global)
{
    list_char node_char = global->character_list;
    float seconds = 0;
    sfTime time;

    for (int i = 0; node_char != NULL; i++) {
        if (node_char->variable.hit == true && node_char->variable.mode >= 1) {
            time = sfClock_getElapsedTime(node_char->object->timer2->clock);
            seconds = time.microseconds / 1000;
            if (seconds > 500) {
                node_char->variable.life -= (5 * node_char->variable.mode);
                if (node_char->variable.life < 0)
                    node_char->variable.dead = 1;
                sfClock_restart(node_char->object->timer2->clock);
            }
        }
        node_char = node_char->next;
    }
}

void tower_damage(st_global *global)
{
    list_tower *node_tower = global->tower_list;
    float seconds = 0;
    sfTime time;

    for (int i = 0; node_tower != NULL; i++) {
        if (node_tower->variable.hit == true) {
            time = sfClock_getElapsedTime(node_tower->variable.timer->clock);
            seconds = time.microseconds / 1000;
            if (seconds > 300) {
                node_tower->variable.life -= 5;
                if (node_tower->variable.position == 67)
                    global->ui->heal -= 5;
                if (node_tower->variable.life < 0)
                    node_tower->variable.dead = 1;
                sfClock_restart(node_tower->variable.timer->clock);
            }
        }
        node_tower = node_tower->next;
    }
}

void character_hit_tower(list_ground node_ground, list_char node_char, \
st_vertex *vertex, st_global *global)
{
    sfVector2f pos;
    list_3D node_3d = global->map->li_3D;

    pos = sfSprite_getPosition(node_char->object->sprite);
    pos.y += 82.5;
    if (is_intersection_character(vertex, (sfVector2f){pos.x, pos.y})) {
        while (node_3d != NULL) {
            if (conditions_1_bloc_around(node_3d, node_ground, node_char, \
            global) == 0)
                break;
            node_3d = node_3d->next;
        }
    }
}

void damage_handling(st_global *global)
{
    list_ground node_ground = global->map->li_ground;
    list_char node_char = global->character_list;
    st_vertex *vertex = malloc(sizeof(*vertex));

    generation_vertex(vertex);
    while (node_char != NULL) {
        while (node_ground != NULL) {
            vertex_ground_by_vertex(node_ground, vertex);
            character_hit_tower(node_ground, node_char, vertex, global);
            node_ground = node_ground->next;
        }
        node_char = node_char->next;
    }
    character_damage(global);
    tower_damage(global);
}

void upgrade_defenses_texture_ground(st_global *global, list_ground \
node_ground, char letter)
{
    global->map->map[node_ground->pos.y][node_ground->pos.x] = letter;
    global->map->map_int[node_ground->pos.y * 2][node_ground->pos.x * 2] = \
    global->map->props[find_index(global->map->props, letter, \
    global->map)].height;
    global->map->map_int[node_ground->pos.y * 2 + 1][node_ground->pos.x * 2] =\
    global->map->props[find_index(global->map->props, letter, \
    global->map)].height;
    global->map->map_int[node_ground->pos.y * 2 + 1]\
    [node_ground->pos.x * 2 + 1] = global->map->props\
    [find_index(global->map->props, letter, \
    global->map)].height;
    global->map->map_int[node_ground->pos.y * 2][node_ground->pos.x * 2 + 1] =\
    global->map->props[find_index(global->map->props, letter, \
    global->map)].height;
}