/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** player movements
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int go_up(char **map, int y, int x, int stock)
{
    if (map[y - 1][x] == ' ') {
        map[y - 1][x] = 'P';
        map[y][x] = ' ';
    }
    if (map[y - 1][x] == 'X' && map[y - 2][x] == ' ') {
        map[y][x] = ' ';
        map[y - 1][x] = 'P';
        map[y - 2][x] = 'X';
    }
    if (map[y - 1][x] == 'X' && map[y - 2][x] == 'O') {
        map[y][x] = ' ';
        map[y - 1][x] = 'P';
        map[y - 2][x] = 'X';
    }
    stock = going_up(map, y, x, stock);
    return (stock);
}

int going_up(char **map, int y, int x, int stock)
{
    if (map[y - 1][x] == 'O') {
        map[y - 1][x] = 'P';
        map[y][x] = ' ';
        stock += 1;
    }
    else if (stock > 0) {
        map[y][x] = ' ';
        map[y - 1][x] = 'P';
        stock = 0;
    }
    return (stock);
}

int go_down(char **map, int y, int x, int stock)
{
    if (map[y + 1][x] == ' ') {
        map[y + 1][x] = 'P';
        map[y][x] = ' ';
    }
    if (map[y + 1][x] == 'X' && map[y + 2][x] == ' ') {
        map[y][x] = ' ';
        map[y + 1][x] = 'P';
        map[y + 2][x] = 'X';
    }
    if (map[y + 1][x] == 'X' && map[y + 2][x] == 'O') {
        map[y][x] = ' ';
        map[y + 1][x] = 'P';
        map[y + 2][x] = 'X';
    }
    stock = going_down(map, y, x, stock);
    return (stock);
}

int going_down(char **map, int y, int x, int stock)
{
    if (map[y + 1][x] == 'O') {
        map[y + 1][x] = 'P';
        map[y][x] = ' ';
        stock += 1;
    }
    else if (stock > 0) {
        map[y][x] = ' ';
        map[y + 1][x] = 'P';
        stock = 0;
    }
    return (stock);
}