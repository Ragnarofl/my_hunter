/*
** EPITECH PROJECT, 2018
** buttons.c
** File description:
** simon-perraud
*/

#include "include/hunter.h"

int button_is_on(button_t *button, sfVector2f clickpos)
{
    int check = 0;
    int posx = sfSprite_getPosition(button->sprite).x;
    int posy = sfSprite_getPosition(button->sprite).y;

    check += clickpos.x < posx + (button->rect.width) * button->scale.x;
    check += clickpos.x > posx;
    check += clickpos.y < posy + (button->rect.height) * button->scale.y;
    check += clickpos.y > posy;
    return (check == 4);
}

void check_buttons_click(sfRenderWindow *win, sfEvent eve, list_t *list, int *i)
{
    sfVector2f coord = {eve.mouseButton.x, eve.mouseButton.y};
    button_t **buttons = list->buttons;

    for (int x = 0; x < 2; x++)
        if (button_is_on(buttons[x], coord) == 1)
            buttons[x]->callback(win, i);
}

void check_buttons_hoover(sfRenderWindow *win, list_t *l, int *i)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*)win);
    sfVector2f coord = {mouse.x, mouse.y};
    button_t **buttons = l->buttons;

    for (int x = 0; x < 2 && *i == 0; x++) {
        if (button_is_on(buttons[x], coord) == 1) {
            buttons[x]->rect.top = 80;
            sfSprite_setTextureRect(buttons[x]->sprite, buttons[x]->rect);
        } else if (button_is_on(buttons[x], coord) != 1)
            buttons[x]->rect.top = 0;
            sfSprite_setTextureRect(buttons[x]->sprite, buttons[x]->rect);
    }
}
