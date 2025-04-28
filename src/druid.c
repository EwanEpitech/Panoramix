/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** druid
*/

#include <stdio.h>
#include <unistd.h>
#include "druid.h"
#include "utils.h"

void *druid_thread(void *potion)
{
    potion_t *pot = (potion_t *)potion;

    print_druid_start();
    while (pot->refills_left > 0) {
        sem_wait(&pot->refill);
        pthread_mutex_lock(&pot->mutex);
        if (pot->refills_left > 0) {
            pot->servings = pot->pot_size;
            pot->refills_left--;
            print_druid_refill(pot->refills_left);
        }
        pthread_mutex_unlock(&pot->mutex);
    }
    print_druid_sleep();
    return NULL;
}
