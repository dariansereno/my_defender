/*
** EPITECH PROJECT, 2021
** drag&drop
** File description:
** my_defender
*/

#include "game.h"

st_drag *generate_drag_n_drop(st_global *global)
{
    global->drag->mousePos = (sfVector2f){0, 0};
    global->drag->mouseReleased = (sfVector2f){0, 0};
    global->drag->origin_pos = (sfVector2f){0, 0};
    global->drag->moving = false;
    global->drag->a = (sfVector2f){0, 0};
    global->drag->b = (sfVector2f){0, 0};
    global->drag->c = (sfVector2f){0, 0};
    global->drag->d = (sfVector2f){0, 0};
    global->drag->p = (sfVector2f){0, 0};
    global->drag->ab = 0;
    global->drag->bc = 0;
    global->drag->cd = 0;
    global->drag->da = 0;
    global->drag->ap = 0;
    global->drag->bp = 0;
    global->drag->cp = 0;
    global->drag->dp = 0;
}

void drag(sfRenderWindow *window, sfEvent event, st_global *global)
{
    sfVector2f pos;

    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == \
    sfMouseLeft) {
        global->variable->frame_index = frame_selected(global, \
        (sfVector2f){event.mouseButton.x, event.mouseButton.y});
        if (global->variable->frame_index != 0) {
            global->drag->origin_pos = \
            sfSprite_getPosition(global->ui->ui\
            [global->variable->frame_index]->sprite);
            global->drag->mousePos.x = event.mouseButton.x - \
            sfSprite_getPosition(global->ui->ui\
            [global->variable->frame_index]->sprite).x;
            global->drag->mousePos.y = event.mouseButton.y - \
            sfSprite_getPosition(global->ui->ui\
            [global->variable->frame_index]->sprite).y;
            global->drag->moving = true;
        }
    }
    drag2(global, event, window, pos);
}

void drag2(st_global *global, sfEvent event, sfRenderWindow *window, \
sfVector2f pos)
{
    if (event.type == sfEvtMouseMoved)
        if (global->drag->moving == true) {
            pos.x = event.mouseMove.x;
            pos.y = event.mouseMove.y;
            sfSprite_setPosition(global->ui->ui\
            [global->variable->frame_index]->sprite, (sfVector2f)\
            {pos.x - global->drag->mousePos.x, pos.y - \
            global->drag->mousePos.y});
        }
    if (event.type == sfEvtMouseButtonReleased) {
        if (global->drag->moving == true) {
            global->drag->mouseReleased.x = event.mouseButton.x;
            global->drag->mouseReleased.y = event.mouseButton.y;
            drop(global, window);
            sfSprite_setPosition(global->ui->ui\
            [global->variable->frame_index]->sprite, global->drag->origin_pos);
        }
        global->drag->moving = false;
    }
}

void drop(st_global *global, sfRenderWindow *window)
{
    list_ground node_ground = global->map->li_ground;
    list_3D node_3d = global->map->li_3D;

    while (node_ground != NULL) {
        vertex_ground(global, node_ground);
        if (is_intersection(global, global->drag->mouseReleased) == true \
        && empty_tiles(node_ground, global) == false)
            texture_drop_fill(global, node_ground);
        node_ground = node_ground->next;
    }
    while (node_3d != NULL) {
        vertex_3_d(global, node_3d);
        if (is_intersection(global, global->drag->mouseReleased) == true)
            texture_drop_empty(global, node_3d);
        node_3d = node_3d->next;
    }
}

int frame_selected(st_global *global, sfVector2f pos)
{
    if (global->variable->interface == 0)
        for (int i = 12; i < 15; i++)
            if (sfFloatRect_contains(&global->ui->ui[i]->hitbox, \
            pos.x, pos.y) == true)
                return (i);
    if (global->variable->interface == 1)
        for (int j = 15; j < 18; j++)
            if (sfFloatRect_contains(&global->ui->ui[j]->hitbox, \
            pos.x, pos.y) == true)
                return (j);
    if (global->variable->interface == 2)
        if (sfFloatRect_contains(&global->ui->ui[18]->hitbox, \
        pos.x, pos.y) == true)
            return (18);
    return (0);
}