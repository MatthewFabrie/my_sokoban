/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** checker
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void you_lost(char **map, char **argv)
{
    int key = 0;

    clear();
    refresh();
    noecho();
    mvprintw(LINES / 2 - 1, COLS / 2 - 3, "You lost!\n");
    mvprintw(LINES / 2, COLS / 2 - 5, "Restart ? y/n\n");
    key = getch();
    while (key != 'n' && key != 'Y' && key != 'y')
        key = getch();
    if (key == 'n') {
        endwin();
        exit(1);
    }
    if (key == 'Y' || key == 'y' || key == 32)
        restarter(map, argv);
}

int count_x(char **tab)
{
    int i;
    int j;
    int nb;

    nb = 0;
    i = 0;
    while (tab[i] != NULL) {
        j = 0;
        while (tab[i][j] != '\0') {
            if (tab[i][j] == 'X')
                nb = nb + 1;
        j = j + 1;
        }
        i = i + 1;
    }
    return (nb);
}

int check_lost(char **tab)
{
    int i = 0;
    int j;
    int blocs = 0;

    while (tab[i] != NULL) {
        j = 0;
        while (tab[i][j] != '\0') {
            if (tab[i][j] == 'X' && check_boxes(tab, i, j) == 1)
                blocs = blocs + 1;
            j = j + 1;
            }
        i = i + 1;
    }
    if (blocs == count_x(tab))
        return (1);
    return (0);
}

int check_boxes(char **tab, int x, int y)
{
    if ((tab[x - 1][y] == '#' || tab[x - 1][y] == 'X')
    && (tab[x][y - 1] == '#' || tab[x][y + 1] == '#'
    || tab[x][y - 1] == 'X' || tab[x][y + 1] == 'X'))
        return (1);
    if ((tab[x + 1][y] == '#' || tab[x + 1][y] == 'X')
    && (tab[x][y - 1] == '#' || tab[x][y + 1] == '#'
    || tab[x][y - 1] == 'X' || tab[x][y + 1] == 'X'))
        return (1);
    return (0);
}

void restarter(char **map, char **argv)
{
    clear();
    map = my_str_to_word_array(my_opener(argv[1]), "\n");
    my_soko(map, argv);
}
