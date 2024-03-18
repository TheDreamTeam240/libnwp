/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** iterate_client_pool.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "client_pool.h"

void iterate_client(client_pool_t *client_pool,
    fd_set_callback_t callbacks[3], size_t i)
{
    for (size_t j = 0; j < 3; j++) {
        if (FD_ISSET(get_client_sock_fd(client_pool->clients[i]),
            callbacks[j].fd_set)) {
            callbacks[j].callback(client_pool, i);
        }
    }
}

int iterate_client_pool(client_pool_t *client_pool)
{
    fd_set_callback_t callbacks[3] = {
        {&client_pool->read_fds, handle_readable_client},
        {&client_pool->write_fds, handle_writable_client},
        {&client_pool->error_fds, handle_error_client}
    };

    if (FD_ISSET(client_pool->listen_sock_fd, &client_pool->read_fds)) {
        if (handle_readable_listen_sock(client_pool) == EXIT_FAILURE) {
            return EXIT_FAILURE;
        }
    }
    for (size_t i = 0; i < MAX_CLIENTS; i++) {
        if (client_pool->clients_state[i] == CLIENT_NOT_USED)
            continue;
        iterate_client(client_pool, callbacks, i);
    }
    return EXIT_SUCCESS;
}

int client_pool_routine(client_pool_t *client_pool)
{
    if (refresh_client_pool(client_pool) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (iterate_client_pool(client_pool) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
