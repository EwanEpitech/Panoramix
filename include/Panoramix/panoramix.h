/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** PANORAMIX
*/

#ifndef PANORAMIX_H
#define PANORAMIX_H

#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

typedef struct potion_s {
    int servings;
    int pot_size;
    int refills_left;
    pthread_mutex_t mutex;
    sem_t refill;
} potion_t;

typedef struct args_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
    potion_t *pot;
} villager_t;

void *villager_thread(void *arg);
void *druid_thread(void *potion);

int parse_args(int ac, char **av, villager_t *args);

#endif
