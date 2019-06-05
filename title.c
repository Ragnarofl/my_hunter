/*
** EPITECH PROJECT, 2018
** title.c
** File description:
** simon-perraud
*/

#include "include/hunter.h"

void close_window(sfRenderWindow *window, int *i)
{
    (void)i;
    sfRenderWindow_close(window);
}

void play(sfRenderWindow *window, int *i)
{
    (void)window;
    *i = 1;
}


void create_background(list_t *list)
{
    sfVector2f pos = {0, 0};
    sfIntRect size = {0, 0, 2541, 769};
    create_object("title.png", pos, size, list);
}

button_t *title_button(char *ssh, sfVector2f pos, sfIntRect rect)
{
    button_t *button = malloc(sizeof(*button));
    button->sprite = sfSprite_create();
    button->texture = sfTexture_create(256, 240);
    button->texture = sfTexture_createFromFile(ssh, NULL);
    button->position.x = pos.x;
    button->position.y = pos.y;
    button->rect.left = rect.left;
    button->rect.top = rect.top;
    button->rect.width = rect.width;
    button->rect.height = rect.height;
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, rect);
    return (button);
}

void create_buttons(list_t *list, char *ssh, char *ssh2)
{
    sfVector2f button1_pos = {550, 250};
    sfVector2f button2_pos = {550, 350};
    sfVector2f Text_pos1 = {-600, -263};
    sfVector2f Text_pos2 = {-615, -363};
    sfVector2f scale = {0.8, 0.8};
    sfIntRect button_size = {0, 0, 256, 80};

    list->buttons = malloc(sizeof(button_t) * 2);
    list->buttons[0] = title_button(ssh, button1_pos, button_size);
    sfSprite_setScale(list->buttons[0]->sprite, scale);
    list->buttons[0]->callback = &play;
    list->buttons[0]->scale = scale;
    list->buttons[0]->text = create_text(Text_pos1, "Start", 30);
    list->buttons[1] = title_button(ssh2, button2_pos, button_size);
    sfSprite_setScale(list->buttons[1]->sprite, scale);
    list->buttons[1]->callback = &close_window;
    list->buttons[1]->scale = scale;
    list->buttons[1]->text = create_text(Text_pos2, "Quit", 30);
}
