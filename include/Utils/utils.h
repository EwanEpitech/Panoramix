/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** utils
*/

#ifndef UTILS_H
    #include "Panoramix/panoramix.h"
    #define UTILS_H

void print_villager_start(int id);
void print_villager_drink(int id, int servings);
void print_villager_call_druid(int id);
void print_villager_fight(int id, int fights_left);
void print_villager_sleep(int id);

void print_druid_start(void);
void print_druid_refill(int refills_left);
void print_druid_sleep(void);

#endif
