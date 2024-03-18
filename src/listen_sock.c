/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** listen_sock.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "listen_sock.h"

listen_sock_t *init_listen_sock(char *ip_addr, unsigned short ip_port)
{
    listen_sock_t *listen_sock = malloc(sizeof(listen_sock_t));

    if (listen_sock == NULL) {
        dprintf(2, "Error: malloc failed\n");
        return NULL;
    }
    if (init_listen_sock_socket(listen_sock, ip_addr,
        ip_port) == EXIT_FAILURE) {
        dprintf(2, "Error: init_listen_sock_socket failed\n");
        return NULL;
    }
    return listen_sock;
}

int terminate_listen_sock(listen_sock_t *listen_sock)
{
    if (close(listen_sock->sock_fd) == -1) {
        dprintf(2, "Error: close failed\n");
        return EXIT_FAILURE;
    }
    free(listen_sock);
    return EXIT_SUCCESS;
}
