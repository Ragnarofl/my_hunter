/*
** EPITECH PROJECT, 2018
** clock.c
** File description:
** simon-perraud
*/

#include "include/hunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (offset != max_value - 83)
        rect->left += offset;
    if (rect->left >= max_value) {
        rect->left = 0;
        rect->top += 73;
    }
    if (rect->top >= 200)
        rect->top = 0;
}

void destroy_duck(duck_t *duck, list_t *list)
{
    object_t *health = list->first->next;

    sfSprite_destroy(duck->sprite);
    sfTexture_destroy(duck->texture);
    free(duck);
    list->life -= 1;
    list->first->next->rect.top -= 254;
    sfSprite_setTextureRect(health->sprite, health->rect);
}

void move_ducks(list_t *list, float speed)
{
    duck_t *duck = list->duck;
    duck_t *ducker = list->duck->next;

    duck->position.x += speed;
    if (duck->position.x >= 1280) {
        list->duck = NULL;
        destroy_duck(duck, list);
    }
    for (; ducker != NULL; ducker = ducker->next, duck = duck->next) {
        ducker->position.x += speed;
        if (ducker->position.x >= 1280) {
            duck->next = ducker->next;
            destroy_duck(ducker, list);
        }
    }
}

clocki_t *create_clock(void)
{
    clocki_t *clock = malloc(sizeof(*clock));

    clock->clock = sfClock_create();
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    return (clock);
}

void manage_clock(clocki_t *clock, clocki_t *respawn, list_t *list, int *i)
{
    object_t *new = list->first;

    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    respawn->time = sfClock_getElapsedTime(respawn->clock);
    respawn->seconds = respawn->time.microseconds / 1000000.0;
    if (*i == 0 && clock->seconds >= 0.01) {
        new->position.x -= 0.3;
        sfSprite_setPosition(new->sprite, new->position);
        if (new->position.x <= -1260)
            new->position.x = 0;
    }
}
