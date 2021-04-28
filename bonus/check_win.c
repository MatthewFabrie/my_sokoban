/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** checks if won
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int not_equal(int *a, int *b, char **map)
{
    int j = 0;
    int counter = 0;

    for (int i = 0; a[i] != -1; i++) {
        for (; b[j] != -1; j++) {
            if (a[i] == b[j])
                counter++;
        }
        j = 0;
    }
    if (counter == count_x(map))
        return (0);
    return (84);
}

int *get_xposition(char **map)
{
    int stock = 1;
    int *a = malloc(sizeof(int) * 1000);
    int b = 0;
    int j = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'X') {
                a[b] = stock;
                b++;
            }
        stock++;
        }
        j = 0;
    }
    a[b] = -1;
    return (a);
}

int *get_oposition(char **argv)
{
    char **tmp = my_str_to_word_array(my_opener(argv[1]), "\n");
    int stock = 1;
    int *a = malloc(sizeof(int) * 1000);
    int b = 0;
    int j = 0;

    for (int i = 0; tmp[i] != NULL; i++) {
        for (; tmp[i][j] != '\0'; j++) {
            if (tmp[i][j] == 'O') {
                a[b] = stock;
                b++;
            }
        stock++;
        }
        j = 0;
    }
    a[b] = -1;
    return (a);
}

void check_win(char **map, char **argv)
{
    if ((not_equal(get_oposition(argv), get_xposition(map), map) == 0)
    && (counter(map, 'O') == 0)) {
        endwin();
        exit(0);
    }
}
