/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** client.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "client.h"

client_t *init_client(int listen_sock_fd)
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL) {
        dprintf(2, "Error: malloc failed\n");
        return NULL;
    }
    client->accept_sock = init_accept_sock(listen_sock_fd);
    if (client->accept_sock == NULL) {
        dprintf(2, "Error: init_accept_sock failed\n");
        return NULL;
    }
    printf("New client\n");
    return client;
}

int terminate_client(client_t *client)
{
    if (terminate_accept_sock(client->accept_sock) == EXIT_FAILURE) {
        dprintf(2, "Error: terminate_accept_sock failed\n");
        return EXIT_FAILURE;
    }
    free(client);
    printf("Bye client\n");
    return EXIT_SUCCESS;
}
