/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** ui
*/

#include "game.h"

void upgrade_coins(st_global *global)
{
    global->ui->ui[6]->animation.width = global->ui->money * 325 / 1000;
    sfSprite_setTextureRect(global->ui->ui[6]->sprite, \
    global->ui->ui[6]->animation);
}

void upgrade_heal(st_global *global)
{
    global->ui->ui[9]->animation.width = global->ui->heal * 325 / 1000;
    sfSprite_setTextureRect(global->ui->ui[9]->sprite, \
    global->ui->ui[9]->animation);
}

void all_bars(sfRenderWindow *window, st_global *global, sfEvent event)
{
    upgrade_coins(global);
    upgrade_heal(global);
    if (event.type == sfEvtMouseButtonPressed && \
    event.mouseButton.button == sfMouseLeft) {
        if (event.mouseButton.x >= 620 && event.mouseButton.x <= 867 && \
        event.mouseButton.y >= 854 && event.mouseButton.y <= 895)
            global->variable->interface = 0;
        if (event.mouseButton.x >= 868 && event.mouseButton.x <= 1104 && \
        event.mouseButton.y >= 851 && event.mouseButton.y <= 894)
            global->variable->interface = 1;
        if (event.mouseButton.x >= 1105 && event.mouseButton.x <= 1350 && \
        event.mouseButton.y >= 852 && event.mouseButton.y <= 895)
            global->variable->interface = 2;
    }
    display_bottom_bar(window, global);
    top_bar(window, global);
    ui_text_bars(global, window);
}

void top_bar(sfRenderWindow *window, st_global *global)
{
    sfSprite_setRotation(global->ui->ui[6]->sprite, 180);
    sfSprite_setPosition(global->ui->ui[6]->sprite, \
    global->ui->ui[6]->position);
    sfSprite_setRotation(global->ui->ui[9]->sprite, 180);
    sfSprite_setPosition(global->ui->ui[9]->sprite, \
    global->ui->ui[9]->position);
    sfRenderWindow_drawSprite(window, global->ui->ui[6]->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->ui->ui[7]->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->ui->ui[8]->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->ui->ui[9]->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->ui->ui[10]->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->ui->ui[11]->sprite, NULL);
}

void display_bottom_bar(sfRenderWindow *window, st_global *global)
{
    sfRenderWindow_drawSprite(window, \
    global->ui->ui[global->variable->interface]->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->ui->ui[3]->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->ui->ui[4]->sprite, NULL);
    sfRenderWindow_drawSprite(window, global->ui->ui[5]->sprite, NULL);
    if (global->variable->interface == 0) {
        sfRenderWindow_drawSprite(window, global->ui->ui[12]->sprite, NULL);
        sfRenderWindow_drawSprite(window, global->ui->ui[13]->sprite, NULL);
        sfRenderWindow_drawSprite(window, global->ui->ui[14]->sprite, NULL);
    }
    else if (global->variable->interface == 1) {
        sfRenderWindow_drawSprite(window, global->ui->ui[15]->sprite, NULL);
        sfRenderWindow_drawSprite(window, global->ui->ui[16]->sprite, NULL);
        sfRenderWindow_drawSprite(window, global->ui->ui[17]->sprite, NULL);
    }
    else
        sfRenderWindow_drawSprite(window, global->ui->ui[18]->sprite, NULL);
}