/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** listen_sock_access.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "listen_sock.h"

int get_listen_sock_fd(listen_sock_t *listen_sock)
{
    return listen_sock->sock_fd;
}
