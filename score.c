/*
** EPITECH PROJECT, 2018
** score.c
** File description:
** simon-perraud
*/

#include "include/hunter.h"
#include "include/my.h"

void check_score(list_t **list)
{
    int fd = open("score", O_RDWR);

    if (list[0]->score < list[1]->score) {
        list[0]->score = list[1]->score;
        sfText_setString(list[0]->text->text, my_itoa(list[0]->score));
        my_dprintf(fd, "%d", list[0]->score);
    }
}
