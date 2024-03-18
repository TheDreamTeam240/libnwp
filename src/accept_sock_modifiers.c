/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** accept_sock_modifiers.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

#include "accept_sock.h"

char *read_accept_sock(accept_sock_t *accept_sock)
{
    char *msg = NULL;
    char buffer[BUFFER_SIZE] = {0};
    ssize_t bytes_read = 0;
    size_t msg_size = 0;

    do {
        bytes_read = read(accept_sock->sock_fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1 || bytes_read == 0)
            return NULL;
        msg = realloc(msg, msg_size + bytes_read + 1);
        if (msg == NULL)
            return NULL;
        memcpy(msg + msg_size, buffer, bytes_read);
        msg_size += bytes_read;
        msg[msg_size] = '\0';
    } while (bytes_read == BUFFER_SIZE);
    return msg;
}

int write_accept_sock(accept_sock_t *accept_sock, char *msg)
{
    if (write(accept_sock->sock_fd, msg, strlen(msg)) == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int printf_accept_sock(accept_sock_t *accept_sock, char *format,
    va_list *args)
{
    if (dprintf(accept_sock->sock_fd, format, args) == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
