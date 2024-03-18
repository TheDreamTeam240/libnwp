/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** refresh_client_pool.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "client_pool.h"

int refresh_fd_set(client_pool_t *client_pool, fd_set *fdset)
{
    FD_ZERO(fdset);
    FD_SET(client_pool->listen_sock_fd, fdset);
    client_pool->max_fd = client_pool->listen_sock_fd;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_pool->clients_state[i] == CLIENT_NOT_USED)
            continue;
        if (get_client_sock_fd(client_pool->clients[i]) >
            client_pool->max_fd) {
            client_pool->max_fd = get_client_sock_fd(client_pool->clients[i]);
        }
        FD_SET(get_client_sock_fd(client_pool->clients[i]), fdset);
    }
    return EXIT_SUCCESS;
}

int refresh_client_pool(client_pool_t *client_pool)
{
    fd_set *fd_sets[3] = {&client_pool->read_fds, &client_pool->write_fds,
        &client_pool->error_fds};

    for (int i = 0; i < 3; i++) {
        if (refresh_fd_set(client_pool, fd_sets[i]) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (select(client_pool->max_fd + 1, &client_pool->read_fds,
        NULL, &client_pool->error_fds, NULL) == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
