/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** listen_sock_modifiers.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "listen_sock.h"

int init_listen_sock_socket(listen_sock_t *listen_sock,
    char *ip_addr, unsigned short ip_port)
{
    listen_sock->sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock->sock_fd == -1) {
        dprintf(2, "Error: socket failed\n");
        return EXIT_FAILURE;
    }
    if (listen_sock_bind(listen_sock, ip_addr, ip_port) == EXIT_FAILURE) {
        dprintf(2, "Error: listen_sock_bind failed\n");
        return EXIT_FAILURE;
    }
    if (listen_sock_listen(listen_sock) == EXIT_FAILURE) {
        dprintf(2, "Error: listen_sock_listen failed\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int listen_sock_bind(listen_sock_t *listen_sock, char *ip_addr,
    unsigned short ip_port)
{
    listen_sock->addr.sin_family = AF_INET;
    listen_sock->addr.sin_port = htons(ip_port);
    listen_sock->addr.sin_addr.s_addr = inet_addr(ip_addr);
    if (bind(listen_sock->sock_fd, (struct sockaddr *)&listen_sock->addr,
        sizeof(listen_sock->addr)) == -1) {
        dprintf(2, "Error: bind failed\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int listen_sock_listen(listen_sock_t *listen_sock)
{
    if (listen(listen_sock->sock_fd, 1) == -1) {
        dprintf(2, "Error: listen failed\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
