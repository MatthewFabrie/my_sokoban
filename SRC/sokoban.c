/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** map and player stuff
*/

#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void my_refresh(char **map, int *tab, int stor)
{
    for (int i = 0; i != stor * 2; i += 2) {
        if (map[tab[i]][tab[i + 1]] == ' ')
            map[tab[i]][tab[i + 1]] = 'O';
    }
}

int *map_save(char **map, int dests)
{
    int *tab = malloc(sizeof(int) * (dests * 2));
    int j = 0;
    int x = 0;

    for (int i = 0; map[i] != NULL; i += 1) {
        for (j = 0; j != my_strlen(map[i]); j += 1) {
            if (map[i][j] == 'O') {
                tab[x] = i;
                tab[x + 1] = j;
                x += 2;
            }
        }
        j = 0;
    }
    return (tab);
}

int player_move(int button, char **map, int stock, char **argv)
{
    int x = 0;
    int y = 0;

    for (; map[y][x] != 'P'; x++) {
        if (map[y][x] == '\n' || map[y][x] == '\0') {
            y++;
            x = 0;
        }
    }
    if (button == 65 && map[y - 1][x] != '#')
        stock = go_up(map, y, x, stock);
    if (button == 66 && map[y + 1][x] != '#')
        stock = go_down(map, y, x, stock);
    if (button == 68 && map[y][x - 1] != '#')
        stock = go_left(map, y, x, stock);
    if (button == 67 && map[y][x + 1] != '#')
        stock = go_right(map, y, x, stock);
    if (button == ' ')
        restarter(map, argv);
    return (stock);
}

void looper(char **map, char **argv)
{
    int stock = 0;
    int i = 0;

    refresh();
    while (map[i] != NULL) {
        mvprintw(LINES / 2 - my_tablen(map) / 2 + i,
        COLS / 2 - my_strlen(map[i]) / 2, map[i]);
        i++;
    }
    stock = player_move(getch(), map, stock, argv);
    check_size(map);
    check_win(map, argv);
    if (check_lost(map) == 1)
        you_lost();
}

int my_soko(char **map, char **argv)
{
    int dests = counter(map, 'O');
    int *buf = map_save(map, dests);

    initscr();
    curs_set(FALSE);
    while (1) {
        looper(map, argv);
        my_refresh(map, buf, dests);
        clear();
    }
    endwin();
    return (0);
}