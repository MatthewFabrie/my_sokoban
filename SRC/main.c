/*
** EPITECH PROJECT, 2021
** sokoban Main
** File description:
** my_getnbr.c
*/

#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int error_handling(char **map)
{
    if (counter(map, 'O') != counter(map, 'X'))
        exit (84);
    if (counter(map, 'P') != 1)
        exit (84);
    character_check(map);
    return (0);
}

char *my_opener(char *map)
{
    struct stat size;
    char *buffer;
    int fd = open(map, O_RDONLY);

    stat(map, &size);
    buffer = malloc(sizeof(char) * size.st_size);
    read(fd, buffer, size.st_size);
    return (buffer);
}

int is_correct(char *test_file)
{
    struct stat dir;

    stat(test_file, &dir);
    return(S_ISREG(dir.st_mode));
}

int helper(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban\n");
    my_putstr("DESCRIPTION\n       ");
    my_putstr("map file representing the warehouse map,");
    my_putstr(" containing '#' for walls,\n");
    my_putstr("           'P' for the player, 'X' for boxes and");
    my_putstr(" 'O' for storage locations.\n");
    exit(0);
}

int main(int argc, char **argv)
{
    char **map = NULL;

    if (argc != 2)
        return (84);
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        helper();
    if (is_correct(argv[1]) == 0)
        return (84);
    map = my_str_to_word_array(my_opener(argv[1]), "\n");
    error_handling(map);
    my_soko(map, argv);
    return (0);
}