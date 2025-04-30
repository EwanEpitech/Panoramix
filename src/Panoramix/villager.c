/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** villager
*/

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "Panoramix/villager.h"
#include "Utils/utils.h"

/**
 * @brief Get the villager id by locking the mutex and incrementing the id
 * @return The id of the villager
 */
static int get_villager_id(void)
{
    static int id = 0;
    static pthread_mutex_t id_mutex = PTHREAD_MUTEX_INITIALIZER;
    int my_id;

    pthread_mutex_lock(&id_mutex);
    my_id = id;
    id++;
    pthread_mutex_unlock(&id_mutex);
    return my_id;
}

/**
 * @brief Handle the empty pot by calling the druid && posting to the semaphore
 * @param my_id The id of the villager
 * @param args Pointer to the villagers structure
 */
static void handle_empty_pot(int my_id, villager_t *args)
{
    if (args->pot->refills_left > 0) {
        print_villager_call_druid(my_id);
        sem_post(&args->pot->refill);
    }
}

/**
 * @brief Handle the drink by decrementing the servings and printing drink log
 * @param my_id The id of the villager
 * @param args Pointer to the villagers structure
 * @param fights_left Pointer to the number of fights left
 */
static void handle_drink(int my_id, villager_t *args, int *fights_left)
{
    print_villager_drink(my_id, args->pot->servings);
    args->pot->servings--;
    print_villager_fight(my_id, --(*fights_left));
}

/**
 * @brief Process the pot by checking if it's empty and handling the drink
 * @param my_id The id of the villager
 * @param args Pointer to the villagers structure
 * @param fights_left Pointer to the number of fights left
 */
static bool process_pot(int my_id, villager_t *args, int *fights_left)
{
    if (args->pot->servings == 0) {
        handle_empty_pot(my_id, args);
        return true;
    }
    handle_drink(my_id, args, fights_left);
    return false;
}

/**
 * @brief Process the pot by checking if it's empty and handling the drink
 * @param my_id The id of the villager
 * @param args Pointer to the villagers structure
 * @param fights_left Pointer to the number of fights left
 */
static void villager_loop(int my_id, villager_t *args, int *fights_left)
{
    while (*fights_left > 0) {
        pthread_mutex_lock(&args->pot->mutex);
        if (args->pot->servings == 0 && args->pot->refills_left == 0) {
            pthread_mutex_unlock(&args->pot->mutex);
            break;
        }
        if (process_pot(my_id, args, fights_left)) {
            pthread_mutex_unlock(&args->pot->mutex);
            usleep(1000);
            continue;
        }
        pthread_mutex_unlock(&args->pot->mutex);
        usleep(1000);
    }
}

/**
 * @brief Thread function for the villagers
 * The villagers will try to drink from the pot,
 * If the pot is empty, they will call the druid
 * If the pot is not empty, they will drink and fight
 * @param arg Pointer to the villagers structure
 * @return NULL
 */
void *villager_thread(void *arg)
{
    villager_t *args = (villager_t *)arg;
    int my_id = get_villager_id();
    int fights_left = args->nb_fights;

    print_villager_start(my_id);
    villager_loop(my_id, args, &fights_left);
    print_villager_sleep(my_id);
    return NULL;
}
