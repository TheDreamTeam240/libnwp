/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** server.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"

int init_server_socket(server_t *server)
{
    server->listen_sock = init_listen_sock(server->ip_addr,
        server->ip_port);
    if (server->listen_sock == NULL)
        return EXIT_FAILURE;
    server->client_pool = init_client_pool(
        get_listen_sock_fd(server->listen_sock),
        server->client_callback, server->data);
    if (server->client_pool == NULL)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

server_t *init_server(char *ip_addr, unsigned short ip_port,
    client_callback_t *client_callback, void *data[MAX_CLIENTS])
{
    server_t *server = malloc(sizeof(server_t));

    if (server == NULL)
        return NULL;
    server->ip_addr = ip_addr;
    server->ip_port = ip_port;
    server->client_callback = client_callback;
    memcpy(server->data, data, sizeof(void *) * MAX_CLIENTS);
    if (init_server_socket(server) == EXIT_FAILURE)
        return NULL;
    return server;
}

int terminate_server(server_t *server)
{
    if (terminate_client_pool(server->client_pool) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (terminate_listen_sock(server->listen_sock) == EXIT_FAILURE)
        return EXIT_FAILURE;
    free(server);
    return EXIT_SUCCESS;
}

int server_routine(server_t *server)
{
    if (client_pool_routine(server->client_pool) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
