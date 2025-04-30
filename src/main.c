/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Panoramix/panoramix.h"
#include "Panoramix/druid.h"
#include "Panoramix/villager.h"

/**
 * @brief Initialize the resources
 * @param args Pointer to the villagers structure
 * @param villagers Pointer to the array of threads
 * @return true on success, false on failure
 */
static bool init_resources(villager_t *args, pthread_t **villagers)
{
    *villagers = malloc(sizeof(pthread_t) * args->nb_villagers);
    if (!*villagers) {
        free(args->pot);
        return false;
    }
    if (pthread_mutex_init(&args->pot->mutex, NULL) != 0 ||
        sem_init(&args->pot->refill, 0, 0) != 0) {
        free(args->pot);
        free(*villagers);
        return false;
    }
    return true;
}

/**
 * @brief Create the threads
 * @param args Pointer to the villagers structure
 * @param druid Pointer to the druid thread
 * @param villagers Pointer to the array of threads
 * @return true on success, false on failure
 */
static bool create_threads(villager_t *args, pthread_t *druid,
    pthread_t *villagers)
{
    if (pthread_create(druid, NULL, druid_thread, args->pot) != 0) {
        pthread_mutex_destroy(&args->pot->mutex);
        sem_destroy(&args->pot->refill);
        free(args->pot);
        free(villagers);
        return false;
    }
    for (int i = 0; i < args->nb_villagers; i++) {
        if (pthread_create(&villagers[i], NULL, villager_thread, args) != 0) {
            pthread_mutex_destroy(&args->pot->mutex);
            sem_destroy(&args->pot->refill);
            free(args->pot);
            free(villagers);
            return false;
        }
        usleep(1000);
    }
    return true;
}

/**
 * @brief Cleanup the resources
 * @param args Pointer to the villagers structure
 * @param villagers Pointer to the array of threads
 */
static void cleanup_resources(villager_t *args, pthread_t *villagers)
{
    pthread_mutex_destroy(&args->pot->mutex);
    sem_destroy(&args->pot->refill);
    free(args->pot);
    free(villagers);
}

/**
 * @brief Main function
 * @param ac Number of arguments
 * @param av Array of arguments
 * @return 0 on success, 84 on failure
 */
int main(int ac, char **av)
{
    villager_t args;
    pthread_t druid;
    pthread_t *villagers;

    if (!parse_args(ac, av, &args))
        return 84;
    if (!init_resources(&args, &villagers))
        return 84;
    if (!create_threads(&args, &druid, villagers))
        return 84;
    for (int i = 0; i < args.nb_villagers; i++)
        pthread_cancel(villagers[i]);
    for (int i = 0; i < args.nb_villagers; i++)
        pthread_join(villagers[i], NULL);
    pthread_cancel(druid);
    pthread_join(druid, NULL);
    cleanup_resources(&args, villagers);
    return 0;
}
