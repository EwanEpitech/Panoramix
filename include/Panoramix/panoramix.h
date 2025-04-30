/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** PANORAMIX
*/

#ifndef PANORAMIX_H
    #include <pthread.h>
    #include <semaphore.h>
    #include <stdbool.h>
    #define PANORAMIX_H

/**
 * @brief Structure for the potion
 * @param servings Number of servings left in the pot
 * @param pot_size Size of the pot
 * @param refills_left Number of refills left
 * @param mutex Mutex - Only one thread can access the pot at a time
 * @param refill Semaphore - Wake up the druid when the pot is empty
 */
typedef struct potion_s {
    int servings;
    int pot_size;
    int refills_left;
    pthread_mutex_t mutex;
    sem_t refill;
} potion_t;

/**
 * @brief Structure for the villagers
 * @param nb_villagers Number of villagers
 * @param pot_size Size of the pot
 * @param nb_fights Number of fights left
 * @param nb_refills Number of refills left
 * @param pot Pointer to the potion structure
 */
typedef struct args_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
    potion_t *pot;
} villager_t;

/**
 * @brief Parse the arguments
 * @param ac Number of arguments
 * @param av Array of arguments
 * @param args Pointer to the villagers structure
 * @return true on success, false on failure
 */
bool parse_args(int ac, char **av, villager_t *args);

#endif
