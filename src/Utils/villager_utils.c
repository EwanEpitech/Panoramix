/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** utils
*/

#include <stdio.h>
#include "Utils/utils.h"

/**
 * @brief Print the start message for a villager
 * @param id The id of the villager
 */
void print_villager_start(int id)
{
    printf("Villager %d: Going into battle!\n", id);
}

/**
 * @brief Print the drink message for a villager
 * @param id The id of the villager
 * @param servings The number of servings left in the pot
 */
void print_villager_drink(int id, int servings)
{
    printf("Villager %d: I need a drink... I see %d servings left.\n",
        id, servings);
}

/**
 * @brief Print the call druid message for a villager
 * @param id The id of the villager
 */
void print_villager_call_druid(int id)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n", id);
}

/**
 * @brief Print the fight message for a villager
 * @param id The id of the villager
 * @param fights_left The number of fights left
 */
void print_villager_fight(int id, int fights_left)
{
    printf("Villager %d: Take that roman scum! Only %d left.\n", id,
        fights_left);
}

/**
 * @brief Print the sleep message for a villager
 * @param id The id of the villager
 */
void print_villager_sleep(int id)
{
    printf("Villager %d: I'm going to sleep now.\n", id);
}
