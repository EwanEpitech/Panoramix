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

/**
 * @brief Entry point for the druid thread responsible for refilling the potion pot.
 *
 * Waits for refill requests, refills the pot with a fixed number of servings, and decrements the number of refills left.
 * Continues until no refills remain, then signals that the druid is going to sleep.
 *
 * @param potion Pointer to a potion_t structure containing shared state for synchronization and refill tracking.
 * @return Always returns NULL upon thread completion.
 */
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
