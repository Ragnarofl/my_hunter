/*
** EPITECH PROJECT, 2018
** text.c
** File description:
** simon-perraud
*/

#include "include/hunter.h"

sfText  *create_text(sfVector2f pos, char *str, int size)
{
    sfFont *font;
    sfText *text;

    text = sfText_create();
    font = sfFont_createFromFile("Hunger_Games.ttf");
    sfText_setString(text, str);
    sfText_setOrigin(text, pos);
    sfText_setCharacterSize(text, size);
    sfText_setFont(text, font);
    return (text);
}

text_t *title_text()
{
    text_t *text = malloc(sizeof(*text));
    text_t *score = malloc(sizeof(*score));
    text_t *number = malloc(sizeof(*number));
    sfVector2f pos = {-475, -40};
    sfVector2f score_pos = {-530, -170};
    sfVector2f number_pos = {-760, -170};

    number->pos = number_pos;
    number->text = create_text(number_pos, read_file("score"), 30);
    number->next = text;
    text->pos = pos;
    text->text = create_text(pos, "EpiHunt", 80);
    text->next = score;
    score->pos = score_pos;
    score->text = create_text(score_pos, "High Score :", 30);
    score->next = NULL;
    return (number);
}

text_t *game_text(void)
{
    text_t *score = malloc(sizeof(*score));
    text_t *text = malloc(sizeof(*text));
    sfVector2f score_pos = {-1000, -700};
    sfVector2f text_pos = {-860, -700};

    score->pos = score_pos;
    score->text = create_text(score_pos, "0", 30);
    score->next = text;
    text->pos = text_pos;
    text->text = create_text(text_pos, "Score : ", 30);
    text->next = NULL;
    return (score);
}

void draw_text(sfRenderWindow *window, list_t *list)
{
    text_t *text = list->text;

    for (;text != NULL; text = text->next)
        sfRenderWindow_drawText(window, text->text, NULL);
}
