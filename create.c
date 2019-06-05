/*
** EPITECH PROJECT, 2018
** create.c
** File description:
** simon-perraud
*/

#include "include/hunter.h"

object_t *create_object(char *ssh, sfVector2f pos, sfIntRect rect, list_t *list)
{
    object_t *new = malloc(sizeof(*new));
    new->sprite = sfSprite_create();
    new->texture = sfTexture_create(1280, 800);
    new->texture = sfTexture_createFromFile(ssh, NULL);
    new->position.x = pos.x;
    new->position.y = pos.y;
    new->rect.left = rect.left;
    new->rect.top = rect.top;
    new->rect.width = rect.width;
    new->rect.height = rect.height;
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTextureRect(new->sprite, rect);
    new->scale = (sfVector2f){1, 1};
    new->next = list->first;
    list->first = new;
    return (new);
}
