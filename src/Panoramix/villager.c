/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** villager
*/

#include <stdio.h>
#include <unistd.h>
#include "Panoramix/villager.h"
#include "Utils/utils.h"

void *villager_thread(void *arg)
{
    static int id = 0;
    static pthread_mutex_t id_mutex = PTHREAD_MUTEX_INITIALIZER;
    int my_id;
    villager_t *args = (villager_t *)arg;
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
