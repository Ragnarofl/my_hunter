/*
** EPITECH PROJECT, 2018
** CSFML.h
** File description:
** simon-perraud
*/

#include "include/hunter.h"

void create_frame(list_t *list)
{
    sfVector2f pos = {850, 680};
    sfIntRect rect = {0, 0, 63, 23};

    create_object("frame.png", pos, rect, list);
}

void create_health(list_t *list)
{
    sfVector2f pos = {70, 680};
    sfVector2f scale = {0.25, 0.25};
    sfIntRect rect = {0, 508, 762, 254};
    object_t *health = create_object("Health.png", pos, rect, list);

    sfSprite_setScale(health->sprite, scale);
}

void create_bg(list_t *list)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 1280, 769};
    object_t *new = create_object("stage.png", pos, rect, list);

    new->scale = (sfVector2f){1, 1};
}
