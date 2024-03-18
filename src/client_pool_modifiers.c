/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** client_pool_modifiers.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "client_pool.h"

int add_client(client_pool_t *client_pool, client_t *client)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_pool->clients_state[i] == CLIENT_USED)
            continue;
        client_pool->clients[i] = client;
        client_pool->clients_state[i] = CLIENT_USED;
        client_pool->last_client_index = i;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int remove_client(client_pool_t *client_pool, client_t *client)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_pool->clients[i] != client)
            continue;
        if (terminate_client(client_pool->clients[i]) == EXIT_FAILURE)
            return EXIT_FAILURE;
        client_pool->clients_state[i] = CLIENT_NOT_USED;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
