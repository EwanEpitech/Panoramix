/*
** EPITECH PROJECT, 2025
** B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
** File description:
** utils
*/

#include <stdio.h>
#include "Utils/utils.h"

void print_villager_start(int id)
{
    printf("Villager %d: Going into battle!\n", id);
}

void print_villager_drink(int id, int servings)
{
    printf("Villager %d: I need a drink... I see %d servings left.\n", id, servings);
}

void print_villager_call_druid(int id)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n", id);
}

void print_villager_fight(int id, int fights_left)
{
    printf("Villager %d: Take that roman scum! Only %d left.\n", id, fights_left);
}

void print_villager_sleep(int id)
{
    printf("Villager %d: I'm going to sleep now.\n", id);
}

void print_druid_start(void)
{
    printf("Druid: I'm ready... but sleepy...\n");
}

void print_druid_refill(int refills_left)
{
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make %d more refills after this one.\n", refills_left);
}

void print_druid_sleep(void)
{
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}
