/*
** EPITECH PROJECT, 2024
** libnwp
** File description:
** connect_sock.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "connect_sock.h"

connect_sock_t *init_connect_sock(char *ip_addr, unsigned short ip_port)
{
    connect_sock_t *connect_sock = malloc(sizeof(connect_sock_t));

    if (connect_sock == NULL)
        return NULL;
    connect_sock->sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect_sock->sock_fd == -1)
        return NULL;
    connect_sock->addr.sin_family = AF_INET;
    connect_sock->addr.sin_port = htons(ip_port);
    connect_sock->addr.sin_addr.s_addr = inet_addr(ip_addr);
    if (connect(connect_sock->sock_fd, (struct sockaddr *)&connect_sock->addr,
        sizeof(connect_sock->addr)) == -1)
        return NULL;
    return connect_sock;
}

int terminate_connect_sock(connect_sock_t *connect_sock)
{
    if (close(connect_sock->sock_fd) == -1)
        return EXIT_FAILURE;
    free(connect_sock);
    return EXIT_SUCCESS;
}
