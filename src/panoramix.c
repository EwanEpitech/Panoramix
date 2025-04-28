/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** panoramix
*/

#include <stdio.h>
#include <stdlib.h>
#include "panoramix.h"

int parse_args(int ac, char **av, args_t *args)
{
    if (ac != 5) {
        fprintf(stderr, "USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n");
        return 84;
    }

    args->nb_villagers = atoi(av[1]);
    args->pot_size = atoi(av[2]);
    args->nb_fights = atoi(av[3]);
    args->nb_refills = atoi(av[4]);

    if (args->nb_villagers <= 0 || args->pot_size <= 0 ||
        args->nb_fights <= 0 || args->nb_refills <= 0) {
        fprintf(stderr, "USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n");
        fprintf(stderr, "Values must be >0.\n");
        return 84;
    }

    args->pot = malloc(sizeof(potion_t));
    if (!args->pot)
        return 84;
    args->pot->servings = args->pot_size;
    args->pot->pot_size = args->pot_size;
    args->pot->refills_left = args->nb_refills;
    return 0;
}
