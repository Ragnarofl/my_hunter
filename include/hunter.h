/*
** EPITECH PROJECT, 2018
** CSFML.h
** File description:
** simon-perraud
*/

#ifndef __CSFML__
#define __CSFML__

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct object_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    struct object_s *next;
} object_t;

typedef struct button_s
{
    sfSprite *sprite;
    sfText *text;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    void (*callback)(sfRenderWindow *, int *);
} button_t;

typedef struct text_s
{
    sfText *text;
    sfVector2f pos;
    sfFont *font;
    struct text_s *next;
} text_t;

typedef struct duck_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    struct duck_s *next;
} duck_t;

typedef struct list_s
{
    object_t *first;
    duck_t *duck;
    button_t **buttons;
    int btn_nbr;
    float speed;
    float resp;
    text_t *text;
    int score;
    int life;
} list_t;

typedef struct clock_s
{
    sfTime time;
    sfClock *clock;
    float seconds;
} clocki_t;

duck_t *create_duck(list_t *);
list_t *create_game(void);
void create_health(list_t *list);
void draw_duck(sfRenderWindow *, list_t *);
void check_ducks(sfEvent, list_t *);
int duck_is_on(duck_t *, sfVector2f);
void manage_ducks(list_t *, clocki_t *, clocki_t *);
void move_ducks(list_t *, float);
void move_rect(sfIntRect *rect, int offset, int max_value);
list_t **create_list_array(void);
void check_score(list_t **);
char *read_file(char *);
void create_bg(list_t *list);
void create_background(list_t *list);
void create_buttons(list_t *, char *, char *);
sfText  *create_text(sfVector2f, char *, int);
void check_buttons_click(sfRenderWindow *, sfEvent, list_t *, int *);
void check_buttons_hoover(sfRenderWindow *, list_t *, int *);
void draw_list(sfRenderWindow *, list_t *, int);
void draw_text(sfRenderWindow *, list_t *);
object_t *create_object(char *, sfVector2f, sfIntRect, list_t *);
void manage_clock(clocki_t *, clocki_t *, list_t *, int *);
clocki_t *create_clock(void);
text_t *title_text(void);
text_t *game_text(void);

#endif /* __CSFML__ */
