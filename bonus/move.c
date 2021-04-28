/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** more player movements
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int go_left(char **map, int y, int x, int stock)
{
    if (map[y][x - 1] == ' ') {
        map[y][x - 1] = 'P';
        map[y][x] = ' ';
    }
    if (map[y][x - 1] == 'X' && map[y][x - 2] == ' ') {
        map[y][x] = ' ';
        map[y][x - 1] = 'P';
        map[y][x - 2] = 'X';
    }
    if (map[y][x - 1] == 'X' && map[y][x - 2] == 'O') {
        map[y][x] = ' ';
        map[y][x - 1] = 'P';
        map[y][x - 2] = 'X';
    }
    stock = going_left(map, y, x, stock);
    return (stock);
}

int going_left(char **map, int y, int x, int stock)
{
    if (map[y][x - 1] == 'O') {
        map[y][x - 1] = 'P';
        map[y][x] = ' ';
        stock += 1;
    }
    else if (stock > 0) {
        map[y][x] = ' ';
        map[y][x - 1] = 'P';
        stock = 0;
    }
    return (stock);
}

int go_right(char **map, int y, int x, int stock)
{
    if (map[y][x + 1] == ' ') {
        map[y][x + 1] = 'P';
        map[y][x] = ' ';
    }
    if (map[y][x + 1] == 'X' && map[y][x + 2] == ' ') {
        map[y][x] = ' ';
        map[y][x + 1] = 'P';
        map[y][x + 2] = 'X';
    }
    if (map[y][x + 1] == 'X' && map[y][x + 2] == 'O') {
        map[y][x] = ' ';
        map[y][x + 1] = 'P';
        map[y][x + 2] = 'X';
    }
    stock = going_right(map, y, x, stock);
    return (stock);
}

int going_right(char **map, int y, int x, int stock)
{
    if (map[y][x + 1] == 'O') {
        map[y][x + 1] = 'P';
        map[y][x] = ' ';
        stock += 1;
    }
    else if (stock > 0) {
        map[y][x] = ' ';
        map[y][x + 1] = 'P';
        stock = 0;
    }
    return (stock);
}