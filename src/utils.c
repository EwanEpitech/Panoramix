/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** utils
*/

#include <stdio.h>
#include "utils.h"

/**
 * @brief Prints a message indicating that a villager is going into battle.
 *
 * @param id The unique identifier of the villager.
 */
void print_villager_start(int id)
{
    printf("Villager %d: Going into battle!\n", id);
}

/**
 * @brief Prints a message indicating a villager needs a drink and shows remaining potion servings.
 *
 * @param id The ID of the villager requesting a drink.
 * @param servings The number of potion servings left.
 */
void print_villager_drink(int id, int servings)
{
    printf("Villager %d: I need a drink... I see %d servings left.\n", id, servings);
}

/**
 * @brief Prints a message indicating that a villager is calling the druid for more potion.
 *
 * @param id The ID of the villager making the request.
 */
void print_villager_call_druid(int id)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n", id);
}

/**
 * @brief Prints a message indicating a villager is fighting and shows remaining fights.
 *
 * @param id The ID of the villager.
 * @param fights_left The number of fights the villager has left.
 */
void print_villager_fight(int id, int fights_left)
{
    printf("Villager %d: Take that roman scum! Only %d left.\n", id, fights_left);
}

/**
 * @brief Prints a message indicating that the specified villager is going to sleep.
 *
 * @param id The ID of the villager.
 */
void print_villager_sleep(int id)
{
    printf("Villager %d: I'm going to sleep now.\n", id);
}

/**
 * @brief Prints a message indicating the druid is ready but sleepy.
 *
 * Outputs a status message to standard output when the druid is prepared for action.
 */
void print_druid_start(void)
{
    printf("Druid: I'm ready... but sleepy...\n");
}

/**
 * @brief Prints a message indicating the druid is refilling potion, with remaining refills.
 *
 * @param refills_left The number of potion refills the druid can make after the current one.
 */
void print_druid_refill(int refills_left)
{
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make %d more refills after this one.\n", refills_left);
}

/**
 * @brief Prints a message indicating the druid is out of potion ingredient and is going back to sleep.
 */
void print_druid_sleep(void)
{
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}
