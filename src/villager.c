/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** villager
*/

#include <stdio.h>
#include <unistd.h>
#include "villager.h"
#include "utils.h"

/**
 * @brief Thread routine for a villager managing its fight and drink cycle.
 *
 * Assigns a unique ID to the villager, then repeatedly attempts to drink from a shared pot and fight until the required number of fights is completed or the pot is exhausted with no refills left. Coordinates with other threads using mutexes and semaphores to ensure safe access to shared resources and to signal for pot refills when needed.
 *
 * @param arg Pointer to an `args_t` structure containing the villager's configuration and shared pot reference.
 * @return Always returns NULL.
 */
void *villager_thread(void *arg)
{
    static int id = 0;
    static pthread_mutex_t id_mutex = PTHREAD_MUTEX_INITIALIZER;
    int my_id;
    args_t *args = (args_t *)arg;
    int fights_left = args->nb_fights;

    pthread_mutex_lock(&id_mutex);
    my_id = id++;
    pthread_mutex_unlock(&id_mutex);

    print_villager_start(my_id);
    while (fights_left > 0) {
        pthread_mutex_lock(&args->pot->mutex);
        if (args->pot->servings == 0 && args->pot->refills_left > 0) {
            print_villager_call_druid(my_id);
            pthread_mutex_unlock(&args->pot->mutex);
            sem_post(&args->pot->refill);
            usleep(1000);
            continue;
        } else if (args->pot->servings > 0) {
            print_villager_drink(my_id, args->pot->servings);
            args->pot->servings--;
            pthread_mutex_unlock(&args->pot->mutex);
            print_villager_fight(my_id, --fights_left);
            usleep(1000);
        } else {
            pthread_mutex_unlock(&args->pot->mutex);
            break;
        }
    }
    print_villager_sleep(my_id);
    pthread_mutex_lock(&args->pot->mutex);
    pthread_mutex_unlock(&args->pot->mutex);
    return NULL;
}
