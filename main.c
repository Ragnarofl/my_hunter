/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Simon-Perraud
*/

#include "include/hunter.h"
#include "include/my.h"

void analyse_events(sfRenderWindow *win, sfEvent eve, list_t **list, int *i)
{
    if (eve.type == sfEvtKeyPressed) {
        if (eve.key.code == sfKeyEscape && *i == 0) {
            sfRenderWindow_close(win);
        }
        else if (eve.key.code == sfKeyEscape && *i == 1) {
            *i = 0;
            check_score(list);
            list[1] = create_game();
            sfText_setString(list[1]->text->text, my_itoa(list[1]->score));
        }
    }
    if (eve.type == sfEvtClosed)
        sfRenderWindow_close(win);
    if (eve.type == sfEvtMouseButtonPressed && list[*i]->duck != NULL)
        check_ducks(eve, list[*i]);
    if (eve.type == sfEvtMouseButtonPressed && list[*i]->buttons != NULL)
        check_buttons_click(win, eve, list[*i], i);
}

void manage_window(sfRenderWindow *window, list_t **list)
{
    int i = 0;
    sfEvent event;
    clocki_t *clock = create_clock();
    clocki_t *respawn = create_clock();

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, list, &i);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        if (list[i]->life <= 0) {
            i = 0;
            list[1] = create_game();
        }
        draw_list(window, list[i], i);
        check_buttons_hoover(window, list[i], &i);
        manage_clock(clock, respawn, list[i], &i);
        if (i == 1)
            manage_ducks(list[1], clock, respawn);
    }
}

int main(void)
{
    char c;
    long int random_test = (long int)&c;
    char *title = "my_hunter";
    sfRenderWindow *window;
    sfVideoMode mode = {1280, 769, 32};
    list_t **list_array = create_list_array();
    srand((unsigned int)random_test);

    window = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);
    manage_window(window, list_array);
    return (0);
}
