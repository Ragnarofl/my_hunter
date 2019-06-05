/*
** EPITECH PROJECT, 2018
** duck.c
** File description:
** simon-perraud
*/

#include "include/hunter.h"
#include "include/my.h"

int duck_is_on(duck_t *duck, sfVector2f clickpos)
{
    int check = 0;
    int posx = sfSprite_getPosition(duck->sprite).x;
    int posy = sfSprite_getPosition(duck->sprite).y;

    check += clickpos.x < posx + (duck->rect.width) * duck->scale.x;
    check += clickpos.x > posx;
    check += clickpos.y < posy + (duck->rect.height) * duck->scale.y;
    check += clickpos.y > posy;
    return (check == 4);
}

void kill_ducks(duck_t *duck, duck_t *ducker, list_t *list, sfVector2f coord)
{
    for (; ducker != NULL; duck = duck->next, ducker = ducker->next)
        if (duck_is_on(ducker, coord) == 1) {
            duck->next = ducker->next;
            sfSprite_destroy(ducker->sprite);
            sfTexture_destroy(ducker->texture);
            free(ducker);
            list->score += 100;
            sfText_setString(list->text->text, my_itoa(list->score));
            break;
        }
}

void check_ducks(sfEvent eve, list_t *list)
{
    sfVector2f coord = {eve.mouseButton.x, eve.mouseButton.y};
    duck_t *duck = list->duck;
    duck_t *ducker = duck->next;
    sfMusic *music = sfMusic_createFromFile("shot.wav");

    sfMusic_setVolume(music, 20);
    sfMusic_play(music);
    if (duck_is_on(duck, coord) == 1) {
        list->duck = ducker;
        sfSprite_destroy(duck->sprite);
        sfTexture_destroy(duck->texture);
        free(duck);
        list->score += 100;
        sfText_setString(list->text->text, my_itoa(list->score));
    } else
        kill_ducks(duck, ducker, list, coord);
}

duck_t *create_duck(list_t *list)
{
    sfVector2f pos = {-75, rand() % 400};
    sfIntRect rect = {0, 0, 75, 70};
    duck_t *new = malloc(sizeof(*new));

    new->sprite = sfSprite_create();
    new->texture = sfTexture_create(1280, 800);
    new->texture = sfTexture_createFromFile("hawk.png", NULL);
    new->position = pos;
    new->rect = rect;
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTextureRect(new->sprite, rect);
    new->scale = (sfVector2f){1, 1};
    new->next = list->duck;
    list->duck = new;
    return (new);
}

void manage_ducks(list_t *list, clocki_t *clock, clocki_t *respawn)
{
    duck_t *duck = list->duck;

    if (clock->seconds >= 0.06 && duck != NULL) {
        for (; duck != NULL; duck = duck->next) {
            move_rect(&duck->rect, 88, 210);
            sfSprite_setTextureRect(duck->sprite, duck->rect);
        }
        duck = list->duck;
        sfClock_restart(clock->clock);
    }
    if (clock->seconds >= 0.01 && duck != NULL)
        move_ducks(list, list->speed);
    if (respawn->seconds >= list->resp) {
        list->duck = create_duck(list);
        sfClock_restart(respawn->clock);
        if (list->speed <= 0.6)
            list->resp *= 0.90;
        if (list->speed <= 2.5)
            list->speed *= 1.05;
    }
}
