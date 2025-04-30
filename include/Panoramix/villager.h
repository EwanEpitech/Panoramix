/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** villager
*/

#ifndef VILLAGER_H
    #include "Panoramix/panoramix.h"
    #define VILLAGER_H

/**
 * @brief Thread function for the villagers
 * @param arg Pointer to the villagers structure
 * @return NULL
 */
void *villager_thread(void *arg);

#endif
