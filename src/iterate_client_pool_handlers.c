/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** iterate_client_pool_handlers.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "client_pool.h"

int handle_readable_listen_sock(client_pool_t *client_pool)
{
    client_t *client = NULL;

    client = init_client(client_pool->listen_sock_fd);
    if (client == NULL)
        return EXIT_FAILURE;
    if (add_client(client_pool, client) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (client_pool->client_callback->connect_callback(
        client_pool, client,
        client_pool->data[client_pool->last_client_index])
        == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int handle_writable_client(client_pool_t *client_pool, size_t client_index)
{
    if (client_pool->client_callback->write_callback(
        client_pool, client_pool->clients[client_index],
        client_pool->data[client_index]) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int handle_readable_client(client_pool_t *client_pool, size_t client_index)
{
    if (client_pool->client_callback->read_callback(
        client_pool, client_pool->clients[client_index],
        client_pool->data[client_index]) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int handle_error_client(client_pool_t *client_pool, size_t client_index)
{
    if (client_pool->client_callback->except_callback(
        client_pool, client_pool->clients[client_index],
        client_pool->data[client_index]) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
