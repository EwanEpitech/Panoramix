/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** utils
*/

#include <stdio.h>
#include "Utils/utils.h"

/**
 * @brief Print the start message for the druid
 */
void print_druid_start(void)
{
    printf("Druid: I'm ready... but sleepy...\n");
}

/**
 * @brief Print the refill message for the druid
 * @param refills_left The number of refills left
 */
void print_druid_refill(int refills_left)
{
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only"
        " make %d more refills after this one.\n", refills_left);
}

/**
 * @brief Print the sleep message for the druid
 */
void print_druid_sleep(void)
{
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}
