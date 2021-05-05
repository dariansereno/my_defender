/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** generation_ui
*/

#include "game.h"

st_object **generate_ui(void)
{
    st_object **tab = malloc(sizeof(st_object *) * 19);

    tab[0] = generate_object("contents/img/build_bar/background_defenses.png",
    (sfVector2f){491, 834}, (sfIntRect){0, 0, 981, 246});
    tab[1] = generate_object("contents/img/build_bar/background_attacks.png", \
    (sfVector2f){491, 834}, (sfIntRect){0, 0, 981, 246});
    tab[2] = generate_object("contents/img/build_bar/background_upgrades.png", \
    (sfVector2f){491, 834}, (sfIntRect){0, 0, 981, 246});
    tab[3] = generate_object("contents/img/build_bar/text_defenses.png", \
    (sfVector2f){694, 862}, (sfIntRect){0, 0, 94, 22});
    tab[4] = generate_object("contents/img/build_bar/text_attacks.png", \
    (sfVector2f){948, 866}, (sfIntRect){0, 0, 78, 21});
    tab[5] = generate_object("contents/img/build_bar/text_upgrades.png", \
    (sfVector2f){1182, 863}, (sfIntRect){0, 0, 98, 26});
    tab = generate_ui2(tab);
    return (tab);
}

st_object **generate_ui2(st_object **tab)
{
    tab[6] = generate_object("contents/img/top_bar/yellow_money.png", \
    (sfVector2f){1826, 81}, (sfIntRect){0, 0, 0, 38});
    tab[7] = generate_object("contents/img/top_bar/back_money.png", \
    (sfVector2f){1501, 43}, (sfIntRect){0, 0, 325, 38});
    tab[8] = generate_object("contents/img/top_bar/coin.png", \
    (sfVector2f){1755, 32}, (sfIntRect){0, 0, 59, 59});
    tab[9] = generate_object("contents/img/top_bar/red_health.png", \
    (sfVector2f){1826, 160}, (sfIntRect){0, 0, 325, 38});
    tab[10] = generate_object("contents/img/top_bar/back_health.png", \
    (sfVector2f){1501, 122}, (sfIntRect){0, 0, 325, 38});
    tab[11] = generate_object("contents/img/top_bar/cross.png", \
    (sfVector2f){1757, 113}, (sfIntRect){0, 0, 55, 56});
    tab[12] = generate_object("contents/img/build_bar/cover/def1.png", \
    (sfVector2f){690, 936}, (sfIntRect){0, 0, 102, 102});
    tab[13] = generate_object("contents/img/build_bar/cover/def2.png", \
    (sfVector2f){931, 936}, (sfIntRect){0, 0, 102, 102});
    tab[14] = generate_object("contents/img/build_bar/cover/def3.png", \
    (sfVector2f){1172, 936}, (sfIntRect){0, 0, 102, 102});
    tab = generate_rectangle_ui(tab);
    return (tab);
}

st_object **generate_rectangle_ui(st_object **tab)
{
    tab[15] = generate_object("contents/img/build_bar/cover/att1.png", \
    (sfVector2f){690, 936}, (sfIntRect){0, 0, 102, 102});
    tab[16] = generate_object("contents/img/build_bar/cover/att2.png", \
    (sfVector2f){931, 939}, (sfIntRect){0, 0, 102, 102});
    tab[17] = generate_object("contents/img/build_bar/cover/att3.png", \
    (sfVector2f){1172, 936}, (sfIntRect){0, 0, 102, 102});
    tab[18] = generate_object("contents/img/build_bar/cover/upgrade.png", \
    (sfVector2f){931, 936}, (sfIntRect){0, 0, 102, 102});
    return (tab);
}

st_interface *generate_interface(st_global *global)
{
    global->ui->ui = malloc(sizeof(*global->ui->ui));
    global->ui->ui = generate_ui();
    global->ui->money_text = sfText_create();
    global->ui->money = 1;
    global->ui->heal = 1000;
    global->ui->money_clock = malloc(sizeof(*global->ui->money_clock));
    global->ui->money_clock->clock = sfClock_create();
    global->ui->money_clock->time = \
    sfClock_getElapsedTime(global->ui->money_clock->clock);
    global->ui->money_clock->seconds = 0;
    global->ui->money_clock->seconds = \
    global->ui->money_clock->time.microseconds / 1000;
    global->ui->heal_text = sfText_create();
    global->ui->font = \
    sfFont_createFromFile("contents/fonts/playbill/PLAYBILL.ttf");
    return (global->ui);
}