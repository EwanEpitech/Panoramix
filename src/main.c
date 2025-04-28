/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "panoramix.h"
#include "druid.h"
#include "villager.h"

int main(int ac, char **av)
{
    args_t args;
    pthread_t druid;
    pthread_t *villagers;
    int i;

    if (parse_args(ac, av, &args) != 0)
        return 84;

    villagers = malloc(sizeof(pthread_t) * args.nb_villagers);
    if (!villagers) {
        free(args.pot);
        return 84;
    }

    if (pthread_mutex_init(&args.pot->mutex, NULL) != 0 ||
        sem_init(&args.pot->refill, 0, 0) != 0) {
        free(args.pot);
        free(villagers);
        return 84;
    }

    if (pthread_create(&druid, NULL, druid_thread, args.pot) != 0) {
        pthread_mutex_destroy(&args.pot->mutex);
        sem_destroy(&args.pot->refill);
        free(args.pot);
        free(villagers);
        return 84;
    }

    for (i = 0; i < args.nb_villagers; i++) {
        if (pthread_create(&villagers[i], NULL, villager_thread, &args) != 0) {
            pthread_mutex_destroy(&args.pot->mutex);
            sem_destroy(&args.pot->refill);
            free(args.pot);
            free(villagers);
            return 84;
        }
        usleep(1000);
    }

    for (i = 0; i < args.nb_villagers; i++)
        pthread_join(villagers[i], NULL);

    pthread_cancel(druid);
    pthread_join(druid, NULL);

    pthread_mutex_destroy(&args.pot->mutex);
    sem_destroy(&args.pot->refill);
    free(args.pot);
    free(villagers);
    return 0;
}
