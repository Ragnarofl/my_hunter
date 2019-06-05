/*
** EPITECH PROJECT, 2018
** list.c
** File description:
** simon-perraud
*/

#include "include/hunter.h"
#include "include/my.h"

void draw_duck(sfRenderWindow *window, list_t *list)
{
    duck_t *duck = list->duck;

    for (; duck != NULL; duck = duck->next) {
        sfRenderWindow_drawSprite(window, duck->sprite, NULL);
        sfSprite_setPosition(duck->sprite, duck->position);
    }
}

void draw_list(sfRenderWindow *window, list_t *list, int i)
{
    object_t *new = list->first;
    button_t **buttons = list->buttons;

    for (;new != NULL; new = new->next) {
        sfRenderWindow_drawSprite(window, new->sprite, NULL);
        sfSprite_setPosition(new->sprite, new->position);
    }
    for (int x = 0; x < list->btn_nbr; x++) {
        sfRenderWindow_drawSprite(window, buttons[x]->sprite, NULL);
        sfSprite_setPosition(buttons[x]->sprite, buttons[x]->position);
        sfRenderWindow_drawText(window, buttons[x]->text, NULL);
    }
    draw_text(window, list);
    if (i == 1)
        draw_duck(window, list);
}

list_t *create_title(void)
{
    list_t *list = malloc(sizeof(*list));

    if (list != NULL) {
        list->first = NULL;
        create_buttons(list, "button.png", "button.png");
        list->btn_nbr = 2;
        list->speed = 0;
        list->resp = 0;
        create_background(list);
        list->text = title_text();
        list->score = my_getnbr(read_file("score"));
        list->duck = NULL;
        list->life = 3;
    }
    return (list);
}

list_t *create_game(void)
{
    list_t *list = malloc(sizeof(*list));

    if (list != NULL) {
        list->first = NULL;
        create_health(list);
        create_bg(list);
        list->buttons = NULL;
        list->btn_nbr = 0;
        list->speed = 0.5;
        list->resp = 2;
        list->text = game_text();
        list->score = 0;
        list->duck = NULL;
        list->life = 3;
    }
    return (list);
}

list_t **create_list_array(void)
{
    list_t **list_array = malloc(sizeof(list_t) * 2);

    list_array[0] = create_title();
    list_array[1] = create_game();
    return (list_array);
}
