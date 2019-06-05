/*
** EPITECH PROJECT, 2018
** my_sort_int_array.c
** File description:
** simon-perraud
*/

void my_swap_sort(int *a, int *b)
{
    int tmp = *b;

    *b = *a;
    *a = tmp;
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;

    (void)size;
    for (; array[i] != '\0'; i++) {
        if (array[i] > array[i + 1] && array[i + 1] != '\0') {
            my_swap_sort(&array[i], &array[i + 1]);
            i = -1;
        }
    }
}
