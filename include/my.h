/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** simon-perraud
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include "printf.h"

void my_putchar(char, int);
int my_isneg(int);
long int my_put_nbr(long int, int);
long int my_putnbr_base(long int, char *, char, int);
int my_swap(int *, int *);
int my_putstr(char *, int);
int my_strlen(char const *);
int my_nbrlen(long int, int);
int my_getnbr(char *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
char *my_itoa(int nb);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
void my_show_word_array(char * const *tab);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *, int);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_malloc_str(char *, int);
int is_char_present(char c, char *cmp);
int my_printf(char *s, ...);
