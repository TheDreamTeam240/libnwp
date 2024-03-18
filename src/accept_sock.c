/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** accept_sock.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "accept_sock.h"

accept_sock_t *init_accept_sock(int listent_sock_fd)
{
    accept_sock_t *accept_sock = malloc(sizeof(accept_sock_t));

    if (accept_sock == NULL) {
        dprintf(2, "Error: malloc failed\n");
        return NULL;
    }
    memset(&accept_sock->addr, 0, sizeof(accept_sock->addr));
    accept_sock->addr_len = sizeof(accept_sock->addr);
    accept_sock->sock_fd = accept(listent_sock_fd,
        (struct sockaddr *)&accept_sock->addr, &accept_sock->addr_len);
    if (accept_sock->sock_fd == -1) {
        dprintf(2, "Error: accept failed\n");
        return NULL;
    }
    accept_sock->buffer = NULL;
    return accept_sock;
}

int terminate_accept_sock(accept_sock_t *accept_sock)
{
    if (accept_sock->buffer != NULL)
        free(accept_sock->buffer);
    if (close(accept_sock->sock_fd) == -1) {
        dprintf(2, "Error: close failed\n");
        return EXIT_FAILURE;
    }
    free(accept_sock);
    return EXIT_SUCCESS;
}
