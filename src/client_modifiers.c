/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** client_modifiers.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "client.h"

char *read_client(client_t *client)
{
    return read_accept_sock(client->accept_sock);
}

int write_client(client_t *client, char *msg)
{
    return write_accept_sock(client->accept_sock, msg);
}

int printf_client(client_t *client, char *format, ...)
{
    va_list args;
    int status;

    va_start(args, format);
    status = printf_accept_sock(client->accept_sock, format, &args);
    va_end(args);
    return status;
}
