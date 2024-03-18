/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** client_pool.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "client_pool.h"

int init_client_pool_clients(client_pool_t *client_pool)
{
    memset(client_pool->clients, 0, sizeof(client_t *) * MAX_CLIENTS);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_pool->clients_state[i] = CLIENT_NOT_USED;
    }
    FD_ZERO(&client_pool->read_fds);
    FD_ZERO(&client_pool->write_fds);
    FD_ZERO(&client_pool->error_fds);
    return EXIT_SUCCESS;
}

client_pool_t *init_client_pool(int listen_sock_fd,
    client_callback_t *client_callback, void *data[MAX_CLIENTS])
{
    client_pool_t *client_pool = malloc(sizeof(client_pool_t));

    if (client_pool == NULL) {
        dprintf(2, "Error: malloc failed\n");
        return NULL;
    }
    client_pool->listen_sock_fd = listen_sock_fd;
    client_pool->client_callback = client_callback;
    client_pool->last_client_index = 0;
    memcpy(client_pool->data, data, sizeof(void *) * MAX_CLIENTS);
    if (init_client_pool_clients(client_pool) == EXIT_FAILURE) {
        dprintf(2, "Error: init_client_pool_clients failed\n");
        return NULL;
    }
    return client_pool;
}

int terminate_client_pool(client_pool_t *client_pool)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_pool->clients_state[i] == CLIENT_NOT_USED)
            continue;
        if (terminate_client(client_pool->clients[i]) == EXIT_FAILURE) {
            dprintf(2, "Error: terminate_client failed\n");
            return EXIT_FAILURE;
        }
    }
    free(client_pool);
    return EXIT_SUCCESS;
}
