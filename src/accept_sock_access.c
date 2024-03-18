/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** accept_sock_access.c
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "accept_sock.h"

int get_accept_sock_fd(accept_sock_t *accept_sock)
{
    return accept_sock->sock_fd;
}
