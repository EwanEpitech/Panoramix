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

static void handle_empty_pot(int my_id, villager_t *args)
{
    if (args->pot->refills_left > 0) {
        print_villager_call_druid(my_id);
        sem_post(&args->pot->refill);
    }
}

static void handle_drink(int my_id, villager_t *args, int *fights_left)
{
    print_villager_drink(my_id, args->pot->servings);
    args->pot->servings--;
    print_villager_fight(my_id, --(*fights_left));
}

static bool process_pot(int my_id, villager_t *args, int *fights_left)
{
    if (args->pot->servings == 0) {
        handle_empty_pot(my_id, args);
        return true;
    }
    handle_drink(my_id, args, fights_left);
    return false;
}

void *villager_thread(void *arg)
{
    villager_t *args = (villager_t *)arg;
    int my_id = get_villager_id();
    int fights_left = args->nb_fights;

    print_villager_start(my_id);
    while (fights_left > 0) {
        pthread_mutex_lock(&args->pot->mutex);
        if (process_pot(my_id, args, &fights_left)) {
            pthread_mutex_unlock(&args->pot->mutex);
            usleep(1000);
            continue;
        }
        pthread_mutex_unlock(&args->pot->mutex);
        usleep(1000);
    }
    print_villager_sleep(my_id);
    return NULL;
}
