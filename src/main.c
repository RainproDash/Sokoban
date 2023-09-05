/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-vivien.boitard
** File description:
** main
*/

#include "../include/header.h"

void destroy_map(sokoban_t *sokoban)
{
    free(sokoban);
}

static void init_struct(sokoban_t *sokoban)
{
    sokoban->map = NULL;
    sokoban->map_copy = NULL;
    sokoban->ch = 0;
    sokoban->nb_o = 0;
    sokoban->nb_x = 0;
    sokoban->nb_p = 0;
    sokoban->p_pos_i = 0;
    sokoban->p_pos_j = 0;
}

static void display_help(void)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap\tfile representin"
    "g the warehouse map, containing '#' for walls,\n\t\t'P' for the player, '"
    "X' for boxes and 'O' for storage locations.\n");
    exit(0);
}

void open_file(char *filepath, sokoban_t *sokoban)
{
    int fd = open(filepath, O_RDONLY);
    struct stat st;
    char *buffer = NULL;

    if (fd == -1) {
        free(sokoban);
        exit(84);
    }
    stat(filepath, &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    sokoban->map = my_str_to_word_array(buffer, '\n');
    manage_error(sokoban);
    sokoban->map_copy = copy_tab(sokoban->map);
    close(fd);
}

int main(int ac, char **av)
{
    sokoban_t *sokoban;

    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0)
        display_help();
    sokoban = malloc(sizeof(sokoban_t));
    init_struct(sokoban);
    open_file(av[1], sokoban);
    manage_game(sokoban);
    destroy_map(sokoban);
    return 0;
}
