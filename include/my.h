/*
** EPITECH PROJECT, 2020
** my h header
** File description:
** this file cointains all file prototypes
*/

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char **my_str_to_word_array(const char *str, const char *separator);
int my_strcmp(char const *s1, char const *s2);
int get_nb_words(const char *str, const char *separator);
int is_correct(char *test_file);
int counter(char **map, char tmp);
int character_check(char **map);
void looper(char **map, char **argv);
int my_soko(char **map, char **argv);
int *map_save(char **map, int dests);
int player_move(int button, char **map, int stock, char **argv);
int going_right(char **map, int i, int j, int x);
int go_right(char **map, int i, int j, int x);
int going_left(char **map, int i, int j, int x);
int go_left(char **map, int i, int j, int x);
int go_up(char **map, int i, int j, int x);
int going_up(char **map, int i, int j, int x);
int go_down(char **map, int i, int j, int x);
int going_down(char **map, int i, int j, int x);
void check_size(char **map);
int my_tablen(char **tab);
int check_lost(char **tab);
int check_boxes(char **tab, int x, int y);
void you_lost(void);
char *my_opener(char *map);
void restarter(char **map, char **argv);
void check_win(char **map, char **argv);
int count_x(char **tab);