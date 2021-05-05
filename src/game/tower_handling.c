/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** tower_handling
*/

#include "game.h"

int not_hit_tower(list_3D node_3d, st_global *global)
{
    list_tower *node_tower = global->tower_list;
    int index = node_3d->pos.y * 7 + (node_3d->pos.x + 1);

    while (node_tower != NULL) {
        if (index == node_tower->variable.position)
            node_tower->variable.hit = false;
        node_tower = node_tower->next;
    }
}

int hit_tower(list_3D node_3d, st_global *global, list_char node_char)
{
    list_tower *node_tower = global->tower_list;
    int index = node_3d->pos.y * 7 + (node_3d->pos.x + 1);

    is_attack_or_defense(global, node_3d, node_char);
    while (node_tower != NULL) {
        if (index == node_tower->variable.position)
            node_tower->variable.hit = true;
        node_tower = node_tower->next;
    }
}

void generate_bank(st_global *global)
{
    st_tower_variables variable = {.life = 1000, \
    .dead = 0, .position = 67, .price = 100, .level = 1};

    variable.timer = malloc(sizeof(*variable.timer));
    variable.timer->clock = sfClock_create();
    variable.timer->seconds = 0;
    push_back_tower(&global->tower_list, variable);
}

void upgrade_defenses(st_global *global, char current, int index, \
list_3D node_3d)
{
    char letter = '\0';
    int price = frame_price(global);
    st_tower_variables variable = {.c = letter, .dead = 0, .life = 100, \
    .position = index, .price = price, .level = 0, .hit = false, .mode = 0};

    if ((global->variable->frame_index == 13 || \
    global->variable->frame_index == 14) && current == 'a')
        letter = frame_letter(global);
    else if (global->variable->frame_index == 14 \
    && (current == 'a' || current == 'b'))
        letter = frame_letter(global);
    if (letter == 'b' || letter == 'c') {
        upgrade_defenses_texture(global, node_3d, letter);
        pop_position_tower(&global->tower_list, index);
        variable.c = letter;
        global->ui->money -= variable.price;
        push_back_tower(&global->tower_list, variable);
    }
}

void upgrade_defenses_texture(st_global *global, list_3D node_3d, char letter)
{
    global->map->map[node_3d->pos.y][node_3d->pos.x] = letter;
    global->map->map_int[node_3d->pos.y * 2][node_3d->pos.x * 2] = \
    global->map->props[find_index(global->map->props, letter, \
    global->map)].height;
    global->map->map_int[node_3d->pos.y * 2 + 1][node_3d->pos.x * 2] = \
    global->map->props[find_index(global->map->props, letter, \
    global->map)].height;
    global->map->map_int[node_3d->pos.y * 2 + 1][node_3d->pos.x * 2 + 1] = \
    global->map->props[find_index(global->map->props, letter, \
    global->map)].height;
    global->map->map_int[node_3d->pos.y * 2][node_3d->pos.x * 2 + 1] = \
    global->map->props[find_index(global->map->props, letter, \
    global->map)].height;
}