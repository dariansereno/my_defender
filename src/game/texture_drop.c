/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** texture_drop
*/

#include "game.h"

void upgrade_bank(st_global *global)
{
    list_tower *node = global->tower_list;

    while (node != NULL) {
        if (node->variable.position == 67) {
            node->variable.level += 1;
            global->ui->money -= global->variable->price_upgrade;
            global->variable->price_upgrade += 100;
            return;
        }
        node = node->next;
    }
}

int frame_price(st_global *global)
{
    int price = 0;

    if (global->variable->frame_index == 12)
        price = 100;
    if (global->variable->frame_index == 13)
        price = 200;
    if (global->variable->frame_index == 14)
        price = 300;
    if (global->variable->frame_index == 15)
        price = 100;
    if (global->variable->frame_index == 16)
        price = 200;
    if (global->variable->frame_index == 17)
        price = 300;
    if (global->variable->frame_index < 12 || \
    global->variable->frame_index > 17)
        price = 0;
    return (price);
}

char frame_letter(st_global *global)
{
    char letter;

    if (global->variable->frame_index == 12)
        letter = 'a';
    if (global->variable->frame_index == 13)
        letter = 'b';
    if (global->variable->frame_index == 14)
        letter = 'c';
    if (global->variable->frame_index == 15)
        letter = 'd';
    if (global->variable->frame_index == 16)
        letter = 'e';
    if (global->variable->frame_index == 17)
        letter = 'f';
    if (global->variable->frame_index < 12 || \
    global->variable->frame_index > 17)
        letter = 'u';
    return (letter);
}

void texture_drop_fill(st_global *global, list_ground node_ground)
{
    char letter = frame_letter(global);
    int price = frame_price(global);
    int index = node_ground->pos.y * 7 + (node_ground->pos.x + 1);
    st_tower_variables variable = {.c = letter, .dead = 0, .life = 100, \
    .position = index, .price = price, .level = 0, .hit = false};

    variable.timer = malloc(sizeof(*variable.timer));
    variable.timer->clock = sfClock_create();
    variable.timer->seconds = 0;
    if (global->variable->frame_index >= 12 && global->variable->frame_index \
    <= 14)
        variable.mode = 1;
    else if (global->variable->frame_index >= 15 && \
    global->variable->frame_index <= 17)
        variable.mode = 2;
    if (global->ui->money > variable.price && letter != 'u') {
        upgrade_defenses_texture_ground(global, node_ground, letter);
        push_back_tower(&global->tower_list, variable);
        global->ui->money -= variable.price;
    }
}

void texture_drop_empty(st_global *global, list_3D node_3d)
{
    char letter = frame_letter(global);
    int index = node_3d->pos.y * 7 + (node_3d->pos.x + 1);

    if ((letter == 'b' || letter == 'c') && node_3d->c != '0')
        upgrade_defenses(global, node_3d->c, index, node_3d);
    if (letter == '0' && node_3d->c != '0') {
        upgrade_defenses_texture(global, node_3d, letter);
        pop_position_tower(&global->tower_list, index);
    }
    if (letter == 'u' && node_3d->c == 'j' && global->ui->money > \
    global->variable->price_upgrade)
        upgrade_bank(global);
}