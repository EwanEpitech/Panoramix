/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** utils
*/

#ifndef UTILS_H
    #include "Panoramix/panoramix.h"
    #define UTILS_H

/**
 * @brief Print the start message for a villager
 * @param id The id of the villager
 */
void print_villager_start(int id);

/**
 * @brief Print the drink message for a villager
 * @param id The id of the villager
 * @param servings The number of servings left in the pot
 */
void print_villager_drink(int id, int servings);

/**
 * @brief Print the call druid message for a villager
 * @param id The id of the villager
 */
void print_villager_call_druid(int id);

/**
 * @brief Print the fight message for a villager
 * @param id The id of the villager
 * @param fights_left The number of fights left
 */
void print_villager_fight(int id, int fights_left);

/**
 * @brief Print the sleep message for a villager
 * @param id The id of the villager
 */
void print_villager_sleep(int id);

/**
 * @brief Print the start message for the druid
 */
void print_druid_start(void);

/**
 * @brief Print the refill message for the druid
 * @param refills_left The number of refills left
 */
void print_druid_refill(int refills_left);

/**
 * @brief Print the sleep message for the druid
 */
void print_druid_sleep(void);

#endif
