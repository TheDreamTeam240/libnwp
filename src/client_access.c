/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** client_access.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "client.h"

int get_client_sock_fd(client_t *client)
{
    return get_accept_sock_fd(client->accept_sock);
}
