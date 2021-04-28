/*
** EPITECH PROJECT, 2021
** sokoban Error handling
** File description:
** error handling
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int counter(char **map, char tmp)
{
    int j = 0;
    int counter = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (;j < my_strlen(map[i]); j++) {
            if (map[i][j] == tmp)
                counter++;
        }
        j = 0;
    }
    return (counter);
}

int character_check(char **map)
{
    int j = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (;j < my_strlen(map[i]); j++) {
            if (map[i][j] != 'O' && map[i][j] != 'X' && map[i][j] != 'P' &&
            map[i][j] != ' ' && map[i][j] != '#')
                exit (84);
        }
        j = 0;
    }
    return (0);
}

int my_tablen(char **tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL)
        i = i + 1;
    return (i);
}

void check_size(char **map)
{
    while (LINES < my_tablen(map) || COLS < my_strlen(map[1])) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 10, "terminal too small");
        refresh();
    }
}