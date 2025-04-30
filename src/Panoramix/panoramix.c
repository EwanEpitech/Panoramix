/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** panoramix
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "Panoramix/panoramix.h"

/**
 * @brief Print an error message
 * @param message The error message to print
 * @return false - synonym for failure
 */
static bool print_error(const char *message)
{
    write(2, message, strlen(message));
    return false;
}

/**
 * @brief Fill the villagers structure
 * @param av Array of arguments
 * @param args Pointer to the villagers structure
 */
static void fill_villagers(char **av, villager_t *args)
{
    args->nb_villagers = atoi(av[1]);
    args->pot_size = atoi(av[2]);
    args->nb_fights = atoi(av[3]);
    args->nb_refills = atoi(av[4]);
}

/**
 * @brief Fill the potion structure
 * @param args Pointer to the villagers structure
 * @return true if the pot is filled, false otherwise
 */
static bool fill_pot(villager_t *args)
{
    args->pot = malloc(sizeof(potion_t));
    if (!args->pot)
        return false;
    args->pot->servings = args->pot_size;
    args->pot->pot_size = args->pot_size;
    args->pot->refills_left = args->nb_refills;
    return true;
}

/**
 * @brief Parse the arguments
 * @param ac Number of arguments
 * @param av Array of arguments
 * @param args Pointer to the villagers structure
 * @return true on success, false on failure
 */
bool parse_args(int ac, char **av, villager_t *args)
{
    if (ac != 5)
        return print_error("USAGE: ./panoramix <nb_villagers> <pot_size>"
            " <nb_fights> <nb_refills>\n");
    fill_villagers(av, args);
    if (args->nb_villagers <= 0 || args->pot_size <= 0 ||
        args->nb_fights <= 0 || args->nb_refills <= 0)
        return print_error("USAGE: ./panoramix <nb_villagers> <pot_size>"
            " <nb_fights> <nb_refills>\nValues must be >0.\n");
    if (!fill_pot(args))
        return false;
    return true;
}
