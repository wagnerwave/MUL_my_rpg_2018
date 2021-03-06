/*
** EPITECH PROJECT, 2018
** src/main
** File description:
** M-x doctor
*/

#include <time.h>
#include <stdlib.h>
#include "world.h"
#include "my.h"

int     display_usage(void)
{
    my_printf("my_rpg\n");
    return (0);
}

int     main(int ac, char **av)
{
    if (ac == 2 && (!my_strcmp(av[1], "-h") || !my_strcmp(av[1], "--help")))
        return (display_usage());
    if (ac > 1)
        return (84);
    srand(time(NULL));
    return (window());
}
